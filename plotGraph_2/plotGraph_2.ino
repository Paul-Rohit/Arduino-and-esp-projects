int random_variable;
int static_variable = 2;

void setup() {
  Serial.begin(9600);
}

void loop() {
  random_variable = random(0, 1);

  Serial.print("Variable_1:");
  Serial.print(random_variable);
  Serial.print(",");
  Serial.print("Variable_2:");
  Serial.println(static_variable);
}
