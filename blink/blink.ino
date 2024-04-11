// Blinking LED on ESP32

// Pin number for the LED
const int ledPinred = 7;
const int ledPinblue = 8;

void setup() {
  // Set the LED pin as an output
  pinMode(ledPinred, OUTPUT);
  pinMode(ledPinblue, OUTPUT);
}

void loop() {
  // Turn on the LED
  digitalWrite(ledPinred, HIGH);
  digitalWrite(ledPinblue, LOW);
  delay(5000);  // Wait for 1 second
  
  // Turn off the LED
  digitalWrite(ledPinred, LOW);
  digitalWrite(ledPinblue, HIGH);
  delay(1000);  // Wait for 1 second
}
