/* Program to perform binary search on the list of array elements */
# include <stdio.h>
void main ( )
{
int binarysearch (int [ ], int, int);
int a [100];
int N, key, position, i;
printf ("Enter the size of array: \n");
scanf ("%d", &N);
printf ("Enter %d elements in ASCENDING ORDER:", N);
for (i=0; i< N; i++)
scanf ("%d", &a[i]);
printf ("Enter the key element: \n");
scanf ("%d", &key);
position = binarysearch (a, N, key);
if (position = = -1)
printf ("element not found !!!");
else
printf ("element found at %d location", position +1);
}
int binarysearch (int a [ ], int N, int key)
{
int low = 0, high = N-1, middle;
while (low < = high)
{
middle = (low + high) / 2;
if (a [middle] = = key)
return (middle);
else if (key < a [middle])
high = middle–1;
else
low = middle+1;

}
return (-1);
}