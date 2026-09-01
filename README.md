<p align="center">
  <h1 align="center">⚡ QC2015P 充电通信 HIL 测试平台</h1>
  <p align="center"><b>GB/T 27930-2024 标准 · 充电桩与车辆双端仿真 · 一键启动即用</b></p>
  <p align="center">
    <img src="https://img.shields.io/badge/标准-GB%2FT%2027930--2024-blue?style=flat-square" />
    <img src="https://img.shields.io/badge/平台-Windows%2010%2F11-blueviolet?style=flat-square" />
    <img src="https://img.shields.io/badge/后端-C%2B%2B-00599C?style=flat-square" />
    <img src="https://img.shields.io/badge/前端-Vue.js-42b883?style=flat-square" />
    <img src="https://img.shields.io/badge/许可证-MIT-green?style=flat-square" />
  </p>
</p>

---

## 🎬 演示视频

<p align="center">
  <a href="https://github.com/Miki-Hunter/QC2015P_Platform/releases">
    <img src="docs/screenshots/01-home.png" width="70%" alt="演示视频封面" />
    <br/>
    <b>▶️ 点击图片前往 Releases 页面下载演示视频</b>
  </a>
</p>

| 版本 | 分辨率 | 大小 | 说明 |
|:-----|:------:|:----:|:-----|
| `演示视频_compressed.mp4` | 1080p 60fps | 26 MB | 推荐，GitHub 可在线播放 |
| `演示视频.mkv` | 2K 120fps | 190 MB | 原始高清录制 |

---

## 📖 这是什么？

一句话：**一台电脑 + 一个 CAN 盒子，就能在实验室里完整模拟充电桩与电动汽车的充电通信全过程。**

```
┌──────────────────────────────────────────────────────────┐
│                    你的电脑（Windows）                      │
│                                                          │
│   ┌─────────────────────────────────────────────────┐    │
│   │            QC2015P 测试平台 (exe)                │    │
│   │                                                 │    │
│   │   ┌───────────┐       ┌───────────┐            │    │
│   │   │  SECC 模型 │       │  EVCC 模型 │            │    │
│   │   │ (充电桩端)  │       │ (车辆端)   │            │    │
│   │   └─────┬─────┘       └─────┬─────┘            │    │
│   │         └──────────┬────────┘                   │    │
│   │              CAN 总线通信                        │    │
│   └────────────────────┼────────────────────────────┘    │
│                        │ USB                             │
│              ┌─────────┴─────────┐                       │
│              │   ZLG USBCAN2     │                       │
│              │   CAN 收发器       │                       │
│              └───────────────────┘                       │
└──────────────────────────────────────────────────────────┘
```

### 🤔 为什么需要它？

| 传统方式 | 本平台 |
|---------|--------|
| 需要真实充电桩 + 真实车辆 | 一台电脑即可模拟双端 |
| 测试条件受限于硬件 | 任意修改参数，快速复现异常场景 |
| 无法回放历史报文 | 10 万条报文留存 + ASC/BLF 录制导出 |
| 每次改代码需重新编译固件 | Web 界面实时改参数，毫秒级生效 |
| 人工肉眼读报文 | DBC 自动解码信号，颜色区分一目了然 |

---

## 🌟 核心亮点一览

<table>
<tr>
<td width="50%" valign="top">

### 🚗🔌 双模型并行仿真
SECC（充电桩）和 EVCC（车辆）**同时运行**，各自独立 1ms 定步长，通过 CAN 总线实时通信，构成完整的充电闭环。

</td>
<td width="50%" valign="top">

### 📊 实时可视化
浏览器打开即用的 Web 界面，**参数实时读写**、**报文实时追踪**、**充电阶段实时指示**，所有状态一目了然。

</td>
</tr>
<tr>
<td width="50%" valign="top">

### 🔧 参数即改即生效
拖拽参数到画布，修改数值点击「应用」，**毫秒级生效**，无需重启、无需重新编译。

</td>
<td width="50%" valign="top">

### 🐍 Python 自动化测试
通过 HTTP API 控制，一行代码读写参数、读取报文，**轻松编写自动化测试脚本**。

</td>
</tr>
<tr>
<td width="50%" valign="top">

### 📝 报文录制与回放
支持 **ASC**（CANoe 可直接打开）和 **BLF**（Vector 二进制）两种格式录制导出，方便事后分析。

