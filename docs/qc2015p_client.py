# -*- coding: utf-8 -*-
"""
QC2015P 本地测试平台 Python 脚本库

简洁封装函数:
    SECC_ValueSet("ChargeSta", 1)      SECC_ValueGet("ChargeSta")
    EVCC_ValueSet("ChargeSta", 1)      EVCC_ValueGet("ChargeSta")
    MsgGet(0x1836F456)                  → 完整报文 {data, timestamp, signals, name, dlc}
    MsgGet(0x1836F456, "Data")          → 原始字节数组
    MsgGet(0x1836F456, "lastTimestamp") → 更新时间戳(us)
    MsgGet(0x1836F456, "PGI05_K1")     → 单个信号值

共享参数（shared_params.conf 中配置的参数对）:
    SECC侧设置会自动同步到EVCC，反之亦然。两侧都可读写。

底层接口仍可用: set_params("SECC_ChargeSta", 1) / get_params("SECC_ChargeSta")

专业 HIL 自动化测试机制（详见 scripts/README.md）:
    with QcSession(device="zlg", baud=250000, restart=True) as s:  # 连接+开录制+参数快照
        s.addCleanup(fn)                    # 逆序清理（模仿 unittest.addCleanup）
        assert_eq(a, b, "消息")             # 断言失败抛 QcAssertError
    # 会话退出自动: 停录制→rename→恢复被改参数→关通道/设备→restart_hil
    finish(True, "完成")                    # 打印 "结论: PASS - 完成"，返回退出码 0/1
"""

import json
import os
import sys
import time
import socket
import subprocess
import urllib.request
import urllib.parse
from typing import Any, Callable, Dict, List, Optional, Union

# Windows定时器精度：默认time.sleep(0.001)实际粒度约15.6ms，
# 会导致轮询类脚本（如长消息中断测试）检测延迟1~2个10ms帧。
# 提升到1ms精度（进程级设置，退出后自动恢复）。
try:
    import ctypes
    ctypes.windll.winmm.timeBeginPeriod(1)
except Exception:
    pass


def qcsleep(ms: float) -> None:
    """高精度等待（毫秒）。
    Windows 下 time.sleep(0.001) 实际粒度约15.6ms，逐帧（10ms）轮询会晚1~2帧。
    <=5ms 用忙等保证精度；更长先 sleep 再忙等收尾。
    """
    _end = time.perf_counter() + ms / 1000.0
    if ms > 5:
        time.sleep(max(0.0, ms / 1000.0 - 0.005))
    while time.perf_counter() < _end:
        pass


def qc_monitor(model: str, name: str) -> Any:
    """读取 UserMonitor 变量（如 MAIN_SEQ、ChargeCapacity、RelinkAllow）。
    数据来源: /api/<model>/monitor_params；变量不存在时抛 QC2015PError。
    """
    data = _get(f"/api/{str(model).lower()}/monitor_params")
    for p in data.get("data", []):
        if p.get("name") == name:
            return p.get("value")
    raise QC2015PError(f"monitor参数未找到: {model}.{name}")

# ============================================================
# 服务器配置
# ============================================================
_host = "localhost"
_port = 9527
_timeout = 5  # HTTP请求超时(秒)

# ============================================================
# 高速TCP持久连接（端口9528，绕过HTTP线程创建开销）
# ============================================================
_fast_sock = None

def _fast_connect():
    """建立到9528的持久TCP连接"""
    global _fast_sock
    if _fast_sock is not None:
        try:
            _fast_sock.sendall(b"")  # 检测连接是否存活
            return _fast_sock
        except (OSError, BrokenPipeError):
            _fast_sock = None
    _fast_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    _fast_sock.settimeout(_timeout)
    _fast_sock.connect((_host, 9528))
    return _fast_sock

def _fast_send(cmd: str) -> str:
    """通过持久TCP连接发送命令，返回响应行"""
    sock = _fast_connect()
    sock.sendall((cmd + "\n").encode("utf-8"))
    # 读取响应（直到\n）
    resp = b""
    while True:
        chunk = sock.recv(4096)
        if not chunk:
            _fast_sock = None
            raise ConnectionError("Fast TCP连接断开")
        resp += chunk
        if b"\n" in resp:
            break
    return resp.decode("utf-8").strip()

def _fast_set(model: str, name: str, value: str) -> bool:
    """高速设置参数"""
    resp = _fast_send(f"SET {model} {name} {value}")
    return resp == "OK"

def _fast_get(model: str, name: str) -> str:
    """高速读取参数"""
    resp = _fast_send(f"GET {model} {name}")
    if resp.startswith("VALUE "):
        return resp[6:]
    return ""

def _fast_dbc(model: str, msg_id: int) -> Optional[Dict]:
    """高速读取单条DBC报文"""
    resp = _fast_send(f"DBC {model} {msg_id}")
    try:
        return json.loads(resp)
    except json.JSONDecodeError:
        return None


def configure(host: str = "localhost", port: int = 9527):
    """配置服务器地址"""
    global _host, _port
    _host = host
    _port = port


# ============================================================
# 内部HTTP工具
# ============================================================

def _url(path: str, params: Optional[Dict] = None) -> str:
    url = f"http://{_host}:{_port}{path}"
    if params:
        url += "?" + urllib.parse.urlencode(params)
    return url


def _get(path: str, params: Optional[Dict] = None) -> Any:
    try:
        req = urllib.request.Request(_url(path, params))
        with urllib.request.urlopen(req, timeout=_timeout) as resp:
            return json.loads(resp.read().decode("utf-8"))
    except urllib.error.URLError:
        raise ConnectionError(f"无法连接 HIL 服务器 ({_host}:{_port})，请确认程序已启动")
    except json.JSONDecodeError:
        raise ValueError(f"服务器返回了无效的JSON: {path}")


class QC2015PError(Exception):
    """HIL平台错误"""
    pass


# ============================================================
# 参数解析：名称 → (模型, 参数名)
# ============================================================

