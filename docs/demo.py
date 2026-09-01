# -*- coding: utf-8 -*-
"""
QC2015P 本地测试平台 Demo Script

演示简洁封装: SECC_ValueSet/Get, EVCC_ValueSet/Get, SignalGet, DataGet
运行前确保 QC2015P_HIL.exe 已启动。

使用方法:
    python demo.py
"""

import sys
import time

# 导入客户端库
from qc2015p_client import (
    SECC_ValueSet, SECC_ValueGet, EVCC_ValueSet, EVCC_ValueGet,
    MsgGet,
    connect, disconnect,
    get_status, is_running, logging, get_trace,
    wait_params, poll_params,
    QC2015PError, configure,
)


def banner(title: str):
    print(f"\n{'='*60}")
    print(f"  {title}")
    print(f"{'='*60}")


def demo_system():
    """系统状态"""
    banner("1. 系统状态")

    st = get_status()
    res = 0
    print(f"  SECC running={st['secc']['running']}  step={st['secc']['stepCount']}")
    print(f"  EVCC running={st['evcc']['running']}  step={st['evcc']['stepCount']}")
    print(f"  CAN ch0={st['can']['ch0']['connected']}  ch1={st['can']['ch1']['connected']}")
    if 1=={st['secc']['running']} and 1=={st['evcc']['running']} and 1=={st['can']['ch0']['connected']} and 1=={st['can']['ch1']['connected']}:
        res = 1
    return res


def demo_set_params():
    """设置模型参数"""
    banner("2. SECC_ValueSet / EVCC_ValueSet — 设置模型参数")

    # 单值（不带前缀）
    print("  [1] SECC_ValueSet('Enable_Va', True)")
    try:
        SECC_ValueSet("Enable_Va", True)
        print("      OK")
    except QC2015PError as e:
        print(f"      失败: {e}")

    # 数字
    print("  [2] SECC_ValueSet('ChargeSta', 1)")
    try:
        SECC_ValueSet("ChargeSta", 1)
        print("      OK")
    except QC2015PError as e:
        print(f"      失败: {e}")

    # 数组
    print("  [3] SECC_ValueSet('CVList', [0, 65792, 67849, 131072, 0])")
    try:
        SECC_ValueSet("CVList", [0, 65792, 67849, 131072, 0])
        print("      OK")
    except QC2015PError as e:
        print(f"      失败: {e}")

    # EVCC 侧
    print("  [4] EVCC_ValueSet('ChargeSta', 1)")
    try:
        EVCC_ValueSet("ChargeSta", 1)
        print("      OK")
    except QC2015PError as e:
        print(f"      失败: {e}")


def demo_get_params():
    """读取模型参数"""
    banner("3. SECC_ValueGet / EVCC_ValueGet — 读取模型参数")

    print("  [1] SECC_ValueGet('Enable_Va')")
    try:
        val = SECC_ValueGet("Enable_Va")
        print(f"      = {val}")
    except QC2015PError as e:
        print(f"      失败: {e}")

    print("  [2] SECC_ValueGet('CVList')")
    try:
        val = SECC_ValueGet("CVList")
        print(f"      = {val}")
    except QC2015PError as e:
        print(f"      失败: {e}")

    # EVCC
    print("  [3] EVCC_ValueGet('Enable_Va')")
    try:
        val = EVCC_ValueGet("Enable_Va")
        print(f"      = {val}")
    except QC2015PError as e:
        print(f"      失败: {e}")


