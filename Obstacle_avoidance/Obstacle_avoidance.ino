#include <NewPing.h>
#include <Servo.h>

// Pin definitions
const int motorPin1 = 12;  // IN1 on L298N
const int motorPin2 = 13;  // IN2 on L298N
const int motorPin3 = 4;   // IN3 on L298N
const int motorPin4 = 5;   // IN4 on L298N
const int enablePin1 = 3;  // ENA on L298N
const int enablePin2 = 6;  // ENB on L298N
const int trigPin = 10;    // Trigger pin of ultrasonic sensor
const int echoPin = 11;    // Echo pin of ultrasonic sensor
const int servoPin = 7;    // Servo signal pin

// Define servo and ultrasonic sensor objects
Servo servo;
NewPing sonar(trigPin, echoPin, 200);  // Max distance 200cm

// Constants for distance thresholds
const int maxDistance = 30;  // Max distance to detect obstacle
const int minDistance = 10;  // Min distance to start avoiding obstacle

// Function prototypes
void moveForward(int speed);
void stopMotors();
void turnLeft();
void turnRight();

void setup() {
  // Setup pins
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(enablePin1, OUTPUT);
  pinMode(enablePin2, OUTPUT);
  
  // Attach servo
  servo.attach(servoPin);
  
  // Initial motor direction (forward)
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  
  // Set servo to middle position
  servo.write(90);
  
  // Start serial communication
  Serial.begin(9600);
}

void loop() {
  // Measure distance in front
  int distance = sonar.ping_cm();

  // If obstacle detected
  if (distance < maxDistance && distance > 0) {
    // Stop motors
    stopMotors();

    // Measure distances to left and right
    servo.write(45); // Turn left
    int leftDistance = sonar.ping_cm();
    delay(500); // Wait for servo to move
    servo.write(135); // Turn right
    int rightDistance = sonar.ping_cm();
    delay(500); // Wait for servo to move back to center
    servo.write(90);

    // Decide direction based on available space
    if (leftDistance > rightDistance) {
      turnLeft();
    } else {
      turnRight();
    }
    delay(1000); // Delay for turn
  } else {
    // Move forward with speed adjustment based on distance
    moveForward(map(distance, minDistance, maxDistance, 100, 255));
  }
}

// Move forward function with speed control
void moveForward(int speed) {
  Serial.println("Forward");
  analogWrite(enablePin1, speed); // Motor A speed
  analogWrite(enablePin2, speed); // Motor B speed
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
}

// Stop motors function
void stopMotors() {
  Serial.println("Stop");
  analogWrite(enablePin1, 0); // Motor A speed
  analogWrite(enablePin2, 0); // Motor B speed
}

// Turn left function
void turnLeft() {
  Serial.println("Left");
  analogWrite(enablePin1, 100); // Motor A speed
  analogWrite(enablePin2, 100); // Motor B speed
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  delay(1000); // Adjust turn duration
}

// Turn right function
void turnRight() {
  Serial.println("Right");
  analogWrite(enablePin1, 100); // Motor A speed
  analogWrite(enablePin2, 100); // Motor B speed
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  delay(1000); // Adjust turn duration
}