def _parse_param_name(name: str) -> tuple:
    """
    解析参数名，返回 (model, real_name)

    "SECC_ChargeSta"  → ("SECC", "ChargeSta")
    "EVCC_CVList"     → ("EVCC", "CVList")
    "ChargeSta"       → (None, "ChargeSta")  # 无前缀，无法确定模型
    """
    for prefix in ("SECC_", "EVCC_"):
        if name.startswith(prefix):
            return prefix.rstrip("_"), name[len(prefix):]
    return None, name


def _model_base(model: str) -> str:
    """模型名 → API路径前缀"""
    return model.lower()  # "SECC" → "secc"


# ============================================================
# 核心API: set_params / get_params
# ============================================================

def set_params(name: str, value: Union[str, int, float, bool, list]) -> bool:
    """
    设置参数值（通过脚本队列，限速执行）。

    模型参数:
        set_params("SECC_ChargeSta", 1)
        set_params("EVCC_CVList", [1, 2, 3, 4])
        set_params("SECC_Enable", True)

    Args:
        name: 参数名 (SECC_xxx 或 EVCC_xxx)
        value: 值 (bool/数字/字符串/数组)

    Returns:
        True=成功

    Raises:
        QC2015PError: 参数名无效或值不合法
        ConnectionError: 服务器连接失败
    """
    model, real_name = _parse_param_name(name)
    if model is None:
        raise QC2015PError(f"参数名需要 'SECC_' 或 'EVCC_' 前缀: {name}")

    # 格式化值
    if isinstance(value, bool):
        value_str = "true" if value else "false"
    elif isinstance(value, list):
        value_str = json.dumps(value)
    elif isinstance(value, (int, float)):
        value_str = str(value)
    elif isinstance(value, str):
        value_str = value
    else:
        raise QC2015PError(f"不支持的值类型: {type(value).__name__}")

    # 会话内记录改动（退出时自动恢复原值）
    _record_set(model, real_name)

    # 直接写入（服务端限速1ms/次）
    result = _get(f"/api/{model.lower()}/params/set", {
        "name": real_name, "value": value_str
    })
    if not result.get("success"):
        raise QC2015PError(f"设置失败: {result.get('error', 'unknown')}")
    return True


def get_params(name: str, msg_id: Optional[int] = None) -> Any:
    """
    获取参数值（通过脚本队列，限速执行）。

    模型参数:
        val = get_params("SECC_ChargeSta")
        arr = get_params("EVCC_CVList")

    DBC信号:
        val = get_params("PGI05_K1", 0x1836F456)

    DBC报文原始数据:
        data = get_params("Data", 0x1836F456)
        ts   = get_params("Timestamp", 0x1836F456)

    Args:
        name: 参数名或DBC信号名 ("SECC_xxx" / "EVCC_xxx" / 信号名)
        msg_id: DBC报文ID (int)，有此参数时从DBC报文查找

    Returns:
        参数值 (已解析为Python类型)

    Raises:
        QC2015PError: 参数名无效或未找到
        ConnectionError: 服务器连接失败
    """
    # ── DBC报文: Data / Timestamp ──
    if msg_id is not None and name in ("Data", "Timestamp", "data", "timestamp"):
        result = _get_dbc_raw(msg_id)
        if result is None:
            raise QC2015PError(f"DBC报文未找到: 0x{msg_id:X}")
        if name.lower() == "data":
            return result.get("data", [])
        else:
            return result.get("lastUpdate", 0)

    # ── DBC信号 ──
    if msg_id is not None:
        result = _get_dbc_signal(name, msg_id)
        if result is None:
            raise QC2015PError(f"DBC信号未找到: {name} @ 0x{msg_id:X}")
        return result

    # ── 模型参数 ──
    model, real_name = _parse_param_name(name)
    if model is None:
        raise QC2015PError(f"参数名需要 'SECC_' 或 'EVCC_' 前缀 (DBC信号请传 msg_id 参数): {name}")

    # 推入脚本队列
    result = _get("/api/script/push", {
        "cmd": "get", "model": model, "name": real_name
    })
    if not result.get("success"):
        raise QC2015PError(f"命令入队失败: {result.get('error', 'unknown')}")

    # 等待执行结果
    result = _wait_result()
    if result is None:
        raise QC2015PError("等待超时，命令未被执行")
    if not result.get("success"):
        raise QC2015PError(f"读取失败: {result.get('error', 'unknown')}")
    return _parse_value(result.get("value", ""))


# ============================================================
# DBC辅助
# ============================================================

def _get_dbc_signal(signal_name: str, msg_id: int) -> Any:
    """从DBC报文中解码单个信号"""
    data = _get("/api/secc/dbc_params")
    msgs = data.get("data", [])
    for msg in msgs:
        if msg.get("id") == msg_id:
            signals = msg.get("signals", {})
            for k, v in signals.items():
                if k.strip() == signal_name or k.strip().lower() == signal_name.lower():
                    return _parse_value(v)
            return None
    return None


def _get_dbc_raw(msg_id: int) -> Optional[Dict]:
    """获取DBC报文原始数据（高速TCP单条查询）"""
    try:
        result = _fast_dbc("SECC", msg_id)
        if result and result.get("id"):
            return result
    except (ConnectionError, OSError):
        pass
    # 回退到HTTP
    result = _get("/api/dbc_msg", {"id": str(msg_id), "model": "SECC"})
    if result and result.get("id"):
        return result
    return None


def _wait_result(timeout: float = 5.0) -> Optional[Dict]:
    """等待脚本命令执行结果（1ms轮询，降低延迟）"""
    start = time.time()
    while time.time() - start < timeout:
        result = _get("/api/script/result")
        if result.get("success") is not None:
            return result
        time.sleep(0.001)
    return None


def _parse_value(value_str: str) -> Any:
    """解析值字符串为Python类型"""
    if not value_str:
        return None
    if isinstance(value_str, (int, float, bool)):
        return value_str
    if isinstance(value_str, list):
        return value_str
    s = str(value_str)
    if s.lower() in ("true", "false"):
        return s.lower() == "true"
    if s.startswith("["):
        try:
            return json.loads(s)
        except json.JSONDecodeError:
            return s
    try:
        if "." in s:
            return float(s)
        return int(s)
    except ValueError:
        return s


