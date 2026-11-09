/* Program to demonstrate Linear search on the list of array elements */
# include <stdio.h>
void main ( )
{
int a [100];
int key, N, position, i;
int linearsearch (int [ ], int, int);
printf ("Enter the size of array: \n");
scanf ("%d", &N);
printf ("Enter %d elements:", N);
for (i=0; i< N; i++)
scanf ("%d", &a [i]);
printf ("Enter the key element: \n");
scanf ("%d", &key);
position = linearsearch (a, N, key);
if (position = = -1)
printf ("element not found !!!");
else
printf ("element found at %d location", position +1);
}
int linearsearch (int a [ ], int N,int key)
{
int i;
for (i = 0; i < N; i++)
{
if (a [i] = = key)
return (i);
}
return (-1);
}