#include<REGx51.h>
#define LED P2
void delay(unsigned int);
int main(void)
{
while(1)
{
unsigned int i;
LED=0x00;
for(i=0;i<=15;i++)
{
LED++;
delay(1000);
}
}
}
void delay(unsigned int d)
{
unsigned int i,j;
for(i=0;i<d;i++)
for(j=0;j<100;j++);
}