# ============================================================
# 设备操作 (也是setter/getter风格)
# ============================================================

def _env_int(name: str, default: int) -> int:
    """读取整数环境变量（支持十进制/0x 十六进制）；未设置或非法时返回默认值。"""
    value = os.environ.get(name)
    if value is None or value.strip() == "":
        return default
    try:
        return int(value.strip(), 0)
    except ValueError:
        return default


def connect(baud: int = 250000, device: str = "zlg", dev_type: int = 0,
            dev_idx: int = 0, ch: Optional[int] = None, term: bool = True,
            secc_phys: Optional[int] = None, evcc_phys: Optional[int] = None) -> bool:
    """
    连接CAN设备（一次请求，按通道语义打开）。

    connect()                              # ZLG USBCAN2, 250k（ch=all 双通道）
    connect(baud=500000)                   # 500k
    connect(device="zlgcanfd")             # ZLG USBCANFD-200U (zlgcan.dll)
    connect(ch=0)                          # 只开通道0（SECC侧独立工作场景）
    connect(term=False)                    # 不启用终端电阻（由后端按设备能力处理）

    请求: GET /api/can/connect?device=&devIdx=&baud=&term=1|0&ch=all|0|1
    （dev_type>0 时额外携带 devType= 参数）

    可重复调用：已连接再调用仍返回成功；API 返回 success=false 时返回
    False 而不抛异常（脚本自行检查返回值）。

    Args:
        baud: 波特率
        device: 厂商驱动名（"zlg" / "zlgcanfd" / "virtual"）
        dev_type: 设备类型（0=按驱动默认：zlg→4, zlgcanfd→41）
        dev_idx: 设备索引
        ch: 通道；None=ch=all（多通道设备同时开 0→SECC、1→EVCC，
            单通道设备只开它能开的）；0/1=只开指定通道
        term: 是否启用终端电阻（true/false → term=1|0）
        secc_phys / evcc_phys: 模型↔设备物理通道绑定（0/1）。
            None=继承后端当前配置（面板改过绑定则跟随面板；默认0/1）；
            显式传入则强制该侧绑定（如连线固定为 SECC=通道0 时传 secc_phys=0）

    Returns:
        True=至少打开一个通道（单通道设备开一个即成功）

    跨硬件复用（可选环境变量，未设置时行为与旧版完全一致）:
        QC2015P_DEVICE      覆盖 device（zlg/zlgcanfd/pcan/vector/kvaser/slcan/
                            toomoss/tosun/chuangxin/esd/ni/etas/intrepid/ebel/virtual）
        QC2015P_BAUD        覆盖 baud
        QC2015P_DEVTYPE     覆盖 dev_type
        QC2015P_DEVIDX      覆盖 dev_idx
        QC2015P_TERM        覆盖 term（0/1）
        QC2015P_CH          覆盖 ch（all/0/1）
        QC2015P_SECC_PHYS / QC2015P_EVCC_PHYS  覆盖模型↔物理通道绑定
        示例: QC2015P_DEVICE=chuangxin QC2015P_DEVTYPE=4 python TC_xxx.py
    """
    # ---------- 跨硬件复用：可选环境变量覆盖 ----------
    device = os.environ.get("QC2015P_DEVICE") or device
    baud = _env_int("QC2015P_BAUD", baud)
    dev_type = _env_int("QC2015P_DEVTYPE", dev_type)
    dev_idx = _env_int("QC2015P_DEVIDX", dev_idx)
    term = bool(_env_int("QC2015P_TERM", 1 if term else 0))
    env_ch = os.environ.get("QC2015P_CH")
    if env_ch is not None and env_ch.strip() != "":
        env_ch = env_ch.strip().lower()
        try:
            ch = None if env_ch == "all" else int(env_ch)
        except ValueError:
            pass
    env_secc = os.environ.get("QC2015P_SECC_PHYS")
    if env_secc is not None and env_secc.strip() != "":
        secc_phys = _env_int("QC2015P_SECC_PHYS", 0)
    env_evcc = os.environ.get("QC2015P_EVCC_PHYS")
    if env_evcc is not None and env_evcc.strip() != "":
        evcc_phys = _env_int("QC2015P_EVCC_PHYS", 1)

    params = {
        "baud": baud,
        "device": device,
        "devIdx": dev_idx,
        "term": 1 if term else 0,
        "ch": "all" if ch is None else str(int(ch)),
    }
    if secc_phys is not None:
        params["seccPhys"] = int(secc_phys)
    if evcc_phys is not None:
        params["evccPhys"] = int(evcc_phys)
    if dev_type > 0:
        params["devType"] = dev_type
    result = _get("/api/can/connect", params)
    return result.get("success", False)


def disconnect() -> bool:
    """
    断开CAN连接（双通道同时断开）。
    """
    r0 = _get("/api/can/disconnect", {"ch": 0})
    r1 = _get("/api/can/disconnect", {"ch": 1})
    # 关闭高速TCP连接
    global _fast_sock
    if _fast_sock:
        try:
            _fast_sock.sendall(b"QUIT\n")
            _fast_sock.close()
        except (OSError, BrokenPipeError):
            pass
        _fast_sock = None
    return r0.get("success", False) and r1.get("success", False)


def get_status() -> Dict:
    """
    获取系统状态。

    Returns:
        {"secc": {"running": bool, "stepCount": int, ...}, ...}
    """
    return _get("/api/status")


def is_running(model: str = "SECC") -> bool:
    """检查模型是否在运行"""
    st = get_status()
    return st.get(model.lower(), {}).get("running", False)


