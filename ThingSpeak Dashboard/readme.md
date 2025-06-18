# ESP8266 DHT11 Temperature & Humidity Logger to ThingSpeak

This project reads temperature and humidity data from a DHT11 sensor using an ESP8266 microcontroller and uploads the data to ThingSpeak cloud platform for IoT data monitoring.

---

## Components Needed

- ESP8266 development board (e.g., NodeMCU, Wemos D1 Mini)  
- DHT11 Temperature and Humidity Sensor  
- 4.7kΩ resistor (for pull-up on data line)  
- Jumper wires and breadboard (optional)  

---

## Wiring

| DHT11 Pin | ESP8266 Pin | Description                     |
|-----------|-------------|--------------------------------|
| VCC (1)   | 3.3V        | Power supply                   |
| Data (2)  | GPIO 2 (D4) | Data pin with 4.7kΩ pull-up   |
| GND (4)   | GND         | Ground                        |

**Note:** Place a 4.7kΩ resistor between the DHT11 Data pin and 3.3V for proper signal operation.

---

## Software Setup

### Libraries Required

- [ESP8266WiFi](https://github.com/esp8266/Arduino)  
- [DHT sensor library](https://github.com/adafruit/DHT-sensor-library)  
- [ThingSpeak](https://github.com/mathworks/thingspeak-arduino)  
- ESP8266HTTPClient (comes with ESP8266 core)

Install these via the Arduino Library Manager.

---

## ThingSpeak Setup

1. Create an account at [ThingSpeak](https://thingspeak.com/).  
2. Create a new channel.  
3. Add two fields named:  
   - Field 1: Temperature  
   - Field 2: Humidity  
4. Copy your **Channel Number** and **Write API Key** for use in the code.

---

## Code Configuration

Edit the following parameters in your code:

```cpp
const char* ssid = "YOUR_WIFI_SSID";           // Replace with your WiFi SSID
const char* password = "YOUR_WIFI_PASSWORD";   // Replace with your WiFi password

unsigned long channelNumber = YOUR_CHANNEL_ID; // Your ThingSpeak channel number
const char* writeAPIKey = "YOUR_WRITE_API_KEY"; // Your ThingSpeak Write API key
