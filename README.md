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

---

## 🧠 System Architecture

The project consists of the following major components:

### 1. MicroBlaze Processor

MicroBlaze is a soft-core RISC processor implemented inside the FPGA fabric.

It executes the embedded C application responsible for:
- Sending the predefined UART message.
- Waiting for incoming characters.
- Reading received characters.
- Echoing received characters back to the terminal.

### 2. AXI4-Lite Interface
The MicroBlaze processor communicates with the UART peripheral through the AXI4-Lite memory-mapped interface.

### 3. AXI UART Lite
AXI UART Lite performs:
- Parallel-to-serial conversion for transmission.
- Serial-to-parallel conversion for reception.
- UART protocol handling.
- Communication with the USB-UART interface.

### 4. USB-UART Bridge
The USB-UART bridge converts the FPGA UART signals into a USB connection that appears as a virtual COM port on the PC.

### 5. PC Serial Terminal
A serial terminal such as Tera Term or PuTTY is used to:
- Receive transmitted messages.
- Send characters to the FPGA.
- Display echoed characters.
---
## 🔧 Vivado Hardware Design
The hardware system was created using Vivado IP Integrator.

### Main IP blocks
```
MicroBlaze
     │
     ▼
AXI Interconnect
     │
     ├──────────────► AXI UART Lite
     │
     └──────────────► Local Memory / BRAM
```

### Design Flow
1. Create a Vivado project.
2. Select the Arty A7 FPGA device.
3. Create a Block Design.
4. Add the MicroBlaze processor.
5. Add AXI UART Lite.
6. Add required memory and AXI infrastructure.
7. Run Block Automation.
8. Connect AXI interfaces.
9. Connect UART signals to the board interface.
10. Validate the design.
11. Generate HDL wrapper.
12. Run synthesis.
13. Run implementation.
14. Generate the bitstream.

The design was successfully synthesized for the Arty A7 target device.

---
## 💻 Vitis Software

After generating the hardware design, the hardware platform was exported to Vitis.
The application performs two main operations.

### Transmitted Message
```
Welcome to UART Communication
```
### Receive and Echo

The application waits for a character from the serial terminal and sends the received character back.

Example:
```
Enter a Character:

User Input:
A

Received Character : A
```
---

## 🧪 UART Verification

The UART communication was verified using a PC serial terminal.

### Test Case 1 — Transmission
FPGA → PC
```
Welcome to UART Communication
```
Result
```
PASS
```
The predefined message was successfully displayed on the terminal.

### Test Case 2 — Character Echo
PC → FPGA
```
ABC123
```
FPGA → PC
```
ABC123
```
Each received character was successfully echoed back through the UART interface.

### Result
```
PASS
```
The TX and RX paths were successfully verified.

## 📊 Resource Utilization
| Resource | Utilization |
|---|---:|
| LUT | 38 |
| FF | 46 |
| BRAM | 0 |
| DSP | 0 |

DSP utilization is zero because the application primarily performs serial communication and simple control operations rather than DSP or multiplication-heavy computation.

## 📈 Performance


| Parameter | Value |
|---|---:|
| System Clock | 100 MHz |
| UART Baud Rate | 9600 bps |
| Data Width | 8 bits |
| Estimated Throughput | ≈ 960 bytes/s |

## 🔍 UART Frame

For standard 8-bit UART communication:
```
┌───────┬──────────────┬────────┐
│ Start │   Data Bits  │ Stop   │
│  1 bit│    8 bits    │ 1 bit  │
└───────┴──────────────┴────────┘
```
Therefore:
```
Total = 1 + 8 + 1
      = 10 bits / character
```
For the word:
```
HELLO
```

there are 5 characters:
```
5 × 10 = 50 bits
```
## 🚀 Learning Outcomes
Through this project, the following concepts were explored:
- FPGA-based embedded systems
- MicroBlaze soft processors
- Vivado IP Integrator
- AXI4-Lite communication
- AXI UART Lite
- UART protocol
- Serial communication
- Vitis embedded software development
- FPGA hardware/software co-design
- Hardware verification
- Resource utilization analysis

## 🔮 Possible Future Improvements
The project can be extended with:
- Interrupt-driven UART communication
- FIFO-based UART buffering
- Higher baud rates
- UART-based sensor communication
- Command-line interface
- Multiple AXI peripherals
- AXI GPIO integration
- UART-controlled FPGA peripherals
- Custom AXI peripheral integration

## 👨‍💻 Author

Chinmay N. Yalawatti

Electronics & Communication Engineering

KLE Technological University, BVB Campus, Hubballi

## ⭐ Project

If you find this project useful for learning FPGA-based embedded systems, feel free to explore the repository. 
