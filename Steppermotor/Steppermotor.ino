#include <AccelStepper.h>

// Define the number of steps per revolution
const int stepsPerRevolution = 2048;

// Define the motor interface pins
#define motorPin1 2
#define motorPin2 3
#define motorPin3 4
#define motorPin4 5

// Create an instance of AccelStepper
AccelStepper stepper(1, motorPin1, motorPin3, motorPin2, motorPin4);

// Define variables for timing
unsigned long previousTime = 0;
const unsigned long stepInterval = 1000; // Delay between steps in milliseconds

void setup() {
  // Set the maximum speed and acceleration
  stepper.setMaxSpeed(10.0);   // Set maximum speed in RPM
  stepper.setAcceleration(100); // Set acceleration in steps per second squared
  
  // Set the initial position of the motor (optional)
  stepper.setCurrentPosition(0);
}

void loop() {
  // Check a condition to change the direction of rotation
  if (/* Condition for direction change */) {
    stepper.step(-stepsPerRevolution); // Set negative steps for reverse rotation
  } else {
    stepper.step(stepsPerRevolution);  // Set positive steps for forward rotation
  }
  
  // Check if the step interval has elapsed
  unsigned long currentTime = millis();
  if (currentTime - previousTime >= stepInterval) {
    previousTime = currentTime; // Update the previous time
    
    // Move the motor continuously
    stepper.runSpeed();
  }
}
