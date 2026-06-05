/* A C Program to Calculate Simple Interest */
#include <stdio.h>
void main()
{
    int P, T, R, SI;
    printf("Enter the principle Amount (P) = ");
    scanf("%d", &P);
    printf("Enter the time period (T) = ");
    scanf("%d", &T);
    printf("Enter the rate of interest (R) = ");
    scanf("%d", &R);
    SI = (P * T * R) / 100;
    printf("Simple Interest = %d", SI);
}
