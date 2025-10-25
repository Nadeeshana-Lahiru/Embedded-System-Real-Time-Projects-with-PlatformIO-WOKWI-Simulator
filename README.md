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

### 2. Temperature Monitoring with Fire Alert 🌡️🔥
Uses a **DHT22 sensor** to measure temperature and displays it on an LCD.

- **Red LED + Buzzer** → Activate when temperature ≥ 45°C (Fire Alert)  
- **Green LED** → Indicates normal temperature  
- **LCD Display** → Shows real-time temperature and status  

*Learn sensor reading, LCD output, and warning system control in Arduino.*

<img width="1920" height="1042" alt="Fire Alarm System using DHT22 LCD LED Buzzer" src="https://github.com/user-attachments/assets/9513fc4e-e1b9-451a-a0fd-62ac0ec4d970" />

---

### 3. Car Reverse Parking Assistance System using Ultrasonic Sensor 📟🚘
To test this setup, I simulated a simple **Parking Assistance System** that detects the distance of nearby objects using an **ultrasonic sensor** and provides visual and sound alerts. 🚗📏🔊  

🔹 The **HC-SR04 ultrasonic sensor** measures the distance between the car and an obstacle.  
🔹 The **LCD display** shows messages like “Safe Distance”, “Object Nearby”, and “Object Very Close”.  
🔹 The **Yellow LED** lights up when an object is moderately close, and the **Red LED** with **buzzer** activates when it’s too close.  
🔹 The system updates the distance on the LCD every second for real-time feedback.  

This project helped me understand how to use **ultrasonic sensors** for object detection and create **real-world safety systems** like parking assistance. ⚙️📟🚘  

<img width="1920" height="1042" alt="car reverse parking assistance system using ultrasonic sensor" src="https://github.com/user-attachments/assets/4306a250-8f3a-4e45-b617-8510852665c9" />

---

### 3. Smart Environment & Obstacle Detection System using DHT22 and Ultrasonic Sensor 🌡️📏🔔
To test this setup, I simulated a **Smart Monitoring System** that measures **temperature** and **distance** using the **DHT22** and **HC-SR04** sensors. 

🔹 The **DHT22 sensor** reads real-time **temperature** data and displays it on the LCD.  
🔹 The **HC-SR04 ultrasonic sensor** measures the **distance** to nearby objects.  
🔹 If the **temperature exceeds 35°C**, the **red LED** turns ON and the **buzzer** alerts high temperature.  
🔹 If an **object is detected within 10 cm**, the buzzer also activates, warning about proximity.  
🔹 The **LCD** shows both **temperature** and **distance** values with clear status indicators.  

This project helped me understand how to **combine multiple sensors** for smart environmental monitoring and obstacle detection — essential for IoT and safety-based embedded systems. ⚙️🌡️📟🚨  

<img width="1920" height="1043" alt="Smart Weather and Object Alert System using DHT22" src="https://github.com/user-attachments/assets/88e9e125-7b7f-4376-b816-801994ea0e06" />

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
