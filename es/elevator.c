#include<REGX51.h>
void delay(unsigned int);
code unsigned char SEG[10]={0XC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
code unsigned char motoru[8]={0X01,0X03,0X02,0X06,0X04,0x0C,0X08,0X09};
code unsigned char motord[8]={0X09,0X08,0X0C,0X04,0X06,0x02,0X03,0x01};
void main()
{
unsigned char loc,pre=0X01;
unsigned int i,j=0;
loc=pre;
P2=pre;
P0=SEG[j];
while(1)
{
while(P1==0XFF);
loc=~P1;
if(loc>pre)
{
while(loc!=pre)
{
pre=pre<<1;
j++;
for(i=0;i<8;i++)
{
P2=motoru[i];
delay(100);
}
P0=SEG[j];
}
}
else if(loc<pre)
{
while(loc!=pre)
{
pre=pre>>1;
j--;
for(i=0;i<8;i++)
{
P2=motord[i];
delay(100);
}
P0=SEG[j];
}
}
}
}
void delay(unsigned int d)
{
unsigned int i,j;
for(i=0;i<d;i++)
for(j=0;j<100;j++);
}
