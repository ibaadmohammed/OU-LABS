/* C programming source code to convert octal to binary according to data entered by user. */
#include<stdio.h>
void main()
{
int i=0;
char octnum[100];
printf("Enter any Octal Number : ");
scanf("%s",octnum);
printf("Equivalent Binary Value = ");
while(octnum[i])
{
switch(octnum[i])
{
case '0' : printf("000");
break;
case '1' : printf("001");
break;
case '2' : printf("010");
break;
case '3' : printf("011");
break;
case '4' : printf("100");
break;
case '5' : printf("101");
break;
case '6' : printf("110");
break;
case '7' : printf("111");
break;
default :printf("\nInvalid Octal Digit %c\n",octnum[i]);
break;
}
i++;
}
}