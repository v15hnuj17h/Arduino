#define IR_SENSOR_PIN D5
#define LED_PIN D4

void setup() {
  pinMode(IR_SENSOR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = digitalRead(IR_SENSOR_PIN);
  if (sensorValue == LOW){
    if (digitalRead(LED_PIN)==LOW){
      digitalWrite(LED_PIN, HIGH);
    }
    else{
      digitalWrite(LED_PIN, LOW);
    }
  }
  delay(1000);
}
