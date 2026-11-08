#include<stdio.h>
int linear(int,int);//function prototype
void main()
{
int a[2],i,key,ans,n;
printf("Enter number of elements");
scanf("%d",&n);
printf("Enter %d elements\n",n);
for(i=0;i<=n-1;i++)
{
scanf("%d", &a[i]);
}
printf("\nEnter the number to be searched\n");
scanf("%d",&key);
ans=linear(key,0); //function call
if(ans<=n-1)
{
printf("Number (%d) found at position (%d)",key,ans+1);
}
else
{
printf("Didnot find the number (%d)",key);
}
}
int linear(intkey,int position) //function definition
{
if(key==a[position])

Page 33 of 61

{
return position;
}
else
{
position++;
return linear(key,position);//Recursive call
}
}