def wait_ready(models=("SECC", "EVCC"), timeout: float = 10.0, interval: float = 0.05,
               min_steps: int = 50) -> bool:
    """等待模型真正进入运行状态（connect() 之后调用，消除冷启动竞态）。

    除 running=true 外，还要求已步进 min_steps 步（默认 50 步≈50ms），
    避免线程刚创建、还没开始 1ms 步进就往下执行。

    Returns:
        True=指定模型全部就绪；False=超时
    """
    end = time.time() + timeout
    while time.time() < end:
        try:
            st = get_status()
            ready = True
            for m in models:
                d = st.get(m.lower(), {})
                if not d.get("running") or int(d.get("stepCount", 0)) < min_steps:
                    ready = False
                    break
            if ready:
                return True
        except Exception:
            pass
        time.sleep(interval)
    return False


def reset_all(timeout: float = 15.0) -> bool:
    """全量软复位：停录制 → 停模型/断CAN → 重置模型状态/IO → 参数恢复启动默认值
    → 清空 DBC 报文缓存/复用组历史（默认 0）/报文追踪缓冲。

    与 restart_hil() 的区别：只复位运行时状态，不重启进程。速度更快（毫秒级），
    且没有进程冷启动带来的“connect 时模型尚未就绪”竞态；连续复位也不会把
    CAN/模型线程留在卡死状态（restart_hil 连续调用可能触发 connect 无响应）。

    复位后 CAN 不会自动重连，需要重新 connect()。

    Returns:
        True=复位成功（SECC/EVCC 均已停止）；False=后端不可达或复位失败
    """
    try:
        r = _get("/api/system/reset")
        return bool(r.get("success"))
    except Exception:
        return False


def _restart_hil_delayed() -> bool:
    """面板内执行时的重启：由外部进程延迟约3秒后发起优雅重启。

    /api/py/exec 子进程若立刻杀掉 HIL，当前 HTTP 响应会连接重置（实测
    脚本结束瞬间 RST），面板显示“执行失败”。改为 ping 延迟等响应返回后，
    再由独立进程调 /api/app/restart（该接口自带“回包→退出→拉起新实例”）。
    """
    cmd = ("ping -n 4 127.0.0.1 >nul && curl -s --max-time 5 "
           "http://" + _host + ":" + str(_port) + "/api/app/restart >nul")
    try:
        flags = getattr(subprocess, "DETACHED_PROCESS", 0x00000008) | 0x08000000  # DETACHED|NO_WINDOW
        subprocess.Popen(["cmd", "/c", cmd], creationflags=flags, close_fds=True,
                         stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL,
                         stderr=subprocess.DEVNULL)
        return True
    except Exception:
        return False


def restart_hil(timeout: float = 20.0) -> bool:
    """重启 QC2015P_HIL.exe（仅本机）。

    会先停止 SECC/EVCC 模型与录制、断开并关闭 CAN 设备，再延迟约 3 秒重启，
    因此不会像强杀那样把 ZLG 驱动通道留在占用状态（VCI_InitCAN failed）。

    Returns:
        True=新实例已就绪；False=超时。
    注意：重启后 CAN 不会自动重连，需要重新 connect()。
    """
    if os.environ.get("QC2015P_UNDER_PANEL"):
        # 面板(/api/py/exec)内执行：延迟重启，保护当前 HTTP 响应不被掐断
        return _restart_hil_delayed()

    global _fast_sock
    if _fast_sock is not None:
        try:
            _fast_sock.close()
        except Exception:
            pass
        _fast_sock = None
    try:
        _get("/api/app/restart")
    except Exception:
        pass   # 旧进程退出时连接可能被重置，属正常现象
    # 旧进程会先回包、约100ms后才退出；先等它释放端口，
    # 否则第一次 /api/status 会打到旧进程，误判为“新实例已就绪”。
    time.sleep(0.5)
    start = time.time()
    while time.time() - start < timeout:
        try:
            _get("/api/status")
            return True
        except Exception:
            time.sleep(0.3)
    return False


def logging(state: int, ch: int = 0, fmt: int = 0) -> bool:
    """
    录制控制。

    logging(1)           # 开始录制 SECC(BLF格式)
    logging(0)           # 停止录制 SECC
    logging(1, ch=1)     # 开始录制 EVCC
    logging(1, fmt=1)    # 开始录制 SECC(ASC格式)
    logging(1, ch=1, fmt=1)  # 开始录制 EVCC(ASC格式)

    若已在录制中调用 logging(1)，会先停止再重新开启新录制。

    Args:
        state: 0=停止, 1=开启
        ch: 0=SECC(默认), 1=EVCC
        fmt: 0=BLF(默认), 1=ASC

    Returns:
        True=正在录制
    """
    model = "EVCC" if ch == 1 else "SECC"
    format_str = "asc" if fmt == 1 else "blf"
    api = f"/api/{model.lower()}/logging"

    # 查询当前录制状态
    status = _get("/api/status")
    is_active = status.get("logging", {}).get(model.lower(), False)

    if state == 1:
        # 开启：若已在录制，先停止再重新开始
        if is_active:
            _get(api, {"format": format_str})  # 停止
        result = _get(api, {"format": format_str})  # 开始
        return result.get("logging", False)
    else:
        # 停止：若未在录制，直接返回
        if not is_active:
            return False
        result = _get(api, {"format": format_str})
        return result.get("logging", False)


def rename_log(model: str, new_name: str) -> str:
    """
    重命名最近一次录制文件（需先停止录制）。

    rename_log("SECC", "充电测试1")      # → "充电测试1.blf"
    rename_log("SECC", "充电测试1")      # 同名冲突 → "充电测试1_20260829_143022.blf"

    Args:
        model: "SECC" 或 "EVCC"
        new_name: 新文件名（不含扩展名，支持中文）

    Returns:
        实际文件名（含扩展名）

    Raises:
        QC2015PError: 重命名失败（录制未停止或文件不存在）
    """
    result = _get("/api/logging/rename", {"model": model, "name": new_name})
    if not result.get("success"):
        raise QC2015PError(f"重命名失败: {result.get('error', 'unknown')}")
    return result.get("name", "")


