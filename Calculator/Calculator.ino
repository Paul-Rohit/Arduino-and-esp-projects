
#include <Keypad.h>
#include <Wire.h>  // Include Wire library for I2C communication
#include <LiquidCrystal_I2C.h>  // Include LiquidCrystal_I2C library

// Set the LCD address (usually 0x27 or 0x3F for most modules)
#define LCD_ADDRESS 0x27

// Set the number of columns and rows for your LCD
#define LCD_COLUMNS 16
#define LCD_ROWS 2

String inputString = "";
float temp1 = 0;
float temp2 = 0;
char oprtr = "";
bool flag = true;
// Initialize the LiquidCrystal_I2C library with the LCD address and columns/rows
LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; // Rows 0 to 3
byte colPins[COLS] = {5, 4, 3, 2}; // Columns 0 to 3


Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
void processString(String str);
void setup() {
  Serial.begin(9600);
  // Initialize the LCD
  lcd.init();

  // Turn on the backlight
  lcd.backlight();

  // Print a message to the LCD
  lcd.print("Hello, World!");
  delay(2000);
}

void loop() {
  char key = keypad.getKey();
  lcd.clear();  // Clear the LCD screen
  lcd.setCursor(0, 0);  // Set cursor to the first column of the first row
  lcd.print("Calculator");
  if (key) {
    Serial.println(key);
    if (key != NO_KEY) {

      switch (key) {
        case '*':
          // Action for key D
          Serial.println("Clear");
          lcd.setCursor(0, 1);  // Set cursor to the first column of the first row
          lcd.print("Clear");
          temp1 = 0;
          temp2 = 0;
          flag = true;
          break;
        default:
          // Default case
          Serial.println("data input");
          intString(key);
          break;
      }
    }
  }
  delay(200);
}
void intString(char X) {
  if (X == '#' || X == 'A' || X == 'B' || X == 'C' || X == 'D') {
    // End of string, do something with the input
    processString(inputString);
    inputString = ""; // Reset inputString for next input
    if (X != '#') {
      oprtr = X;
    }
    calculator(X);

  } else {
    inputString += X; // Append keypress to inputString
  }
  lcd.setCursor(0, 1);  // Set cursor to the first column of the first row
  lcd.print(inputString);
}
void processString(String str) {
  // Do something with the string (e.g., display it)
  Serial.println("Received string: " + str);
  if (temp2 == 0 && flag){
    temp2 = str.toInt();
    flag = false;
  }
  else{
    temp1 = str.toInt();
    flag = true;
  }
  lcd.setCursor(0, 1);  // Set cursor to the first column of the first row
  lcd.print(str);
}
void calculator(char Y) {
  if (Y == '#') {
    switch (oprtr) {
      case 'A':
        // Action for key A
        Serial.println("You pressed key A");
        lcd.clear();  // Clear the LCD screen
        lcd.setCursor(0, 0);
        lcd.print("Add");
        temp2 = temp1 + temp2;
        lcd.setCursor(0, 1);
        lcd.print(temp2);
        delay(200);
        break;
      case 'B':
        // Action for key B
        Serial.println("You pressed key B");
        lcd.clear();  // Clear the LCD screen
        lcd.setCursor(0, 0);
        lcd.print("Subtract");
        temp2 = temp2 - temp1;
        /*if (temp2 < 0) {
          lcd.setCursor(0, 1);
          lcd.print("-");
          lcd.setCursor(0, 2);
          lcd.print(temp2);
          }
          else {*/
        lcd.setCursor(0, 1);
        lcd.print(temp2);
        delay(200);
        //}
        break;
      case 'C':
        // Action for key C
        Serial.println("You pressed key C");
        lcd.clear();  // Clear the LCD screen
        lcd.setCursor(0, 0);
        lcd.print("Multiply");
        temp2 = (temp2 == 0) ? 1 : temp2;
        temp2 = temp1 * temp2;
        lcd.setCursor(0, 1);
        lcd.print(temp2);
        delay(200);
        break;
      case 'D':
        // Action for key D
        Serial.println("You pressed key D");
        lcd.clear();  // Clear the LCD screen
        lcd.setCursor(0, 0);
        lcd.print("Divide");
        if (temp1 == 0) {
          lcd.setCursor(0, 0);
          lcd.print("no div by 0");
        }
        else {
          temp2 = temp2 / temp1;
          lcd.setCursor(0, 1);
          lcd.print(temp2);
        }
        delay(200);
        break;
    }
  }
}
