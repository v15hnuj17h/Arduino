# 🌡️ DHT11 Sensor Data Reader using Arduino/NodeMCU

This project demonstrates how to interface a **DHT11 temperature and humidity sensor** with an **Arduino Uno** or **NodeMCU (ESP8266)**. The sensor readings are displayed on the **Serial Monitor** using Arduino IDE or PlatformIO.

---

## ✅ Features

- Reads **temperature (°C)** and **humidity (%)** every 2 seconds.
- Displays data in real-time via the Serial Monitor.
- Supports both Arduino Uno and NodeMCU boards.

---

## 🔧 Components Used

| Component         | Quantity |
|------------------|----------|
| DHT11 Sensor      | 1        |
| Arduino Uno / NodeMCU | 1    |
| Breadboard & Jumper Wires | 1 set   |
| 10kΩ Resistor (optional, for pull-up) | 1 |

---

## 🔌 Wiring Diagram

### 🟦 For Arduino Uno
- `DHT11 VCC` → 5V  
- `DHT11 GND` → GND  
- `DHT11 Data` → Digital Pin 2

### 🟦 For NodeMCU (ESP8266)
- `DHT11 VCC` → 3.3V  
- `DHT11 GND` → GND  
- `DHT11 Data` → D4 (GPIO2)

> 💡 *A 10kΩ pull-up resistor between VCC and Data pin is recommended for stable readings.*

---

## 📜 Code Overview

The code uses the **Adafruit DHT sensor library** to read data from the DHT11 sensor.

### 🔁 Loop Function
- Every 2 seconds, it reads temperature and humidity using `dht.readTemperature()` and `dht.readHumidity()`.
- If the sensor fails to provide data, an error message is printed.
- Otherwise, the readings are displayed on the Serial Monitor.

### 🧪 Sample Output
