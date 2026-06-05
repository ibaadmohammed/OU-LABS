/* A C Program to Calculate Area and Perimeter of Circle */
#include <stdio.h>
void main()
{
    float r, area, peri;
    printf("Enter radius");
    scanf("%f", &r);
    area = 3.14 * r * r;
    peri = 2 * 3.14 * r;
    printf("Area of Circle = %f \n perimeter of Circle = %f", area, peri);
}
