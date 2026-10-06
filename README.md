# ROS 2 Exploration Mobile Robot Framework

![ROS 2](https://img.shields.io/badge/ROS2-Humble-22314E?style=flat-square&logo=ros&logoColor=white)
![micro-ROS](https://img.shields.io/badge/Middleware-micro--ROS-00599C?style=flat-square)
![PlatformIO](https://img.shields.io/badge/IDE-PlatformIO-F58B00?style=flat-square&logo=platformio&logoColor=white)
![C++](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=flat-square&logo=c%2B%2B&logoColor=white)
![Hardware](https://img.shields.io/badge/Board-ESP32%20%2F%20L298N-E7352C?style=flat-square)
![License](https://img.shields.io/badge/License-Apache%202.0-blue?style=flat-square)

An ESP32-based differential-drive mobile robot built on **ROS 2 Humble**, **micro-ROS** and **PlatformIO**. This repository holds the firmware configuration for my own robot hardware (motors, encoders, IMU, PID tuning), the motor calibration step, and the teleoperation workflow.

> **Credit:** the firmware and libraries are based on the open-source [linorobot2_hardware](https://github.com/linorobot/linorobot2_hardware) project (Apache-2.0) by Juan Miguel Jimeno and contributors. See [What is mine vs. upstream](#-what-is-mine-vs-upstream).

---

## 🤖 What is mine vs. upstream

| | Source |
| :--- | :--- |
| Firmware core, sensor / motor / kinematics libraries (`lib/`), micro-ROS integration | **Upstream** — [linorobot2_hardware](https://github.com/linorobot/linorobot2_hardware) |
| Navigation stack and teleoperation | **Upstream** — [linorobot2](https://github.com/linorobot/linorobot2) |
| Robot configuration `config/custom/myrobot_config.h` — wheel diameter, wheel separation, encoder counts per revolution, motor RPM / voltage, PID gains, ESP32 pin mapping, IMU selection | **Mine** — measured and tuned for my hardware |
| PlatformIO environments (`platformio.ini`) for the ESP32 + L298N build and the board variant | **Mine** — adapted from upstream |
| Hardware assembly (ESP32, L298N driver, motors, encoders, wiring), bring-up and real-robot testing | **Mine** |

### Two hardware variants

| Folder | Configuration |
| :--- | :--- |
| `L298N/` | ESP32 dev board + **L298N** motor driver, GY-85 IMU (or `firmware_noimu` without IMU), serial micro-ROS transport, 65 mm wheels, 0.20 m wheel separation, 110 RPM motors on 12 V |
| `robot_board/` | Custom-pin board variant with **QMI8658** IMU + **AK09918** magnetometer, WiFi micro-ROS transport, 65 mm wheels, 0.25 m wheel separation, separately tuned PID and encoder counts |

> **WiFi credentials:** `robot_board/config/custom/myrobot_config.h` contains placeholders (`YOUR_WIFI_SSID` / `YOUR_WIFI_PASSWORD`). Replace them locally before building and do not commit real values. Also set `AGENT_IP` to the IP address of the computer running the micro-ROS agent.

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
Once calibration is complete, upload the `L298N/firmware_noimu` project to establish connection with the micro-ROS system for ROS 2 communication.

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

---

## 📄 License & Credits

Released under the [Apache License 2.0](LICENSE), the same license as the upstream project.

- [linorobot/linorobot2_hardware](https://github.com/linorobot/linorobot2_hardware) — firmware and libraries this project is based on
- [linorobot/linorobot2](https://github.com/linorobot/linorobot2) — ROS 2 navigation framework
- [micro-ROS](https://micro.ros.org/) and [PlatformIO](https://platformio.org/)
