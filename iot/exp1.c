void setup( ) 
{
 pinMode(13, OUTPUT); // initialize a digital pin as an output
}
void loop( ) 
{
digitalWrite(13, HIGH); // turn the LED ON (HIGH is the voltage level)
delay(2000); // wait for two seconds
digitalWrite(13, LOW); // turn the LED OFF (LOW is the voltage level)
delay(1000); // wait for a second
}