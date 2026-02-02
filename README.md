Harika! Projen V3.3 seviyesine ulaştı. 📼 Artık sadece bir simülasyon değil, verileri kaydeden gerçek bir GCS (Ground Control Station) yazılımı oldu.

README dosyanı; yeni Kara Kutu (Black Box) özelliğini, Dosya İşlemlerini (File I/O) ve V3.3 sürüm notlarını içerecek şekilde güncelledim. Ayrıca Roadmap kısmındaki o kutucuğu da yeşil tikle işaretledim! ✅

Aşağıdaki metni kopyala, README.md dosyanın içindekileri sil ve bunu yapıştır.

Markdown
# 🚁 UAV Fleet Command System (CLI)

![C Build & Check](https://github.com/ahmetcann66/UAV-Fleet-Command-CLI/actions/workflows/ci.yml/badge.svg) ![Language](https://img.shields.io/badge/Language-C-blue) ![Platform](https://img.shields.io/badge/Platform-Windows%20%2F%20Linux-lightgrey) ![License](https://img.shields.io/badge/License-MIT-green)

## 📖 Overview
**UAV Fleet Command System** is a C-based simulation of a **Ground Control Station (GCS)** logic. This project focuses on **fleet management algorithms**, **telemetry tracking**, **collision avoidance**, and **tactical fire control systems**.

It allows the operator to command a swarm of UAVs (Unmanned Aerial Vehicles) simultaneously via a terminal interface, monitoring critical parameters like fuel, altitude, ammunition, and operational status for multiple units (TB2, AKINCI, AKSUNGUR).

## 🚀 Features (V3.3 - Black Box Update)
* **📼 Flight Data Recorder (Black Box):** Automatically logs all mission-critical events (takeoffs, firing sequences, errors, radar locks) to a persistent `ucus_kayitlari.txt` file with precise timestamps.
* **📡 Radar & ISR Module:** Implements a **"Search & Lock"** mechanic. Operators must detect targets via radar scans before the Fire Control System disengages its safety lock.
* **Multi-UAV Architecture:** Manage a mixed fleet containing **TB2**, **AKINCI**, and **AKSUNGUR** models simultaneously.
* **🎨 Visual Interface:** ASCII Art representations of each UAV model directly in the terminal dashboard.
* **🎯 Fire Control System (FCS):** Model-specific armament logic (MAM-L, MAM-C, L-UMTAS).
* **🛡️ Active Collision Avoidance:** **"Look-Ahead" algorithm** that scans the fleet's altitude data before any movement, preventing mid-air collisions.
* **🔒 Safety Interlocks:** Ground safety switches prevent firing while at 0m altitude or without a confirmed target lock.

## 🛠️ Technical Implementation
This project demonstrates key Computer Engineering and Embedded Systems concepts:
* **File I/O & Persistence:** Uses standard C library (`fopen`, `fprintf`) to append mission data to a text file, ensuring data survival after program termination.
* **Stochastic Algorithms:** Uses `rand()` and `<time.h>` to simulate unpredictable battlefield sensor data.
* **Defensive Programming:** The system uses a `carpismaVarmi()` function to validate commands *before* execution.
* **State Management:** Tracks complex states (Altitude, Fuel, Ammo, Lock Status) for multiple objects.

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
=== UAV FLEET COMMAND SYSTEM (V3.3) ===
       | 
   ---=|=---
    \_|^|_/    
    AKINCI-TIHA

Selected UAV: AKINCI (Altitude: 5000m | Ammo: 8) [KILITLI]
---------------------------------------
...
8. RADAR SCAN (Target Acquisition)

!!! TESPIT: Dusman zirhli araci tespit edildi! Kordinatlar kilitlendi. !!!
>>> AKINCI, 1 adet MAM-C fuzesi atisladi! HEDEF IMHA EDILDI. <<<

[INFO] Event logged to ucus_kayitlari.txt
📐 System Architecture (Logic Flow)
The following diagram illustrates the core logic loop, including the new Data Logging layer.

Kod snippet'i
graph TD
    A[Start System] --> B{Select Action}
    B -->|Option 1| C[Switch Active UAV]
    C --> V[Draw ASCII Art]
    B -->|Option 3/4| D{Collision Check?}
    D -- Yes --> E[Block Movement]
    D -- No --> F[Update Altitude & Fuel]
    B -->|Option 5| G{Target Locked?}
    G -- No --> H[Safety Lock Active]
    G -- Yes --> I[Fire Control System]
    I --> J{Ammo Check}
    J -- Has Ammo --> K[Fire Missile & Reset Lock]
    J -- Empty --> L[Warning: Out of Ammo]
    B -->|Option 8| M[Radar Scan logic]
    M --> N[Random Probability %50]
    
    %% Logging Layer
    F -.-> Z[Write to ucus_kayitlari.txt]
    K -.-> Z
    L -.-> Z
    N -.-> Z
🗺️ Roadmap
[x] Multi-UAV Architecture (Struct Arrays)

[x] Basic Flight Controls & Telemetry

[x] Collision Avoidance System

[x] Fire Control System (FCS)

[x] Radar & ISR System

[x] Data Logging: Saving flight logs to .txt files (Black Box simulation).

[ ] Autonomous Patrol Mode: Auto-pilot features for loitering missions.

🤝 Contributing
Contributions are welcome! Please open an issue or submit a pull request for any improvements.

📄 License
This project is licensed under the MIT License.
