#include<REGx51.h>
#define BUZZER P2_7
void delay(unsigned int d);
int main(void)
{
    P2=0x00;
    while(1)
    {
        BUZZER=1;
        delay(1);
        BUZZER=0;
        delay(1);
    }
}
void delay(unsigned int d)
{
    unsigned int i,j,k;
    for(k=0;k<100;k++)
    {
        for(i=0;i<d;i++);
            for(j=0;j<25;j++);
    }
}