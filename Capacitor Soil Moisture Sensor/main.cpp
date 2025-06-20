const int soilPin = A0;        // Soil moisture sensor connected to A0
const int ledPin = 13;         // Onboard LED pin
int soilValue = 0;             // Variable to store analog reading
int moisturePercent = 0;       // Moisture percentage

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);          // For debugging
}

void loop() {
  soilValue = analogRead(soilPin);
  // Serial.print(soilValue);
  // Serial.print("-----");

  // Map analog value to percentage (adjust based on your sensor's calibration)
  // Example: dry=300, wet=800
  moisturePercent = map(soilValue, 455, 225, 0, 100);
  moisturePercent = constrain(moisturePercent, 0, 100); // Ensure within 0-100

  Serial.print("Moisture: ");
  Serial.print(moisturePercent);
  Serial.println("%");

  // Turn on LED if moisture < 30%
  if (moisturePercent < 50) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(1000); // Wait for 1 second
}
