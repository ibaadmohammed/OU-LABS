#include <regx51.h>
#define LED P2
void delay(unsigned int d);
main()
{
while(1)
{
int i;
LED=0x00;
for(i=0;i<=15;i++)
{
delay(10000);
LED=LED-1;
}
}
}
void delay(unsigned int d)
{
int i,j;
for(i=0;i<d;i++);
for(j=0;j<101;j++);
}