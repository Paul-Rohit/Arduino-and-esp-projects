#define tempPin A0
float val;
float static_variable = 25.00;

void setup() {
  Serial.begin(9600);
}

void loop() {
  val = analogRead(tempPin);
  float mv = ( val/1024.0)*5000;
  float cel = mv/10;

  Serial.print("Temp:");
  Serial.print(cel);
  Serial.print(",");
  Serial.print("R_temp:");
  Serial.println(static_variable);
  delay(1500);
}
