/* A C Program to Display Even Numbers Upto 50 */
#include <stdio.h>
void main()
{
    int i;
    printf("Displaying even numbers upto 50\n");
    i = 2;
    do
    {
        printf("%d\t", i);
        i = i + 2;
    }
    while (i <= 50);
}
