#include<REGX51.h>
#define LED1 P2_0
#define LED2 P2_1
void isr0(void)interrupt 0
{
LED1=~LED1;
}
void isr1(void)interrupt 2
{
LED2=~LED2;
}
void main()
{
IE=0X85;
IP=0X01;
P2=0X00;
while(1);
}
