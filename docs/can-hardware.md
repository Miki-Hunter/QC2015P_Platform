# CAN 硬件接口与支持矩阵（2026-11-14）

本文说明本次硬件接口变更、当前支持的全部设备，以及新增厂商的接入方式。

---

## 1. 本次变更概览

| 变更 | 内容 |
|---|---|
| 新增多厂商抽象库 | `vendor/canhw/`：CANHardwareCpp（.NET CAN.Hardware 的 C++ 移植，12 家厂商 / 23 个 Wrapper） |
| 新增适配层 | `src/can_canhw.cpp`：把 `canhw::IHardware` 适配为现有 `ICanDevice`，**不改 CanManager / 模型线程** |
| 新增 6 家设备 | `chuangxin`、`esd`、`ni`、`etas`、`intrepid`、`ebel` |
| 驱动总数 | 9（原有）+ 6（新增）= **15 款 device 键** |
| 线程/性能 | canhw 读线程绑定非模型核、优先级 `ABOVE_NORMAL`、空闲轮询 1ms；模型线程路径不变 |
| 构建 | 新增 `Makefile`：`obj/` 中间产物 + 并行/增量；全量 108s → 13s |
| 脚本复用 | `qc2015p_client.connect()` 支持 `QC2015P_*` 环境变量覆盖，同一脚本跨硬件台架直接运行 |

> 原有 9 个驱动（`zlg`/`zlgcanfd`/`pcan`/`vector`/`kvaser`/`slcan`/`tosun`/`toomoss`/`virtual`）
> **代码与行为均未改动**，ZLG 400U 修复、通道枚举、SLCAN、虚拟 CAN 全部保留。

---

## 2. 硬件抽象分层

```
模型线程 / HTTP API / DBC / 报文追踪
        │
   can_driver.h                薄封装（CAN_Connect / CAN_ReceiveFromChannel / ...）
        │
   CanManager                  通道状态 + 无锁 SPSC 环 + 专用 I/O 线程（src/can_device.h/.cpp）
        │
   ICanDevice                  统一驱动接口
        ├── 原生驱动（9 个）    can_zlg.cpp / can_zlgcanfd.cpp / can_peak.cpp / ...
        └── canhw 适配层        src/can_canhw.cpp → vendor/canhw（6 家）
```

### 2.1 `ICanDevice` 接口契约

| 方法 | 语义 |
|---|---|
| `open(devType, devIdx)` | 打开物理设备；`devType/devIdx` 语义由厂商解释 |
| `close()` | 关闭设备与所有通道 |
| `initChannel(ch, {baud, term})` | 配置并启动物理通道 |
| `clearBuffer(ch)` | 清空该通道收发缓冲 |
| `receive(ch, frames, maxCount)` | 非阻塞收帧（由 CanManager I/O 线程调用） |
| `transmit(ch, frames, count)` | 发送（由 CanManager I/O 线程调用，允许阻塞） |
| `channelCount()` | 设备物理通道数（`ch=all` 判定用） |
| `listChannels(...)` | 面板「刷新设备」的通道清单 |
| `channelsNeedOpen()` | 枚举是否需要先 `open()`（ZLG 等零副作用驱动返回 false） |

### 2.2 线程与数据流（1ms 定步长）

```
模型线程（1ms） ──入队──▶ TX 环 ──I/O线程──▶ device->transmit()（可阻塞）
模型线程（1ms） ◀─出队── RX 环 ◀──I/O线程── device->receive()
```

canhw 适配层的额外一跳只发生在**模型线程之外**：

```
canhw 读线程 --eventHandler--> 适配层 SPSC 环 --CanManager I/O 线程--> RX 环 --> 模型线程
```

- `eventHandler` 只收 `dir==1`（过滤 TX 回显），把 SocketCAN 高位标志拆回
  `id + externFlag + remoteFlag`；
