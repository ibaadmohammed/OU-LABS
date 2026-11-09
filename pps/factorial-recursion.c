/* Program for finding factorial of a number using recursion*/
#include<stdio.h>
int fact(int);
void main()
{
long int num,f;
printf("\nEnter a number: ");
scanf("%ld",&num);
f=fact(num);
printf("\nFactorial of %ld is: %ld",num,f);
}
int fact(int n)
{
if(n==1)
return 1;
else
return(n*fact(n-1));
}