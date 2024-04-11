#define trigPin A0
#define echoPin A1
int distance;
int duration;
int distRight;
int distLeft;
//Right motor
int enableRightMotor = 6;
int rightMotorPin1 = 7;
int rightMotorPin2 = 8;


//Left motor
int enableLeftMotor = 5;
int leftMotorPin1 = 9;
int leftMotorPin2 = 10;
//Motor speed
int MotorSpeedLow = 80;
int MotorSpeedHigh = 150;
int MotorSpeedNorm = 120;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(enableRightMotor, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);

  pinMode(enableLeftMotor, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  measure();
  if (distance>=20 && distance<100)
  {
    Serial.println(distance);
    forward();
  }
  else if((distance<19 && distance>10) || (distance>100))
  {
    Serial.println("Stop");
    stopandcheck();
  }
  else
  {
    reverse();
  }
  delay(10);
}
void forward(){
  digitalWrite(rightMotorPin1 , HIGH);
  digitalWrite(rightMotorPin2 , LOW);
  digitalWrite(leftMotorPin1 , HIGH);
  digitalWrite(leftMotorPin2 , LOW);
  analogWrite(enableRightMotor, abs(MotorSpeedNorm));
  analogWrite(enableLeftMotor, abs(MotorSpeedNorm));
}
void stopandcheck(){
  digitalWrite(rightMotorPin1 , LOW);
  digitalWrite(rightMotorPin2 , LOW);
  digitalWrite(leftMotorPin1 , LOW);
  digitalWrite(leftMotorPin2 , LOW);
  delay(10);
}
void reverse(){
  digitalWrite(rightMotorPin1 , HIGH);
  digitalWrite(rightMotorPin2 , LOW);
  digitalWrite(leftMotorPin1 , HIGH);
  digitalWrite(leftMotorPin2 , LOW);
  analogWrite(enableRightMotor, abs(MotorSpeedNorm));
  analogWrite(enableLeftMotor, abs(MotorSpeedNorm));
  delay(100);
}
/*void leftTurn()
{
  //left
  digitalWrite(rightMotorPin1 , HIGH);
  digitalWrite(rightMotorPin2 , LOW);
  digitalWrite(leftMotorPin1 , LOW);
  digitalWrite(leftMotorPin2 , HIGH);
  analogWrite(enableRightMotor, abs(MotorSpeedHigh));
  analogWrite(enableLeftMotor, abs(MotorSpeedLow));
  delay(50);
}
void rightTurn()
{
  //right
  digitalWrite(rightMotorPin1 , LOW);
  digitalWrite(rightMotorPin2 , HIGH);
  digitalWrite(leftMotorPin1 , HIGH);
  digitalWrite(leftMotorPin2 , LOW);
  
  analogWrite(enableRightMotor, abs(MotorSpeedLow));
  analogWrite(enableLeftMotor, abs(MotorSpeedHigh));
  delay(50);
}*/
void measure()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
}
