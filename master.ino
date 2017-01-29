
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
float dataADC=0;
float tekanan=0;
float voltage=0;

void setup() {
  // set up the LCD's number of columns and rows:
  Serial.begin(9600);
  lcd.begin(16, 4);
  // Print a message to the LCD.
  lcd.print("hello, world!");
  analogReference(DEFAULT);
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.clear();
  dataADC=analogRead(0);
  voltage=dataADC*1.1/1023;
  tekanan=(voltage/0.045)+0.2;
  tekanan=tekanan*7.5;
  lcd.setCursor(0, 0);
  lcd.print("Time:");
  lcd.setCursor(5, 0);
  lcd.print(millis() / 1000);
  lcd.setCursor(0, 1);
  lcd.print("ADC:");
  lcd.setCursor(4, 1);
  lcd.print(dataADC);
  lcd.setCursor(0, 2);
  lcd.print("Voltage:");
  lcd.setCursor(8, 2);
  lcd.print(voltage);
  lcd.setCursor(0, 3);
  lcd.print("Tekanan:");
  lcd.setCursor(8, 3);
  lcd.print(tekanan);
  delay(250);
}
