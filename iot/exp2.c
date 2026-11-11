void setup( )
{
pinMode(9,INPUT); // initialize a digital pin as an input
Serial.begin(9600); // using a baud rate of 9600 bps
}
void loop( )
{
int SensorValue = digitalRead(9); // read data from the IR sensor
if (SensorValue == HIGH) // check condition & display the output text
{
Serial.println("Not Detected");
}
else
{
Serial.println("Detected");
}
delay(1000); // wait for a second
}