# ⚙️ Embedded System Real-Time Projects with PlatformIO + WOKWI Simulator 💡

## 🧩 Overview
This repository is a **collection of real-time embedded system projects** built using **PlatformIO** and simulated on **WOKWI**.  
It helps students and beginners **practice Arduino projects virtually** — no physical hardware needed!  
Each project demonstrates **core embedded concepts** such as sensors, actuators, displays, and user interaction.

---

## 🧰 Tools Used
| Tool | Purpose |
|------|----------|
| **Visual Studio Code** | Main development environment |
| **PlatformIO IDE Extension** | Build and debug Arduino projects |
| **WOKWI Simulator** | Online hardware simulation |

---

## 🧭 Getting Started

### Step 1: Install PlatformIO in VS Code
1. Open **Visual Studio Code**
2. Go to **Extensions → Search “PlatformIO IDE” → Install**
3. You’ll see an **Alien 👽 icon** — that’s your control panel for Arduino projects.

### Step 2: Link with WOKWI
1. Go to [https://wokwi.com](https://wokwi.com) → Create a free account.  
2. Design your circuit → Copy the **diagram.json**.
3. Paste it into your project folder in VS Code.  
4. Configure `wokwi.toml` (for linking your compiled `.hex` file).

### Step 3: Run the Simulation
- Open **diagram.json** in VS Code → Click the **▶️ Play** button.  
- Watch your Arduino circuit come alive virtually! ⚡

---

# 🕹️ Example Project: Virtual Pet Game 🐾

This is a **fun and interactive Arduino project** where you care for a virtual pet using **buttons**, **LEDs**, **buzzer**, and an **LCD display**.

### 🔹 Components Used
- LCD Display (I2C)
- Push Buttons (Start, Feed, Play)
- LEDs (Green, Blue, Red)
- Buzzer

### 🔹 How It Works
- Press **Start** to begin the game.  
- The pet’s **health** and **happiness** are tracked in real time.  
- **Feed** and **Play** buttons improve the pet’s stats.  
- LEDs show pet mood:
  - 🟢 Green → Happy  
  - 🔵 Blue → Okay  
  - 🔴 Red → Sad  
- If health gets too low, the **buzzer alerts** you to feed your pet!

### 🔹 Learning Outcome
This project teaches:
- Real-time state management  
- Digital input/output handling  
- LCD and buzzer control  
- Embedded logic design for interactive systems  

<img width="1920" height="1041" alt="Virtual Pet Game" src="https://github.com/user-attachments/assets/8ed0aa08-ea2a-4152-8a71-6fd19e1aa88f" />

---

# 2. Temperature Monitoring with Fire Alert 🌡️🔥
Uses a **DHT22 sensor** to measure temperature and displays it on an LCD.

- **Red LED + Buzzer** → Activate when temperature ≥ 45°C (Fire Alert)  
- **Green LED** → Indicates normal temperature  
- **LCD Display** → Shows real-time temperature and status  

*Learn sensor reading, LCD output, and warning system control in Arduino.*

<img width="1920" height="1042" alt="Fire Alarm System using DHT22 LCD LED Buzzer" src="https://github.com/user-attachments/assets/9513fc4e-e1b9-451a-a0fd-62ac0ec4d970" />

---

# 3. Car Reverse Parking Assistance System using Ultrasonic Sensor 📟🚘
To test this setup, I simulated a simple **Parking Assistance System** that detects the distance of nearby objects using an **ultrasonic sensor** and provides visual and sound alerts. 🚗📏🔊  

🔹 The **HC-SR04 ultrasonic sensor** measures the distance between the car and an obstacle.  
🔹 The **LCD display** shows messages like “Safe Distance”, “Object Nearby”, and “Object Very Close”.  
🔹 The **Yellow LED** lights up when an object is moderately close, and the **Red LED** with **buzzer** activates when it’s too close.  
🔹 The system updates the distance on the LCD every second for real-time feedback.  

This project helped me understand how to use **ultrasonic sensors** for object detection and create **real-world safety systems** like parking assistance. ⚙️📟🚘  

<img width="1920" height="1042" alt="car reverse parking assistance system using ultrasonic sensor" src="https://github.com/user-attachments/assets/4306a250-8f3a-4e45-b617-8510852665c9" />

---

# 4. Smart Environment & Obstacle Detection System using DHT22 and Ultrasonic Sensor 🌡️📏🔔
To test this setup, I simulated a **Smart Monitoring System** that measures **temperature** and **distance** using the **DHT22** and **HC-SR04** sensors. 

🔹 The **DHT22 sensor** reads real-time **temperature** data and displays it on the LCD.  
🔹 The **HC-SR04 ultrasonic sensor** measures the **distance** to nearby objects.  
🔹 If the **temperature exceeds 35°C**, the **red LED** turns ON and the **buzzer** alerts high temperature.  
🔹 If an **object is detected within 10 cm**, the buzzer also activates, warning about proximity.  
🔹 The **LCD** shows both **temperature** and **distance** values with clear status indicators.  

This project helped me understand how to **combine multiple sensors** for smart environmental monitoring and obstacle detection — essential for IoT and safety-based embedded systems. ⚙️🌡️📟🚨  

<img width="1920" height="1043" alt="Smart Weather and Object Alert System using DHT22" src="https://github.com/user-attachments/assets/88e9e125-7b7f-4376-b816-801994ea0e06" />

---

# 5. Smart Home Security System with PIR Sensor, LCD, LED, and Buzzer 🚨🏠📟 
To test this setup, I simulated a simple **Smart Home Security System** that detects motion using a **PIR sensor** and provides **visual and sound alerts** through an **LED**, **buzzer**, and **LCD display**. 

🔹 The **PIR sensor (pin 2)** detects human motion in the monitored area.  
🔹 When **motion is detected**, the **red LED (pin 13)** lights up, the **buzzer (pin 12)** sounds, and the LCD displays **“Motion Detected”**.  
🔹 When **no motion** is detected, the system shows **“Area Secure”**, turns off the LED, and silences the buzzer.  
🔹 The LCD provides **real-time status updates** for clear user feedback.  

This project helped me understand how to **integrate multiple components** — sensors, indicators, and displays — to build a **responsive and interactive home security system** using Arduino. ⚙️🧠🔔  


<img width="1920" height="1045" alt="Smart Home Security System with PIR sensor LCD LED BUZZER" src="https://github.com/user-attachments/assets/66393521-864f-427e-89ff-256446b026cd" />

---

# 6. Maze Control Game with Joystick and Dual Servos 🎮🌀⚙️  
To test this setup, I simulated a simple **Maze Control Game** using a **joystick module** and **two servo motors** to tilt a maze platform.  

🔹 The **joystick X-axis (A0)** controls the **Servo on pin 9**, tilting the maze **left and right**.  
🔹 The **joystick Y-axis (A1)** controls the **Servo on pin 10**, tilting the maze **forward and backward**.  
🔹 Moving the joystick changes the servo angles smoothly, allowing the ball on the maze to **roll in the desired direction**.  
🔹 The project demonstrates **analog input mapping**, **servo motor control**, and **real-time movement response**.  

This project helped me understand how to **integrate analog sensors with actuators** to create a **fun and interactive Arduino-based motion control game**. ⚙️🧠🎯  

<img width="1920" height="1046" alt="maze game with joystick and servo mortors" src="https://github.com/user-attachments/assets/e5b54d02-5205-4b05-9566-a60e75e6246a" />

<img width="1920" height="1046" alt="maze game with joystick and servo mortors" src="https://github.com/user-attachments/assets/50437703-7bc3-4d27-956e-c0334fd2efa6" />

---

# 7. Robotic Arm Control with Joystick and Dual Servos 🤖🕹️⚙️  
For this project, I built a simple **two-axis robotic arm** that is controlled using a **single joystick module**. The joystick smoothly moves two servo motors, allowing the arm to rotate and lift like a basic robotic system.

- 🔹 The **joystick X-axis (A0)** controls the **Servo on pin 9**, moving the arm **left and right**.  
- 🔹 The **joystick Y-axis (A1)** controls the **Servo on pin 10**, moving the arm **up and down**.  
- 🔹 Smooth servo motion is achieved by gradually updating the angle, giving the arm **slow and controlled movement**.  
- 🔹 The project demonstrates **analog sensor reading**, **servo angle mapping**, and **real-time motion control**.  

This project helped me understand how to **control multiple actuators using a single analog input**, creating a **simple and responsive Arduino-based robotic arm**. ⚙️🤖🎯  

<img width="1920" height="1037" alt="Robotic Arm with 2 Servo anf Joystick" src="https://github.com/user-attachments/assets/66a79cda-b450-472a-96c8-1eb1434511a0" />

---

# 8. Smart Car Parking System using Arduino 🚗🅿️⚙️  

For this project, I developed an **Arduino-based Smart Car Parking System** that automatically manages **vehicle entry, exit, and parking slot availability** using **ultrasonic sensors, servo motors, an IR sensor, LED indicator, and an I2C LCD display**.

- 🔹 **Ultrasonic Sensor (Entry Gate)** detects a vehicle within **5–10 cm** and opens the **entry gate servo** if parking slots are available.  
- 🔹 **Ultrasonic Sensor (Exit Gate)** detects exiting vehicles and opens the **exit gate servo**, updating the slot count correctly.  
- 🔹 **Servo Motors** act as **automatic barriers**, opening and closing with time-based control.  
- 🔹 **I2C LCD Display (16×2)** shows real-time messages such as **WELCOME**, **Car Entering**, **Car Exiting**, **Parking Full**, **Parking Empty**, and **Available Slots**.  
- 🔹 **IR Sensor with LED Indicator** detects nearby motion and turns the **LED ON for 2 seconds** as a visual alert.  
- 🔹 **Slot Management Logic** prevents:
  - Entry when parking is **FULL**
  - Exit errors using a **cooldown timer**
  - False sensor triggering using distance validation

This project helped me understand **sensor fusion**, **real-time decision making**, **servo-based automation**, and **smart parking management using Arduino**, simulating a **real-world embedded system solution**. 🚦📟🤖  

### 📸 Project Images – Smart Car Parking System

### 📸 Project Images – Smart Car Parking System

| 🚗 Entry & Exit Detection | 📟 LCD & Slot Status |
|--------------------------|----------------------|
| <img src="https://github.com/user-attachments/assets/9c7b02f1-0375-4e71-b0f6-6d2d49fb355f" width="800" height="450"/> | <img src="https://github.com/user-attachments/assets/52b567fc-646e-4a05-b57c-612a3270798e" width="800" height="450"/> |

| 🔦 IR Sensor & LED | ⚙️ Complete System View |
|-------------------|------------------------|
| <img src="https://github.com/user-attachments/assets/f8fa13e7-7699-4a5a-ae63-f3a97d2d40aa" width="800" height="450"/> | <img src="https://github.com/user-attachments/assets/fd14945d-4a13-40b6-80e1-2db305e1e62a" width="800" height="450"/> |

---

## 🧑‍💻 Author
**Nadeeshana Lahiru Kavinda**  
📍 Software Specialize Student, Dept of ICT, Faculty of Technology, South Eastern University of Sri Lanka.  
💻 *Embedded Systems | IoT | Software Development Enthusiast | Full Stack Developer*

[![LinkedIn](https://img.shields.io/badge/LinkedIn-Nadeeshana%20Lahiru-blue?style=flat-square&logo=linkedin)](https://www.linkedin.com/in/nadeeshana-lahiru-kavinda-991645244)

---

## 🏷️ License
This project is licensed under the [MIT License](./LICENSE.md) — see the file for details.

---

## 💬 Community
Have you tried creating your own embedded projects on **WOKWI**?  
Share your creations, improvements, or ideas — contributions are welcome! 💬  

---

## 🏁 Final Note
> “Simulation bridges the gap between imagination and innovation.” 🌟
