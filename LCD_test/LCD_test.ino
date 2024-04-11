#include <Wire.h>  // Include Wire library for I2C communication
#include <LiquidCrystal_I2C.h>  // Include LiquidCrystal_I2C library

// Set the LCD address (usually 0x27 or 0x3F for most modules)
#define LCD_ADDRESS 0x27

// Set the number of columns and rows for your LCD
#define LCD_COLUMNS 16
#define LCD_ROWS 2

// Initialize the LiquidCrystal_I2C library with the LCD address and columns/rows
LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);

void setup() {
  // Initialize the LCD
  lcd.init();
  
  // Turn on the backlight
  lcd.backlight();

  // Print a message to the LCD
  lcd.print("Hello, World!");
  delay(2000);
}

void loop() {
  // Example: scrolling message
  lcd.clear();  // Clear the LCD screen
  lcd.setCursor(0, 0);  // Set cursor to the first column of the first row
  lcd.print("Scrolling text...");

  // Scroll the text
  while (true) {
    lcd.scrollDisplayLeft();  // Scroll one position left
    delay(300);  // Delay for smooth scrolling
  }
}
