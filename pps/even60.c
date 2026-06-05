/* A C Program to Display Even Numbers Upto 60 */
#include <stdio.h>
#include <conio.h>
void main()
{
    int i;
    i = 2;
    printf("Displaying even numbers upto 60");
    while (i <= 60)
    {
        printf("%d\t", i);
        i = i + 2;
    }
}
