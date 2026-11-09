/*Write a program to convert given binary number to decimal.*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void main()
{
long int decimal = 0, binary ,remainder;
long int temp, i=0;
printf(“\n enter binary number \n”);
scanf(“%ld”, &binary);
temp = binary;
do
{
remainder = binary % 10;
binary = binary /10;
decimal = decimal + (remainder * pow (2, i));
i++;
}
while (binary>0);
printf ("\n the value of binary %ld in decimal is %ld", temp, decimal);
}