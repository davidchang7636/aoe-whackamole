#include <LiquidCrystal.h> 
#include <Wire.h>
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

int count = 0;
int contrast = 125;

const char whack[] PROGMEM = "This is whackamole";
char buffer[20];

int freeRam () {
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}

void setup()
{
  Serial.begin(9600);
  analogWrite(6,contrast);
  lcd.begin(20, 4);
  //lcd.print("Hello there who");
} 

void printScreen() {
  lcd.setCursor(0, 1);
  lcd.print("This is whackamole");

  lcd.setCursor(0, 2);
  lcd.print(count);
  count++;
  //Serial.println(freeRam());
}

void loop()
{ 
  printScreen();
  delay(1000);
}