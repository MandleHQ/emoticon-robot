#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 2, 3, 4, 5);

void setup(){
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available()) {
    delay(100);
    lcd.clear();
    int pos = 0;
    while (Serial.available() > 0) {
      lcd.write(Serial.read());
      ++pos;
      if(pos == 16)
        lcd.setCursor(0,1);
    }
  }
}
