/* A C Program to Check Whether a Number is Positive, Negative or Zero */
#include <stdio.h>
#include <conio.h>
void main()
{
    int n;
    printf("Enter any Integer - ");
    scanf("%d", &n);
    if (n > 0)
    printf("The Integer is positive");
    else if (n < 0)
    printf("The integer is negative");
    else
    printf("The integer is zero");
}
