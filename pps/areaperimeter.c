/* Program to calculate area and perimeter of a circle*/
# include <stdio.h>
void main ( )
{
float r, area, perimeter;
printf ("Enter radius of circle \n");
scanf ("%f", &r);
perimeter = 2 * 3.14 * r;
area= 3.14 * r * r;
printf ("Area of circle is %f", area);
printf ("\n perimeter / circumference is %f", perimeter);