def get_trace(model: str = "SECC") -> List[Dict]:
    """
    获取报文追踪。

    Returns:
        [{"direction": "TX", "id": int, "data": [int], ...}, ...]
    """
    result = _get(f"/api/{model.lower()}/trace")
    return result.get("messages", [])


# ============================================================
# 简洁封装函数
# ============================================================

def _format_value(value: Union[str, int, float, bool, list]) -> str:
    """将Python值格式化为API传输字符串"""
    if isinstance(value, bool):
        return "true" if value else "false"
    if isinstance(value, list):
        return json.dumps(value)
    if isinstance(value, (int, float)):
        return str(value)
    if isinstance(value, str):
        return value
    raise QC2015PError(f"不支持的值类型: {type(value).__name__}")

def SECC_ValueSet(name: str, value: Union[str, int, float, bool, list]) -> bool:
    """设置 SECC 模型参数（高速TCP直写，≈0.3ms）。
       SECC_ValueSet("ChargeSta", 1)  →  直接写入 SECC 模型的 ChargeSta 参数
    """
    value_str = _format_value(value)
    _record_set("SECC", name)  # 会话内记录原值（写入前）
    try:
        return _fast_set("SECC", name, value_str)
    except (ConnectionError, OSError):
        # 回退到HTTP
        result = _get("/api/secc/params/set", {"name": name, "value": value_str})
        return result.get("success", False)


def SECC_ValueGet(name: str) -> Any:
    """读取 SECC 模型参数（高速TCP直读）。
       SECC_ValueGet("ChargeSta")  →  直接读取 SECC 模型的 ChargeSta 参数
    """
    try:
        val = _fast_get("SECC", name)
        return _parse_value(val)
    except (ConnectionError, OSError):
        result = _get("/api/secc/params")
        for p in result.get("data", []):
            if p.get("name") == name:
                return _parse_value(p.get("value", ""))
        raise QC2015PError(f"参数未找到: {name}")


def EVCC_ValueSet(name: str, value: Union[str, int, float, bool, list]) -> bool:
    """设置 EVCC 模型参数（高速TCP直写，≈0.3ms）。
       EVCC_ValueSet("ChargeSta", 1)  →  直接写入 EVCC 模型的 ChargeSta 参数
    """
    value_str = _format_value(value)
    _record_set("EVCC", name)  # 会话内记录原值（写入前）
    try:
        return _fast_set("EVCC", name, value_str)
    except (ConnectionError, OSError):
        result = _get("/api/evcc/params/set", {"name": name, "value": value_str})
        return result.get("success", False)


def EVCC_ValueGet(name: str) -> Any:
    """读取 EVCC 模型参数（高速TCP直读）。
       EVCC_ValueGet("ChargeSta")  →  直接读取 EVCC 模型的 ChargeSta 参数
    """
    try:
        val = _fast_get("EVCC", name)
        return _parse_value(val)
    except (ConnectionError, OSError):
        result = _get("/api/evcc/params")
        for p in result.get("data", []):
            if p.get("name") == name:
                return _parse_value(p.get("value", ""))
        raise QC2015PError(f"参数未找到: {name}")


def MsgGet(msg_id, what=None) -> Any:
    """读取 DBC 报文信息（两侧内容相同，统一从 SECC 通道查询）。

    MsgGet(0x1836F456)                  → 完整报文 {data, timestamp, signals, name, dlc}
    MsgGet(0x1836F456, "Data")          → 原始字节数组 [0x01, 0x02, ...]
    MsgGet(0x1836F456, "timestamp") → 最近更新时间戳(us)
    MsgGet(0x1836F456, "PGI05_K1")     → 单个信号值
    """
    if not isinstance(msg_id, int):
        raise QC2015PError(f"报文ID必须是整数: {msg_id!r}")

    result = _get_dbc_raw(msg_id)
    if result is None:
        raise QC2015PError(f"DBC报文未找到: 0x{msg_id:X}")

    # 只传ID → 返回完整信息（信号名去空格，值转数值）
    if what is None:
        raw_signals = result.get("signals", {})
        signals = {k.strip(): _parse_value(v) for k, v in raw_signals.items()}
        return {
            "data": result.get("data", []),
            "timestamp": result.get("lastUpdate", 0),
            "signals": signals,
            "name": result.get("name", ""),
            "dlc": result.get("dlc", 0),
        }

    if not isinstance(what, str):
        raise QC2015PError(f"查询类型必须是字符串: {what!r}")

    # MsgGet(id, "Data") — 原始字节数组
    if what == "Data":
        return result.get("data", [])

    # MsgGet(id, "timestamp") — 更新时间戳
    if what == "timestamp":
        return result.get("lastUpdate", 0)

    # 其余当作信号名查询（信号名可能有尾部空格，需strip匹配）
    signals = result.get("signals", {})
    for k, v in signals.items():
        if k.strip() == what or k.strip().lower() == what.lower():
            return _parse_value(v)
    raise QC2015PError(
        f"未找到 '{what}' @ 0x{msg_id:X}（不是 Data/lastTimestamp，也不在信号列表中）"
    )


# ============================================================
# 便捷方法
# ============================================================

def wait_params(name: str, expected: Any, timeout: float = 5.0) -> bool:
    """
    等待参数变为期望值。

    wait_params("SECC_ChargeSta", 1, timeout=5)
    """
    start = time.time()
    while time.time() - start < timeout:
        try:
            if get_params(name) == expected:
                return True
        except QC2015PError:
            pass
        time.sleep(0.05)
    return False


def poll_params(name: str, count: int = 10, interval: float = 0.1) -> list:
    """
    轮询读取参数值。

    values = poll_params("SECC_ChargeSta", count=10, interval=0.1)
    """
    values = []
    for _ in range(count):
        try:
            values.append(get_params(name))
        except QC2015PError:
            values.append(None)
        time.sleep(interval)
    return values


# ============================================================
# 断言辅助（专业 HIL 自动化测试机制）
# 失败统一抛 QcAssertError，顶层捕获后经 finish() 转成 FAIL 结论 + 退出码
# ============================================================

EXIT_PASS = 0   # CI 退出码约定: PASS
EXIT_FAIL = 1   # CI 退出码约定: FAIL


