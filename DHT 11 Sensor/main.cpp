#include <DHT.h>

// Define the DHT11 sensor type
#define DHTTYPE DHT11

// Define the pin where the data line is connected
#define DHTPIN 2  // For Arduino Uno: use pin 2; for NodeMCU: use D4 (GPIO2)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println("Reading from DHT11 Sensor...");
}

void loop() {
  // Wait a few seconds between readings
  delay(2000);

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Check if any reads failed
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT11 sensor!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C\t");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
}
