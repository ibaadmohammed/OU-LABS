#include<REGX51.h>
#define LED P2
void delay(unsigned int);
int main()
{
while(1)
{
LED=0x00;
delay(1000);
LED=0x54;
delay(1000);
LED=0x56;
delay(1000);
LED=0x51;
delay(1000);
LED=0x59;
delay(1000);
LED=0x45;
delay(1000);
LED=0x65;
delay(1000);
LED=0x15;
delay(1000);
LED=0x95;
delay(1000);
}
}
void delay (unsigned int d)
{
unsigned int i,j;
for(i=0;i<d;i++)
for(j=0;j<100;j++);
}
