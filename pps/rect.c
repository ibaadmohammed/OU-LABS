/* A C Program to Calculate Area and Perimeter of Rectangle */
#include <stdio.h>
void main()
{
    float l, w, area, peri;
    printf("Enter length (l) - ");
    scanf("%f", &l);
    printf("Enter width (w) - ");
    scanf("%f", &w);
    area = l * w;
    peri = 2 * (l + w);
    printf("Area of Rectangle = %f \n perimeter of Rectangle = %f", area, peri);
}
