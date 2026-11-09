/* Program to perform addition on two matrices using array */
#include <stdio.h>
void main ( )
{
int x[10][10], y[10][10], z[10][10];
int i, j, row, col;
printf ("Enter no of rows and column: \n");
scanf ("%d %d", &row,&col);
printf ("Enter Array1 elements: \n");
for (i=0; i< row; i++)
for (j=0; j< col; j++)
scanf (“%d”, &x[i][j]);
printf ("Enter Array2 elements: \n");
for (i=0; i< row; i++)
for (j=0; j< col; j++)
scanf ("%d", &y[i][j]);
for (i=0; i< row; i++)
for (j=0; j< col; i++)
z [i][j] = x [i][j] + y[i][j];
printf ("\n Resultant Matrix: \n");
for (i=0; i< row; i++)
{
for (j=0; j< col; j++)
printf ("%d \t", z[i][j]);
printf ("\n");
}
}