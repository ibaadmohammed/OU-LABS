/* Menu driven program to perform arithmetic operations using switch ( ) statement*/
# include <stdio.h>
void main ( )
{
int a, b, sub, mul, add, div, mod, opt;
printf ("Menu:\n 1.Addition\n 2. Subtraction \n 3.Multiplication \n 4.Division \n 5.Modulo \n");
printf ("Enter option from menu: \n");
scanf ("%d", &opt);
printf ("\n Enter two nos:");
scanf ("%d %d", &a, &b);
switch (opt)
{
case 1: add= a + b;
printf ("\n sum is=%d", add);
break;
case 2: sub= a - b;
printf ("\n difference is=%d", sub);
break;
case 3: mul= a * b;
printf ("\n Product is=%d", mul);
break;
case 4: div= a / b;
printf ("\n Quotient is=%d", div);
break;
case 5: mod= a % b;
printf ("\n Reminder is=%d", mod);
break;
default: printf ("\n Wrong option!!!");
break;
}


}