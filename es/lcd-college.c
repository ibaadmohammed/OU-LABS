#include<REGX51.h>
#define EN P3_5
#define RS P3_4
#define LCD P0
void LCDinit(void);
void putcomL(unsigned char);
void putstrL(unsigned char*, unsigned char);
void putcharL(unsigned char);
void delay(unsigned int);
void main()
{
LCDinit();
delay(1000);
putstrL("Your College",0X01);
putstrL("Your Branch",0xC0);
while(1);
}
void LCDinit(void)
{
putcomL(0x38);
putcomL(0x0F);
putcomL(0x80);
putcomL(0x06);
putcomL(0x01);
}
void putcomL(unsigned char cmd)
{
RS=0;
LCD=cmd;
EN=1;
delay(1000);
EN=0;
}
void putcharL(unsigned char dat)
{
RS=1;
LCD=dat;
EN=1;
delay(1000);
EN=0;
}
void putstrL(unsigned char*str,unsigned char cmd)
{
unsigned char i=0;
putcomL(cmd);
while(*str)
{
i++;
if(i==17)
putcomL(0xc0);
putcharL(*str++);
}
}
void delay(unsigned int d)
{
unsigned int i,j;
for(i=0;i<d;i++)
for(j=0;j<100;j++);
}
