/* A C Program to Calculate Area and Perimeter of Square */
#include <stdio.h>
void main()
{
    float a, area, peri;
    printf("Enter length of side(a) - ");
    scanf("%f", &a);
    area = a * a;
    peri = 4 * a;
    printf("Area of Square = %f \n perimeter of Square = %f", area, peri);
}
