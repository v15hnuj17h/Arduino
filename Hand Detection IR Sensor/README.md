# IR Sensor Hand Detection with NodeMCU

This project uses an **IR proximity sensor** with a **NodeMCU ESP8266** to detect when a hand is placed near the sensor and toggles an LED ON/OFF every second while the hand is detected.

---

## Components Required

- NodeMCU ESP8266 board
- IR Proximity Sensor (with digital output pin)
- LED
- 220Ω Resistor
- Jumper wires
- Breadboard (optional)

---

## Wiring Connections

| IR Sensor Pin | NodeMCU Pin  | Description            |
|---------------|--------------|------------------------|
| VCC           | 3.3V or 5V   | Power supply to sensor |
| GND           | GND          | Common ground          |
| D0 (Digital Output) | D5 (GPIO14) | IR sensor output signal |

| LED Pin       | NodeMCU Pin  | Description            |
|---------------|--------------|------------------------|
| Anode (+)     | D4 (GPIO2)   | LED positive through resistor |
| Cathode (-)   | GND          | LED negative to ground  |

*Note: Use a 220Ω resistor in series with the LED anode.*

---

## Code Overview

- The IR sensor digital output is connected to **D5** and read as an input.
- The LED is connected to **D4** and controlled by the NodeMCU.
- When the IR sensor detects a hand (sensor output LOW), the LED toggles ON or OFF every second.
- If no hand is detected, the LED remains off.

---

## Code Snippet

```cpp
#define IR_SENSOR_PIN D5
#define LED_PIN D4

void setup() {
  pinMode(IR_SENSOR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = digitalRead(IR_SENSOR_PIN);

  if (sensorValue == LOW) {
    if (digitalRead(LED_PIN) == LOW) {
      digitalWrite(LED_PIN, HIGH);
    } else {
      digitalWrite(LED_PIN, LOW);
    }
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  delay(1000);
}
