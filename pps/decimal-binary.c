#include<stdio.h>
void main()
{
int decimal,i=1,binary=0,rem;
printf("Enter a decimal number to convert:");
scanf("%d",&decimal);
while(decimal>0)
{
rem=decimal%2;
decimal=decimal/2;
binary=binary+(rem*i);
i=i*10;
}
printf("of given number is %d",binary);
}