#define ECHOPIN D6
#define TRIGPIN D5

void setup(){
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Ultrasonic Sensor Test");
  digitalWrite(TRIGPIN, LOW);
}

void loop(){
  float dist = distance(TRIGPIN,ECHOPIN);
  Serial.print("Distance: ");
  Serial.print(dist);
  Serial.println(" cm");

  delay(500);
}

float distance(int TRIGPIN, int ECHOPIN){
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  float duration = pulseIn(ECHOPIN, HIGH);
  float distance = (duration * 0.034) / 2;
  return distance;
}