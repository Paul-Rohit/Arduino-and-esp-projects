char inData[5]; // Allocate some space for the string
int inChar; // Where to store the character read
byte charIndex = 0; // Index into array; where to store the character
boolean okPrint;
void setup()
{
 Serial.begin(9600);  
}


void loop()
{

  while(Serial.available() > 0) // Don't read unless
                                                 // there you know there is data
  {   
      for(charIndex=0;charIndex<4;charIndex++) // One less than the size of the array
      {
          inChar = Serial.read(); // Read a character
          inData[charIndex] = char(inChar); // Store it
          inData[charIndex] = '\0'; // Null terminate the string
      }
      Serial.println(inData);
  }
}
