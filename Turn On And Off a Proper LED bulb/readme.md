#  NodeMCU Relay Control via Serial Monitor

This project lets you control an AC-powered LED bulb using a **NodeMCU (ESP8266)** and a **relay module**, with commands sent through the **Serial Monitor** (Arduino IDE or PlatformIO).  

Type `ON` or `OFF` in the serial monitor to control the bulb.

---

##  Components Required

- NodeMCU (ESP8266)
- 1-Channel Relay Module (5V logic-compatible)
- AC LED bulb with holder and mains plug
- Jumper wires
- Breadboard (optional)
- Arduino IDE or PlatformIO

---

##  Safety Warning

> **Danger:** This project involves AC mains voltage (230V/110V). Make sure you understand the risks before connecting an AC bulb. If you're not experienced, ask for help from someone qualified.

---

##  Wiring

### NodeMCU to Relay

| NodeMCU Pin | Relay Module Pin |
|-------------|------------------|
| D1 (GPIO5)  | IN               |
| 3V3         | VCC              |
| GND         | GND              |

### Relay to AC Bulb

- **COM** → AC Live (from wall socket)
- **NO (Normally Open)** → Live wire to bulb
- **Neutral** → Directly to bulb from socket

---

### How to Use

- Connect all hardware as shown above.

- Upload the code using Arduino IDE or PlatformIO.

- Open Serial Monitor (Ctrl + Shift + M) at 9600 baud.

- Type ON to turn on the bulb, OFF to turn it off.

---


#  PlatformIO Setup for NodeMCU Relay Control

This guide helps you set up a PlatformIO project to control an AC LED bulb via a relay module using NodeMCU (ESP8266).



##  Project Structure

Organize your project folder like this:
project-folder/
├── src/
│ └── main.cpp
├── platformio.ini
└── README.md

---


- `src/main.cpp` — Your main Arduino sketch.
- `platformio.ini` — Project configuration file.
- `README.md` — Optional project documentation.

---

## ⚙️ platformio.ini Configuration

Create a `platformio.ini` file in the root of your project folder with this content:

```ini
[env:nodemcuv2]
platform = espressif8266
board = nodemcuv2
framework = arduino
monitor_speed = 9600
```

---

# Credits

## Project Author
- **Vishnujith**  
  B.Tech Student  
  Creator and primary developer of the NodeMCU Relay Control project.

## Thanks & Acknowledgments
- Arduino and PlatformIO communities for their excellent tools and support.
- Open-source developers and contributors whose code and libraries made this project possible.

## License
This project is licensed under the MIT License.  
Use at your own risk.



