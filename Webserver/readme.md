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
```


# NodeMCU ESP8266 DHT11 Web Server

This project creates a web server hosted on a NodeMCU (ESP8266) that reads temperature and humidity data from a DHT11 sensor and displays it on a webpage accessible over your local WiFi network.

## Features

- Displays live temperature and humidity readings
- Webpage auto-updates every 5 seconds using JavaScript
- Fully hosted on the NodeMCU with no external server required

## Hardware Requirements

- NodeMCU ESP8266 board
- DHT11 temperature and humidity sensor
- Jumper wires
- Breadboard (optional)

### Wiring

| DHT11 Pin | NodeMCU Pin |
|-----------|-------------|
| VCC       | 3V3         |
| GND       | GND         |
| DATA      | D4 (GPIO2)  |

## Software Requirements

- Arduino IDE
- ESP8266 board support installed
- Required libraries:
  - DHT sensor library by Adafruit
  - Adafruit Unified Sensor
  - ESP8266WiFi (included with ESP8266 board package)

## Arduino IDE Setup

1. Install the necessary libraries from Library Manager
2. Select the board: `NodeMCU 1.0 (ESP-12E Module)`
3. Connect the board via USB and choose the correct COM port
4. Replace WiFi credentials in the code with your own

## Code Overview

The ESP8266 serves two routes:

- `/` serves a basic HTML page with embedded JavaScript
- `/data` returns current temperature and humidity in JSON format

### Example Code

```cpp
#include <ESP8266WiFi.h>
#include <DHT.h>

const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

#define DHTPIN D4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  dht.begin();
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    String request = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        request += c;
        if (c == '\n') {
          if (request.indexOf("GET /data") >= 0) {
            float temp = dht.readTemperature();
            float hum = dht.readHumidity();
            client.println("HTTP/1.1 200 OK");
            client.println("Content-Type: application/json");
            client.println();
            client.print("{\"temperature\":");
            client.print(temp);
            client.print(",\"humidity\":");
            client.print(hum);
            client.println("}");
          } else {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-Type: text/html");
            client.println("Connection: close");
            client.println();
            client.println("<!DOCTYPE html><html><head><title>DHT11 Live Data</title>");
            client.println("<style>body{text-align:center;font-family:sans-serif;margin-top:50px;}</style>");
            client.println("</head><body>");
            client.println("<h1>DHT11 Sensor Readings</h1>");
            client.println("<p>Temperature: <span id='temp'>--</span> °C</p>");
            client.println("<p>Humidity: <span id='hum'>--</span> %</p>");
            client.println("<script>");
            client.println("function updateData() {");
            client.println(" fetch('/data').then(response => response.json()).then(data => {");
            client.println("   document.getElementById('temp').textContent = data.temperature.toFixed(1);");
            client.println("   document.getElementById('hum').textContent = data.humidity.toFixed(1);");
            client.println(" });");
            client.println("}");
            client.println("setInterval(updateData, 5000); updateData();");
            client.println("</script></body></html>");
          }
          break;
        }
      }
    }
    client.stop();
  }
}
