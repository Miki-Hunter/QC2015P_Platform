<p align="center">
  <h1 align="center">⚡ QC2015P Charging Communication Protocol Local Test Platform</h1>
  <p align="center"><b>GB/T 27930.2-2024 Standard · Backward Compatible with GB/T 27930-2015 · Dual-end EVSE & EV Simulation · One-click Launch</b></p>
  <p align="center">
    <img src="https://img.shields.io/badge/Standard-GB%2FT%2027930.2--2024-blue?style=flat-square" />
    <img src="https://img.shields.io/badge/Compatible-GB%2FT%2027930--2015-9c27b0?style=flat-square" />
    <img src="https://img.shields.io/badge/Platform-Windows%2010%2F11-blueviolet?style=flat-square" />
    <img src="https://img.shields.io/badge/Backend-C%2B%2B-00599C?style=flat-square" />
    <img src="https://img.shields.io/badge/Frontend-Vue.js-42b883?style=flat-square" />
    <img src="https://img.shields.io/badge/License-MIT-green?style=flat-square" />
  </p>
</p>

<p align="center">
  <a href="README.md">🇨🇳 中文</a> | <b>🇬🇧 English</b>
</p>

---

## 🎬 Demo Video

<p align="center">
  <img src="演示视频.gif" width="850" alt="QC2015P Charging Communication HIL Test Platform Demo" />
</p>

<details>
<summary>📥 Download Original HD Video (1080p MP4)</summary>