- 回调只做无锁入环，绝不回调进 canhw Wrapper（其回调在内部锁内触发）；
- canhw 读线程通过 `SetWorkerAffinityMask(QcAuxAffinityMask())` 绑定非模型核，
  `SetWorkerPriority(THREAD_PRIORITY_ABOVE_NORMAL)`，空闲轮询 `SetReadIdleMs(1)`。

---

## 3. 支持硬件矩阵

> “实测”= 2026-11-14 在真实硬件上打开并跑通双模型；
> “代码级”= 编译/注册/无驱动优雅失败已验证，未接真机。

### 3.1 原生驱动（9 款）

| device | 品牌 / 型号 | 通道 | 驱动 DLL | devType / devIdx | 终端电阻 | 状态 |
|---|---|---|---|---|---|---|
| `zlg` | ZLG USBCAN2 / USBCAN_2E_U | 2 | USBCAN.dll | 4 / 21；devIdx=第 N 台 | 硬件 | **实测** |
| `zlgcanfd` | ZLG USBCANFD-100U/200U/400U/800U | 1/2/4/8 | zlgcan.dll + kerneldlls | 42/41/76/59 | **软件，默认开** | 400U 实测；200U/100U/800U 待回归 |
| `pcan` | PEAK PCAN-USB / USB Pro / FD 全系 | 1/2 | PCANBasic.dll（系统安装） | devType 忽略；devIdx=句柄偏移 | 硬件拨码 | **实测** |
| `vector` | Vector VN1610/1630/1640/1611/5610/5650… | 1/2/4… | vxlapi64.dll | devType=hwType；devIdx=hwIndex | 硬件 | 代码级 |
| `kvaser` | Kvaser Leaf/Mercury/EAGLE 全系 | 1/2… | canlib32.dll | 全局通道号 = devIdx+ch | 线缆 | 代码级 |
| `slcan` | CANable 等 SLCAN 适配器 | 1 | 纯 Win32 串口 | devType=COM 口号 | 无 | 代码级 |
| `tosun` | 同星 TSCAN TCANFD 系列 | 1~16 | libTSCAN.dll + libTSH.dll | 通道 0 基；devIdx=第 N 台 | **软件（120Ω）** | 代码级 |
| `toomoss` | TOOMOSS USB2CAN / USB2CANFD | 1/2 | USB2XXX.dll | 通道 0/1；devIdx=第 N 台 | **软件** | 代码级 |
| `virtual` | 无硬件虚拟双通道 | 2 | 无 | 全部忽略 | 无 | **实测** |

### 3.2 canhw 适配层（本次新增 6 家）

| device | 品牌 / 型号 | 通道 | 依赖 DLL | 设备寻址 | 波特率 | 终端电阻 | 状态 |
|---|---|---|---|---|---|---|---|
| `chuangxin` | 创芯 USBCAN-2A/2C、CANalyst-II（兼容 ZLG VCI） | 1/2 | ControlCAN.dll（随仓库 `kerneldlls/`） | devType=VCI device_type：3/4/20/21；devIdx=设备索引 | 50K~1M | 硬件 | 代码级（DLL 已随包） |
| `esd` | ESD NTCAN CAN 接口卡 | 1 | ntcan64.dll（系统安装） | channel 0 基 | 10K~1M | 硬件 | 代码级 |
| `ni` | NI-XNET | 1 | nixnet.dll（NI-XNET 驱动） | 接口名约定 `CAN1` / `CAN2`；devIdx 不适用 | 125K/250K/500K/1M | 硬件 | 代码级 |
| `etas` | ETAS BOA V2 | 1 | BOA 驱动（注册表定位） | channelIndex 按 CSI 枚举 | 125K/250K/500K/1M | 硬件 | 代码级 |
| `intrepid` | Intrepid neoVI | 1 | icsneo40.dll（系统安装） | channel 0~6 = HSCAN1~7 | 10K~1M | 硬件 | 代码级 |
| `ebel` | Eberspächer FlexCard | 1 | fcbase.dll（系统安装） | channel 0~7 = CC1~8 | 10K~1M | 硬件 | 代码级（**仅经典 CAN**） |

