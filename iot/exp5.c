void setup( )
{
pinMode(9, OUTPUT); // Trigger pin
pinMode(10, INPUT); // Echo pin
Serial.begin(9600); // using a baud rate of 9600 bps
}
void loop( )
{
long duration, inch, cm;
digitalWrite(9, LOW); // transmitting a pulse
delayMicroseconds(2);
digitalWrite(9, HIGH);
delayMicroseconds(10);
digitalWrite(9, LOW);
duration = pulseIn(10, HIGH); // reading the transmitted pulse
inch = duration / 74 / 2; // calculating the distance
cm = duration / 29 / 2;
Serial.print(inch); // printing the calculated distance
Serial.print(" inches \t");
Serial.print(cm);
Serial.println(" cms");
delay(1000); // wait for a second
}