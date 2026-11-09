/* Program to compute sin x value using sine series expansion */
# include <stdio.h>
void main ( )
{
int degree, i=1;
double radian, term, Nr, Dr, sum = 0.0;
printf ("Enter a value in degree: \n");
scanf ("%d", &degree);
radian = degree * 0.01745329;
Nr = radian;
Dr = 1.0;
term = Nr / Dr;
while (i <= 20)
{
sum = sum + term;
Nr = (-Nr) * radian * radian;
Dr = Dr * (i + 1) * (i + 2);
term = Nr / Dr;
i = i + 2;
}
printf ("sine value = %lf", sum);
}