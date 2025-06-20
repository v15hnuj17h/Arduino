#include <DHT.h>

// --- DHT11 Setup ---
#define DHTPIN 2         // DHT11 data pin connected to digital pin 2
#define DHTTYPE DHT11    // Define sensor type

DHT dht(DHTPIN, DHTTYPE);

// --- Soil Moisture Setup ---
const int soilPin = A0;    // Soil moisture sensor connected to A0
const int ledPin = 7;     // Onboard LED pin
int soilValue = 0;
int moisturePercent = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  dht.begin();             // Start DHT sensor
}

void loop() {
  // --- Soil Moisture Reading ---
  soilValue = analogRead(soilPin);
  moisturePercent = map(soilValue, 455, 225, 0, 100);
  moisturePercent = constrain(moisturePercent, 0, 100);

  Serial.print("Moisture: ");
  Serial.print(moisturePercent);
  Serial.print("%-----");

  // --- Temperature & Humidity Reading ---
  float temp = dht.readTemperature();    // Temperature in Celsius
  float hum = dht.readHumidity();        // Humidity

  // Check if any reads failed
  if (isnan(temp) || isnan(hum)) {
    Serial.println("Failed to read from DHT11 sensor!");
  } else {
    Serial.print("Temperature: ");
    Serial.print(temp);
    Serial.print("°C-----");

    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.println("%");
  }

  // --- LED Moisture Alert ---
  if (moisturePercent < 30) {
    digitalWrite(ledPin, LOW);
  } else {
    digitalWrite(ledPin, HIGH);
  }

  delay(2000); // Wait 2 seconds between reads
}
