/* A C Program to Display Odd Numbers Upto 40 */
#include <stdio.h>
#include <conio.h>
void main()
{
    int i;
    i = 1;
    printf("Displaying odd numbers upto 40");
    while (i <= 40)
    {
        printf("%d\t", i);
        i = i + 2;
    }
}
