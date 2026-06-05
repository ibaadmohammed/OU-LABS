/* A C Program to Add Two Numbers Using scanf */
#include <stdio.h>
void main()
{
    int a, b, Sum;
    printf("Enter values of a and b\n");
    scanf("%d%d", &a, &b);
    Sum = a + b;
    printf("Addition = %d", Sum);
}
