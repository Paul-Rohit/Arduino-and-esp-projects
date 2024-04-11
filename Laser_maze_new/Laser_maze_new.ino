int laserRelayPin = 24;
int redLight = 26;
int blueLight = 28;
int greenLight = 22;
int buzzer = 6;
int button = 15;
int buttonStart = 21;
int buttonStartState = 1;
int buttonState =  1;
const int ldrPins[] = {31, 33, 35, 37, 39, 41, 43, 45, 47, 49, 51, 53};
const int numberOfLasers = 1;
unsigned long startTime = 0.0;
unsigned long currentTime = 0.0;
unsigned long elapsedTime = 0.0;
unsigned long Time = 0.0;

void game() {
  currentTime = millis();
  digitalWrite(laserRelayPin, LOW);
  digitalWrite(blueLight, LOW);
  digitalWrite(redLight, HIGH);
  digitalWrite(greenLight, HIGH);

  if (detectNoLaser()) {
    Serial.println("OBSTACLE DETECTED");
    digitalWrite(laserRelayPin, HIGH);
    digitalWrite(redLight, LOW);
    digitalWrite(blueLight, HIGH);
    delay(3000);
    //track = 0;
    but();
  }

  buttonState = digitalRead(button);
  if(buttonState == LOW) {
    Serial.println("Button PRESSED");
    digitalWrite(laserRelayPin, HIGH);
    digitalWrite(buzzer, HIGH);
    digitalWrite(redLight, HIGH);
    digitalWrite(blueLight, HIGH);
    digitalWrite(greenLight, LOW);
    delay(3000);
    digitalWrite(buzzer, LOW);
    buttonState = HIGH;
    but();
  }

  elapsedTime = currentTime - startTime;
  Time = elapsedTime / 1000;
  Serial.print("Elapsed Time: ");
  Serial.print(Time);
  Serial.println(" seconds");
  if (Time > 60) {
    Serial.println("Too Slow game ovr");
    digitalWrite(laserRelayPin, HIGH);
    digitalWrite(redLight, LOW);
    digitalWrite(blueLight, HIGH);
    delay(3000);
    but();
  }

  game();
}

void setup() {
  Serial.begin(9600);
  pinMode(laserRelayPin, OUTPUT);
  pinMode(redLight, OUTPUT);
  pinMode(blueLight, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(20, OUTPUT);
  pinMode(21, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(greenLight, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(buttonStart, INPUT_PULLUP);

  for (int i = 0; i < numberOfLasers; i++) {
    pinMode(ldrPins[i], INPUT);
  }
  
  digitalWrite(laserRelayPin, HIGH);
  digitalWrite(blueLight, HIGH);
  digitalWrite(redLight, HIGH);
  digitalWrite(greenLight, HIGH);
  digitalWrite(buzzer, LOW);
  digitalWrite(16, HIGH);
  digitalWrite(17, LOW);
  digitalWrite(17, LOW);

  delay(3000);
  Serial.println("Waiting for Start Button");
}

void but() {
  digitalWrite(laserRelayPin, HIGH);
  digitalWrite(blueLight, HIGH);
  digitalWrite(redLight, HIGH);
  digitalWrite(greenLight, HIGH);
  digitalWrite(buzzer, LOW);
  digitalWrite(16, HIGH);
  digitalWrite(17, LOW);

  buttonStartState = digitalRead(buttonStart);
  if (buttonStartState == LOW) {
    Serial.println("pressed Start Button");
    buttonStartState = HIGH;
    delay(5000);
    delay(1500);
    startTime = millis();
    game();
  }
  but();
}

void loop() {
  but();
}

bool detectNoLaser() {
  for (int i = 0; i < numberOfLasers; i++) {
    if (digitalRead(ldrPins[i]) == 0) {
      Serial.println("NO OBSTACLE");
      return false;
    }
  }
  return true;
}
