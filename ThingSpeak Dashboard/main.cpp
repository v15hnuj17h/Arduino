#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <DHT.h>
#include <ThingSpeak.h>
#include <ESP8266HTTPClient.h>
// put function declarations here:
#define DHTPIN 2
#define DHTTYPE DHT11

const char *ssid = "realme 8 5G";
const char *password = "vishnujith";

unsigned long channelNumber = 2992785; // replace with your channel number
const char *writeAPIKey = "IOR1JU9FO2CAUM2O";
DHT dht(DHTPIN, DHTTYPE);

WiFiClient client;
void setup()
{
  Serial.begin(9600);
  dht.begin();
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi");
  ThingSpeak.begin(client);

  // put your setup code here, to run once:
}

void loop()
{
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    Serial.println("Temperature: " + String(temperature) + " °C");
    Serial.println("Humidity: " + String(humidity) + "%");

    // Set the fields before writing
    ThingSpeak.setField(1, temperature);
    ThingSpeak.setField(2, humidity);

    // Write both fields in one request
    int response = ThingSpeak.writeFields(channelNumber, writeAPIKey);

    if (response == 200) {
      Serial.println("Data sent to ThingSpeak");
    } else {
      Serial.println("Failed to send data to ThingSpeak. HTTP response code: " + String(response));
    }
  }
  delay(2000); // Wait 20 seconds before next read
}

// put function definitions here: