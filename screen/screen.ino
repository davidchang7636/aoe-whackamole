#include <LiquidCrystal.h> 
#include <Wire.h>
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

int count = 0;
int contrast = 50;


void setup()
{
  analogWrite(6,contrast);
  lcd.begin(20, 4);
  Wire.setClock(10000);
  //lcd.print("Hello there who");
} 

void loop()
{ 
  Wire.setClock(5000);
  lcd.setCursor(0, 0);
  lcd.print("Hello World");
  
  lcd.setCursor(0, 1);
  lcd.print("This is whackamole");

  lcd.setCursor(0, 2);
  lcd.print(count);
  count++;
  delay(1000);
}