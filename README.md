
# ขั้นตอนการทำงานของระบบ

กระบวนการปรับจูนและพัฒนาเฟิร์มแวร์ของหุ่นยนต์มีขั้นตอนดังนี้:

1. **Calibration ด้วย L298N Module**  
   ทำการปรับจูนมอเตอร์ให้หมุนไปในทิศทางที่ถูกต้องตามแกนมาตรฐานของหุ่นยนต์  
   โดยใช้ **PlatformIO** ในการอัปโหลดโค้ดลงบนบอร์ด **ESP32** เพื่อให้ระบบมอเตอร์ทำงานได้อย่างแม่นยำตามมาตรฐานสากล

2. **อัปโหลด Firmware_noimu ลงบอร์ด ESP32**  
   หลังจากการปรับจูนเสร็จสิ้น ให้ทำการอัปโหลดไฟล์ **`Firmware_noimu`**  
   เพื่อเชื่อมต่อกับระบบ **micro-ROS** สำหรับการสื่อสารกับ ROS2

3. **รัน teleop keyboard เพื่อควบคุมหุ่นยนต์**  
   ใช้คำสั่งต่อไปนี้เพื่อควบคุมการเคลื่อนที่ของหุ่นยนต์ผ่านคีย์บอร์ด:
   ```bash
   ros2 run teleop_twist_keyboard teleop_twist_keyboard
4. **ทำการลง framework linorobot2**
   ```bash
   git clone -b humble https://github.com/linorobot/linorobot2.git

<br>
<h3 align="center">📸 รูปภาพผลงานและการทดสอบระบบ (Demonstration)</h3>
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
        <h4>📁 คลังรูปภาพและคลิปเพิ่มเติม</h4>
        <p>ดูรูปถ่ายและวิดีโอการทดสอบทั้งหมดได้ที่:</p>
        <a href="https://drive.google.com/drive/u/1/folders/1T3-4MkC7d6NUzJjEYTvIWPL26tQI5V4o" target="_blank">
          <img src="https://img.shields.com/badge/Google_Drive-View_Media_Folder-4285F4?style=for-the-badge&logo=googledrive&logoColor=white" alt="Google Drive" />
        </a>
      </td>
    </tr>
  </table>
</div>
