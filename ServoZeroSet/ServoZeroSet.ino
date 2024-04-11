#include <Servo.h>

Servo servo; // Create a servo object

const int servoPin = 7; // Define the servo pin

void setup() {
  servo.attach(servoPin); // Attach the servo to the pin
}

void loop() {
  servo.write(90); // Set the servo to 0-degree position
  delay(1000); // Wait for 1 second
}