> 新增 6 家在本工程中统一按**经典 CAN**注册（GB/T 27930 为 250k 经典 CAN）。
> `vendor/canhw` 里的 FD Wrapper 保留但未接入；需要时在 `src/can_canhw.cpp`
> 增加 `CommProtocol::CANFD` 注册并在 `Makefile` 追加对应 `.o` 即可。

### 3.3 前端 / API / 脚本入口

- 前端 `CanPanel`：品牌下拉已包含 6 个新品牌，型号联动 `device/devType`；
  「刷新设备」走 `/api/can/channels`。
- API：`GET /api/can/devices` 返回 15 款；`GET /api/can/connect?device=...` 连接。
- Python/TestPanel 脚本：`connect(device="chuangxin", dev_type=4)`；
  或使用环境变量覆盖（见下）。

```bash
QC2015P_DEVICE=chuangxin QC2015P_DEVTYPE=4 QC2015P_BAUD=250000 \
    python scripts/SECC/ParametersConfiguration/TC_xxx.py
```

支持的覆盖变量：`QC2015P_DEVICE / BAUD / DEVTYPE / DEVIDX / TERM / CH /
SECC_PHYS / EVCC_PHYS`。**未设置时行为与旧版完全一致。**

---

## 4. 如何新增一家 canhw 厂商

以 `Acme` 为例：

1. **`src/can_canhw.cpp`**
   - `enum class CanhwVendor` 加 `Acme`；
   - `VendorName()` 加显示名；
   - `CreateHardware()` 加 `Factory::GetInstance(HardwareManufacturer::Acme, ...)`；
   - `ApplyConfig()` 把 `(devType, devIdx, physCh, baud, term)` 写入 `AcmeCANConfig`；
   - `ComputeChannelCount()` 给出通道数；
   - `EnsureCanhwRegistered()` 加 `Factory::Register(...)`；
   - 文件底部 `RegisterCanDevice("acme", ...)`。
2. **`Makefile`**
   - `CANHW_DIRS` 加 `vendor/canhw/src/acme`；
   - `CANHW_OBJS` 加 `AcmeApi.o`、`AcmeCanWrapper.o`（只编经典 CAN）。
3. **前端/文档**
   - `web/src/components/CanPanel.vue` 的 `BRANDS/MODELS/BRAND_HINTS` 增加品牌；
   - `web/src/qc/qcBlocks.js` 的连接积木下拉与 `devTypeGenerator` 增加型号；
   - 本文 3.2 表格、README 设备表、`docs/API.md` 同步。
4. 重新构建：`compile.bat`（双击）即可；新设备会出现在 `/api/can/devices`。

---

## 5. 已知限制

1. **canhw 的 ZLG/PEAK/Kvaser/Vector/Tosun/Toomoss 封装未启用**：
   为避免丢功能（ZLG 400U 修复、devIdx、通道枚举、SLCAN、虚拟 CAN），这些厂商继续使用原有原生驱动。
2. **6 家新增厂商均为经典 CAN**；FD 未暴露。
3. **NI 的 `devIdx` 不适用**：按接口名 `CAN1`/`CAN2` 寻址，接口名可在 NI MAX 中重命名。
4. **ESD/NI/ETAS/Intrepid/EbEl/创芯 无软件终端电阻**：`term` 记录提示后忽略。
5. **真机验证范围**：本次仅实测 `zlg`（USBCAN2）与 `pcan`（PEAK USB）；其余为代码级验证
   （注册、编译、无驱动时优雅失败）。接真机时建议按 `docs/API.md` 的 connect 参数逐款回归。
6. **ZLG 200U 回归**：`zlgcanfd` 已改为 `TYPE_CANFD + protocol=0`（400U 修复），
   200U/100U/800U 仍建议真机复测，详见 `docs/patch-zlgcanfd-400u.md`。
