#  NodeMCU ESP8266 Web Server - "Hello, World!"

This project demonstrates how to host a simple web server on a NodeMCU (ESP8266) using the Arduino IDE. The server connects to a WiFi network and displays a basic "Hello, World!" message on a web page.

---

##  Features

- Connects to a WiFi network
- Hosts a web server on port 80
- Displays "Hello, World!" on a web page when accessed via browser

---

##  Requirements

- NodeMCU (ESP8266)
- Arduino IDE
- ESP8266 Board Package (Install from Boards Manager)
- USB cable
- WiFi network credentials

---

##  Setup Instructions

1. **Install ESP8266 Board Package:**
   - In Arduino IDE: Go to `File > Preferences > Additional Board Manager URLs`
   - Add: `http://arduino.esp8266.com/stable/package_esp8266com_index.json`
   - Then go to `Tools > Board > Boards Manager` and install "esp8266".

2. **Connect Your NodeMCU to the PC**

3. **Upload the Code**
   - Open `NodeMCU_HelloWorld_WebServer.ino` (provided below)
   - Replace `YOUR_SSID` and `YOUR_PASSWORD` with your WiFi credentials
   - Select the correct board and port from `Tools`
   - Click `Upload`

4. **Open Serial Monitor**
   - Set baud rate to `115200`
   - Find and copy the IP address displayed

5. **Access the Web Server**
   - Open a browser and go to `http://<YOUR_NODEMCU_IP>`
   - You should see "Hello, World!" displayed.

---

##  Code

```cpp
#include <ESP8266WiFi.h>

const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi..");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.print("NodeMCU IP Address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    Serial.println("New Client.");
    String currentLine = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        if (c == '\n' && currentLine.length() == 0) {
          client.println("HTTP/1.1 200 OK");
          client.println("Content-type:text/html");
          client.println();
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
    delay(1);
    client.stop();
    Serial.println("Client Disconnected.");
  }
}
