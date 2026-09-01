# QC2015P 本地测试平台 API Reference

HTTP API接口文档，供前端和Python脚本使用。

**Base URL**: `http://localhost:9527`

**协议**: HTTP/1.1 GET (所有接口均使用GET方法，参数通过query string传递)

**CORS**: 所有接口均支持跨域访问 (`Access-Control-Allow-Origin: *`)

---

## 目录

1. [系统API](#1-系统api)
2. [CAN API](#2-can-api)
3. [SECC参数API](#3-secc参数api)
4. [EVCC参数API](#4-evcc参数api)
5. [DBC只读参数API](#5-dbc只读参数api)
6. [Monitor只读参数API](#6-monitor只读参数api)
7. [报文追踪API](#7-报文追踪api)
8. [录制API](#8-录制api)
9. [脚本命令队列API](#9-脚本命令队列api)
10. [数据格式说明](#10-数据格式说明)
11. [Python使用示例](#11-python使用示例)

---

## 1. 系统API

### GET /api/status

获取系统运行状态。

**响应**:
```json
{
    "type": "status",
    "secc": {
        "running": true,
        "stepCount": 12345,
        "avgPeriodUs": 998.5,
        "jitterUs": 12.3,
        "overrunCount": 0
    },
    "evcc": {
        "running": true,
        "stepCount": 12345,
        "avgPeriodUs": 999.1,
        "jitterUs": 8.7,
        "overrunCount": 0
    },
    "can": {
        "ch0": {"connected": true, "rxCount": 100, "txCount": 50, "errorCount": 0},
        "ch1": {"connected": true, "rxCount": 80, "txCount": 40, "errorCount": 0}
    },
    "logging": {"secc": false, "evcc": false}
}
```

| 字段 | 说明 |
|------|------|
| `secc.running` | SECC模型是否在运行 |
| `secc.stepCount` | 累计步进次数 |
| `secc.avgPeriodUs` | 平均周期(微秒) |
| `secc.jitterUs` | 平均抖动(微秒) |
| `secc.overrunCount` | 超时次数 |
| `can.ch0.connected` | 通道0是否连接 |
| `logging.secc` | SECC是否正在录制 |

---

## 2. CAN API

### GET /api/can/connect

连接CAN设备并启动对应模型。

**参数**:

| 参数 | 类型 | 默认值 | 说明 |
|------|------|--------|------|
| `devType` | int | 4 | 设备类型 (4=USBCAN2) |
| `devIdx` | int | 0 | 设备索引 |
| `ch` | int | 0 | 通道号 (0=SECC, 1=EVCC) |
| `baud` | int | 250000 | 波特率 |

**响应**:
```json
{
    "success": true,
    "channel": 0,
    "connected": true
}
```

**说明**: 连接通道0会自动启动SECC模型线程，连接通道1会自动启动EVCC模型线程。

### GET /api/can/disconnect

断开CAN连接并停止对应模型。

**参数**:

| 参数 | 类型 | 默认值 | 说明 |
|------|------|--------|------|
| `ch` | int | 0 | 通道号 |

**响应**:
```json
{
    "success": true,
    "channel": 0,
    "connected": false
}
```

---

## 3. SECC参数API

### GET /api/secc/params

获取SECC模型参数列表（含当前值）。

**响应**:
```json
{
    "type": "params",
    "model": "SECC",
    "data": [
        {
            "id": 1,
            "name": "SM_RM_SECC_Enable_Va",
            "type": "boolean_T",
            "category": "SM_RM_SECC",
            "unit": "",
            "offset": 0,
            "size": 1,
            "value": true
        },
        {
            "id": 2,
            "name": "EVCC_CVList",
            "type": "uint32_T",
            "category": "EVCC",
            "unit": "V",
            "offset": 60,
            "size": 20,
            "value": [0, 65792, 67849, 131072, 0]
        }
    ]
}
```

| 字段 | 说明 |
|------|------|
| `id` | 参数唯一ID |
| `name` | 参数名称（结构体字段名） |
| `type` | C类型 (boolean_T/real_T/uint8_T等) |
| `category` | 分类（根据名称前缀自动分类） |
| `unit` | 单位（根据名称推断） |
| `offset` | 在rt_Simulink_Struct中的字节偏移 |
| `size` | 字节大小 |
| `value` | 当前值 |

### GET /api/secc/params/set

设置SECC模型参数值。

**参数**:

| 参数 | 类型 | 必填 | 说明 |
|------|------|------|------|
| `name` | string | 是 | 参数名称 |
| `value` | string | 是 | 参数值 |

**值格式**:

| 类型 | 格式 | 示例 |
|------|------|------|
| boolean_T | `true` / `false` | `value=true` |
| real_T | 数值 | `value=50.0` |
| uint8_T | 整数 | `value=1` |
| uint8_T[] (数组) | JSON数组 | `value=[1,2,3,4,5,6,7,8]` |
| real_T[] (数组) | JSON数组 | `value=[1.0,2.0,3.0]` |

**响应**:
```json
{"success": true}
```

---

## 4. EVCC参数API

与SECC参数API完全对称，路径前缀为 `/api/evcc/`。

- `GET /api/evcc/params` — 获取EVCC参数列表
- `GET /api/evcc/params/set?name=xxx&value=xxx` — 设置EVCC参数

---

## 5. DBC只读参数API

### GET /api/secc/dbc_params

获取所有DBC报文的实时状态（只读）。

**响应**:
```json
{
    "type": "dbc_params",
    "data": [
        {
            "id": 406123606,
            "name": "LM_SECC",
            "dlc": 8,
            "direction": "TX",
            "lastUpdate": 1234567.89,
            "data": [1, 2, 3, 4, 5, 6, 7, 8],
            "signals": {
                "Protocol_Va": "0x01",
                "Enable_Va": "1",
                "Charge_Voltage_Va": "750"
            }
        }
    ]
}
```

| 字段 | 说明 |
|------|------|
| `id` | CAN报文ID |
| `name` | 报文名称（来自DBC） |
| `dlc` | 数据长度 |
| `direction` | 方向：TX=发送，RX=接收 |
| `lastUpdate` | 最后更新时间戳(微秒) |
| `data` | 原始数据[8字节] |
| `signals` | 解码后的信号值 |

### GET /api/evcc/dbc_params

与SECC相同，获取EVCC的DBC报文状态。

---

## 6. Monitor只读参数API

### GET /api/secc/monitor_params

获取SECC UserMonitor结构体变量的实时值（只读）。

**响应**:
```json
{
    "type": "monitor_params",
    "data": [
        {
            "name": "Vol_Bat",
            "type": "real_T",
            "unit": "V",
            "offset": 0,
            "size": 8,
            "value": 0
        },
        {
            "name": "Current_Bat",
            "type": "real_T",
            "unit": "A",
            "offset": 8,
            "size": 8,
            "value": 0
        }
    ]
}
```

**注意**: UserMonitor变量的名称和数量不固定，每次启动时从 `_types.h` 文件解析。

### GET /api/evcc/monitor_params

与SECC相同，获取EVCC的UserMonitor变量。

---

## 7. 报文追踪API

### GET /api/secc/trace

获取SECC通道（通道0）的报文追踪数据。

**响应**:
```json
{
    "type": "trace",
    "messages": [
        {
            "timestamp": 1234567.89,
            "direction": "TX",
            "id": 406123606,
            "dlc": 8,
            "extended": true,
            "data": [1, 2, 3, 4, 5, 6, 7, 8],
            "signals": {
                "Protocol_Va": "0x01",
                "Enable_Va": "1"
            }
        }
    ]
}
```

**说明**: `signals` 字段仅在DBC已加载时存在。

### GET /api/evcc/trace

获取EVCC通道（通道1）的报文追踪数据。

### GET /api/can/trace

获取所有CAN通道的报文追踪数据。

---

## 8. 录制API

### GET /api/secc/logging

开始/停止SECC报文录制。

**参数**:

| 参数 | 类型 | 默认值 | 说明 |
|------|------|--------|------|
| `format` | string | "asc" | 录制格式："asc" 或 "blf" |

**响应**:
```json
{"logging": true}
```

**说明**: 再次调用会切换状态（开→关，关→开）。

### GET /api/evcc/logging

与SECC相同，控制EVCC报文录制。

**录制文件位置**: `Logger/` 目录下

**文件名格式**: `{SECC|EVCC}_{YYYYMMDD}_{HHMMSS}.{asc|blf}`

---

## 9. 脚本命令队列API

用于Python脚本的**限速执行**机制。每个模型线程的1ms step中最多执行一条命令，防止while循环导致程序卡死。

### GET /api/script/push

推入命令到脚本队列。

**参数**:

| 参数 | 类型 | 必填 | 说明 |
|------|------|------|------|
| `cmd` | string | 是 | 命令类型："set" 或 "get" |
| `model` | string | 是 | 模型："SECC" 或 "EVCC" |
| `name` | string | 是 | 参数名称 |
| `value` | string | 否 | 值（set时必填） |

**示例**:
```
GET /api/script/push?cmd=set&model=SECC&name=SM_RM_SECC_Enable_Va&value=true
GET /api/script/push?cmd=get&model=EVCC&name=EVCC_CVList
```

**响应**:
```json
{"success": true, "queued": 3}
```

| 字段 | 说明 |
|------|------|
| `queued` | 当前队列中待执行的命令数 |

### GET /api/script/result

获取一个命令执行结果（非阻塞）。

**响应**（有结果时）:
```json
{
    "success": true,
    "value": true
}
```

**响应**（get命令时）:
```json
{
    "success": true,
    "value": [0, 65792, 67849, 131072, 0]
}
```

**响应**（无结果时）:
```json
{"success": null, "message": "no result yet"}
```

### GET /api/script/clear

清空命令队列。

**响应**:
```json
{"success": true}
```

### GET /api/script/status

查看命令队列状态。

**响应**:
```json
{"queue_size": 5}
```

---

## 10. 数据格式说明

### 参数类型映射

| C类型 | 字节大小 | Python示例值 |
|-------|----------|-------------|
| `boolean_T` | 1 | `true` |
| `real_T` | 8 | `50.0` |
| `real32_T` | 4 | `3.14` |
| `uint8_T` | 1 | `1` |
| `uint16_T` | 2 | `1000` |
| `uint32_T` | 4 | `65536` |
| `int8_T` | 1 | `-1` |
| `int16_T` | 2 | `-1000` |
| `int32_T` | 4 | `-65536` |
| `uint8_T[]` | N*1 | `[1,2,3]` |
| `real_T[]` | N*8 | `[1.0,2.0]` |

### 参数分类

参数根据名称前缀自动分类：

| 前缀 | 分类 |
|------|------|
| `SM_RM_SECC_*` | SM_RM_SECC |
| `SM_URM_SECC_*` | SM_URM_SECC |
| `LM_SECC_*` | LM_SECC |
| `CONTROL_SECC_*` | CONTROL_SECC |
| `VC_SECC_*` | VC_SECC |
| `EVCC_*` | EVCC |
| 其他 | General |

### 参数单位推断

| 名称包含 | 单位 |
|----------|------|
| `Voltage`, `Vol` | V |
| `Current` | A |
| `Power` | W |
| `SOC` | % |
| `Time` | s |
| `Enable` | - |
| `Error` | - |

---

## 11. Python使用示例

### 基本操作

```python
from scripts.qc2015p_client import QC2015PClient

client = QC2015PClient()

# 系统状态
status = client.status()
print(f"SECC running: {status['secc']['running']}")

# 连接CAN
client.can_connect(ch=0, baud=250000)
client.can_connect(ch=1, baud=250000)

# 读取参数
params = client.get_params("SECC")
for p in params[:5]:
    print(f"{p['name']}: {p['value']}")

# 设置参数
client.set_param("SECC", "SM_RM_SECC_Enable_Va", True)
```

### 安全读写（脚本队列）

```python
# 安全设置（通过队列，限速执行）
client.set_param_safe("SECC", "SM_RM_SECC_Enable_Va", True)

# 安全读取（通过队列）
value = client.get_param("SECC", "SM_RM_SECC_Enable_Va")

# 批量设置
results = client.batch_set("SECC", {
    "SM_RM_SECC_Enable_Va": True,
    "SM_RM_SECC_Enable_SW": False,
})
```

### DBC监控

```python
# 获取DBC报文
dbc_msgs = client.get_dbc_params("SECC")
for msg in dbc_msgs:
    print(f"[0x{msg['id']:08X}] {msg['name']} ({msg['direction']})")
    for sig, val in msg['signals'].items():
        print(f"  {sig} = {val}")

# 获取特定信号
val = client.get_dbc_signal("SECC", 406123606, "Protocol_Va")
```

### 轮询监控

```python
# 轮询读取参数值
values = client.poll_param("SECC", "SM_RM_SECC_Enable_Va", interval=0.1, count=10)

# 等待参数变为期望值
ok = client.wait_param("SECC", "SM_RM_SECC_Enable_Va", True, timeout=5.0)
```

### 录制控制

```python
# 开始录制
client.start_logging("SECC", fmt="asc")
client.start_logging("EVCC", fmt="blf")

# 检查录制状态
if client.is_logging("SECC"):
    print("SECC正在录制")

# 停止录制
client.stop_logging("SECC")
```

---

## 错误处理

所有API错误返回JSON格式：

```json
{"error": "not found"}
```

Python客户端会抛出以下异常：
- `ConnectionError` — 无法连接服务器
- `ValueError` — JSON解析失败

---

## 线程安全

- 所有API通过HTTP访问，天然线程安全
- 脚本命令队列内部使用mutex保护
- 模型参数的直接读写（`/api/secc/params/set`）不保证原子性，建议使用脚本队列