Download the original recording from the [Releases](https://github.com/Miki-Hunter/QC2015P_Platform/releases) page.

</details>


## 📖 What Is This?

In one sentence: **A single PC + a CAN adapter can fully simulate the entire charging communication process between an EVSE (charger) and an EV in the lab.**

```
┌──────────────────────────────────────────────────────────┐
│                    Your PC (Windows)                      │
│                                                          │
│   ┌─────────────────────────────────────────────────┐    │
│   │            QC2015P Test Platform (exe)          │    │
│   │                                                 │    │
│   │   ┌───────────┐       ┌───────────┐            │    │
│   │   │  SECC Model│       │  EVCC Model│           │    │
│   │   │ (EVSE Side)│       │ (EV Side)  │           │    │
│   │   └─────┬─────┘       └─────┬─────┘            │    │
│   │         └──────────┬────────┘                   │    │
│   │              CAN Bus Communication              │    │
│   └────────────────────┼────────────────────────────┘    │
│                        │ USB                             │
│              ┌─────────┴─────────┐                       │
│              │   ZLG USBCAN2     │                       │
│              │   CAN Adapter      │                       │
│              └───────────────────┘                       │
└──────────────────────────────────────────────────────────┘
```

### 🤔 Why Do You Need It?

**In one line: it turns charging-communication testing from "you need a real car, a real charger and somebody staring at a screen" into "one PC, repeatable on demand, fully recorded".**

| The traditional way | With this platform |
|---------------------|--------------------|
| Assemble a real EVSE + real vehicle, then queue for a test bench | Both the charger and the vehicle are played by software on one PC |
| Reproducing an intermittent fault means booking the car and the charger again | Pull-the-plug, timeout, dropped-frame and other fault scenarios replay on demand — just change a parameter |
| Every test-condition change means recompile, reflash, restart | Edit it in the browser; effective in milliseconds, no downtime |
| After a failure, someone has to recall what was on screen | 100K communication records kept automatically, exportable anytime for review |
| Messages are raw hex and unreadable to humans | Auto-translated into named values (voltage / current / SOC), each message colour-coded |

> If all you want to know is "what's good about it" — **fewer people, less equipment, less time, and repeatable results.** The rest of this page covers the UI and usage.

---

## 🌟 Key Highlights

<table>
<tr>
<td width="50%" valign="top">

### 🚗🔌 One PC Plays Both Ends
The charger and the vehicle run **side by side** on the same PC, each advancing in 1ms steps and talking over a CAN cable — a complete charging session, start to finish.

</td>
<td width="50%" valign="top">

### 📊 Open a Browser and You're In
No client to install — open a URL and **change parameters, watch the messages, follow the charging progress**, with the current phase visible at a glance.

</td>
</tr>
<tr>
<td width="50%" valign="top">

### 🔧 Changes Take Effect Instantly
Drag a parameter onto the canvas, edit the value, click "Apply" — **effective in milliseconds**. No restart, and certainly no reflashing.

</td>
<td width="50%" valign="top">

### 🐍 If You Can Script, You Can Automate
Read/write parameters and read messages in one line of code — **hand the repetitive testing to a script** instead of clicking through the UI.

</td>
</tr>
<tr>
<td width="50%" valign="top">

### 📝 Recorded and Replayable End to End
Export the traffic as **ASC** (opens directly in CANoe) or **BLF**, ready for after-the-fact review, evidence, or analysis in your usual tools.

</td>
<td width="50%" valign="top">

### 🎨 Dark / Light Theme
Two built-in themes — **dark tech style** for demos, **light clean style** for daily development, switch with one click.

</td>
</tr>
<tr>
<td width="50%" valign="top">

### 🔄 Both Protocol Generations Supported
One model ships the **2024 national standard** and the **2015 legacy fast-charging protocol** — which one runs is negotiated between the two ends, and individual messages and signals can be overridden.

</td>
<td width="50%" valign="top">

### ⚡ Fast Enough for High-Frequency Testing
A scripted parameter change costs **≈0.3ms** (over a persistent connection to the internal high-speed command port), so thousands of automated cases won't slow the platform down.

</td>
</tr>
</table>

---

## 🔌 Backward Compatible with GB/T 27930-2015

**What it buys you**: one platform tests both the new national standard (2024) and the old one (2015). Combos like "new charger + old vehicle" no longer need different hardware or a different build — each side declares whether it supports the new protocol, the two ends negotiate which one to run, and all you do is tick a box in the UI.

Technically, one model ships both the 2024 (2015P) and 2015 protocol stacks, and **which flow actually runs is decided by negotiation between the two ends** — neither side picks unilaterally.

| Side | Switch | Default | Meaning |
|:-----|:-------|:-------:|:--------|
| EVSE side (SECC) | `SECC_2015P_Enable` | `true` | Whether **this end supports 2015P** (i.e. GB/T 27930.2-2024) |
| EV side (EVCC) | `EVCC_2015P_Enable` | `true` | same |

This is a **local capability flag, not a protocol selector**:

| Value | Behaviour of this end |
|:-----:|:----------------------|
| `true` (default) | Supports 2015P, **while remaining 2015-compatible**. Which flow runs depends on negotiation — even with both ends enabled, it may still fall back to the 2015 flow, for example when the **version number is below 2.0.0** |
| `false` | This end runs the **2015 protocol only** (2015P is itself backward compatible with 2015, so charging still works) |

> ⚠️ **If either end is set to `false`**, only two outcomes are possible: the whole session runs the 2015 flow, or charging fails.

### Supported 2015 Messages

| Side | Message Set | Per-message control |
|:-----|:------------|:--------------------|
| 🔌 SECC (EVSE) | `CHM` handshake · `CRM` recognition · `CRO` ready · `CML` params · `CCS` charging · `CST` stop · `CSD` statistics · `CEM` error | ✅ all 8 |
| 🚗 EVCC (EV) | `BHM` handshake · `BRO` ready · `BCL` demand · `BSM` monitoring · `BST` stop · `BSD` statistics · `BEM` error | ✅ all 7 |
| 🚗 EVCC (EV) | `BRM` recognition · `BCP` params · `BCS` status | ⚙️ Sent automatically by internal model logic (no dedicated enable parameter); payload still overridable per signal via SPN parameters |

> Transport-layer messages on both sides are grouped under the `TP_*` prefix.

📊 **Want to see the real thing?** The repository root ships a **sample recording** captured with this platform: [`向下兼容2015协议_V1.0.blf`](向下兼容2015协议_V1.0.blf) — a complete 2015 legacy-protocol charging session. Open it directly in CANoe / CANalyzer; no hardware required.

### Four Control Parameters per Message

Taking `CRM` as an example, every message marked ✅ above exposes the same four parameters — editable in the Web UI or from a Python script.

> **Naming convention** — every paired parameter in this project follows the `_SW` + `_Va` rule:
> `_SW` is the switch (boolean, **defaults to `false`**) and `_Va` is only consumed while `_SW` is `true`.
> In other words: **touch nothing and the internal state machine drives everything**; to let a script take over one specific point, set its `_SW` to `true` and supply the desired value in `_Va`.

| Parameter | Type | Default | Description |
|:----------|:-----|:-------:|:------------|
| `CRM_Enable_SW` | boolean | `false` | Manual takeover switch: when `true`, `CRM_Enable_Va` decides whether this message is transmitted; when `false` (default) the internal state machine controls it |
| `CRM_Enable_Va` | boolean | `false` | Manual enable value, effective only while `CRM_Enable_SW` is `true` |
| `CRM_Cycle_Va` | real | 250 | Transmit cycle (ms) |
| `CRM_Data_SW` | boolean | `false` | Data override switch: when `true` the payload is rewritten from the SPN parameters below; when `false` (default) the model's internal logic is used |

### Per-Signal Override (SPN Parameters)

With `CRM_Data_SW` on, every signal inside the message can be overridden individually — parameter names follow `SPN<number>_<MSG>_<signal>`, where `_SW` arms the override and `_Va` supplies the value:

```python
# Override the "BMS identification" signal in CRM, keep all other fields from model logic
SECC_ValueSetBatch({
    "CRM_Data_SW":                True,   # arm the data override
    "SPN2560_CRM_BMSIdentify_SW": True,   # arm this one signal
    "SPN2560_CRM_BMSIdentify_Va": 0x5A,   # write a custom value
})
```

This round of model updates adds **99** parameters on the SECC side and **180** on the EVCC side, spanning three levels of control: message level (enable / cycle / data override), signal level (per-field SPN override) and raw message injection.

### Raw Message Injection

Each side has a `DefineMsg_*` parameter group that injects an arbitrary extra message onto the bus (disabled by default):

| Parameter | Default | Description |
|:----------|:-------:|:------------|
| `SECC_DefineMsg_Enable` | `false` | Whether to inject |
| `SECC_DefineMsg_ID` | `405206102` | Message ID (including extended-frame flag) |
| `SECC_DefineMsg_Extended` | `1` | Extended frame (uint8: 1 = extended, 0 = standard) |
| `SECC_DefineMsg_Length` | `8` | DLC |
| `SECC_DefineMsg_Cycle` | `50` | Transmit cycle (ms) |

### Legacy Phases in the UI

The top SEQ badge also maps the 2015 protocol phases (SEQ 10~99); those labels carry an `(old)` suffix to distinguish them from the 2024 ones — see [Charging Phase Indicator](#1️⃣-real-time-charging-phase-indicator).

---

## 🖥️ Interface Overview

### Home Page

<p align="center">
  <img src="docs/screenshots/01-home.png" width="90%" alt="Home Page" />
  <br/><em>▲ Home — Select SECC (EVSE side) or EVCC (vehicle side) test page</em>
</p>

### SECC Page (EVSE Side) — Full View

<p align="center">
  <img src="docs/screenshots/02-secc-full.png" width="90%" alt="SECC Page Full View" />
  <br/><em>▲ SECC Page — Top: charging phase indicator + Left: parameter list + Center: parameter canvas + Bottom: message trace</em>
</p>

### EVCC Page (Vehicle Side) — Full View

<p align="center">
  <img src="docs/screenshots/03-evcc-full.png" width="90%" alt="EVCC Page Full View" />
  <br/><em>▲ EVCC Page — Layout matches SECC, parameters and messages correspond to the vehicle side</em>
</p>

---

## 🔍 Feature Details (With Screenshots)

### 1️⃣ Real-time Charging Phase Indicator

The top navigation bar displays the current charging phase in real-time, with colors changing automatically:

<p align="center">
  <img src="docs/screenshots/06-charging-phase.png" width="70%" alt="Charging Phase Indicator" />
  <br/><em>▲ Top SEQ badge — Current phase: "Authentication", pink background</em>
</p>

Full charging phase color map — **GB/T 27930.2-2024 (new protocol)**:

| Phase | SEQ Value | Color |
|:------|:---------:|:-----:|
| Initial | 0 | 🩶 Gray |
| Version Negotiation | 1 | 🩵 Cyan |
| Function Negotiation | 2~200 | 💙 Blue |
| Parameter Configuration | 201~300 | 💜 Purple |
| **Authentication** | **301~400** | **💗 Pink** |
| Reservation | 401~500 | ❤️ Rose |
| Output Circuit Detection | 501~600 | 🧡 Orange |
| Power Supply Mode | 601~700 | 🟠 Dark Orange |
| Pre-charge | 701~750 | 💚 Green |
| Energy Transfer | 751~777 | 🟢 Bright Green |
| Charging Pause | 778~780 | 💛 Yellow |
| Charging Termination | 781~800 | ❤️ Red |
| Charging Complete | 801~900 | 🩵 Teal |

**GB/T 27930-2015 (legacy protocol, labels carry an `(old)` suffix)**:

| Phase | SEQ Value | Color |
|:------|:---------:|:-----:|
| Handshake (old) | 10~29 | 🤎 Brown |
| Parameter Config (old) | 30~49 | 🩶 Blue Gray |
| Charging (old) | 50~59 | 🟩 Green |
| Charging Stopped (old) | 60~79 | ❤️ Red |
| Finished (old) | 80~99 | 🩵 Teal |

**Error / reconnect branches (shared by both protocols)**:

| Phase | SEQ Value | Color |
|:------|:---------:|:-----:|
| Waiting to reconnect/reboot | 1000 | 💟 Purple |
| Waiting to reboot | 1001 | 💜 Light Purple |
| Reboot waking up | 1008~1009 | 🩵 Sky Blue |
| Reboot timeout | 1010 | ❤️ Red |
| Reconnect/reboot forbidden | 1020 | 🤎 Dark Brown |

> Any SEQ value outside these ranges renders as `SEQ=xxx - Unknown(xxx)` on a gray background.

### 2️⃣ Parameter Canvas — Drag & Drop Editing

Drag parameters from the left list to the canvas area to **view and modify** values in real-time:

<p align="center">
  <img src="docs/screenshots/04-canvas-detail.png" width="70%" alt="Parameter Canvas" />
  <br/><em>▲ Parameter Canvas — Drag parameter cards to canvas, edit values in real-time, gray text shows notes</em>
</p>

**Three parameter types supported:**

| Type | Editable | Description |
|:-----|:--------:|:------------|
| 🔧 Model Parameters | ✅ Read/Write | **The test conditions you want to change** (voltage, current, enable switches…); effective immediately |
| 📡 DBC Signals | 👁️ Read-only | What is actually on the bus, **translated into named values and numbers** |
| 📊 Monitor Variables | 👁️ Read-only | Live internal state (charging progress, detection results, …) |

**Convenient Operations:**
- 🖱️ **Drag to Add** — Drag from left list to canvas
- ✏️ **Click to Edit** — Click values on cards to modify directly
- 📋 **Apply All** — Batch submit all modifications at once
- 💾 **Import/Export** — Save canvas configuration as JSON for next use
- 📌 **Default Config** — Pre-configured common parameters, shown on startup

### 3️⃣ Message Trace — 15-Color Identification

The charger and the vehicle exchange hundreds of messages per second (the trade term is "messages" / "frames"). This panel lists them live, **assigning each message its own colour** so you can tell at a glance who is talking:

<p align="center">
  <img src="docs/screenshots/05-trace-detail.png" width="90%" alt="Message Trace" />
  <br/><em>▲ Message Trace — 15 colors assigned by ID, with color bar + ID text + subtle background</em>
</p>

**Core Capabilities:**
- 📦 **100K Message Buffer** — Both backend and frontend retain 100K messages, virtual scrolling smooth
- 🔍 **Real-time Filtering** — Quick filter by ID or name
- ⬆️ **Scroll Up to Review** — Auto-load earlier history when scrolling to top
- 🖱️ **Click to Decode** — Click any message row to see DBC signal decode details
- ⏱️ **Message Period** — Auto-calculate send period for each message

### 4️⃣ Recording & Export

<p align="center">
  <img src="docs/screenshots/10-recording.png" width="50%" alt="Recording Panel" />
  <br/><em>▲ Recording Control — Select ASC or BLF format, one-click start/stop recording</em>
</p>

| Format | Description | Tool |
|:-------|:------------|:-----|
| **ASC** | Text format, human-readable | Open directly in CANoe / CANalyzer |
| **BLF** | Vector binary format, smaller files | CANoe / CANalyzer / Python |

### 5️⃣ Parameter List — Three in One

<p align="center">
  <img src="docs/screenshots/09-param-list.png" width="40%" alt="Parameter List" />
  <br/><em>▲ Parameter List — Model parameters, DBC signals, Monitor variables unified display</em>
</p>

### 6️⃣ Dark / Light Theme

<p align="center">
  <img src="docs/screenshots/07-dark-theme.png" width="45%" alt="Dark Theme" />
  &nbsp;&nbsp;
  <img src="docs/screenshots/08-light-theme.png" width="45%" alt="Light Theme" />
  <br/><em>▲ Left: Dark theme (tech style, for demos) | Right: Light theme (clean, for daily use)</em>
</p>

---

## 🏗️ System Architecture

In plain terms: **the browser handles "seeing" and "clicking", the C++ program does the "computing" and "communicating", and both charging models are built graphically in Simulink and turned into code automatically** — the division of labour:

```
┌─────────────────────────────────────────────────────────────────────┐
│                       Browser (Chrome / Edge)                        │
│                                                                     │
│   ┌──────────┐   ┌──────────┐   ┌──────────┐   ┌──────────┐       │
│   │   Home   │   │ SECC Page│   │ EVCC Page│   │  Canvas  │       │
│   │          │   │          │   │          │   │  Trace   │       │
│   └────┬─────┘   └────┬─────┘   └────┬─────┘   └──────────┘       │
│        └───────────────┼──────────────┘                             │
│                        │ HTTP API (JSON)                             │
└────────────────────────┼────────────────────────────────────────────┘
                         │
┌────────────────────────┼────────────────────────────────────────────┐
│                   C++ Backend (QC2015P_HIL.exe)                      │
│                        │                                             │
│   ┌────────────────────┴────────────────────────────────────────┐   │
│   │                  HTTP Server (Port 9527)                     │   │
│   │  Param R/W │ DBC Decode │ Trace │ Fast TCP 9528 │ Recording │   │
│   └──────┬──────────────┬──────────────┬────────────────────────┘   │
│          │              │              │                             │
│   ┌──────┴──────┐ ┌─────┴──────┐ ┌────┴──────┐                     │
│   │  SECC Model  │ │  EVCC Model │ │ CAN Driver│                    │
│   │  CPU2 Bound  │ │  CPU4 Bound  │ │ZLG USBCAN2│                   │
│   │  1ms Step    │ │  1ms Step    │ │ Dual Ch   │                    │
│   └──────┬──────┘ └─────┬──────┘ └────┬──────┘                     │
│          │              │              │                             │
│   Simulink Coder  Simulink Coder   CAN Bus                         │
│   Generated C++   Generated C++   (Ch0=SECC, Ch1=EVCC)             │
└─────────────────────────────────────────────────────────────────────┘
```

### Data Flow

In one line: **traffic arriving from the hardware is stored and shown to you, and also translated into parameter values; a parameter you edit in the UI lands in the model on the next millisecond.**

```
CAN Hardware ──→ CAN Driver ──→ Message Buffer ──→ Frontend Polling Display
                    │
                    ├──→ DBC Signal Decode ──→ Frontend Parameter Update
                    │
                    └──→ Long Msg Assembly ──→ PGI Complete Message ──→ Display

Frontend Param Edit ──→ HTTP API ──→ Model Memory Write ──→ Effective in 1ms
```

---

## 🚀 Quick Start

### 📋 Prerequisites

| Dependency | Description | Required |
|:-----------|:------------|:--------:|
| **ZLG USBCAN2** | CAN adapter hardware | ✅ |
| **Windows 10/11** | Operating system | ✅ |
| **Chrome / Edge** | Browser | ✅ |

### ▶️ Usage Steps

This repository provides **pre-compiled executables** — no build environment needed.

**Step 1: Download**

Download the `build` folder from this repository, or download the packaged archive from the [Releases](https://github.com/Miki-Hunter/QC2015P_Platform/releases) page.

**Step 2: Connect CAN Hardware**

Plug in ZLG USBCAN2 via USB, ensure drivers are installed.

**Step 3: Launch**

```
Enter the build folder, double-click QC2015P_HIL.exe
```

> ⚠️ Ensure all files in the `build` directory (DLLs, web folder, model folder, DBC file) remain intact — the program reads these resources at runtime.

**Step 4: Access in Browser**

After startup, open in browser:

| Page | URL | Description |
|:-----|:----|:------------|
| 🏠 Home | http://localhost:9527 | Navigation entry |
| 🔌 SECC | http://localhost:9527/secc.html | EVSE side testing |
| 🚗 EVCC | http://localhost:9527/evcc.html | Vehicle side testing |

---

## 🐍 Python Automation (Optional)

The repository includes a Python client library — zero dependencies, ready to use.

**What it buys you**: when you need **hundreds or thousands of repeated runs** (consistency cases, regression suites), nobody has to click through the UI each time — a few lines of Python let the platform change parameters, wait for states, read results and save records by itself. Simplest example below.

### Quick Example

```python
import sys
sys.path.insert(0, "docs")
from qc2015p_client import SECC_ValueSet, SECC_ValueGet, EVCC_ValueGet, MsgGet, connect

# Connect CAN (dual channel)
connect(baud=250000)

# Set EVSE parameter (one line)
SECC_ValueSet("ChargeSta", 1)

# Read vehicle parameter
val = EVCC_ValueGet("ChargeSta")
print(f"EVCC charging status: {val}")

# Read CAN message signal
soc = MsgGet(0x1836F456, "PGI05_K1")
print(f"SOC value: {soc}")
```

### Batch Writes (multiple parameters in one request)

```python
# Option 1 — one call, several parameters
# (example: switch to the 2015 protocol and force CHM on)
SECC_ValueSetBatch({
    "SECC_2015P_Enable": False,   # false = run the 2015 legacy protocol
    "CHM_Enable_SW": True,        # take manual control of CHM transmission
    "CHM_Enable_Va": True,        # force it on
})

# Option 2 — context manager, merged into a single request on exit
with BatchSet() as b:
    b.secc("ChargeSta", 1)
    b.secc("CC2", 3.5)
    b.evcc("MaxVoltage", 750)
```

### API Quick Reference

| Function | Description | Example |
|:---------|:------------|:--------|
| `connect(baud)` | Connect CAN dual channel | `connect(baud=250000)` |
| `disconnect()` | Disconnect CAN dual channel | `disconnect()` |
| `SECC_ValueSet(name, val)` | Set SECC parameter | `SECC_ValueSet("ChargeSta", 1)` |
| `SECC_ValueGet(name)` | Read SECC parameter | `SECC_ValueGet("ChargeSta")` |
| `EVCC_ValueSet(name, val)` | Set EVCC parameter | `EVCC_ValueSet("ChargeSta", 1)` |
| `EVCC_ValueGet(name)` | Read EVCC parameter | `EVCC_ValueGet("ChargeSta")` |
| `SECC_ValueSetBatch(dict)` | Batch-write SECC parameters | `SECC_ValueSetBatch({"CC2": 3.5})` |
| `EVCC_ValueSetBatch(dict)` | Batch-write EVCC parameters | `EVCC_ValueSetBatch({"CC2": 3.5})` |
| `MsgGet(id)` | Read full message info | `MsgGet(0x1836F456)` |
| `MsgGet(id, "Data")` | Read raw byte array | `MsgGet(0x1836F456, "Data")` |
| `MsgGet(id, signal)` | Read single signal | `MsgGet(0x1836F456, "PGI05_K1")` |
| `wait_params(name, expect, timeout)` | Wait until a parameter reaches a value | `wait_params("SECC_ChargeSta", 1)` |
| `poll_params(name, count, interval)` | Sample a parameter repeatedly | `poll_params("SECC_ChargeSta", 10, 0.1)` |
| `logging(state, ch, fmt)` | Recording control | `logging(1, ch=0, fmt=1)` |
| `rename_log(model, name)` | Rename a recording file (UTF-8 names OK) | `rename_log("SECC", "charge_test_1")` |
| `get_trace(model)` | Get message trace | `get_trace("SECC")` |
| `get_status()` | Get system status | `get_status()` |

> ⚡ `*_ValueSet` / `*_ValueGet` / `MsgGet` use the **persistent TCP connection on 127.0.0.1:9528** (≈0.3ms per operation), an order of magnitude faster than HTTP. If 9528 is unavailable they fall back to HTTP automatically — no script changes needed.

> 📌 Parameter names are the **field names exactly as shown in the Web UI parameter list** — no prefix added or stripped: pass `"ChargeSta"` for a field named `ChargeSta`, and the full name for fields that already carry it, such as `SECC_2015P_Enable`.

> 📄 Full API documentation: [docs/API.md](docs/API.md) | Source code: [docs/qc2015p_client.py](docs/qc2015p_client.py)

---

## 📁 File Structure

```
QC2015P_Platform/
│
├── 📂 build/                        ← Compiled output (run directly)
│   ├── QC2015P_HIL.exe              ← Main program
│   ├── *.dll                        ← Runtime dependencies (GCC / USBCAN / binlog)
│   ├── 27930_2024_MIX.dbc           ← DBC signal definition file
│   ├── 📂 web/                      ← Frontend pages (built)
│   │   ├── index.html               ← Home page
│   │   ├── secc.html                ← SECC page
│   │   ├── evcc.html                ← EVCC page
│   │   └── assets/                  ← JS/CSS resources
│   ├── 📂 model/                    ← Simulink model headers
│   │   ├── secc/                    ← SECC model headers
│   │   └── evcc/                    ← EVCC model headers
│   └── 📂 Logger/                   ← Message recording output
│       └── canvas/                  ← Canvas default config
│
├── 📂 docs/                         ← Documentation, scripts & screenshots
│   ├── API.md                       ← HTTP API reference
│   ├── qc2015p_client.py            ← Python client library (zero deps)
│   ├── demo.py                      ← Demo script
│   └── screenshots/                 ← UI screenshots (10 images)
│
├── 📄 README.md                     ← Chinese README
├── 📄 README_EN.md                  ← English README (this file)
├── 🎬 演示视频_compressed.mp4        ← Demo video (1080p 60fps, 26MB)
└── 📊 向下兼容2015协议_V1.0.blf       ← Sample recording of a 2015-protocol charging session (opens in CANoe)
```

---

## 🔧 Tech Stack

<table>
<tr>
<td align="center" width="120">
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/cplusplus/cplusplus-original.svg" width="48"/><br/>
  <b>C++ 17</b><br/>Backend Core
</td>
<td align="center" width="120">
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/vuejs/vuejs-original.svg" width="48"/><br/>
  <b>Vue.js 3</b><br/>Frontend UI
</td>
<td align="center" width="120">
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/vitejs/vitejs-original.svg" width="48"/><br/>
  <b>Vite 5</b><br/>Build Tool
</td>
<td align="center" width="120">
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/python/python-original.svg" width="48"/><br/>
  <b>Python 3</b><br/>Automation
</td>
<td align="center" width="120">
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/matlab/matlab-original.svg" width="48"/><br/>
  <b>Simulink</b><br/>Model Design
</td>
</tr>
</table>

| Layer | Technology | What it does (in plain words) |
|:------|:-----------|:------------------------------|
| **Frontend** | Vue.js 3 + Vite 5 | The UI you see and click in the browser — **no client install**, dark/light theme |
| **Backend** | C++ 17 + MinGW-w64 | The program that actually simulates and sends/receives frames, **advancing one step per millisecond** |
| **CAN** | ZLG USBCAN2 DLL | The hardware box that talks to real chargers / vehicles |
| **Model** | Simulink Coder | The charging logic of charger and vehicle, **built graphically and turned into code automatically** — no hand-written code |
| **Protocol** | GB/T 27930.2-2024 + GB/T 27930-2015 | Both generations of the national standard are supported |
| **DBC** | CANdb++ format | The message spec: **which bits are voltage, which are current** — the platform uses it to translate automatically |

---

## ❓ FAQ

<details>
<summary><b>Q: Double-clicking exe does nothing?</b></summary>

Try running from command line to see error messages. Common causes:
1. Missing DLLs — Ensure all DLL files in the `build` directory are intact
2. Port occupied — Ensure port 9527 is not used by another program

> Port 9528 (the high-speed command port) being occupied does not prevent startup — the program prints `[WARN] Fast port 9528 bind failed` and keeps running; the Python client falls back to HTTP automatically.
</details>

<details>
<summary><b>Q: CAN connection failed?</b></summary>

Ensure **no other CAN software** (e.g., CANoe, USBCAN tools) is using the same device. ZLG USBCAN2 does not support multiple software opening simultaneously.
</details>

<details>
<summary><b>Q: Parameter changes not taking effect?</b></summary>

1. Ensure you clicked the "**Apply**" button
2. Ensure the corresponding **Enable** parameter is set to `true`
3. Ensure the model is running (CAN connected)
</details>

<details>
<summary><b>Q: What does the <code>2015P_Enable</code> switch actually mean, and what happens if I turn it off?</b></summary>

It states **whether this end supports 2015P** (i.e. GB/T 27930.2-2024). It is a **capability flag**, not a protocol selector:

| Value | Behaviour of this end |
|:-----:|:----------------------|
| `true` (default) | Supports 2015P and remains 2015-compatible. Which flow runs is negotiated — it **still falls back to the 2015 flow when the version number is below 2.0.0** |
| `false` | This end runs the 2015 protocol only (2015P is backward compatible with 2015, so charging still works) |

Two things to keep in mind:

- Both ends being enabled (`true`) **does not guarantee the 2024 flow** — the negotiation result decides.
- **If either end is `false`**, the session either runs the 2015 flow or fails to charge.

Search for `2015P_Enable` in the Web UI parameter list, or change it from Python in one line:

```python
# make the EVSE end run the 2015 protocol only
SECC_ValueSetBatch({"SECC_2015P_Enable": False})
```
</details>

<details>
<summary><b>Q: Browser page is blank?</b></summary>

1. Ensure the `build/web` directory is complete
2. Ensure the program has started without errors
3. Try clearing browser cache and refreshing
</details>

---

## 📄 Related Documentation

- [HTTP API Reference](docs/API.md) — Complete API interface documentation
- [Python Client Library](docs/qc2015p_client.py) — Zero dependencies, import and use directly
- [Python Demo Script](docs/demo.py) — Full feature demo, run with `python demo.py`

---

<details>
<summary><b>📝 Changelog</b> (click to expand)</summary>

**2026-09-27 — Backward compatibility with GB/T 27930-2015**

- **Sample recording added**: `向下兼容2015协议_V1.0.blf` in the repository root — a real 2015 legacy-protocol charging session captured with this platform, openable directly in CANoe / CANalyzer without any hardware

- **Models updated**: SECC v1.503, EVCC v1.494
- **2015 protocol support**: 99 new parameters on the SECC side, 180 on the EVCC side, covering every 2015 message
  - SECC: `CHM` `CRM` `CRO` `CML` `CCS` `CST` `CSD` `CEM`
  - EVCC: `BHM` `BRM` `BCP` `BRO` `BCL` `BCS` `BSM` `BST` `BSD` `BEM`
- **2015P capability flag**: new `SECC_2015P_Enable` / `EVCC_2015P_Enable` (default `true`) stating **whether this end supports 2015P (2024)**; set to `false` and that end runs the 2015 protocol only. The two ends are independent, and the flow actually used is decided by negotiation
- **Per-message control**: every message exposes `<MSG>_Enable_SW` (manual transmit takeover) / `_Enable_Va` (manual enable value) / `_Cycle_Va` (cycle) / `_Data_SW` (data override)
- **Per-signal override**: new `SPN<number>_<MSG>_<signal>_SW` / `_Va` parameters for field-level payload rewriting
- **Raw message injection**: new `<SECC|EVCC>_DefineMsg_ID/Length/Enable/Extended/Cycle` parameter group
- **Phase display**: the top SEQ badge gained the legacy protocol mapping (SEQ 10~99), labels suffixed with `(old)`
- **High-speed TCP command port 9528**: script parameter I/O now uses a persistent connection at ≈0.3ms per operation (previously one HTTP thread spawn per call)
- **Python client**: added `SECC/EVCC_ValueSetBatch`, the `BatchSet` context manager, `wait_params`, `poll_params`, `rename_log`
- Build side: `compile.bat`'s objcopy step now weakens 5 additional symbols (`MultiWordAnd`, `uMultiWordShl`, `uMultiWordShr`, `rt_urand`, `rt_nrand`) to resolve link conflicts after the model update

> This update has been synced into the repository's `build/` folder — download and run directly. Python users should also refresh `docs/qc2015p_client.py`.

**Earlier versions**

- **2026-09-05** — Python client convenience wrappers (`SECC_ValueSet/Get` etc.), cross-model shared parameters via `shared_params.conf`
- **2026-08-19** — `ValueSet` switched to direct model write with server-side 1ms rate limiting; script command queue path removed
- **2026-08-18** — Charging phase indicator (SEQ badge) in the top nav
- **2026-08-17** — Thorough trace clearing, fixed table column widths, canvas default config files (`Logger/canvas/*.canvas`)
- **2026-08-16** — 100K-message trace buffer with virtual scrolling and scroll-up history; ASC/BLF dual-format export
- **2026-08-13** — Trace performance work (hex data strings, incremental rendering), frontend path fix
- **2026-08-09** — Automatic model code sync, auto-kill of the running instance before build, dual-stack listener fixing `localhost` latency (2387ms → 11.5ms), batch parameter writes
- **2026-08-07** — GBT27930 long-message reassembly (`LongMessageAssembler`), CAN FD 64-byte support
- **2026-08-06** — First release: dual model + 1ms fixed step + dual-channel CAN + Vue.js frontend

</details>

---

<p align="center">
  <b>⚡ QC2015P Local Platform — Making Charging Communication Testing Simple ⚡</b>
  <br/><br/>
  For questions or suggestions, please contact the project maintainer.
</p>
