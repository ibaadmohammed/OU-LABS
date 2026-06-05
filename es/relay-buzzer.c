#include<REGX51.h>
#define RELAY1 P2_4
#define RELAY2 P2_5
#define RELAY3 P2_6
#define BUZZER P2_7
void delay(unsigned int);
int main()
{
P2=0x00;
while(1)
{
RELAY1=1;
delay(1000);
RELAY1=0;
delay(1000);
RELAY2=1;
delay(1000);
RELAY2=0;
delay(1000);
RELAY3=1;
delay(1000);
RELAY3=0;
delay(1000);
BUZZER=1;
delay(1000);
BUZZER=0;
delay(1000);
}
}
void delay(unsigned int d)
{
unsigned int i,j;
for(i=0;i<d;i++)
for(j=0;j<100;j++);
}
