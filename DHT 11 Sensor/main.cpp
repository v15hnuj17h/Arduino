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


//THE IMPROVED VERSION REGRADING TEMPERTURE AND HUMIDITY WARNING

// #include <DHT.h>

// #define DHTTYPE DHT11
// #define DHTPIN 2

// DHT dht(DHTPIN, DHTTYPE);

// // Flags to track if a warning has been shown
// bool tempWarningShown = false;
// bool humidWarningShown = false;

// void setup() {
//   Serial.begin(9600);
//   dht.begin();
//   Serial.println("Reading from DHT11 Sensor...");
// }

// void loop() {
//   delay(2000);

//   float temperature = dht.readTemperature();
//   float humidity = dht.readHumidity();

//   if (isnan(temperature) || isnan(humidity)) {
//     Serial.println("Error: Failed to read from DHT11 sensor!");
//     return;
//   }

//   // Check temperature condition
//   if (temperature > 40.0) {
//     if (!tempWarningShown) {
//       Serial.println("Warning: Temperature exceeds 40°C!");
//       tempWarningShown = true;
//     }
//     return; // Stop further execution for this loop
//   } else {
//     tempWarningShown = false; // Reset if back to normal
//   }

//   // Check humidity condition
//   if (humidity < 20.0) {
//     if (!humidWarningShown) {
//       Serial.println("Warning: Humidity is below 20%!");
//       humidWarningShown = true;
//     }
//     return; // Stop further execution for this loop
//   } else {
//     humidWarningShown = false; // Reset if back to normal
//   }

//   // Only print if no warning
//   Serial.print("Temperature: ");
//   Serial.print(temperature);
//   Serial.print(" °C\t");

//   Serial.print("Humidity: ");
//   Serial.print(humidity);
//   Serial.println(" %");
// }