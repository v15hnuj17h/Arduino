# NodeMCU Built-in LED Control via Web Interface

This project allows you to control the built-in LED on a NodeMCU (ESP8266) through a web interface hosted on the board. Users can access the webpage over a local Wi-Fi network to turn the LED on or off and see the current status.

## Features

- Web server hosted directly on the NodeMCU
- Buttons to turn the LED ON or OFF
- Displays the current status of the LED

## Hardware Required

- NodeMCU ESP8266 development board
- Micro USB cable
- Wi-Fi connection

## Software Requirements

- Arduino IDE
- ESP8266 board package installed in the Arduino IDE

## Setup Instructions

1. Connect your NodeMCU to your computer using a USB cable.
2. Open the Arduino IDE.
3. Install the ESP8266 board support via the Board Manager if not already installed.
4. Select the appropriate board and port in the Arduino IDE:
   - Board: "NodeMCU 1.0 (ESP-12E Module)"
   - Port: Select the correct COM port
5. Replace the placeholder values `YOUR_SSID` and `YOUR_PASSWORD` in the sketch with your actual Wi-Fi credentials.
6. Upload the sketch to the NodeMCU.

## How to Use

1. After uploading, open the Serial Monitor at 115200 baud.
2. Wait for the NodeMCU to connect to Wi-Fi. It will display its local IP address.
3. Open a browser on a device connected to the same network and enter the IP address shown in the Serial Monitor.
4. Use the buttons on the webpage to turn the LED on or off.
5. The current status of the LED is displayed on the webpage.

## Notes

- The built-in LED on most NodeMCU boards is connected to GPIO2 and is **active LOW** (meaning it turns ON when the pin is set to LOW).
- The web server handles HTTP GET requests for `/LED=ON` and `/LED=OFF`.

## License

This project is open-source and free to use for educational and personal projects.

---


# NodeMCU LED Toggle Control via Web Interface

This project lets you control the built-in LED of a NodeMCU (ESP8266) using a single toggle button on a webpage hosted by the device. The page also displays the current LED status.

## Features

- Hosted web server on the NodeMCU
- One button to toggle the LED ON or OFF
- Displays current LED status on the same page

## Hardware Required

- NodeMCU ESP8266 board
- Micro USB cable
- Wi-Fi access point

## Software Required

- Arduino IDE
- ESP8266 board package

## Setup Instructions

1. Connect the NodeMCU to your PC using a USB cable.
2. Open the Arduino IDE and install the ESP8266 board via the Board Manager.
3. Select:
   - Board: NodeMCU 1.0 (ESP-12E Module)
   - Port: Your COM port
4. Replace `YOUR_SSID` and `YOUR_PASSWORD` with your Wi-Fi credentials.
5. Upload the code to your NodeMCU.

## How to Use

1. Open the Serial Monitor at 115200 baud after uploading.
2. Note the IP address shown after Wi-Fi connection.
3. Open the IP in your browser.
4. Click the "Toggle LED" button to switch the LED ON/OFF.
5. The status will update on the webpage.

## Notes

- The built-in LED is usually connected to GPIO2.
- It is **active LOW** — setting the pin to `LOW` turns it ON.

## License

Free to use for personal and educational projects.
