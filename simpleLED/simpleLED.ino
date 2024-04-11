void setup() {
  // put your setup code here, to run once:
  pinMode(7,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  dot();
  dash();
}
void dot(){
  digitalWrite(7,HIGH);
  delay(500);
  digitalWrite(7,LOW);
  delay(500);
  
}
void dash(){
  digitalWrite(7,HIGH);
  delay(1500);
  digitalWrite(7,LOW);
  delay(500);
}
