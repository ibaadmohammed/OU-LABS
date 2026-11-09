/* Program to compute cosine x value using cosine series expansion */
#include <stdio.h>
void main ( )
{
int degree, i=2;
double radian, term, Nr, Dr, sum = 1.0;
printf ("Enter a value in degree: \n");
scanf ("%d", &degree);
radian = degree * 0.01745329;
Nr = - radian * radian;
Dr = 2.0;
term = Nr / Dr;
while (i <= 20)
{
sum = sum + term;
Nr = (-Nr) * radian * radian;
Dr = Dr * (i + 1) * (i + 2);
term = Nr / Dr;
i = i + 2;
}
printf ("cosine value = %lf", sum);
}