# 🚁 UAV Fleet Command System (CLI)

<div align="center">
  <img src="https://dummyimage.com/1200x400/000/fff&text=UAV+Fleet+Command+System+-+V3.4" alt="Project Banner" width="100%" />
  <br/><br/>

  ![Language](https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c)
  ![Platform](https://img.shields.io/badge/Platform-Windows%20%2F%20Linux-lightgrey?style=for-the-badge&logo=linux)
  ![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)
  ![Version](https://img.shields.io/badge/Version-V3.4%20(Auto%20Pilot)-orange?style=for-the-badge)
</div>

---

## 🎯 Project Purpose
**UAV Fleet Command System** is a sophisticated C-based simulation designed to demonstrate the engineering logic behind a real-world **Ground Control Station (GCS)**. The primary goal is to simulate the tactical management of a mixed UAV swarm (**TB2, AKINCI, AKSUNGUR**) in a high-stakes terminal environment.

It goes beyond simple flight simulation by implementing critical aerospace software functions:
* **🗺️ Autonomous Mission Planner:** Executes sequential tasks (waypoints) using **Linked Lists**.
* **📼 Black Box (Flight Recorder):** Persistent logging of mission telemetry to local files.
* **📡 ISR & Radar Logic:** Stochastic target acquisition and locking mechanisms.
* **🛡️ Collision Avoidance:** Active altitude scanning algorithms to prevent mid-air crashes.

---

## 🛠️ Technologies & Tools Used

This project is built using core system programming tools to ensure performance and reliability.

| Category | Technologies |
| :--- | :--- |
| **Core Language** | ![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white) |
| **Data Structures** | **Linked Lists**, **Struct Arrays**, **Pointers** |
| **Memory Mgmt** | `malloc()`, `free()` (Dynamic Allocation) |
| **Version Control** | ![Git](https://img.shields.io/badge/git-%23F05033.svg?style=for-the-badge&logo=git&logoColor=white) |
| **Documentation** | ![Markdown](https://img.shields.io/badge/markdown-%23000000.svg?style=for-the-badge&logo=markdown&logoColor=white) ![Mermaid JS](https://img.shields.io/badge/Mermaid-FF3E00?style=for-the-badge&logo=mermaid&logoColor=white) |

---

## 📐 System Logic & Architecture

The following diagram illustrates the core decision-making loop, including the new **Autonomous Mission Planner**.

```mermaid
graph TD
    Start((Start)) --> Menu{Main Menu}
    
    %% Autonomous Logic
    Menu -- "9. Mission Planner" --> Queue[Add Tasks to Linked List]
    Queue --> Execute[Execute Mission Loop]
    Execute --> Step{Next Node?}
    Step -- Yes --> Action[Perform Task: Fly/Scan/Fire]
    Action --> Wait[Simulate Delay]
    Wait --> Free[Free Node Memory]
    Free --> Step
    Step -- No --> Done[Mission Complete]
    
    %% Manual Logic
    Menu -- "Manual Control" --> Man[Manual Flight/Fire/Scan]
    
    %% Logging Layer
    Action -.-> Log[💾 Write to Black Box .txt]
    Man -.-> Log
    
    Menu -- "0. Exit" --> Stop((Terminate))
    
    style Queue fill:#ccf,stroke:#333,stroke-width:2px
    style Execute fill:#ccf,stroke:#333,stroke-width:2px
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
1 Switch UAV: Cycle control between TB2, AKINCI, and AKSUNGUR.

5 FIRE MISSION: Launch ammunition (Requires Radar Lock).

8 RADAR SCAN: Scan the sector for targets.

9 MISSION PLANNER: Create an autonomous flight path.

Add waypoints (Ascend, Descend, Scan, Fire) to the queue.

Execute the chain automatically.

0 Exit: Close simulation and save logs.

🖥️ Example Output
Plaintext
=== UAV FLEET COMMAND (V3.4 - AUTO PILOT) ===
...
Secim: 9

--- GOREV PLANLAYICI (Kuyruk Olustur) ---
1. Yuksel Ekle
2. Alcal Ekle
3. Tara Ekle
...
Secim: 5 (BASLAT)

>>> OTONOM GOREV MODU BASLATILIYOR <<<

--- Gorev Adimi 1 Isleniyor ---
[AUTO] Yukselis komutu...
Irtifa: 1000m

--- Gorev Adimi 2 Isleniyor ---
[AUTO] Radar Taramasi...
[RADAR] Bolge taraniyor...
👨‍💻 Author
<div align="center">

Ahmet Can

</div>


📄 License
This project is licensed under the MIT License - see the LICENSE file for details.