/* Program to print the Fibonacci series*/
# include <stdio.h>
void main ( )
{
int i, n, a=0, b=1, c;
printf ("Enter no of terms to be printed: \n");
scanf ('%d', &n);
printf ("\n Fibonacci Series \n");
for (i=0; i<n; i++)
{
printf ("%d \t", a);
c = a + b;
a = b;
b = c;
}
}