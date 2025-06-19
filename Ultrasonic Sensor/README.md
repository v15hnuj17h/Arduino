# Ultrasonic Sensor Distance Measurement with Arduino

This project uses an **HC-SR04 Ultrasonic Sensor** with an **Arduino** to measure distance in centimeters. The measured distance is printed to the Serial Monitor.

## 📦 Components Used

- Arduino UNO (or compatible)
- HC-SR04 Ultrasonic Sensor
- Jumper wires
- Breadboard (optional)

## 🔌 Wiring Connections

| HC-SR04 Pin | Arduino Pin |
|-------------|-------------|
| VCC         | 5V          |
| GND         | GND         |
| TRIG        | D5          |
| ECHO        | D6          |

> ⚠️ Note: Do not use the same pin for both TRIG and ECHO.

## 📟 How It Works

1. Arduino sends a 10µs HIGH pulse to the TRIG pin.
2. The sensor emits an ultrasonic wave.
3. When the wave reflects off an object and returns, the ECHO pin goes HIGH.
4. The duration of this HIGH signal is used to calculate the distance:
