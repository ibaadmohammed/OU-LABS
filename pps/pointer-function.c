//Program to find the sum of two numbers implementing the concept of pointer to function
#include<stdio.h>
void main()
{
int add(int,int);
int a,b;
int (*fptr)();
fptr=&add;
printf("enter two numbers\n");
scanf("%d%d",&a,&b);
printf("result=%d",(*fptr)(a,b));
}
int add(int a, int b)
{
return(a+b);
}