class QcAssertError(Exception):
    """断言失败（携带失败消息），由 finish()/run_case() 统一转成 FAIL 结论"""

    def __init__(self, msg: str = ""):
        self.msg = str(msg)
        super().__init__(self.msg)

    def __str__(self) -> str:
        return self.msg


def assert_true(cond: Any, msg: str = "") -> None:
    """断言条件为真，否则抛 QcAssertError。

    assert_true(res == 2, "版本协商序列未完成")
    """
    if not cond:
        raise QcAssertError(msg or f"条件不满足: {cond!r}")


def assert_eq(a: Any, b: Any, msg: str = "") -> None:
    """断言 a == b，否则抛 QcAssertError（携带双方取值）。

    assert_eq(EVCC_ValueGet("ProtocolVersion"), 2, "协议版本号")
    """
    if a != b:
        head = msg or "值不相等"
        raise QcAssertError(f"{head}: 实际={a!r}, 期望={b!r}")


def assert_changed(getter: Callable[[], Any], before: Any, timeout: float = 5.0,
                   interval: float = 0.05, msg: str = "") -> Any:
    """轮询等待 getter() 的返回值偏离 before（值发生变化），带超时。

    变化发生 → 返回新值（可继续二次断言）；超时 → 抛 QcAssertError。
    轮询期间 getter 抛可恢复异常（如参数瞬时不可读）视为"尚未变化"继续等。

    new = assert_changed(lambda: MsgGet(0xC3956F4, "timestamp"), ts0, timeout=3)
    assert_changed(lambda: SECC_ValueGet("ChargeSta"), 0, timeout=2)
    """
    end = time.time() + timeout
    while True:
        try:
            cur = getter()
        except (QC2015PError, ConnectionError, OSError):
            cur = _QC_UNREADABLE  # 读不到 → 视为尚未变化
        if cur is not _QC_UNREADABLE and cur != before:
            return cur
        if time.time() >= end:
            raise QcAssertError(
                msg or f"值未在 {timeout}s 内变化 (before={before!r})"
            )
        time.sleep(interval)


_QC_UNREADABLE = object()  # 内部哨兵：轮询期间 getter 读取失败


def assert_in(container: Any, item: Any, msg: str = "") -> None:
    """断言 item 在容器内（列表/字符串/字典/集合）。

    assert_in([2,255,255], MsgGet(0xC3756F4, "Data")[0:3])   # 数据段包含
    assert_in("PASS", line)                                   # 字符串包含
    """
    try:
        ok = item in container
    except TypeError:
        ok = False
    if not ok:
        raise QcAssertError(msg or f"assert_in 失败: {item!r} not in {container!r}")


def assert_near(a: Any, b: Any, tol: float = 1e-6, msg: str = "") -> None:
    """断言 |a-b| <= tol（数值容差比较，适合带缩放/浮点的信号值）。"""
    try:
        ok = abs(float(a) - float(b)) <= tol
    except (TypeError, ValueError):
        ok = False
    if not ok:
        raise QcAssertError(msg or f"assert_near 失败: |{a!r} - {b!r}| > {tol}")


def wait_until(cond: Callable[[], bool], timeout: float = 5.0, interval: float = 0.01,
               msg: str = "") -> None:
    """轮询等待任意条件成立（cond 为无参可调用），超时抛 QcAssertError。

    与 assert_changed 的分工：
      wait_until   —— 等"条件为真"（如 lambda: MsgGet(...) == 2）
      assert_changed —— 等"值发生变化"
    与 qc_wait_until 面板积木语义一致（超时=断言失败）。

    wait_until(lambda: qc_monitor("SECC", "MAIN_SEQ") >= 200, timeout=3)
    """
    if not callable(cond):
        raise QcAssertError("wait_until: cond 必须是可调用对象（如 lambda: ...）")
    end = time.time() + timeout
    while True:
        try:
            if cond():
                return
        except (QC2015PError, ConnectionError, OSError):
            pass   # 读不到 → 继续等
        if time.time() >= end:
            raise QcAssertError(msg or f"wait_until 超时({timeout}s): 条件未成立")
        time.sleep(interval)


def retry(fn: Callable[[], Any], attempts: int = 3, delay: float = 0.2,
         exceptions: tuple = (QC2015PError, ConnectionError, OSError)) -> Any:
    """重试执行 fn()，返回其结果；attempts 次全失败则抛最后一次异常。

    常用于建立连接/开录制等可能瞬时失败的操作：
        sock = retry(lambda: connect(...), attempts=3)
    """
    last: Exception = RuntimeError("retry: attempts 必须 >= 1")
    for i in range(max(1, attempts)):
        try:
            return fn()
        except exceptions as e:
            last = e
            if i < attempts - 1:
                time.sleep(delay)
    raise last


def finish(result: Any, reason: str = "") -> int:
    """输出与测试面板一致的结论行，并返回进程退出码。

    打印格式: 结论: PASS/FAIL - 原因   （与面板 qc_result 积木一致）
    返回:    0=PASS, 1=FAIL   →  if __name__ 下直接 sys.exit(finish(...))

    return finish(True, "完成")
    return finish(False, str(e))
    """
    ok = bool(result)
    print(f"结论: {'PASS' if ok else 'FAIL'} - {reason}", flush=True)
    return EXIT_PASS if ok else EXIT_FAIL


def run_case(fn: Callable[[], Any]) -> int:
    """顶层统一入口：执行测试函数并把各类失败统一转成 FAIL 结论 + 退出码。

    - QcAssertError / QC2015PError / 其他异常 → finish(False, 消息)
    - fn 返回 (bool, reason) 元组             → 按该结果输出
    - fn 返回 True / None                     → PASS "完成"
    - fn 返回 False / 字符串 reason           → FAIL/PASS 对应处理

    sys.exit(run_case(do_test))
    """
    try:
        ret = fn()
    except QcAssertError as e:
        return finish(False, e.msg)
    except QC2015PError as e:
        return finish(False, f"平台错误: {e}")
    except ConnectionError as e:
        return finish(False, f"连接失败: {e}")
    except Exception as e:  # noqa: BLE001 —— 顶层兜底，任何异常都算 FAIL
        return finish(False, f"未预期异常: {type(e).__name__}: {e}")
    if isinstance(ret, tuple) and len(ret) == 2:
        return finish(ret[0], ret[1])
    if isinstance(ret, str):
        return finish(True, ret)
    if ret is None:
        return finish(True, "完成")
    return finish(bool(ret), "完成")


