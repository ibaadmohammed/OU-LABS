/* A C Program to Multiply Two Floating Point Numbers Using scanf */
#include <stdio.h>
void main()
{
    float p, q, product;
    printf("Enter value of p = ");
    scanf("%f", &p);
    printf("Enter value of q = ");
    scanf("%f", &q);
    product = p * q;
    printf("Multiplication = %f", product);
}
