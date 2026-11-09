/* Program illustrating a union */
# include <stdio.h>
union data
{
int x;
double y;
float z;
};
void main ( )
{
union data d;
d.x = 100;
d.y = 300.00;
printf (“integer = %d \n", d.x);
printf (“double = %f \n", d.y);
d.z = 50.00;
printf (“float = %f \n", d.z);
}