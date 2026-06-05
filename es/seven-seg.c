#include<REGX51.h>
#define SEG1{P3_3=0;P3_4=0;P3_5=1;}
#define SEG2{P3_3=0;P3_4=1;P3_5=0;}
#define SEG3{P3_3=1;P3_4=0;P3_5=0;}
#define NULL{P3_3=0;P3_4=0;P3_5=0;}
code unsigned char
SEG[10]={0XC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
int main(void)
{
unsigned char i,j,k,m;
unsigned int l;
while(1)
{
for(i=0;i<10;i++)
{
for(j=0;j<10;j++)
{
for(k=0;k<10;k++)
{
for(l=0;l<1000;l++)
{
NULL
P0=SEG[i];
SEG1
for(m=0;m<10;m++);
NULL
P0=SEG[j];
SEG2
for(m=0;m<10;m++);
NULL
P0=SEG[k];
SEG3
for(m=0;m<10;m++);
}
}
}
}
}
}