</td>
<td width="50%" valign="top">

### 🎨 深色 / 浅色主题
内置两套主题，**深色科技感**适合演示汇报，**浅色清爽**适合日常开发，一键切换。

</td>
</tr>
</table>

---

## 🖥️ 界面总览

### 主页

<p align="center">
  <img src="docs/screenshots/01-home.png" width="90%" alt="主页" />
  <br/><em>▲ 主页 — 选择进入 SECC（充电桩端）或 EVCC（车辆端）测试页面</em>
</p>

### SECC 页面（充电桩端）— 全貌

<p align="center">
  <img src="docs/screenshots/02-secc-full.png" width="90%" alt="SECC 页面全貌" />
  <br/><em>▲ SECC 页面 — 顶部充电阶段指示 + 左侧参数列表 + 中间参数画布 + 底部报文追踪</em>
</p>

### EVCC 页面（车辆端）— 全貌

<p align="center">
  <img src="docs/screenshots/03-evcc-full.png" width="90%" alt="EVCC 页面全貌" />
  <br/><em>▲ EVCC 页面 — 布局与 SECC 一致，参数和报文内容对应车辆端</em>
</p>

---

## 🔍 功能详解（配图说明）

### 1️⃣ 充电阶段实时指示

顶部导航栏实时显示当前充电阶段，颜色随阶段自动变化，**一眼识别充电进度**：

<p align="center">
  <img src="docs/screenshots/06-charging-phase.png" width="70%" alt="充电阶段指示" />
  <br/><em>▲ 顶部 SEQ 徽章 — 当前阶段「鉴权」，粉色背景</em>
</p>

充电全流程阶段颜色一览：

| 阶段 | SEQ 值 | 颜色 |
|:-----|:------:|:----:|
| 初始值 | 0 | 🩶 灰色 |
| 版本协商 | 1 | 🩵 青色 |
| 功能协商 | 2~202 | 💙 蓝色 |
| 参数配置 | 203~302 | 💜 紫色 |
| **鉴权** | **303~402** | **💗 粉色** |
| 预约充电 | 403~502 | ❤️ 玫红 |
| 输出回路检测 | 503~602 | 🧡 橙色 |
| 供电模式 | 603~702 | 🟠 深橙 |
| 预充及能量传输 |703~777 | 💚 绿色 |
| 充电暂停 | 778~780 | 💛 黄色 |
| 充电中止 | 781~800 | ❤️ 红色 |
| 充电结束 | 801~900 | 🩵 青绿 |

### 2️⃣ 参数画布 — 拖拽编辑

从左侧参数列表拖拽参数到画布区域，即可**实时查看和修改**参数值：

<p align="center">
  <img src="docs/screenshots/04-canvas-detail.png" width="70%" alt="参数画布" />
  <br/><em>▲ 参数画布 — 拖拽参数卡片到画布，实时编辑值，灰色小字为备注说明</em>
</p>

**支持三种参数类型：**

| 类型 | 可编辑 | 说明 |
|:-----|:------:|:-----|
| 🔧 模型参数 | ✅ 可读写 | Simulink 模型内部变量，修改后立即生效 |
| 📡 DBC 信号 | 👁️ 只读 | CAN 报文中的信号值，自动从 DBC 文件解码 |
| 📊 Monitor 变量 | 👁️ 只读 | 模型输出的实时监控变量 |

**便捷操作：**
- 🖱️ **拖拽添加** — 从左侧列表拖到画布
- ✏️ **点击编辑** — 点击卡片上的值直接修改
- 📋 **全部应用** — 一键批量提交所有修改
- 💾 **导入/导出** — 画布配置保存为 JSON，下次直接加载
- 📌 **默认配置** — 预置常用参数，启动即显示

### 3️⃣ 报文追踪 — 15 色标识

CAN 报文实时追踪，**不同报文 ID 自动分配不同颜色**，快速区分：

<p align="center">
  <img src="docs/screenshots/05-trace-detail.png" width="90%" alt="报文追踪" />
  <br/><em>▲ 报文追踪 — 15 种颜色按 ID 自动分配，左侧色条 + ID 文字色 + 微弱背景色三层标识</em>
</p>

**15 色色板（按出现顺序循环）：**

