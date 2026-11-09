/* C programming source code to convert binary to octal according to data entered by user. */
#include <stdio.h>
#include <math.h>
void main()
{
long int n;
int octal=0,decimal=0,i=0;
printf("Enter a binary number: ");
scanf("%ld",&n);
while(n!=0)
{
decimal=decimal+(n%10)*pow(2,i);
++i;
n=n/10;
}
/*At this point, the decimal variable contains corresponding decimal value of binary number. */
i=1;
while (decimal!=0)
{
octal+=(decimal%8)*i;
decimal/=8;
i*=10;
}
printf("Its equivalent octal number is: %d",octal);
}