/* Program to find the sum of individual digits in a number*/
#include <stdio.h>
void main ( )
{
int rem, num, sum = 0;
printf ("Enter a number: \n");
scanf ("%d", &num);
while (num> 0)
{
rem = num % 10;
num = num / 10;
sum = sum + rem;
}
printf ("Sum of Digits in a number =%d", sum);
}