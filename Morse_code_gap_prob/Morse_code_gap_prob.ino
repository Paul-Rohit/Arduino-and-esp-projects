int led_value[3];
int temp=0;
int i = 0;
const int ldrPin = A0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(ldrPin, INPUT); // Here LDR sensor is determined as input.

}

void loop() {
  // put your main code here, to run repeatedly:
  //  digitalWrite(13, HIGH);
  //  delay(100);
  //  digitalWrite(13, LOW);
  //  delay(100);

  int ldrStatus = analogRead(ldrPin);

  if (ldrStatus <= 400) {
    led_value[0] = 0;
    Serial.println("0");
    Serial.println(ldrStatus);
    delay(1000);
  }
  else {
    led_value[0] = 1;
    Serial.println("1f");
    Serial.println(ldrStatus);
    delay(1000);
  }

  ldrStatus = analogRead(ldrPin);
  if (ldrStatus <= 400) {
    led_value[1] = 0;
    Serial.println("0");
    Serial.println(ldrStatus);
    delay(1000);
  }
  else {
    led_value[1] = 1;
    Serial.println("1s");
    Serial.println(ldrStatus);
    delay(1000);
  }
//
//  if (ldrStatus <= 400) {
//    led_value[2] = 0;
//    Serial.println("0");
//    Serial.println(ldrStatus);
//    delay(1000);
//  }
//  else {
//    led_value[2] = 1;
//    Serial.println("1");
//    Serial.println(ldrStatus);
//    delay(1000);
//  }

  if (led_value[0] == 1 && led_value[1] == 1) {
    Serial.print("-");
  }
  else if (led_value[0] == 1 && led_value[1] == 0) {
    Serial.print(".");
  }
  //    else if(led_value[2]==0)
  //    {
  //      Serial.print("_");
  //    }

 else if (led_value[0] == 0 && led_value[1] == 0 && temp==0) {
    Serial.print(" ");
    temp=1;
    
  }
  else if (led_value[0] == 0 && led_value[1] == 0 && temp==1) {
    Serial.println("no data transmission");
    temp=0;
  }
  else {
    Serial.println("Error");
  }

}
