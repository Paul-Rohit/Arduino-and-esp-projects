
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
  lcd.print("Keypad");
  if (key) {
    Serial.println(key);
     lcd.setCursor(0, 1);  // Set cursor to the first column of the second row
    lcd.print(key);
  }
  delay(200);
}