def demo_dbc_signal():
    """读取DBC信号"""
    banner("4. MsgGet — 读取DBC报文信息")

    # 先获取所有DBC报文，找一个有信号的
    print("  [1] 扫描DBC报文...")
    from qc2015p_client import _get
    data = _get("/api/secc/dbc_params")
    msgs = data.get("data", [])

    if not msgs:
        print("      无DBC报文数据，跳过")
        return

    # 找第一个有信号的报文
    target = None
    for m in msgs:
        if m.get("signals"):
            target = m
            break

    if not target:
        print("      无信号数据，跳过")
        return

    msg_id = target["id"]
    sig_name = list(target["signals"].keys())[0]

    print(f"  [2] 报文 0x{msg_id:08X} ({target['name']})")

    # MsgGet 获取完整报文信息
    print(f"  [3] MsgGet(0x{msg_id:X})")
    try:
        msg = MsgGet(msg_id)
        print(f"      data      = {msg['data']}")
        print(f"      timestamp = {msg['timestamp']} us")
        print(f"      name      = {msg['name']}")
        print(f"      dlc       = {msg['dlc']}")
        print(f"      signals   = {msg['signals']}")
    except QC2015PError as e:
        print(f"      失败: {e}")

    # MsgGet 按需查询
    print(f"  [4] MsgGet(0x{msg_id:X}, 'Data')")
    try:
        raw = MsgGet(msg_id, "Data")
        print(f"      = {raw}")
    except QC2015PError as e:
        print(f"      失败: {e}")

    print(f"  [5] MsgGet(0x{msg_id:X}, 'lastTimestamp')")
    try:
        ts = MsgGet(msg_id, "lastTimestamp")
        print(f"      = {ts} us")
    except QC2015PError as e:
        print(f"      失败: {e}")

    print(f"  [6] MsgGet(0x{msg_id:X}, '{sig_name}')")
    try:
        val = MsgGet(msg_id, sig_name)
        print(f"      = {val}")
    except QC2015PError as e:
        print(f"      失败: {e}")


def demo_error_handling():
    """错误处理"""
    banner("5. 错误处理")

    # 不存在的参数
    print("  [1] get_params('SECC_NonExistParam')")
    try:
        val = get_params("SECC_NonExistParam")
        print(f"      = {val}")
    except QC2015PError as e:
        print(f"      捕获异常: {e}")

    # 不存在的DBC信号
    print("  [2] get_params('FakeSignal', 0x12345678)")
    try:
        val = get_params("FakeSignal", 0x12345678)
        print(f"      = {val}")
    except QC2015PError as e:
        print(f"      捕获异常: {e}")

    # 无前缀写入
    print("  [3] set_params('NoPrefix', 1)")
    try:
        set_params("NoPrefix", 1)
    except QC2015PError as e:
        print(f"      捕获异常: {e}")


def demo_device():
    """设备操作"""
    banner("6. 设备操作")

    print(f"  SECC running: {is_running('SECC')}")
    print(f"  EVCC running: {is_running('EVCC')}")

    # 录制
    print("  logging('SECC') → 开始录制")
    try:
        logging("SECC","blf")
        time.sleep(0.5)
        logging("SECC")  # 再次调用停止
        print("  已停止")
    except Exception as e:
        print(f"  录制操作: {e}")

    # 报文追踪
    trace = get_trace("SECC")
    print(f"  报文追踪: {len(trace)} 条")


def demo_poll():
    """轮询读取"""
    banner("7. 轮询读取")

    print("  poll_params('SECC_Enable_Va', count=3, interval=0.1)")
    try:
        values = poll_params("SECC_Enable_Va", count=3, interval=0.1)
        print(f"  结果: {values}")
    except QC2015PError as e:
        print(f"      失败: {e}")


def main():
    print("QC2015P 本地测试平台 - Python Demo")
    print("确保 QC2015P_HIL.exe 已启动 (http://localhost:9527)\n")

    # 检查连接
    try:
        get_status()
        print("连接成功！")
    except ConnectionError as e:
        print(f"连接失败: {e}")
        sys.exit(1)

    demo_system()
    demo_set_params()
    demo_get_params()
    demo_dbc_signal()
    demo_error_handling()
    demo_device()
    demo_poll()

    banner("演示完成")


if __name__ == "__main__":
    main()
