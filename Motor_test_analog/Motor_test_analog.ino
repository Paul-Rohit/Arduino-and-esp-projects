// Motor Control with L298N and Arduino (Controlling Two Motors)

// Define pin numbers
const int enablePin1 = 10; // PWM pin for speed control of Motor 1
const int in1Pin1 = 2;    // Control pin 1 of Motor 1
const int in2Pin1 = 3;    // Control pin 2 of Motor 1
const int enablePin2 = 6;// PWM pin for speed control of Motor 2
const int in1Pin2 = 4;    // Control pin 1 of Motor 2
const int in2Pin2 = 5;    // Control pin 2 of Motor 2

void setup() {
  // Set pin modes
  pinMode(enablePin1, OUTPUT);
  pinMode(in1Pin1, OUTPUT);
  pinMode(in2Pin1, OUTPUT);
  pinMode(enablePin2, OUTPUT);
  pinMode(in1Pin2, OUTPUT);
  pinMode(in2Pin2, OUTPUT);
}

void loop() {
  // Run both motors forward
  digitalWrite(in1Pin1, HIGH);
  digitalWrite(in2Pin1, LOW);
  analogWrite(enablePin1, 200); // Adjust PWM value for speed of Motor 1
  
  digitalWrite(in1Pin2, HIGH);
  digitalWrite(in2Pin2, LOW);
  analogWrite(enablePin2, 200); // Adjust PWM value for speed of Motor 2

  delay(2000); // Run for 2 seconds

  // Stop both motors
  analogWrite(enablePin1, 0);
  analogWrite(enablePin2, 0);

  delay(1000); // Pause for 1 second

  // Run both motors backward
  digitalWrite(in1Pin1, LOW);
  digitalWrite(in2Pin1, HIGH);
  analogWrite(enablePin1, 100); // Adjust PWM value for speed of Motor 1
  
  digitalWrite(in1Pin2, LOW);
  digitalWrite(in2Pin2, HIGH);
  analogWrite(enablePin2, 100); // Adjust PWM value for speed of Motor 2

  delay(2000); // Run for 2 seconds

  // Stop both motors
  analogWrite(enablePin1, 0);
  analogWrite(enablePin2, 0);

  delay(1000); // Pause for 1 second
}
