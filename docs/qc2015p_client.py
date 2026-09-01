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
"""

import json
import time
import urllib.request
import urllib.parse
from typing import Any, Dict, List, Optional, Union

# ============================================================
# 服务器配置
# ============================================================
_host = "localhost"
_port = 9527
_timeout = 5  # HTTP请求超时(秒)


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

    # 推入脚本队列
    result = _get("/api/script/push", {
        "cmd": "set", "model": model, "name": real_name, "value": value_str
    })
    if not result.get("success"):
        raise QC2015PError(f"命令入队失败: {result.get('error', 'unknown')}")

    # 等待执行结果
    result = _wait_result()
    if result is None:
        raise QC2015PError("等待超时，命令未被执行")
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
    """获取DBC报文原始数据"""
    data = _get("/api/secc/dbc_params")
    for msg in data.get("data", []):
        if msg.get("id") == msg_id:
            return msg
    return None


def _wait_result(timeout: float = 5.0) -> Optional[Dict]:
    """等待脚本命令执行结果"""
    start = time.time()
    while time.time() - start < timeout:
        result = _get("/api/script/result")
        if result.get("success") is not None:
            return result
        time.sleep(0.005)
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

def connect(baud: int = 250000) -> bool:
    """
    连接CAN设备（双通道同时打开）。

    connect()              # 250k
    connect(baud=500000)   # 500k

    Returns:
        True=两个通道都连接成功
    """
    r0 = _get("/api/can/connect", {"ch": 0, "baud": baud})
    r1 = _get("/api/can/connect", {"ch": 1, "baud": baud})
    return r0.get("success", False) and r1.get("success", False)


def disconnect() -> bool:
    """
    断开CAN连接（双通道同时断开）。
    """
    r0 = _get("/api/can/disconnect", {"ch": 0})
    r1 = _get("/api/can/disconnect", {"ch": 1})
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
    """设置 SECC 模型参数。共享参数会自动同步到 EVCC。
       SECC_ValueSet("ChargeSta", 1)  →  直接写入 SECC 模型的 ChargeSta 参数
    """
    value_str = _format_value(value)
    result = _get("/api/script/push", {
        "cmd": "set", "model": "SECC", "name": name, "value": value_str
    })
    if not result.get("success"):
        raise QC2015PError(f"命令入队失败: {result.get('error', 'unknown')}")
    result = _wait_result()
    if result is None:
        raise QC2015PError("等待超时，命令未被执行")
    if not result.get("success"):
        raise QC2015PError(f"设置失败: {result.get('error', 'unknown')}")
    return True


def SECC_ValueGet(name: str) -> Any:
    """读取 SECC 模型参数。
       SECC_ValueGet("ChargeSta")  →  直接读取 SECC 模型的 ChargeSta 参数
    """
    result = _get("/api/script/push", {
        "cmd": "get", "model": "SECC", "name": name
    })
    if not result.get("success"):
        raise QC2015PError(f"命令入队失败: {result.get('error', 'unknown')}")
    result = _wait_result()
    if result is None:
        raise QC2015PError("等待超时，命令未被执行")
    if not result.get("success"):
        raise QC2015PError(f"读取失败: {result.get('error', 'unknown')}")
    return _parse_value(result.get("value", ""))


def EVCC_ValueSet(name: str, value: Union[str, int, float, bool, list]) -> bool:
    """设置 EVCC 模型参数。共享参数会自动同步到 SECC。
       EVCC_ValueSet("ChargeSta", 1)  →  直接写入 EVCC 模型的 ChargeSta 参数
    """
    value_str = _format_value(value)
    result = _get("/api/script/push", {
        "cmd": "set", "model": "EVCC", "name": name, "value": value_str
    })
    if not result.get("success"):
        raise QC2015PError(f"命令入队失败: {result.get('error', 'unknown')}")
    result = _wait_result()
    if result is None:
        raise QC2015PError("等待超时，命令未被执行")
    if not result.get("success"):
        raise QC2015PError(f"设置失败: {result.get('error', 'unknown')}")
    return True


def EVCC_ValueGet(name: str) -> Any:
    """读取 EVCC 模型参数。
       EVCC_ValueGet("ChargeSta")  →  直接读取 EVCC 模型的 ChargeSta 参数
    """
    result = _get("/api/script/push", {
        "cmd": "get", "model": "EVCC", "name": name
    })
    if not result.get("success"):
        raise QC2015PError(f"命令入队失败: {result.get('error', 'unknown')}")
    result = _wait_result()
    if result is None:
        raise QC2015PError("等待超时，命令未被执行")
    if not result.get("success"):
        raise QC2015PError(f"读取失败: {result.get('error', 'unknown')}")
    return _parse_value(result.get("value", ""))


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
