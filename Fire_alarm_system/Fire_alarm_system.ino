
#include <Wire.h>  // Include Wire library for I2C communication
#include <LiquidCrystal_I2C.h>  // Include LiquidCrystal_I2C library

// Set the LCD address (usually 0x27 or 0x3F for most modules)
#define LCD_ADDRESS 0x27

// Set the number of columns and rows for your LCD
#define LCD_COLUMNS 16
#define LCD_ROWS 2

// Initialize the LiquidCrystal_I2C library with the LCD address and columns/rows
LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);

const int lm35Pin = A0;
const int buzzerPin = 8;
const int fireThreshold = 50; 


void setup() {
 Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  lcd.init();
  
  // Turn on the backlight
  lcd.backlight();

  // Print a message to the LCD
  lcd.print("Hello, World!");
  delay(2000);
}

void loop() {
  int sensorValue = analogRead(lm35Pin);
  Serial.print(sensorValue);
  float temperatureC = map(sensorValue, 0, 358, 10, 125);
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");
  lcd.clear();  // Clear the LCD screen
  lcd.setCursor(0, 0);  // Set cursor to the first column of the first row
  lcd.print("Temperature...");
  lcd.setCursor(0, 1);
  lcd.print(temperatureC);
  if (temperatureC >= fireThreshold) {
    tone(buzzerPin, 1000); 
    delay(1000); 
    noTone(buzzerPin); 
    delay(1000); 
  }
  delay(1000); 
}
