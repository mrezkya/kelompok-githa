#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
  const int t = 3;
  const int e = 2;
  long dr;
  int ds;
void setup()
{
  pinMode(t, OUTPUT);
  pinMode(e, INPUT);
	// initialize the LCD
	lcd.begin();
  Serial.begin(9600);
}

void loop()
{
 digitalWrite(t, LOW);
 delayMicroseconds(1);
 digitalWrite(t, HIGH);
 delayMicroseconds(10);
 digitalWrite(t, LOW);
 dr = pulseIn(e, HIGH);
 ds = dr*0.034/2;
 Serial.print("distance : ");
 Serial.println(ds);
// lcd.clear();
 Serial.println("cm");
 lcd.setCursor(0,0);
 lcd.print("jarak : ");
  lcd.print(ds);
  lcd.print("cm");
 lcd.clear()
 delay(2000);
}
