/* Program to perform Selection sort on the given list of numbers */
# include <stdio.h>
void main ( )
{
int A [100];
int small, N, i, j, temp;
printf (“Enter the size of array: \n”);
scanf (“%d”, &N);
printf (“\n Enter array elements: \n”, N);
for (i=0; i< N; i++)
scanf (“%d”, &A [i]);
for (i=0; i<N; i + +)
{
small = i;
for (j =i + 1; j < N; j + +)
{
if (A [j] < A[small])
{
small = j;
}
}
temp = A [i];
A [i] = A [small];
A [small] = temp;
}
printf (“\n the sorted array list is: \n”);
for (i = 0; i < N; i + +){
printf (“ %d \t”, A [i]);
}
}