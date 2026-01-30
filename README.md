# 🚁 UAV Fleet Command System (CLI)

![C Build & Check](https://github.com/ahmetcann66/UAV-Fleet-Command-CLI/actions/workflows/ci.yml/badge.svg) ![Language](https://img.shields.io/badge/Language-C-blue) ![Platform](https://img.shields.io/badge/Platform-Windows%20%2F%20Linux-lightgrey) ![License](https://img.shields.io/badge/License-MIT-green)

## 📖 Overview
**UAV Fleet Command System** is a C-based simulation of a **Ground Control Station (GCS)** logic. This project focuses on **fleet management algorithms**, **telemetry tracking**, **collision avoidance**, and **tactical fire control systems**.

It allows the operator to command a swarm of UAVs (Unmanned Aerial Vehicles) simultaneously via a terminal interface, monitoring critical parameters like fuel, altitude, ammunition, and operational status for multiple units (TB2, AKINCI, AKSUNGUR).

## 🚀 Features (V3.0)
* **Multi-UAV Architecture:** Manage a mixed fleet containing **TB2**, **AKINCI**, and **AKSUNGUR** models simultaneously.
* **🎯 Fire Control System (FCS):** Model-specific armament logic.
    * **TB2:** MAM-L Smart Micro Munition
    * **AKINCI:** MAM-C High Precision Missile
    * **AKSUNGUR:** L-UMTAS Long Range Anti-Tank Missile
* **🛡️ Active Collision Avoidance:** **"Look-Ahead" algorithm** that scans the fleet's altitude data before any movement, preventing mid-air collisions.
* **🔒 Safety Interlocks:** Ground safety switches prevent firing while at 0m altitude.
* **🔄 Logistics & Maintenance:** Full "Sortie Reset" capability to refuel and rearm the fleet.
* **Real-Time Telemetry:** Monitor distinct fuel levels, altitude, ammo count, and status flags.

## 🛠️ Technical Implementation
This project demonstrates key Computer Engineering and Embedded Systems concepts:
* **Defensive Programming:** The system uses a `carpismaVarmi()` function to validate commands *before* execution.
* **State Management:** Tracks complex states (Altitude, Fuel, Ammo) for multiple objects instances.
* **Conditional Logic:** Implements role-based actions (e.g., only AKINCI fires MAM-C).
* **Memory Management:** Efficient handling of UAV instances via global structures.

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
=== UAV FLEET COMMAND SYSTEM (V3.0) ===
Selected UAV: AKINCI (Altitude: 5000m | Ammo: 8)
---------------------------------------
1. Switch UAV
2. Status Report
3. Ascend (+1000m)
4. Descend (-1000m)
5. FIRE MISSION (Atis Yap)
6. Fleet Status
7. Maintenance (Refuel & Rearm)
0. Exit

>>> AKINCI, 1 adet MAM-C fuzesi atisladi! HEDEF VURULDU. <<<
🗺️ Roadmap
[x] Multi-UAV Architecture (Struct Arrays)

[x] Basic Flight Controls & Telemetry

[x] Collision Avoidance System: Algorithm to prevent UAVs from sharing the same altitude coordinates.

[x] Fire Control System (FCS): Weapon selection and firing logic based on UAV model.

[x] Logistics Logic: Rearming and refueling algorithms.

[ ] Data Logging: Saving flight logs to .txt files (Black Box simulation).

[ ] Autonomous Mode: Auto-pilot features for specific mission profiles.

🤝 Contributing
Contributions are welcome! Please open an issue or submit a pull request for any improvements.

📄 License
This project is licensed under the MIT License.
