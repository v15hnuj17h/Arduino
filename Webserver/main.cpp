// #include <ESP8266WiFi.h>

// // Replace with your network credentials
// const char* ssid = "realme 8 5G";
// const char* password = "vishnujith";

// // Set web server port number to 80
// WiFiServer server(80);

// void setup() {
//   Serial.begin(115200);

//   // Connect to Wi-Fi
//   WiFi.begin(ssid, password);
//   Serial.print("Connecting to WiFi..");

//   while (WiFi.status() != WL_CONNECTED) {
//     delay(1000);
//     Serial.print(".");
//   }

//   // Print the IP address
//   Serial.println("");
//   Serial.println("WiFi connected.");
//   Serial.print("NodeMCU IP Address: ");
//   Serial.println(WiFi.localIP());

//   // Start the server
//   server.begin();
// }

// void loop() {
//   WiFiClient client = server.available();   // Listen for incoming clients

//   if (client) {
//     Serial.println("New Client.");
//     String currentLine = "";

//     while (client.connected()) {
//       if (client.available()) {
//         char c = client.read();
//         Serial.write(c);

//         // if you've gotten to the end of the line (received a newline character) and the line is blank, send a response
//         if (c == '\n' && currentLine.length() == 0) {
//           // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
//           client.println("HTTP/1.1 200 OK");
//           client.println("Content-type:text/html");
//           client.println(); // End of headers

//           // Web page content
//           client.println("<!DOCTYPE html><html><head><title>Hello</title></head><body><h1>Hello, My dear!</h1></body></html>");

//           break;
//         }

//         if (c == '\n') {
//           currentLine = "";
//         } else if (c != '\r') {
//           currentLine += c;
//         }
//       }
//     }

//     delay(1); // Give the browser time to receive the data
//     client.stop();
//     Serial.println("Client Disconnected.");
//   }
// }

//Temp And Humidity 

#include <ESP8266WiFi.h>
#include <DHT.h>

// Replace with your network credentials
const char* ssid = "realme 8 5G";
const char* password = "vishnujith";

// DHT setup
#define DHTPIN D4         // GPIO2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Start server on port 80
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  dht.begin();

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP Address: ");
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
          float h = dht.readHumidity();
          float t = dht.readTemperature(); // Celsius

          if (isnan(h) || isnan(t)) {
            Serial.println("Failed to read from DHT sensor!");
            client.println("HTTP/1.1 500 Internal Server Error");
            client.println("Content-type:text/html");
            client.println();
            client.println("<h1>Error reading from DHT sensor!</h1>");
          } else {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // Web Page with auto-refresh
            client.println("<!DOCTYPE html><html><head>");
            client.println("<meta http-equiv='refresh' content='5'>");
            client.println("<title>Temp & Humidity</title>");
            client.println("</head><body>");
            client.println("<h1>ESP8266 DHT11 Sensor</h1>");
            client.println("<p>Temperature: " + String(t) + " &deg;C</p>");
            client.println("<p>Humidity: " + String(h) + " %</p>");
            client.println("<p><small>Auto-refresh every 5 seconds</small></p>");
            client.println("</body></html>");
          }
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