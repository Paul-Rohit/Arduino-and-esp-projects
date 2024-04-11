#define trigPin 9
#define echoPin 10
#define ledRed 4
#define ledBlue 5
#define ledGreen 6
void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(500);
  if (distance>= 50){
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledRed, LOW);
    digitalWrite(ledBlue, LOW);
  }
  else if (distance<50 && distance>=20){
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledRed, LOW);
    digitalWrite(ledBlue, HIGH);
  }
  else{
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledBlue, LOW);
  }
  
}
