#include<REGX51.h>
#define LED P2
void delay(unsigned int d);
int main(void)
{
while(1)
{
unsigned int i;
LED=0X01;
for(i=0;i<=7;i++)
{
delay(1000);
LED=LED<<0x01;
}
LED=0X80;
for(i=0;i<=0;i++)
{
delay(1000);
LED = LED>>0X01;
}
}
}
void delay(unsigned int d)
{
unsigned int i,j;
for(i=0;i<d;i++)
for(j=0;j<100;j++);
}
