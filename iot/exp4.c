#include <DHT11.h>
DHT11 dht11(2); // create an instance of the DHT11 class
void setup( )
{
Serial.begin(9600); // using a baud rate of 9600 bps
}
void loop( )
{
int temp, humid;
int result = dht11.readTemperatureHumidity(temp, humid); // reading from DHT11
if (result == 0) // If reading is successful, print the values
{
Serial.print("Temperature: ");
Serial.print(temp);
Serial.print(" °C\t Humidity: ");
Serial.print(humid);
Serial.println("%");
}
else
{
Serial.println(“Reading Error”); // print error message
}
delay(1000); // wait for a second
}