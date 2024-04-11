#define ldrPin A0
#define buzzer 7
int ldrValue = 0;
int static_variable = 500;
void setup() {
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  ldrValue = analogRead(ldrPin);
  

  Serial.print("Light_Intensity:");
  Serial.print(ldrValue);
  Serial.print(",");
  Serial.print("Threshold:");
  Serial.println(static_variable);
  if (ldrValue<650){
    tone(buzzer, 1000);
    //delay(3000);
  }
  else{
    noTone(buzzer);
  }
  delay(50);
}
