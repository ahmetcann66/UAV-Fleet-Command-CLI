🚁 UAV Fleet Command System (CLI)
V3.3 – BLACK BOX EDITION
<div align="center"> <img src="https://dummyimage.com/1200x420/0b0f19/ffffff&text=UAV+Fleet+Command+System+%7C+V3.3+Black+Box+Edition" width="100%" />

<br/><br/>










</div>
📌 Overview

UAV Fleet Command System is a C-based command-line simulation that models the core operational logic of a modern Ground Control Station (GCS) used in military UAV operations.

The project focuses on decision-making, safety interlocks, mission flow, and logging, rather than graphics — mirroring real-world defense and embedded software systems.

🎯 Project Objectives

Simulate multi-UAV fleet management

Demonstrate ISR, Fire Control & Safety logic

Implement Black Box–style mission logging

Apply defensive programming principles

Serve as a portfolio-grade defense software project

🧠 Simulated UAV Platforms
UAV	Role
Bayraktar TB2	Tactical ISR / Precision Strike
AKINCI TİHA	Heavy Strike / Deep Mission
AKSUNGUR	Long-Endurance ISR
🧩 Core Features

📡 ISR & Radar Scan System

🎯 Fire Control System (FCS)

🛡️ Collision Avoidance Logic

⛔ Safety Interlocks

📼 Black Box (Flight Recorder)

🔁 Real-time UAV Switching

⛽ Fuel & Ammunition Management

🛠️ Technology Stack
Category	Technologies
Language	C
Compiler	GCC
Platform	Windows / Linux
Version Control	Git, GitHub
Documentation	Markdown
Diagramming	Mermaid
📐 System Architecture & Decision Flow
graph TD
    Start((System Start)) --> Menu{Main Menu}

    Menu -- Radar Scan --> Radar[ISR Sensor Scan]
    Radar -- Target Found --> Lock[TARGET LOCKED]
    Radar -- No Signal --> NoTarget[NO TARGET]

    Menu -- Fire Mission --> CheckLock{Target Locked?}
    CheckLock -- YES --> Fire[Missile Fired]
    CheckLock -- NO --> Safety[⛔ Safety Interlock]

    Menu -- Altitude Change --> Collision{Collision Risk?}
    Collision -- SAFE --> Move[Altitude Updated]
    Collision -- RISK --> Abort[⛔ Maneuver Blocked]

    Fire -.-> Log[📼 Black Box Log]
    Move -.-> Log
    Lock -.-> Log

    Menu -- Exit --> End((Shutdown))

    style Log fill:#e6e6fa,stroke:#333,stroke-width:2px
    style Safety fill:#ffcccc,stroke:#ff0000,stroke-width:2px
    style Abort fill:#ffcccc,stroke:#ff0000,stroke-width:2px

📂 Project Structure
UAV-Fleet-Command-CLI/
│
├── main.c                # Core application logic
├── ucus_kayitlari.txt    # Black Box flight logs (auto-generated)
├── README.md             # Project documentation
├── LICENSE               # MIT License

⚙️ Installation
Prerequisites

GCC or any standard C compiler

Windows or Linux terminal

Clone Repository
git clone https://github.com/ahmetcann66/UAV-Fleet-Command-CLI.git
cd UAV-Fleet-Command-CLI

Compile
gcc main.c -o uav_system

🎮 Usage
Run Application

Windows

uav_system.exe


Linux / macOS

./uav_system

🎛️ Control Menu
Key	Function
1	Switch UAV
2	Status Report
3	Ascend
4	Descend
5	Fire Mission
8	Radar Scan (ISR)
0	Exit System
🖥️ Sample CLI Output
=== UAV FLEET COMMAND SYSTEM | V3.3 BLACK BOX ===

       |
   ---=|=---
    \_|^|_/
     AKINCI

UAV: AKINCI | ALT: 5000m | AMMO: 8 | STATUS: LOCKED
-----------------------------------------------
[RADAR] Target detected and locked.
[FIRE] MAM-C missile launched.
[HIT] Target neutralized.

📼 Black Box Log Example

ucus_kayitlari.txt

[03-02-2026 14:30:10] SYSTEM STARTED
[03-02-2026 14:31:05] RADAR TARGET LOCKED (AKINCI)
[03-02-2026 14:31:12] FIRE MISSION SUCCESSFUL

🛣️ Roadmap (Next Versions)

🔄 V4.0 Modular Code Architecture

🛰️ Sensor Fusion Logic

📡 Data-Link Simulation

🧠 AI-Based Target Priority

🖥️ GUI (Optional)

🤝 Contribution

Contributions, suggestions, and improvements are welcome.
Fork the repository and submit a pull request.

👨‍💻 Author
<div align="center">

Ahmet Can BOZKURT
🎓 Information Systems & Technologies – 3rd Year
🛡️ Defense, UAV & Embedded Systems Enthusiast

</div>
📄 License

This project is licensed under the MIT License.
See the LICENSE file for details.
