#include<NewPing.h>
#include<Servo.h>
#include<AFMotor.h>

  void setup() 
  {
  // put your setup code here, to run once:
Servo myservo; //create servo object to control the servo:
 int pos=0;     //variable to store the servo position:


   Serial.begin(9600); //initailize serial communication at 9600 bits per second:
   myservo.attach(10); // servo attached to pin 10 of Arduino UNO
{
for(pos = 90; pos <= 180; pos += 1){    // goes from 90 degrees to 180 degrees:
  myservo.write(pos);                   //tell servo to move according to the value of 'pos' variable:
  delay(15);                            //wait 15ms for the servo to reach the position:
  } 
for(pos = 180; pos >= 0; pos-= 1) {     // goes from 180 degrees to 0 degrees:
  myservo.write(pos);                   //tell servo to move according to the value of 'pos' variable:
  delay(15);                            //wait 15ms for the servo to reach the position:
  }
for(pos = 0; pos<=90; pos += 1) { 
   pinMode(LEFT, INPUT);  //set analog pin RIGHT as an input:
}

// the lope function runs forever
void loop() {                             
  
delay(50);                                        //wait 50ms between pings:
distance = sonar.ping_cm();                       //send ping, get distance in cm and store it in 'distance' variable:
Serial.print("distance");                   
Serial.println(distance);                         // print the distance in serial monitor:
}

void loop() {
  // put your main code here, to run repeatedly:

}
  
}
