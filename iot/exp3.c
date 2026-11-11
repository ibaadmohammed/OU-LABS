void setup( )
{
Serial.begin(9600); // using a baud rate of 9600 bps
}
void loop( )
{
int SensorValue = analogRead(A0); // read data from the LDR
if (SensorValue < 300) // check the reading & display the output text
{
Serial.print(SensorValue);
Serial.println("\t Its Bright");
}
else
{
Serial.print(SensorValue);
Serial.println("\t Its Dark");
}
delay(1000); // wait for a second
}