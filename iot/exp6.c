#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
void setup( )
{
lcd.init( ); // initialize the LCD
lcd.backlight( );
}
void loop( )
{
lcd.clear( ); // clear the LCD
lcd.setCursor(0,0); // display the text in line-1
lcd.print("Hello");
lcd.setCursor(0,1); // display the text in line-2
lcd.print("world");
delay(5000); // wait for five seconds
}