# ============================================================
# 参数快照 / 恢复（autocleanup 核心）
# 快照一次全量拉取（约27KB/模型），之后只按 diff 恢复，避免频繁整包传输
# ============================================================

def _raw_set(model: str, name: str, value: Any) -> None:
    """按模型直接写参数（不做 SECC_/EVCC_ 前缀解析，供恢复逻辑使用）。"""
    if value is None:
        return
    value_str = _format_value(value)
    result = _get(f"/api/{_model_base(model)}/params/set",
                  {"name": name, "value": value_str})
    if not result.get("success"):
        raise QC2015PError(f"恢复参数失败: {model}.{name}: "
                           f"{result.get('error', 'unknown')}")


def snapshot_params(model: str) -> Dict[str, Any]:
    """抓取模型当前全量参数快照（一次 HTTP 拉取）。

    snap = snapshot_params("SECC")     # {"ChargeSta": 1, "CVList": [...], ...}

    Args:
        model: "SECC" / "EVCC"（大小写不敏感）

    Returns:
        {参数名: 当前值}
    """
    result = _get(f"/api/{_model_base(model)}/params")
    snap: Dict[str, Any] = {}
    for p in result.get("data", []):
        name = p.get("name")
        if name is not None:
            snap[name] = p.get("value")
    return snap


def restore_params(model: str, snap: Dict[str, Any]) -> List[str]:
    """把模型参数恢复到快照值（只写入有差异的参数）。

    恢复前重新拉取一次当前值做 diff —— 与快照相同的参数不会被重写，
    因此正常情况下写入次数 = 实际被改动的参数个数。

    Args:
        model: "SECC" / "EVCC"
        snap: snapshot_params() 的返回值

    Returns:
        实际被恢复（写入）的参数名列表
    """
    current = snapshot_params(model)
    restored: List[str] = []
    for name, want in snap.items():
        if name not in current:
            continue  # 快照后参数被移除，跳过
        if _val_equal(current.get(name), want):
            continue  # 无差异，不写
        _raw_set(model, name, want)
        restored.append(name)
    return restored


def _val_equal(a: Any, b: Any) -> bool:
    """参数值等价比较（容忍 True==1、1==1.0 这类类型差异，但 True!=2）。"""
    if a == b:
        return True
    # bool 与数字混用：按 0/1 语义比较（True 等价 1，不等价其他数字）
    if isinstance(a, bool) and isinstance(b, (int, float)) and not isinstance(b, bool):
        return b in (0, 1) and bool(a) == bool(b)
    if isinstance(b, bool) and isinstance(a, (int, float)) and not isinstance(a, bool):
        return a in (0, 1) and bool(a) == bool(b)
    return False


# ============================================================
# QcSession：测试会话上下文管理器（连接 → 录制 → 快照 → 逆序清理 → 收尾）
# ============================================================

# 当前活动会话（供 set 路径记录改动；无会话时为 None，不影响既有脚本）
_active_session: Optional["QcSession"] = None


def _record_set(model: str, name: str) -> None:
    """set 路径钩子：若处于 QcSession 内，记录该参数的原值（仅首次）。"""
    sess = _active_session
    if sess is not None:
        sess._record_set(model, name)


