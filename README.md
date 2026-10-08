# UART Communication using AXI UART Lite and MicroBlaze

![FPGA](https://img.shields.io/badge/FPGA-Arty%20A7-blue)
![Vivado](https://img.shields.io/badge/Vivado-Design%20Suite-orange)
![Vitis](https://img.shields.io/badge/Vitis-IDE-red)
![MicroBlaze](https://img.shields.io/badge/Processor-MicroBlaze-green)
![UART](https://img.shields.io/badge/Communication-UART-purple)
![AXI](https://img.shields.io/badge/Bus-AXI4--Lite-yellow)

A MicroBlaze-based UART communication system implemented on an **Arty A7 FPGA** using **AXI UART Lite**, **Vivado IP Integrator**, and **Vitis**.

The system demonstrates serial communication between an FPGA and a PC terminal, including predefined message transmission and character reception with echo functionality.

---

## 📌 Project Overview

UART (Universal Asynchronous Receiver Transmitter) is one of the most widely used serial communication protocols in embedded systems.

In this project, the **MicroBlaze soft processor** controls the **AXI UART Lite** peripheral through an **AXI4-Lite interface**.

The AXI UART Lite peripheral communicates with a PC through the **USB-UART interface** available on the Arty A7 board.

### Communication Flow

```text
                FPGA
┌───────────────────────────────────────┐
│                                       │
│       ┌───────────────┐               │
│       │   MicroBlaze  │               │
│       │   Processor   │               │
│       └───────┬───────┘               │
│               │ AXI4-Lite             │
│               ▼                       │
│       ┌───────────────┐               │
│       │ AXI           │               │
│       │ Interconnect  │               │
│       └───────┬───────┘               │
│               │                       │
│               ▼                       │
│       ┌───────────────┐               │
│       │ AXI UART Lite │               │
│       └───────┬───────┘               │
│               │ UART                  │
└───────────────┼───────────────────────┘
                │
                ▼
        ┌─────────────────┐
        │   USB-UART      │
        │     Bridge      │
        └────────┬────────┘
                 │ USB
                 ▼
        ┌─────────────────┐
        │ PC / Terminal   │
        │ Tera Term /     │
        │ PuTTY           │
        └─────────────────┘
```
---
### 🎯 Objectives
- Understand UART serial communication.
- Implement UART communication using AXI UART Lite.
- Integrate a MicroBlaze soft processor in Vivado.
- Connect MicroBlaze to AXI UART Lite through AXI4-Lite.
- Develop an embedded C application using Vitis.
- Transmit a predefined message from FPGA to PC.
- Receive characters from the PC terminal.
- Echo received characters back to the terminal.
- Verify the complete UART TX/RX communication path.

---
### 🛠️ Hardware Requirements
- Arty A7 FPGA Board
- USB Cable
- PC/Laptop

---

### 💻 Software Requirements
- Xilinx Vivado Design Suite
- Vitis IDE
- Tera Term / PuTTY or another serial terminal

---

### ⚙️ System Specifications

| Parameter | Value |
|---|---|
| FPGA Board | Arty A7 |
| Processor | MicroBlaze |
| UART IP | AXI UART Lite |
| Communication Bus | AXI4-Lite |
| System Clock | 100 MHz |
| UART Baud Rate | 9600 bps |
| Data Width | 8 bits |
| Terminal | Tera Term / PuTTY |
