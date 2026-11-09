/* Program to find the maximum, minimum and sum of given set of numbers*/
#include <stdio.h>
void main ( )
{
int a[20], max, min, sum = 0, i, n;
printf("Enter the size of array: \n");
scanf("%d",&n);
printf("Enter the elements of array: \n");
for (i=0; i<n; i++)
scanf("%d",&a[i]);
max = a[0];
min = a[0];
for (i=0; i<n; i++)
{
if (a[i] > max)
max = a[i];
if (a[i] < min)
min = a[i];
sum = sum + a[i];
}
printf("maximum =%d\n",max);
printf("minimum =%d\n",min);
printf("sum =%d\n",sum);
}