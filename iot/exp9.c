#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#include <DHT11.h>
DHT11 dht11(2); // create an instance of the DHT11 class
void setup( )
{
lcd.init( ); // initialize the LCD
lcd.backlight( );
lcd.clear( ); // clear the LCD
}
void loop( )
{
int temp, humid;
int result = dht11.readTemperatureHumidity(temp, humid); // reading from DHT11
if (result == 0) // If reading is successful, print the values
{
lcd.setCursor(0,0); // display in line-1
lcd.print("Temp ");
lcd.print(temp);
lcd.setCursor(0,1); // display in line-2
lcd.print("Humid ");
lcd.print(humid);
}
else
{
lcd.clear( ); // clear the LCD
lcd.setCursor(0,0); // display in line-1
lcd.print(“ Error ”); // print error message
}
delay(1000); // wait for a second
}