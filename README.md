# ROS 2 Exploration Mobile Robot Framework

![ROS 2](https://img.shields.io/badge/ROS2-Humble-22314E?style=flat-square&logo=ros&logoColor=white)
![micro-ROS](https://img.shields.io/badge/Middleware-micro--ROS-00599C?style=flat-square)
![PlatformIO](https://img.shields.io/badge/IDE-PlatformIO-O58B00?style=flat-square&logo=platformio&logoColor=white)
![C++](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=flat-square&logo=c%2B%2B&logoColor=white)
![Hardware](https://img.shields.io/badge/Board-ESP32%20%2F%20L298N-E7352C?style=flat-square)

An ESP32-based mobile robot framework utilizing ROS 2 Humble, micro-ROS, and PlatformIO. Features motor direction calibration, firmware deployment, and teleoperation control integration.

---

## 🛠️ System Architecture & Tech Stack

| Layer | Technology / Component | Purpose & Function |
| :--- | :--- | :--- |
| **High-Level Framework** | ROS 2 Humble / linorobot2 | Robot navigation, kinematics, and teleoperation control |
| **Communication Layer** | micro-ROS (`micro_ros_agent`) | Bridge communication between ESP32 microcontroller and ROS 2 |
| **Microcontroller** | ESP32 | Embedded processor running C++ firmware for motor control |
| **Motor Driver** | L298N Driver Module | Dual H-Bridge motor controller for differential drive motors |
| **Development Environment**| PlatformIO / C++ | Embedded firmware compilation, calibration, and flashing |

---

## 🚀 Setup & Execution Workflow

### 1. Calibration via L298N Module
Perform motor calibration using PlatformIO to ensure motor rotation aligns correctly with standard robot kinematics, uploading code directly to the ESP32 board.

### 2. Upload Firmware_noimu to ESP32 Board
Once calibration is complete, upload the `Firmware_noimu` file to establish connection with the micro-ROS system for ROS 2 communication.

### 3. Run Teleop Keyboard for Robot Control
Execute the following command to control robot movement via keyboard:

```bash
ros2 run teleop_twist_keyboard teleop_twist_keyboard
```

### 4. Install Linorobot2 Framework
Clone and set up the `linorobot2` framework for mobile robot navigation and control:

```bash
git clone -b humble https://github.com/linorobot/linorobot2.git
```
---

<br>
<h3 align="center">Demonstration & Media</h3>
<br>
<div align="center">
  <table width="100%">
    <tr>
      <td align="center" width="33%" valign="top">
        <img height="260" alt="Actual Robot Prototype" src="https://github.com/user-attachments/assets/26dc39b0-cacc-4a80-b088-045dc406d707" />
        <br>
        <sub><i>Actual Robot Prototype</i></sub>
      </td>
      <td align="center" width="33%" valign="top">
        <img height="260" alt="Real Robot Test" src="https://github.com/user-attachments/assets/d39d7bfa-ddfa-4c18-951d-14b000701ea7" />
        <br>
        <sub><i>Real Robot Test: Controlling actual robot movement via teleop keyboard in ROS 2</i></sub>
      </td>
      <td align="center" width="33%" valign="middle">
        <h4>📁 Media Repository</h4>
        <p>Access complete test footage & photo archives:</p>
        <a href="https://drive.google.com/drive/u/1/folders/1T3-4MkC7d6NUzJjEYTvIWPL26tQI5V4o" target="_blank">
          <img src="https://img.shields.io/badge/Google_Drive-View_Media_Folder-4285F4?style=for-the-badge&logo=googledrive&logoColor=white" alt="Google Drive" />
        </a>
      </td>
    </tr>
  </table>
</div>
