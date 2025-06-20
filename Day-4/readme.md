# 🌱 Soil Moisture & Temperature-Humidity Monitor using Arduino

This project uses an Arduino board to monitor **soil moisture**, **temperature**, and **humidity**. An LED (active-low) turns on if the soil is too dry.

## 🛠️ Components Used

- Arduino Uno / Nano / Compatible board
- Soil Moisture Sensor (analog output)
- DHT11 Temperature & Humidity Sensor
- 10kΩ resistor (for DHT11 pull-up if needed)
- LED (active-low connection)
- Jumper wires
- Breadboard

## 📐 Circuit Connections

### Soil Moisture Sensor:
- **VCC** → 5V  
- **GND** → GND  
- **Analog Out** → A0  

### DHT11 Sensor:
- **VCC** → 5V  
- **GND** → GND  
- **DATA** → D2  

### LED (Active-Low):
- **Anode** → +5V (through 220Ω resistor)  
- **Cathode** → D7  

## 💻 Code Overview

- **Soil moisture** is read as an analog value and mapped to a percentage.
- **DHT11** provides temperature (°C) and humidity (%).
- If soil moisture is below 30%, the LED turns ON (LOW signal due to active-low setup).
- Data is printed to the Serial Monitor every 2 seconds.

## 🚀 How to Use

1. **Install DHT sensor library:**
   - Go to **Arduino IDE** → `Sketch` → `Include Library` → `Manage Libraries`
   - Search for **"DHT sensor library by Adafruit"** and install it.

2. **Upload Code:**
   - Open the provided `.ino` file in Arduino IDE.
   - Select your board and COM port.
   - Click **Upload**.

3. **Monitor Data:**
   - Open the **Serial Monitor** at **9600 baud** to view live data.

## 🧪 Calibration Note

You may need to adjust the `map()` function in the code based on your soil sensor’s dry/wet values:

```cpp
moisturePercent = map(soilValue, 455, 225, 0, 100);
