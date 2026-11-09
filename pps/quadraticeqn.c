/*Program to find a roots of quadratic equation. */
#include<stdio.h>
#include<math.h>
void main()
{
int a,b,c,D;
float x,y;
printf("enter coefficient of x^2,x and constant");
scanf("%d%d%d",&a,&b,&c);
D=b*b-4*a*c;
if(D<0)
printf("both roots are imaginary");
if(D==0)
{
printf("both roots are equal");
x=-b/(2.0*a);
printf("roots is %f",x);
}
if(D>0)
{
printf("roots are real and distinct");
x=(-b+sqrt(D))/(2*a);
y=(-b-sqrt(D))/(2*a);
printf("\n roots are %f,%f",x,y);
}
}