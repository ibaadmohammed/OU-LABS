#include<stdio.h>
void main()
{
int r,c,sp,n,temp;
printf("Enter the number of rows in the pyramid: ");
scanf("%d",&n);
temp=n;
for(r=1; r<=temp; r++)
{
for(sp=1; sp<=n; sp++)
printf(" ");
for(c=1; c<=r; c++)
{
printf("%d",r);
printf(" ");
}
printf("\n");
n=n-1;
}
}