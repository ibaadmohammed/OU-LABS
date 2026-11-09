/* Program to Print array elements in reverse order */
# include <stdio.h>
void main ( )
{
void reverse (int *, int);
int a[10], n, i;
printf ("Enter the size: \n");
scanf ("%d", &n);
printf ("Enter %d array elements", n);
for (i = 0; i < n; i + +)
scanf ("%d", &a[i]);
reverse (a, n);
}
void reverse (int * a, int n)
{
int i;
for ( i = n-1, i >= 0; i --)
printf (“%d \t”, a [i]);
}