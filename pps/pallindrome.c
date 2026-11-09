/* Program to Check whether the number entered is a palindrome or not */
# include <stdio.h>
void main ( )
{
int num, rev = 0, rem, temp;
printf ("Enter a number: \n");
scanf ("%d", &num);
temp = num;
while (num> 0)
{
rem = num % 10;
num = num / 10;
rev = rev * 10 + rem;
}
if (rev = = temp)
printf ("it is a palindrome");
else
printf ("it is not a palindrome");
}