/* Program to check whether the number entered is a prime number or not */
# include <stdio.h>
void main ( )
{
int n,i,count=0;
printf ("Enter a number: \n");
scanf ("%d", &num);
for (i = 1; i<=num; i++)
{
if (num%i = = 0)
{
count++:
}
}
if (count= = 2)
printf ("it is a prime number");
else
printf("It is not a Prime number");
}