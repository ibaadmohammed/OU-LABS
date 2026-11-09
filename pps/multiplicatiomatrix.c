/* Program to perform multiplication on two matrices using array */
#include <stdio.h>
void main ( )
{
int x [10][10], y [10][10], z [10][10];
int i, j, r1, c1, r2, c2, t;
printf ("Enter the rows and column for Mat-1: \n");
scanf ("%d %d", &r1,&c1);
printf ("Enter the rows and column for Mat-2: \n");
scanf (“%d %d”, &r2,&c2);
if (c1 = = r2)
{
printf ("Matrix Multiplication possible: \n");
printf ("Enter %d elements for Mat-1:\n", r1*c1);
for (i=0; i< r1; i++)
for (j=0; j< c1; j++)
scanf (“%d”, &x[i][j]);
printf ("Enter %d elements for Mat-2:\n", r2*c2);
for (i=0; i< r2; i++)
for (j=0; j< c2; j++)
scanf (“%d”, &y[i][j]);
for (i=0; i< r1; i++)
{
for (j=0; j< c2; j++)
{
z [i][j] = 0;
for (t = 0; t< c1; t + +)
z [i][j] = z [i][j] + (x [i][t] * y [t][j]);
}
}
printf ("Resultant Matrix: \n");


for (i=0; i< r1; i+ +)
{
for (j=0; j< c2; j++)
printf (“%d \t”, z[i][j]);
printf (“\n”);
}
}
else
printf (“matrix Multiplication is not possible”);
}