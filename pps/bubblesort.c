/* Program to perform Bubble sort on list of array elements */
# include <stdio.h>
void main ( )
{
int a [100];
int trip, N, i, temp;
printf ("Enter the size of array: \n");
scanf ("%d", &N);
printf ("Enter %d elements: \n", N);
for (i=0; i< N; i++)
{
scanf ("%d", &a [i]);
}
for (trip = 1; trip < N; trip++)
{
for (i=0; i<N-trip; i+ +)
{
if(a[i] > a[i + 1])
{
temp = a[i];
a[i] = a[ i + 1];
a[i + 1] = temp;
}
}
}
printf ("\n the sorted array list is: \n");
for (i=0; i < N; i + +)
printf("%d\t",a[i]);
}