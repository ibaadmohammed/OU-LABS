#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
void setup( )
{
lcd.init( ); // initialize the LCD
lcd.backlight( );
lcd.clear( ); // clear the LCD
}
void loop( )
{
int SensorValue = analogRead(A0); // read data from the LDR
lcd.setCursor(0,1); // display in line-2
lcd.print(SensorValue);
if (SensorValue < 300) // check the reading & display the output text
{
lcd.setCursor(0,0); // display in line-1
lcd.print("Bright");
}
else
{
lcd.setCursor(0,0); // display in line-1
lcd.print("Dark ");
}
delay(1000); // wait for a second
}