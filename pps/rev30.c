/* A C Program to Display Natural Numbers Upto 30 in Reverse Order */
#include <stdio.h>
void main()
{
    int i;
    i = 30;
    printf("Displaying natural number upto 30 in reverse order\n");
    while (i >= 1)
    {
        printf("%d\t", i);
        i--;
    }
}
