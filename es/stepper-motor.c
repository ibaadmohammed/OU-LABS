#include<REGX51.h>
void delay(unsigned int);
int main()
{
unsigned int i;
while(1)
{
for(i=0;i<=50;i++)
{
P2=0x08;
delay(100);
P2=0x04;
delay(100);
P2=0x02;
delay(100);
P2=0x01;
delay(100);
}
for(i=0;i<=50;i++)
{
P2=0x01;
delay(100);
P2=0x02;
delay(100);
P2=0x04;
delay(100);
P2=0x08;
delay(100);
}
}
}
void delay(unsigned int d)
{
unsigned int i,j;
for(i=0;i<d;i++)
for(j=0;j<100;j++);
}
