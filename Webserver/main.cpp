#include <ESP8266WiFi.h>

// Replace with your network credentials
const char* ssid = "realme 8 5G";
const char* password = "vishnujith";

// Set web server port number to 80
WiFiServer server(80);

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi..");

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  // Print the IP address
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.print("NodeMCU IP Address: ");
  Serial.println(WiFi.localIP());

  // Start the server
  server.begin();
}

void loop() {
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {
    Serial.println("New Client.");
    String currentLine = "";

    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);

        // if you've gotten to the end of the line (received a newline character) and the line is blank, send a response
        if (c == '\n' && currentLine.length() == 0) {
          // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
          client.println("HTTP/1.1 200 OK");
          client.println("Content-type:text/html");
          client.println(); // End of headers

          // Web page content
          client.println("<!DOCTYPE html><html><head><title>Hello</title></head><body><h1>Hello, World!</h1></body></html>");

          break;
        }

        if (c == '\n') {
          currentLine = "";
        } else if (c != '\r') {
          currentLine += c;
        }
      }
    }

    delay(1); // Give the browser time to receive the data
    client.stop();
    Serial.println("Client Disconnected.");
  }
}
