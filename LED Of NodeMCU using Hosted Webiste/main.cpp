#include <ESP8266WiFi.h>

// Replace with your Wi-Fi credentials
const char* ssid = "realme 8 5G";
const char* password = "vishnujith";

WiFiServer server(80);

String ledStatus = "OFF";  // Initial status
const int ledPin = LED_BUILTIN; // Usually GPIO2 (D4 on NodeMCU)

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH); // Turn OFF LED initially (inverted logic)

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Wait until the client sends some data
  while (!client.available()) {
    delay(1);
  }

  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  // Handle request
  if (request.indexOf("/LED=ON") != -1) {
    digitalWrite(ledPin, LOW); // ON (inverted logic)
    ledStatus = "ON";
  }
  if (request.indexOf("/LED=OFF") != -1) {
    digitalWrite(ledPin, HIGH); // OFF (inverted logic)
    ledStatus = "OFF";
  }

  // Build web page
  String html = "<!DOCTYPE html><html><head><title>LED Control</title></head><body>";
  html += "<h2>NodeMCU LED Control</h2>";
  html += "<p>LED Status: <strong>" + ledStatus + "</strong></p>";
  html += "<a href=\"/LED=ON\"><button>Turn ON</button></a>";
  html += "<a href=\"/LED=OFF\"><button>Turn OFF</button></a>";
  html += "</body></html>";

  // Send response
  client.print("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");
  client.print(html);

  delay(1);
}

// Toggle

// #include <ESP8266WiFi.h>

// // Replace with your Wi-Fi credentials
// const char* ssid = "realme 8 5G";
// const char* password = "vishnujith";

// WiFiServer server(80);

// bool ledOn = false;
// const int ledPin = LED_BUILTIN; // GPIO2

// void setup() {
//   Serial.begin(115200);
//   pinMode(ledPin, OUTPUT);
//   digitalWrite(ledPin, HIGH); // LED OFF (active LOW)

//   WiFi.begin(ssid, password);
//   Serial.print("Connecting to WiFi");

//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }

//   Serial.println("\nWiFi connected");
//   Serial.print("IP address: ");
//   Serial.println(WiFi.localIP());

//   server.begin();
// }

// void loop() {
//   WiFiClient client = server.available();
//   if (!client) return;

//   while (!client.available()) {
//     delay(1);
//   }

//   String request = client.readStringUntil('\r');
//   Serial.println(request);
//   client.flush();

//   if (request.indexOf("/toggle") != -1) {
//     ledOn = !ledOn;
//     digitalWrite(ledPin, ledOn ? LOW : HIGH); // Toggle LED (active LOW)
//   }

//   String statusText = ledOn ? "ON" : "OFF";

//   // Web Page
//   String html = "<!DOCTYPE html><html><head><title>LED Toggle</title></head><body>";
//   html += "<h2>NodeMCU LED Control</h2>";
//   html += "<p>LED Status: <strong>" + statusText + "</strong></p>";
//   html += "<a href=\"/toggle\"><button>Toggle LED</button></a>";
//   html += "</body></html>";

//   client.print("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");
//   client.print(html);

//   delay(1);
//   Serial.println("Client disconnected");
// }
