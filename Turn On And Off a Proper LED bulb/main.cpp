#define RELAY_PIN D1  // GPIO5

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // Start with bulb OFF
  Serial.println("Type ON or OFF to control the bulb.");
}

void loop() {
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    command.trim(); // Remove newline or extra spaces

    if (command.equalsIgnoreCase("ON")) {
      digitalWrite(RELAY_PIN, LOW);
      Serial.println("Bulb turned ON");
    } else if (command.equalsIgnoreCase("OFF")) {
      digitalWrite(RELAY_PIN, HIGH);
      Serial.println("Bulb turned OFF");
    } else {
      Serial.println("Invalid command. Type ON or OFF.");
    }
  }
}