| 🔴 红 | 🟠 橙 | 🟡 黄 | 🟢 黄绿 | 🟩 绿 | 🩵 青绿 | 🩵 青 | 💙 蓝 |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| #E53935 | #FF8A00 | #FFD400 | #8BC34A | #2E9E44 | #00A99D | #00BCD4 | #1E6FD9 |

| 💜 靛蓝 | 💟 紫 | 💗 品红 | 🌸 粉 | 🤎 棕 | 🩶 蓝灰 | 🏅 金 |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| #4A4FA5 | #8E4DB1 | #C2185B | #EF6CA0 | #8D6E63 | #78909C | #B8872E |

**核心能力：**
- 📦 **10 万条留存** — 后端 + 前端各保留 10 万条报文，虚拟滚动不卡顿
- 🔍 **实时过滤** — 按 ID 或名称快速筛选
- ⬆️ **上划回看** — 滚到顶部自动加载更早历史
- 🖱️ **点击解码** — 点击任意报文行，弹层显示 DBC 信号解码详情
- ⏱️ **报文周期** — 自动计算每条报文的发送周期

### 4️⃣ 录制与导出

<p align="center">
  <img src="docs/screenshots/10-recording.png" width="50%" alt="录制面板" />
  <br/><em>▲ 录制控制 — 选择 ASC 或 BLF 格式，一键开始/停止录制</em>
</p>

| 格式 | 说明 | 打开工具 |
|:-----|:-----|:---------|
| **ASC** | 文本格式，人类可读 | CANoe / CANalyzer 直接打开 |
| **BLF** | Vector 二进制格式，文件更小 | CANoe / CANalyzer / Python |

- SECC 和 EVCC **独立录制**，互不干扰
- 文件自动命名：`SECC_20260830_143022.asc`

### 5️⃣ 参数列表 — 三合一

<p align="center">
  <img src="docs/screenshots/09-param-list.png" width="40%" alt="参数列表" />
  <br/><em>▲ 参数列表 — 模型参数、DBC 信号、Monitor 变量三类统一展示</em>
</p>

- 🔧 **模型参数** — 按分类筛选，支持搜索，可编辑
- 📡 **DBC 信号** — 按报文分组，显示 TX/RX 方向和发送方
- 📊 **Monitor 变量** — 实时刷新，只读

### 6️⃣ 深色 / 浅色主题

<p align="center">
  <img src="docs/screenshots/07-dark-theme.png" width="45%" alt="深色主题" />
  &nbsp;&nbsp;
  <img src="docs/screenshots/08-light-theme.png" width="45%" alt="浅色主题" />
  <br/><em>▲ 左：深色主题（科技感，适合演示） | 右：浅色主题（清爽，适合日常）</em>
</p>

---

## 🏗️ 系统架构

```
┌─────────────────────────────────────────────────────────────────────┐
│                       浏览器 (Chrome / Edge)                         │
│                                                                     │
│   ┌──────────┐   ┌──────────┐   ┌──────────┐   ┌──────────┐       │
│   │  主页    │   │ SECC页面  │   │ EVCC页面  │   │  参数画布  │      │
│   │          │   │          │   │          │   │  报文追踪  │       │
│   └────┬─────┘   └────┬─────┘   └────┬─────┘   └──────────┘       │
│        └───────────────┼──────────────┘                             │
│                        │ HTTP API (JSON)                             │
└────────────────────────┼────────────────────────────────────────────┘
                         │
┌────────────────────────┼────────────────────────────────────────────┐
│                   C++ 后端 (QC2015P_HIL.exe)                         │
│                        │                                             │
│   ┌────────────────────┴────────────────────────────────────────┐   │
│   │                  HTTP Server (端口 9527)                      │   │
│   │   参数读写 │ DBC解码 │ 报文追踪 │ 脚本队列 │ 录制导出         │   │
│   └──────┬──────────────┬──────────────┬────────────────────────┘   │
│          │              │              │                             │
│   ┌──────┴──────┐ ┌─────┴──────┐ ┌────┴──────┐                     │
│   │  SECC 模型   │ │  EVCC 模型  │ │ CAN 驱动层 │                    │
│   │  CPU2 绑定   │ │  CPU4 绑定  │ │ZLG USBCAN2│                    │
│   │  1ms 定步长  │ │  1ms 定步长  │ │ 双通道收发 │                    │
│   └──────┬──────┘ └─────┬──────┘ └────┬──────┘                     │
│          │              │              │                             │
│   Simulink Coder  Simulink Coder   CAN 总线                        │
│   生成的 C++ 代码   生成的 C++ 代码   (通道0=SECC, 通道1=EVCC)       │
└─────────────────────────────────────────────────────────────────────┘
```

