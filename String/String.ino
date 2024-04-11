String A;
int i =0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Enter");
  while(!Serial.available()){ }
  A = Serial.readStringUntil("\n");
  i=sizeof(A);
  Serial.println(i);
  Serial.println(A);
  if(A[1]== '0')
  {
    Serial.print("true");
  }
}
