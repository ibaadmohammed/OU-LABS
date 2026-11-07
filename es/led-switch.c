#include<regx52.h>
#define LED P0
#define SWITCH P1
int main(void)
{
LED=0X00;
while(1)
{
LED=~SWITCH;
}
}