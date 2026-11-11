/* C programming source code to convert binary to hexadecimal according to data entered by
user. */
#include <stdio.h>
#include <math.h>
void main()
{
long int n;
int decimal=0,i=0,hex,count=0,j=0;
char a[20];
printf("Enter a binary number: ");
scanf("%ld",&n);
while(n!=0)
{
decimal=decimal+(n%10)*pow(2,i);
++i;
n=n/10;
}
while (decimal>0)
{
hex=decimal %16;
decimal=decimal /16;
a[i]=hex;
if (hex==10)
a[i] ='A';
if (hex==11)
a[i] ='B';
if (hex==12)
a[i] ='C';
if (hex==13)
a[i] ='D';
if (hex==14)
a[i] ='E';
if (hex==15)
a[i] ='F';
i++;
count++;
}
for (j=count -1; j>=0; j--)
{
if(a[j]>=65 &&a[j]<=70)
printf("%c", a[j]);
else
printf("%d", a[j]);
}
}