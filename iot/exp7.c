#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
void setup( )
{
pinMode(9,INPUT); // initialize a digital pin as an input
lcd.init( ); // initialize the LCD
lcd.backlight( );
lcd.clear( ); // clear the LCD
}
void loop( )
{
int SensorValue = digitalRead(9); // read data from the IR sensor
if (SensorValue == HIGH) // check condition & display the output text
{
lcd.setCursor(0,0); // display the text in line-1
lcd.print (" Not Detected ");
}
else
{
lcd.setCursor(0,0); // display the text in line-1
lcd.print("Object Detected");
}
delay(1000); // wait for a second
}