### 数据流简图

```
CAN 硬件 ──→ CAN 驱动 ──→ 报文缓冲区 ──→ 前端轮询显示
                │
                ├──→ DBC 信号解码 ──→ 前端参数更新
                │
                └──→ 长消息重组 ──→ PGI 完整报文 ──→ 前端显示

前端修改参数 ──→ HTTP API ──→ 模型内存写入 ──→ 下一毫秒生效
```

---

## 🚀 快速开始

### 📋 前置条件

| 依赖 | 说明 | 是否必需 |
|:-----|:-----|:--------:|
| **ZLG USBCAN2** | CAN 收发硬件 | ✅ |
| **Windows 10/11** | 操作系统 | ✅ |
| **Chrome / Edge** | 浏览器 | ✅ |

### ▶️ 使用步骤

本仓库提供的是**编译好的可执行程序**，无需编译环境，直接运行即可。

**第 1 步：下载**

从本仓库下载 `build` 文件夹，或从 [Releases](https://github.com/Miki-Hunter/QC2015P_Platform/releases) 页面下载打包好的压缩包。

**第 2 步：连接 CAN 硬件**

将 ZLG USBCAN2 插入 USB 口，确保驱动已安装。

**第 3 步：启动程序**

```
进入 build 文件夹，双击 QC2015P_HIL.exe
```

> ⚠️ 请确保 `build` 目录下所有文件（DLL、web 文件夹、model 文件夹、DBC 文件）保持完整，程序运行时需要读取这些资源。

**第 4 步：浏览器访问**

启动后在浏览器中打开：

| 页面 | 地址 | 说明 |
|:-----|:-----|:-----|
| 🏠 主页 | http://localhost:9527 | 导航入口 |
| 🔌 SECC | http://localhost:9527/secc.html | 充电桩端测试 |
| 🚗 EVCC | http://localhost:9527/evcc.html | 车辆端测试 |

---

## 🐍 Python 自动化测试（可选）

仓库已提供 Python 客户端库，无需额外依赖，开箱即用。

### 最简示例

```python
import sys
sys.path.insert(0, "docs")
from qc2015p_client import SECC_ValueSet, SECC_ValueGet, EVCC_ValueGet, MsgGet, connect

# 连接 CAN（双通道）
connect(baud=250000)

# 设置充电桩参数（一行搞定）
SECC_ValueSet("ChargeSta", 1)

# 读取车辆参数
val = EVCC_ValueGet("ChargeSta")
print(f"EVCC 充电状态: {val}")

# 读取 CAN 报文信号
soc = MsgGet(0x1836F456, "PGI05_K1")
print(f"SOC 值: {soc}")
```

### 常用 API 速查

| 函数 | 说明 | 示例 |
|:-----|:-----|:-----|
| `connect(baud)` | 连接 CAN 双通道 | `connect(baud=250000)` |
| `SECC_ValueSet(name, val)` | 设置 SECC 参数 | `SECC_ValueSet("ChargeSta", 1)` |
| `SECC_ValueGet(name)` | 读取 SECC 参数 | `SECC_ValueGet("ChargeSta")` |
| `EVCC_ValueSet(name, val)` | 设置 EVCC 参数 | `EVCC_ValueSet("ChargeSta", 1)` |
| `EVCC_ValueGet(name)` | 读取 EVCC 参数 | `EVCC_ValueGet("ChargeSta")` |
| `MsgGet(id)` | 读取完整报文信息 | `MsgGet(0x1836F456)` |
| `MsgGet(id, signal)` | 读取单个信号 | `MsgGet(0x1836F456, "PGI05_K1")` |
| `logging(state, ch, fmt)` | 录制控制 | `logging(1, ch=0, fmt=1)` |
| `get_trace(model)` | 获取报文追踪 | `get_trace("SECC")` |

> 📄 完整 API 文档请参阅 [docs/API.md](docs/API.md) | 脚本源码在 [docs/qc2015p_client.py](docs/qc2015p_client.py)

---

## 📁 文件结构

```
QC2015P_Platform/
│
├── 📂 build/                        ← 编译输出（可直接运行）
│   ├── QC2015P_HIL.exe              ← 主程序
│   ├── *.dll                        ← 运行时依赖（GCC / USBCAN / binlog）
│   ├── 27930_2024_MIX.dbc           ← DBC 信号定义文件
│   ├── 📂 web/                      ← 前端页面（已构建）
│   │   ├── index.html               ← 主页
│   │   ├── secc.html                ← SECC 页面
│   │   ├── evcc.html                ← EVCC 页面
│   │   └── assets/                  ← JS/CSS 资源
│   ├── 📂 model/                    ← Simulink 模型头文件
│   │   ├── secc/                    ← SECC 模型头文件
│   │   └── evcc/                    ← EVCC 模型头文件
│   └── 📂 Logger/                   ← 报文录制输出目录
│       └── canvas/                  ← 画布默认配置
│
├── 📂 docs/                         ← 文档、脚本与截图
│   ├── API.md                       ← HTTP API 参考文档
│   ├── qc2015p_client.py            ← Python 客户端库（零依赖）
│   ├── demo.py                      ← 演示脚本
│   └── screenshots/                 ← 界面截图（10 张）
│
├── 📄 README.md                     ← 本文件
└── 🎬 演示视频_compressed.mp4        ← 操作演示（1080p 60fps，26MB）
```

---

## 🔧 技术栈

<table>
<tr>
<td align="center" width="120">
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/cplusplus/cplusplus-original.svg" width="48"/><br/>
  <b>C++ 17</b><br/>后端核心
</td>
<td align="center" width="120">
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/vuejs/vuejs-original.svg" width="48"/><br/>
  <b>Vue.js 3</b><br/>前端界面
</td>
<td align="center" width="120">
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/vitejs/vitejs-original.svg" width="48"/><br/>
  <b>Vite 5</b><br/>构建工具
</td>
<td align="center" width="120">
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/python/python-original.svg" width="48"/><br/>
  <b>Python 3</b><br/>自动化脚本
</td>
<td align="center" width="120">
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/matlab/matlab-original.svg" width="48"/><br/>
  <b>Simulink</b><br/>模型设计
</td>
</tr>
</table>

| 层级 | 技术 | 说明 |
|:-----|:-----|:-----|
| **前端** | Vue.js 3 + Vite 5 | 响应式 SPA，深色/浅色主题 |
| **后端** | C++ 17 + MinGW-w64 | 高性能 HTTP 服务器，1ms 定步长 |
| **CAN** | ZLG USBCAN2 DLL | 双通道 CAN 收发 |
| **模型** | Simulink Coder | 自动生成 C++ 代码 |
| **协议** | GB/T 27930-2024 | 新国标充电通信协议 |
| **DBC** | CANdb++ 格式 | 信号定义，支持多路复用 |

---

## ❓ 常见问题

<details>
<summary><b>Q: 双击 exe 没反应？</b></summary>

请确保在命令行中运行，查看错误信息。常见原因：
1. 缺少 DLL — 确保 `build` 目录下所有 DLL 文件完整
2. 端口被占用 — 确保 9527 端口没有被其他程序占用
</details>

<details>
<summary><b>Q: CAN 连接失败？</b></summary>

确保**没有其他 CAN 软件**（如 CANoe、USBCAN 工具）正在使用同一设备。ZLG USBCAN2 不支持多软件同时打开。
</details>

<details>
<summary><b>Q: 参数修改不生效？</b></summary>

1. 确保点击了「**应用**」按钮
2. 确保对应的 **Enable** 参数已设置为 `true`
3. 确保模型正在运行（CAN 已连接）
</details>

<details>
<summary><b>Q: 浏览器页面空白？</b></summary>

1. 确保 `build/web` 目录完整
2. 确保程序已启动且没有报错
3. 尝试清除浏览器缓存后刷新
</details>

---

## 📄 相关文档

- [HTTP API 参考文档](docs/API.md) — 完整的 API 接口说明
- [Python 客户端库](docs/qc2015p_client.py) — 零依赖，直接 import 使用
- [Python 演示脚本](docs/demo.py) — 完整功能演示，`python demo.py` 即可运行

---

<p align="center">
  <b>⚡ QC2015P 本地平台 — 让充电通信测试变得简单 ⚡</b>
  <br/><br/>
  如有问题或建议，请联系项目维护者。
</p>
