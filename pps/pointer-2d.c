// Program to Display the contents of two dimensional array using pointers.
#include<stdio.h>
void main()
{
int a[3][2]={100,200,300,400,500,600},i,j,*ptr;
ptr=&a[0][0];
for(i=0;i<=3-1;i++)
{
for(j=0;j<=2-1;j++)
{
printf("Element = %d\n",*ptr);
ptr++;
}
}
}