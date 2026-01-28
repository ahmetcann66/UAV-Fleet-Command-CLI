# 🚁 UAV Fleet Command System (CLI)

![C Build & Check](https://github.com/ahmetcann66/UAV-Fleet-Command-CLI/actions/workflows/ci.yml/badge.svg) ![Language](https://img.shields.io/badge/Language-C-blue) ![Platform](https://img.shields.io/badge/Platform-Windows%20%2F%20Linux-lightgrey) ![License](https://img.shields.io/badge/License-MIT-green)

## 📖 Overview
**UAV Fleet Command System** is a C-based simulation of a **Ground Control Station (GCS)** logic. Unlike simple flight simulators, this project focuses on **fleet management algorithms**, **telemetry tracking**, and **state-machine based control systems**.

It allows the operator to command a swarm of UAVs (Unmanned Aerial Vehicles) simultaneously via a terminal interface, monitoring critical parameters like fuel, altitude, and operational status for multiple units (TB2, AKINCI, AKSUNGUR).

## 🚀 Features
* **Multi-UAV Architecture:** Manage a mixed fleet containing **TB2**, **AKINCI**, and **AKSUNGUR** models simultaneously.
* **Real-Time Telemetry:** Monitor distinct fuel levels, altitude, and status flags for each unit.
* **Fleet Management Core:** Switch between active UAVs using a centralized command dashboard.
* **Safety Protocols:** Logic safeguards against crashes (min altitude limits) and fuel exhaustion.
* **Cross-Platform:** Compatible with both Windows (`cls`) and Linux (`clear`) systems via preprocessor directives.

## 🛠️ Technical Implementation
This project demonstrates key Computer Engineering and Embedded Systems concepts:
* **Data Structures:** Usage of `struct` arrays to handle multi-object states (Fleet Logic).
* **Memory Management:** Efficient handling of UAV instances.
* **Control Flow:** Switch-case driven menu system simulating an avionics interface.
* **Modular Design:** Helper functions for display logic (`filoDurumu`) and flight mechanics.

## 💻 How to Run

### 1. Clone the Repository
```bash
git clone [https://github.com/ahmetcann66/UAV-Fleet-Command-CLI.git](https://github.com/ahmetcann66/UAV-Fleet-Command-CLI.git)
cd UAV-Fleet-Command-CLI
2. Compile
You can use any GCC compiler.

Bash
gcc main.c -o uav_system
3. Execute
Bash
# For Windows
uav_system.exe

# For Linux/Mac
./uav_system
📊 Simulation Preview
Plaintext
=== UAV FLEET COMMAND SYSTEM ===
Selected UAV: AKINCI
--------------------------------
1. Switch UAV
2. Status Report (Current Unit)
3. Ascend (+1000m, -5 fuel)
4. Descend (-1000m, -5 fuel)
...
🗺️ Roadmap
[x] Multi-UAV Architecture (Struct Arrays)

[x] Basic Flight Controls & Telemetry

[ ] Collision Avoidance System: Algorithm to prevent UAVs from sharing the same altitude coordinates.

[ ] Data Logging: Saving flight logs to .txt files (Black Box simulation).

[ ] Autonomous Mode: Auto-pilot features for specific mission profiles.

🤝 Contributing
Contributions are welcome! Please open an issue or submit a pull request for any improvements.

📄 License
This project is licensed under the MIT License.