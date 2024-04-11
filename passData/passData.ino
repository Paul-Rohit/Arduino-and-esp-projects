#define ldrPin A0
int count =1;
int DL = 1000;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ldrPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int ldrStatus=analogRead(ldrPin);
Serial.println(ldrStatus);
delay(DL);
}
