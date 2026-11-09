#include<stdio.h>
void fibonacci(int);
void main()
{
int n,a=0,b=1;
printf("Enter the range of the Fibonacci series: ");
scanf("%d",&n);
printf("Fibonacci Series: ");
printf("%d\t%d\t",a,b);
fibonacci(n);
}
void fibonacci(int n)
{
static int a=0,b=1,sum;
if(n>2)
{
sum = a+ b;
a= b;
b= sum;
printf("%d\t",sum);
fibonacci(n-1);
}
}