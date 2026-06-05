#include<REGX51.h>
#define LED P2
void delay (unsigned int);
int main(void)
{
while(1)
{
LED=0X55;
delay(1000);
LED=0XAA;
delay(1000);
}
}
void delay(unsigned int d)
{
unsigned int i,j;
for(i=0;i<d;i++)
for (j=0;j<100;j++);
}
