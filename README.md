# 🚁 UAV Fleet Command System (CLI)

<div align="center">
  <img src="https://dummyimage.com/1200x400/000/fff&text=UAV+Fleet+Command+System+-+V3.3" alt="Project Banner" width="100%" />
  <br/><br/>

  ![Language](https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c)
  ![Platform](https://img.shields.io/badge/Platform-Windows%20%2F%20Linux-lightgrey?style=for-the-badge&logo=linux)
  ![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)
  ![Version](https://img.shields.io/badge/Version-V3.3%20(Black%20Box)-orange?style=for-the-badge)
</div>

---

## 🎯 Project Purpose
**UAV Fleet Command System** is a sophisticated C-based simulation designed to demonstrate the engineering logic behind a real-world **Ground Control Station (GCS)**. The primary goal is to simulate the tactical management of a mixed UAV swarm (**TB2, AKINCI, AKSUNGUR**) in a high-stakes terminal environment.

It goes beyond simple flight simulation by implementing critical aerospace software functions:
* **📼 Black Box (Flight Recorder):** Persistent logging of mission telemetry to local files.
* **📡 ISR & Radar Logic:** Stochastic target acquisition and locking mechanisms.
* **🛡️ Collision Avoidance:** Active altitude scanning algorithms to prevent mid-air crashes.
* **🎯 Fire Control (FCS):** Weapon release protocols with embedded safety interlocks.

---

## 🛠️ Technologies & Tools Used

This project is built using core system programming tools to ensure performance and reliability.

| Category | Technologies |
| :--- | :--- |
| **Core Language** | ![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white) |
| **Compiler** | ![GCC](https://img.shields.io/badge/gcc-%23FFD43B.svg?style=for-the-badge&logo=gnu&logoColor=222222) |
| **Version Control** | ![Git](https://img.shields.io/badge/git-%23F05033.svg?style=for-the-badge&logo=git&logoColor=white) ![GitHub](https://img.shields.io/badge/github-%23121011.svg?style=for-the-badge&logo=github&logoColor=white) |
| **Documentation** | ![Markdown](https://img.shields.io/badge/markdown-%23000000.svg?style=for-the-badge&logo=markdown&logoColor=white) ![Mermaid JS](https://img.shields.io/badge/Mermaid-FF3E00?style=for-the-badge&logo=mermaid&logoColor=white) |
| **Environment** | ![Windows Terminal](https://img.shields.io/badge/Windows%20Terminal-%234D4D4D.svg?style=for-the-badge&logo=windows-terminal&logoColor=white) ![Linux Shell](https://img.shields.io/badge/Shell_Script-%23121011.svg?style=for-the-badge&logo=gnu-bash&logoColor=white) |

---

## 📐 System Logic & Architecture

The following diagram illustrates the core decision-making loop of the software, highlighting the **Safety Interlocks** and the **Data Logging** layer.

```mermaid
graph TD
    Start((Start)) --> Menu{Main Menu}
    
    %% Radar & ISR Logic
    Menu -- "8. Radar Scan" --> Radar[Stochastic Sensor Scan]
    Radar -- Target Found --> Lock[State: TARGET LOCKED]
    Radar -- Scan Empty --> Unlock[State: NO TARGET]
    
    %% Fire Control Logic
    Menu -- "5. Fire Mission" --> CheckLock{Target Locked?}
    CheckLock -- YES --> Fire[Fire Missile & Update Ammo]
    CheckLock -- NO --> Deny[⛔ Safety Lock Engaged]
    
    %% Navigation & Collision Logic
    Menu -- "3/4. Altitude" --> ColCheck{Collision Check}
    ColCheck -- Safe --> Move[Update Altitude & Fuel]
    ColCheck -- Risk --> Block[⛔ Collision Warning]
    
    %% Logging Layer
    Fire -.-> Log[💾 Write to ucus_kayitlari.txt]
    Move -.-> Log
    Lock -.-> Log
    
    Menu -- "0. Exit" --> Stop((Terminate))
    
    style Log fill:#f9f,stroke:#333,stroke-width:2px,color:#000
    style Deny fill:#ffcccc,stroke:#ff0000,stroke-width:2px
    style Block fill:#ffcccc,stroke:#ff0000,stroke-width:2px
⚙️ Installation
Prerequisites
You need a standard C compiler (like GCC) installed on your system.

1. Clone the Repository
Open your terminal and clone the project files:

Bash
git clone [https://github.com/ahmetcann66/UAV-Fleet-Command-CLI.git](https://github.com/ahmetcann66/UAV-Fleet-Command-CLI.git)
cd UAV-Fleet-Command-CLI
2. Compile the Code
Compile the source code using GCC:

Bash
gcc main.c -o uav_system
🎮 Usage
Running the Application
For Windows:

Bash
uav_system.exe
For Linux / macOS:

Bash
./uav_system
Controls
The system uses a numeric menu interface.

1 Switch UAV: Cycle control between TB2, AKINCI, and AKSUNGUR.

3 Ascend: Increase altitude by 1000m (Consumes Fuel).

5 FIRE MISSION: Launch ammunition (Requires Radar Lock).

8 RADAR SCAN: Scan the sector for targets (Required before firing).

0 Exit: Close the simulation and save the Black Box logs.

🖥️ Example Output / Screenshot
When you run the system, the CLI provides visual feedback (ASCII Art) and real-time telemetry.

Plaintext
=== UAV FLEET COMMAND SYSTEM (V3.3 - BLACK BOX) ===

       | 
   ---=|=---
    \_|^|_/    
    AKINCI-TIHA

Selected UAV: AKINCI (Altitude: 5000m | Ammo: 8) [KILITLI]
---------------------------------------
1. IHA Degistir
2. Durum Raporu
...
8. RADAR TARAMASI (ISR Scan)

Seciminiz: 8

[RADAR] Bolge taraniyor... Sinyal araniyor...
!!! TESPIT: Dusman zirhli araci tespit edildi! Kordinatlar kilitlendi. !!!

Seciminiz: 5

*** HEDEF KILITLENDI... FUSELAGE RELEASED ***
>>> AKINCI, 1 adet MAM-C fuzesi atisladi! HEDEF IMHA EDILDI. <<<
📼 Black Box Log Output
Content of the automatically generated ucus_kayitlari.txt:

Plaintext
[03-02-2026 14:30:10] [SISTEM] UAV Fleet Command System V3.3 Baslatildi.
[03-02-2026 14:31:05] [RADAR] AKINCI RADAR HEDEF TESPIT ETTI.
[03-02-2026 14:31:12] [ATIS] AKINCI MAM-C ATISLADI. Hedef Vuruldu.
👨‍💻 Author
<div align="center">

Ahmet Can

</div>

📄 License
This project is licensed under the MIT License - see the LICENSE file for details.