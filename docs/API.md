# QC2015P 本地测试平台 API Reference

HTTP API接口文档，供前端和Python脚本使用。

**Base URL**: `http://localhost:9527`

**协议**: HTTP/1.1 GET（所有HTTP接口均使用GET方法，参数通过query string传递）

**高速命令端口**: `127.0.0.1:9528`（持久TCP连接，参数读写延迟 ≈0.3ms，见 [10. 高速TCP命令端口](#10-高速tcp命令端口9528)）

**CORS**: 所有接口均支持跨域访问 (`Access-Control-Allow-Origin: *`)

**连接**: 所有响应均带 `Connection: close`，不做 HTTP keep-alive

---

## 目录

1. [系统API](#1-系统api)
2. [CAN API](#2-can-api)
3. [SECC参数API](#3-secc参数api)
4. [EVCC参数API](#4-evcc参数api)
5. [DBC只读参数API](#5-dbc只读参数api)
6. [Monitor只读参数API](#6-monitor只读参数api)
7. [报文追踪API](#7-报文追踪api)
8. [录制 / 导出API](#8-录制--导出api)
9. [画布默认配置API](#9-画布默认配置api)
10. [高速TCP命令端口(9528)](#10-高速tcp命令端口9528)
11. [脚本命令队列API（遗留）](#11-脚本命令队列api遗留)
12. [数据格式说明](#12-数据格式说明)
13. [Python客户端](#13-python客户端)

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

### GET /api/model/reset

复位两个模型（重新初始化模型内部状态，不重启进程、不断开CAN）。

**响应**:
```json
{"success": true}
```

### GET /api/secc/ui_logs

获取后端推送的UI日志（`MAIN_SEQ` 阶段变化等事件），前端按 `since` 增量轮询。

**参数**:

| 参数 | 类型 | 默认值 | 说明 |
|------|------|--------|------|
| `since` | uint64 | 0 | 只返回 `id` 大于该值的日志（增量拉取水位） |

**响应**:
```json
{
    "type": "ui_logs",
    "logs": [
        {"id": 12, "model": "SECC", "level": "info", "message": "MAIN_SEQ 303 -> 401"}
    ]
}
```

> `/api/evcc/ui_logs` 与SECC对称。

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

断开CAN连接并停止对应模型（同时自动停止该通道的报文录制）。

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
            "name": "SECC_2015P_Enable",
            "type": "boolean_T",
            "category": "SECC",
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

设置单个SECC模型参数值。

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

> 服务端对写入做了 1ms/次 的限速，保护模型定步长。

### GET /api/secc/params/set_batch

一次请求批量设置多个SECC参数。

**参数**: query中直接给出多个 `参数名=值` 对（参数名可带或不带 `SECC_` 前缀）。

**示例**:
```
GET /api/secc/params/set_batch?ChargeSta=1&CC2=3.5&SECC_2015P_Enable=true
```

**响应**:
```json
{"success": true, "applied": 3, "failed": ""}
```

| 字段 | 说明 |
|------|------|
| `applied` | 成功写入的参数个数 |
| `failed` | 写入失败的参数名（逗号分隔），全部成功时为空串 |

> 任一参数失败时 `success` 为 `false`，但已成功的参数仍然生效。

### GET /api/params/set（通用）

不带模型前缀的通用写入端点，参数名需为模型结构体中的原始字段名。

```
GET /api/params/set?name=ChargeSta&value=1
```

---

## 4. EVCC参数API

与SECC参数API完全对称，路径前缀为 `/api/evcc/`。

- `GET /api/evcc/params` — 获取EVCC参数列表
- `GET /api/evcc/params/set?name=xxx&value=xxx` — 设置单个EVCC参数
- `GET /api/evcc/params/set_batch?xxx=1&yyy=2` — 批量设置EVCC参数

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
            "sender": "SECC",
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
| `direction` | 方向：TX=发送，RX=接收（按模型独立维护） |
| `sender` | DBC中定义的发送方节点（SECC/EVCC） |
| `lastUpdate` | 最后更新时间戳(微秒) |
| `data` | 原始数据（字节数组） |
| `signals` | 解码后的信号值 |

### GET /api/evcc/dbc_params

与SECC相同，获取EVCC的DBC报文状态。

### GET /api/dbc_msg

单条报文查询（高性能：只返回指定ID，不拉全量）。**Python `MsgGet()` 默认走这个端点。**

**参数**:

| 参数 | 类型 | 默认值 | 说明 |
|------|------|--------|------|
| `id` | uint32 | 0 | 报文ID（十进制） |
| `model` | string | SECC | `SECC` 或 `EVCC` |

**响应**（报文存在时）:
```json
{
    "id": 406123606,
    "name": "LM_SECC",
    "dlc": 8,
    "sender": "SECC",
    "direction": "TX",
    "lastUpdate": 1234567,
    "data": [1, 2, 3, 4, 5, 6, 7, 8],
    "signals": {"PGI05_K1": "42"}
}
```

**响应**（报文未收到过）: `{}`

---

## 6. Monitor只读参数API

### GET /api/secc/monitor_params

获取SECC UserMonitor结构体变量的实时值（只读）。

**响应**:
```json
{
    "type": "monitor_params",
    "data": [
        {"name": "MAIN_SEQ", "type": "real_T", "unit": "", "offset": 0, "size": 8, "value": 303},
        {"name": "ChargeCapacity", "type": "real_T", "unit": "", "offset": 8, "size": 8, "value": 0}
    ]
}
```

**注意**: UserMonitor变量的名称和数量不固定，每次启动时从 `_types.h` 文件解析。SECC当前的Monitor变量为 `MAIN_SEQ`、`ChargeCapacity`、`RelinkAllow`、`RebootAllow`、`DetectAllow`。

### GET /api/evcc/monitor_params

与SECC相同，获取EVCC的UserMonitor变量（EVCC侧序号变量名为 `EVCC_MAIN_SEQ`）。

---

## 7. 报文追踪API

### GET /api/secc/trace

获取SECC通道（通道0）的报文追踪数据。

**参数**:

| 参数 | 类型 | 默认值 | 说明 |
|------|------|--------|------|
| `since` | uint64 | 0 | 只返回 `timestamp` 大于该值的新报文（增量拉取）；单次最多返回500条 |

**响应**:
```json
{
    "type": "trace",
    "messages": [
        {
            "timestamp": 1234567,
            "direction": "TX",
            "id": 406123606,
            "dlc": 8,
            "extended": true,
            "data": "01 02 03 04 05 06 07 08",
            "periodUs": 10000,
            "name": "LM_SECC"
        }
    ]
}
```

| 字段 | 说明 |
|------|------|
| `timestamp` | 时间戳（微秒） |
| `direction` | `TX` / `RX` |
| `data` | **十六进制字符串**（空格分隔，每字节两位小写十六进制） |
| `periodUs` | 该ID的发送周期（微秒），后端自动统计 |
| `name` | 报文名称（来自DBC，未知ID为空） |

### GET /api/evcc/trace

获取EVCC通道（通道1）的报文追踪数据。

### GET /api/can/trace

获取所有CAN通道的报文追踪数据（合并两通道）。

### GET /api/trace/older

向前翻页：获取比 `before` 更早的报文，用于前端「上划回看历史」。返回顺序为**旧→新**。

**参数**:

| 参数 | 类型 | 默认值 | 说明 |
|------|------|--------|------|
| `channel` | int | -1 | 通道号，-1=全部 |
| `before` | uint64 | 0 | 时间戳水位，返回 `timestamp < before` 的报文；为0时返回空 |
| `limit` | int | 500 | 最多返回条数（上限5000） |

### GET /api/trace/export

全量导出某通道当前缓冲内的全部报文（旧→新），供前端组装完整 ASC 文件。

**参数**: `channel`（0/1）

**响应**: 与 `/api/secc/trace` 同构的 `{"type":"trace","messages":[...]}`，但**一次性返回全部**（不受500条限制）。

### GET /api/trace/export_blf

后端生成 BLF 文件，把当前缓冲内该通道的全部报文写入 `Logger/export_<model>_<时间戳>.blf`。

**参数**: `channel`（0/1）

**响应**:
```json
{"success": true, "name": "export_SECC_20260927_143022.blf", "count": 152340}
```

拿到 `name` 后再通过 [`GET /logger/<name>`](#get-loggername) 二进制下载。

### GET /api/trace/decode

按需解码单条报文的信号（前端点击报文行时调用，避免轮询热路径逐帧预解码）。

**参数**:

| 参数 | 类型 | 说明 |
|------|------|------|
| `id` | uint32 | 报文ID |
| `data` | string | 十六进制数据串（容忍空格等任意分隔符，长短报文均支持） |

**响应**:
```json
{"signals": {"PGI05_K1": "42", "PGI05_K2": "0"}}
```

### GET /api/trace/clear

清空后端报文追踪缓冲区（前端点「清除」时调用，避免上划后拉回旧数据）。

**响应**:
```json
{"success": true}
```

---

## 8. 录制 / 导出API

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

### GET /api/logging/rename

重命名最近一次录制文件（需先停止录制）。

**参数**:

| 参数 | 类型 | 必填 | 说明 |
|------|------|------|------|
| `model` | string | 是 | `SECC` 或 `EVCC` |
| `name` | string | 是 | 新文件名（不含扩展名，支持中文，需URL编码） |

**响应**:
```json
{"success": true, "name": "充电测试1.blf"}
```

重名时自动追加时间后缀：`充电测试1_20260927_143022.blf`。录制进行中或文件不存在时返回 `{"success":false,...}`。

### GET /logger/&lt;name&gt;

二进制下载 `Logger/` 目录下的录制/导出文件。

**响应**: `Content-Type: application/octet-stream`，带 `Content-Disposition: attachment`。

**安全**: 只允许纯文件名，含 `..`、`/`、`\` 的请求返回 400。

---

## 9. 画布默认配置API

### GET /api/canvas/default

读取画布默认参数配置文件。

**参数**: `model`（`SECC` / `EVCC`，大小写不敏感）

**响应**:
```json
[
    {"name": "SECC_ChargeSta", "note": "充电状态（0=未充电，1=充电中）"},
    {"name": "SOC_Exe", "note": "执行SOC（Monitor只读）"}
]
```

**说明**: 从 `Logger/canvas/<MODEL>.canvas` 读取。文件格式为每行 `参数名 备注说明`（`#` 开头为注释，空行跳过），备注可省略。文件不存在时返回 `[]`。

```
# 注释行
SECC_ChargeSta 充电状态（0=未充电，1=充电中）
SECC_CC2 CC2检测电压
```

---

## 10. 高速TCP命令端口(9528)

Python脚本参数读写的低延迟通道，**只监听 `127.0.0.1`**，用于绕过HTTP每请求新建线程的开销。协议为**行文本**，`\n` 分隔，连接**持久复用**。

### 命令

| 客户端发送 | 服务端响应 | 说明 |
|-----------|-----------|------|
| `SET <model> <name> <value>\n` | `OK\n` | 写模型参数 |
| `GET <model> <name>\n` | `VALUE <value>\n` | 读模型参数 |
| `DBC <model> <id>\n` | `{json}\n` | 查单条报文（同 `/api/dbc_msg`） |
| `QUIT\n` | `BYE\n` | 关闭连接 |

`<model>` 为 `SECC` 或 `EVCC`，`<value>` 为与HTTP端点相同的文本格式。

### 示例

```
SET SECC ChargeSta 1
OK
GET SECC MAIN_SEQ
VALUE 303
DBC SECC 406123606
{"id":406123606,"name":"LM_SECC",...}
QUIT
BYE
```

**降级**: 端口9528绑定失败时程序打印 `[WARN] Fast port 9528 bind failed` 并继续运行；Python客户端会自动回退到HTTP端点，功能不受影响。

---

## 11. 脚本命令队列API（遗留）

> ⚠️ **已不推荐使用。** 当前Python客户端（`qc2015p_client.py`）已改为**直写模型参数** + 服务端1ms限速，不再走命令队列。以下端点仍保留在服务端以兼容旧脚本。

每个模型线程的1ms step中最多执行一条命令，防止Python脚本中的while循环导致模型卡死。

### GET /api/script/push

推入命令到脚本队列。

| 参数 | 类型 | 必填 | 说明 |
|------|------|------|------|
| `cmd` | string | 是 | 命令类型："set" 或 "get" |
| `model` | string | 是 | 模型："SECC" 或 "EVCC" |
| `name` | string | 是 | 参数名称 |
| `value` | string | 否 | 值（set时必填） |

**响应**: `{"success": true, "queued": 3}`

### GET /api/script/result

获取一个命令执行结果（非阻塞）。有结果时返回 `{"success":true,"value":...}`，无结果时返回 `{"success":null,"message":"no result yet"}`。

### GET /api/script/clear

清空命令队列。响应 `{"success": true}`。

### GET /api/script/status

查看命令队列状态。响应 `{"queue_size": 5}`。

---

## 12. 数据格式说明

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
| `SECC_` | SECC |
| `EVCC_` | EVCC |
| `SM_RM_SECC_*` | SM_RM_SECC |
| `SM_URM_SECC_*` | SM_URM_SECC |
| `LM_SECC_*` | LM_SECC |
| `CONTROL_SECC_*` | CONTROL_SECC |
| `VC_SECC_*` | VC_SECC |
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

### GB/T 27930-2015 兼容参数命名

模型内置2015旧协议报文收发能力，参数按如下规则命名。

> **通用约定**：所有成对参数都是 `_SW`（开关，boolean，默认 `false`）+ `_Va`（取值）。`_Va` 只在对应的 `_SW` 为 `true` 时被取用；`_SW` 为 `false` 时全部由模型内部状态机自动控制。

| 命名形式 | 含义 | 示例 |
|----------|------|------|
| `SECC_2015P_Enable` / `EVCC_2015P_Enable` | 本端是否支持 2015P（2024 新协议）：`true`=支持（默认，同时兼容 2015）、`false`=本端只跑 2015 | `SECC_2015P_Enable=false` |
| `<MSG>_Enable_SW` / `<MSG>_Enable_Va` | 手动接管开关 / 手动使能值（`_SW` 关闭时由状态机自动控制） | `CHM_Enable_SW=true; CHM_Enable_Va=false` |
| `<MSG>_Cycle_Va` | 该报文发送周期(ms) | `CRM_Cycle_Va=250` |
| `<MSG>_Data_SW` | 该报文数据字段覆盖开关 | `BCL_Data_SW=false` |
| `SPN<编号>_<MSG>_<信号>_SW` / `_Va` | 逐信号改写报文内容 | `SPN2821_BCP_SOC_Va=80` |
| `<SECC\|EVCC>_DefineMsg_*` | 用户自定义报文注入（ID/Length/Enable/Extended/Cycle） | `SECC_DefineMsg_ID=405206102` |

充电桩侧（SECC）报文集：`CHM` `CRM` `CRO` `CML` `CCS` `CST` `CSD` `CEM` + `TP_*`（传输层）
车辆侧（EVCC）报文集：`BHM` `BRM` `BCP` `BRO` `BCL` `BCS` `BSM` `BST` `BSD` `BEM` + `TP_*`

详见 [README「向下兼容 GB/T 27930-2015 旧快充协议」](README.md) 一节。

---

## 13. Python客户端

客户端库位于 [`docs/qc2015p_client.py`](qc2015p_client.py)，仅依赖标准库，无需安装任何第三方包。

```python
import sys
sys.path.insert(0, "docs")
from qc2015p_client import *
```

### 简洁封装（推荐）

| 函数 | 说明 | 示例 |
|------|------|------|
| `SECC_ValueSet(name, value)` | 设置SECC参数（高速TCP ≈0.3ms，失败回退HTTP） | `SECC_ValueSet("ChargeSta", 1)` |
| `SECC_ValueGet(name)` | 读SECC参数（模型参数或UserMonitor变量） | `SECC_ValueGet("MAIN_SEQ")` |
| `EVCC_ValueSet(name, value)` | 设置EVCC参数 | `EVCC_ValueSet("ChargeSta", 1)` |
| `EVCC_ValueGet(name)` | 读EVCC参数 | `EVCC_ValueGet("EVCC_MAIN_SEQ")` |
| `SECC_ValueSetBatch(dict)` | 一次请求批量写SECC参数 | `SECC_ValueSetBatch({"ChargeSta":1})` |
| `EVCC_ValueSetBatch(dict)` | 一次请求批量写EVCC参数 | `EVCC_ValueSetBatch({"ChargeSta":1})` |
| `BatchSet()` | 批量写上下文管理器，退出时合并提交 | 见下 |
| `MsgGet(id)` | 读报文完整信息 | `MsgGet(0x1836F456)` |
| `MsgGet(id, "Data")` | 读原始字节数组 | `MsgGet(0x1836F456, "Data")` |
| `MsgGet(id, "timestamp")` | 读最近更新时间戳(us) | `MsgGet(0x1836F456, "timestamp")` |
| `MsgGet(id, signal)` | 读单个信号（大小写不敏感，自动去尾部空格） | `MsgGet(0x1836F456, "PGI05_K1")` |
| `wait_params(name, expected, timeout)` | 等待参数变为期望值 | `wait_params("SECC_ChargeSta", 1)` |
| `poll_params(name, count, interval)` | 轮询采样参数值 | `poll_params("SECC_ChargeSta", 10, 0.1)` |

> 📌 **参数名怎么传**：`SECC_ValueSet/Get` 与 `EVCC_ValueSet/Get` 的 `name` 参数就是**Web 界面参数列表里显示的字段名，原样传入、不做任何前缀增删**。
> 例如字段名是 `ChargeSta` 就传 `"ChargeSta"`，字段名本身带前缀的 `SECC_2015P_Enable`、`SECC_ChargeSta` 就传全名。
> 而底层接口 `set_params()` / `get_params()` 相反，**必须**带 `SECC_`/`EVCC_` 前缀（它靠前缀判断写哪个模型）。

### 底层接口（仍可用）

| 函数 | 说明 | 示例 |
|------|------|------|
| `set_params(name, value)` | 设置参数（**需带** `SECC_`/`EVCC_` 前缀） | `set_params("SECC_ChargeSta", 1)` |
| `get_params(name)` | 读取模型参数 | `get_params("SECC_ChargeSta")` |
| `get_params(name, msg_id)` | 读取DBC信号 | `get_params("PGI05_K1", 0x1836F456)` |
| `get_params("Data", msg_id)` | 读取报文原始字节 | `get_params("Data", 0x1836F456)` |
| `connect(baud)` | 连接CAN（双通道一起打开） | `connect(baud=250000)` |
| `disconnect()` | 断开CAN（双通道一起断开，并关闭高速TCP连接） | `disconnect()` |
| `get_status()` | 获取系统状态 | `get_status()` |
| `is_running(model)` | 检查模型运行状态 | `is_running("SECC")` |
| `logging(state, ch, fmt)` | 录制控制 | `logging(1, ch=0, fmt=1)` |
| `rename_log(model, name)` | 重命名录制文件（支持中文） | `rename_log("SECC", "充电测试1")` |
| `get_trace(model)` | 获取报文追踪 | `get_trace("SECC")` |
| `configure(host, port)` | 修改服务器地址 | `configure("192.168.1.10")` |

### 批量写入示例

```python
# 方式一：一次调用写多条（示例：切到 2015 旧协议，并强制发送 CHM 握手报文）
SECC_ValueSetBatch({
    "SECC_2015P_Enable": False,   # false = 跑 2015 旧协议
    "CHM_Enable_SW": True,        # 手动接管 CHM 的发送
    "CHM_Enable_Va": True,        # 强制发送
})

# 方式二：上下文管理器，收集完退出时自动合并成1个请求
with BatchSet() as b:
    b.secc("ChargeSta", 1)
    b.secc("CC2", 3.5)
    b.evcc("MaxVoltage", 750)
# 退出with块 → 自动提交
```

### 异常

| 异常 | 触发场景 |
|------|----------|
| `ConnectionError` | 无法连接服务器（程序未启动 / 端口被占用） |
| `QC2015PError` | 参数名无效、参数未找到、写入失败、重命名失败 |
| `ValueError` | 服务器返回了无效JSON |

---

## 线程安全

- 所有参数读写经模型包装器的 `CRITICAL_SECTION` 保护，与模型step互斥
- 模型参数写入服务端限速 1ms/次，避免高频脚本拖慢定步长
- 报文追踪缓冲区（`g_traceBuffer`）与UI日志缓冲区（`g_uiLogBuffer`）各自独立加锁，JSON构建在锁外完成
- 高速TCP端口为每个连接派生独立线程，连接内串行处理命令