class QcSession:
    """HIL 测试会话上下文管理器（模仿 unittest 的生命周期管理）。

    with QcSession(device="zlg", baud=250000, restart=True) as s:
        s.addCleanup(fn)                  # 注册逆序清理（后进先出）
        ...                               # setup → act → assert
    # 退出（无论成败）自动执行:
    #   用户 addCleanup(逆序) → 停录制 → rename → 恢复被改参数
    #   → disconnect → (可选) restart_hil

    Args:
        device/baud/dev_type/dev_idx: 透传给 connect()
        restart: 退出时是否 restart_hil（默认 True）
        record:  进入时是否开录制（默认 True）
        record_ch: 录制通道 0=SECC / 1=EVCC
        log_name: rename_log 的目标文件名；None=取当前脚本文件名，
                  仍为 None 且取不到脚本名时跳过 rename
        restore: 退出时是否自动恢复会话内被改动的参数（默认 True）
        models:  参与快照/恢复的模型（默认两侧都抓，进入时各拉一次）
        settle_ms: 连接后的稳定等待（毫秒，默认 500，与面板导出脚本一致）
        wait_running: 进入时是否等待 SECC/EVCC 模型运行（默认 False）
    """

    def __init__(self, device: str = "zlg", baud: int = 250000,
                 dev_type: int = 0, dev_idx: int = 0, restart: bool = True,
                 record: bool = True, record_ch: int = 0,
                 log_name: Optional[str] = None, restore: bool = True,
                 models: tuple = ("SECC", "EVCC"), settle_ms: float = 500,
                 wait_running: bool = False, run_timeout: float = 10.0):
        self.device = device
        self.baud = baud
        self.dev_type = dev_type
        self.dev_idx = dev_idx
        self.restart = restart
        self.record = record
        self.record_ch = record_ch
        self.log_name = log_name
        self.restore = restore
        self.models = tuple(str(m).upper() for m in models)
        self.settle_ms = settle_ms
        self.wait_running = wait_running
        self.run_timeout = run_timeout

        self._cleanups: List[Callable[[], Any]] = []
        self._snaps: Dict[str, Dict[str, Any]] = {}      # model → 参数快照
        self._changed: Dict[tuple, Any] = {}             # (model, name) → 原值
        self._connected = False
        self._recording = False
        self._entered = False

    # ---------- unittest 风格注册清理 ----------

    def addCleanup(self, fn: Callable[[], Any], *args: Any, **kwargs: Any) -> None:
        """注册逆序清理函数（与 unittest.TestCase.addCleanup 语义一致）。
        会话退出时后进先出执行；单个清理失败不影响其余清理执行。
        """
        if args or kwargs:
            self._cleanups.append(lambda: fn(*args, **kwargs))
        else:
            self._cleanups.append(fn)

    # ---------- set 路径钩子 ----------

    def _record_set(self, model: str, name: str) -> None:
        """记录参数原值（每参数仅记录首次改动前的值）。"""
        if not self.restore:
            return
        model = str(model).upper()
        key = (model, name)
        if key in self._changed:
            return
        snap = self._snaps.get(model, {})
        if name in snap and snap[name] is not None:
            self._changed[key] = snap[name]
            return
        # 快照缺失（restore 未开快照或参数不在快照内）→ 直读当前值兜底
        try:
            cur = _parse_value(_fast_get(model, name))
            if cur is not None:
                self._changed[key] = cur
        except (ConnectionError, OSError, QC2015PError):
            pass  # 读不到原值则放弃恢复该参数

    # ---------- 上下文协议 ----------

    def __enter__(self) -> "QcSession":
        global _active_session
        if self._entered:
            raise QC2015PError("QcSession 不可重入")
        self._entered = True

        # 1) 连接 CAN（失败则清理半开状态并抛出）
        try:
            ok = connect(baud=self.baud, device=self.device,
                         dev_type=self.dev_type, dev_idx=self.dev_idx)
        except BaseException:
            self._entered = False  # 未真正进入，允许重试
            raise
        if not ok:
            try:
                disconnect()
            except Exception:
                pass
            self._entered = False  # 未真正进入，允许重试
            raise QC2015PError(
                f"CAN连接失败: device={self.device} baud={self.baud}")
        self._connected = True

        # 进入阶段后续步骤失败时回滚（__enter__ 抛出后 __exit__ 不会执行）
        try:
            # 2) 稳定等待
            if self.settle_ms and self.settle_ms > 0:
                qcsleep(self.settle_ms)

            # 3) 等待模型运行（可选）
            if self.wait_running:
                end = time.time() + self.run_timeout
                while time.time() < end:
                    if is_running("SECC") and is_running("EVCC"):
                        break
                    time.sleep(0.1)
                else:
                    raise QcAssertError(
                        f"SECC或EVCC未在{self.run_timeout}s内启动")

            # 4) 开录制（尽力而为：录制失败不阻断测试）
            if self.record:
                try:
                    self._recording = bool(logging(1, ch=self.record_ch))
                except (ConnectionError, QC2015PError) as e:
                    print(f"[WARN] 开启录制失败: {e}")
                    self._recording = False

            # 5) 参数快照（每模型仅此一次全量拉取，供退出时恢复 diff）
            if self.restore:
                for m in self.models:
                    try:
                        self._snaps[m] = snapshot_params(m)
                    except (ConnectionError, QC2015PError) as e:
                        print(f"[WARN] 参数快照失败({m}): {e}")
                        self._snaps[m] = {}
        except BaseException:
            # 回滚：停已开的录制、关已连的通道/设备
            if self._recording:
                try:
                    logging(0, ch=self.record_ch)
                except Exception:
                    pass
                self._recording = False
            if self._connected:
                try:
                    disconnect()
                except Exception:
                    pass
                self._connected = False
            self._entered = False
            raise

        _active_session = self
        return self

    def __exit__(self, exc_type, exc, tb) -> bool:
        global _active_session
        # 用户 addCleanup 的错误 → 无主体异常时升级为失败；
        # 基础设施收尾（停录制/rename/恢复/断开/重启）失败 → 仅告警，
        # 与既有脚本 try/except: pass 的"尽力收尾"语义一致。
        cleanup_errors: List[BaseException] = []

        def _step(fn: Callable[[], Any], what: str,
                  fatal: bool = False) -> None:
            """执行单步收尾，异常处理后继续（保证后续步骤都能执行）。"""
            try:
                fn()
            except Exception as e:  # noqa: BLE001 —— 收尾步骤全部容错
                if fatal:
                    cleanup_errors.append(e)
                print(f"[WARN] {what}: {e}")

        try:
            # 1) 用户注册的清理：逆序（LIFO）
            while self._cleanups:
                fn = self._cleanups.pop()
                _step(fn, "cleanup失败", fatal=True)

            # 2) 停录制 + rename（保持与面板导出脚本一致的收尾顺序）
            if self._recording:
                def _stop_and_rename():
                    model = "EVCC" if self.record_ch == 1 else "SECC"
                    logging(0, ch=self.record_ch)
                    name = self.log_name
                    if name is None:
                        argv0 = sys.argv[0] if sys.argv else ""
                        if argv0 and argv0 not in ("-c", ""):
                            name = os.path.splitext(os.path.basename(argv0))[0]
                    if name:
                        rename_log(model, name)
                _step(_stop_and_rename, "停止录制/重命名失败")

            # 3) 恢复会话内被改动的参数（逐个写回，单个失败不阻断其余）
            if self.restore and self._changed:
                def _restore_changed():
                    for (model, name), value in list(self._changed.items()):
                        if value is None:
                            continue
                        try:
                            _raw_set(model, name, value)
                        except Exception as e:  # noqa: BLE001
                            print(f"[WARN] 恢复参数失败 {model}.{name}: {e}")
                _step(_restore_changed, "参数自动恢复失败")

            # 4) 关通道/关设备
            if self._connected:
                _step(disconnect, "断开CAN失败")

            # 5) 重启 HIL（可选）
            if self.restart:
                _step(lambda: restart_hil(), "重启HIL失败")
        finally:
            _active_session = None

        # 无主体异常时，用户清理的错误升级为失败（有主体异常则保留原异常）
        if exc_type is None and cleanup_errors:
            raise cleanup_errors[0]
        return False  # 永不吞掉主体异常

