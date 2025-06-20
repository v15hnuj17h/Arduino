# Capacitive Soil Moisture Sensor with Arduino Uno

This project reads the soil moisture level using a **capacitive soil moisture sensor (v1.2)** connected to an Arduino Uno and turns on the onboard LED when the soil moisture drops below a certain threshold.

---

## Components Required

- Arduino Uno
- Capacitive Soil Moisture Sensor v1.2
- USB cable for programming Arduino
- Soil and pot for testing

---

## Wiring

| Sensor Pin       | Arduino Pin |
|------------------|-------------|
| Analog Output (A0) | A0          |
| VCC              | 3.3V or 5V  |
| GND              | GND         |

The onboard LED of Arduino Uno is connected internally to pin 13.

---

## Code Explanation

- The sensor reads analog values between approximately **225 (wet soil)** and **455 (dry soil)**.
- The code maps these values to a moisture percentage between 0% and 100%.
- When the moisture percentage drops below **50%**, the onboard LED turns ON, indicating the soil is dry.
- Moisture percentage and raw sensor values are printed to the Serial Monitor every second.

---

## Usage

1. Upload the Arduino sketch to your Arduino Uno.
2. Open the Serial Monitor (baud rate 9600) to view moisture percentage readings.
3. Insert the sensor into the soil.
4. The onboard LED will turn on when moisture is below the threshold (50%).

---

## Arduino Code

```cpp
const int soilPin = A0;        // Soil moisture sensor connected to A0
const int ledPin = 13;         // Onboard LED pin
int soilValue = 0;             // Variable to store analog reading
int moisturePercent = 0;       // Moisture percentage

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  soilValue = analogRead(soilPin);

  // Map analog value to percentage (adjust based on your sensor's calibration)
  moisturePercent = map(soilValue, 455, 225, 0, 100);
  moisturePercent = constrain(moisturePercent, 0, 100);

  Serial.print("Moisture: ");
  Serial.print(moisturePercent);
  Serial.println("%");

  // Turn on LED if moisture < 50%
  if (moisturePercent < 50) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(1000);
}
