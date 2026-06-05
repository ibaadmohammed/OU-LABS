/* A C Program to Display Weekdays from 1 to 7 */
#include <stdio.h>
void main()
{
    int n;
    printf("Enter a number from 1 to 7\n");
    scanf("%d", &n);
    if (n == 1)
    printf("You entered Monday");
    else if (n == 2)
    printf("You entered Tuesday");
    else if (n == 3)
    printf("You entered Wednesday");
    else if (n == 4)
    printf("You entered Thursday");
    else if (n == 5)
    printf("You entered Friday");
    else if (n == 6)
    printf("You entered Saturday");
    else if (n == 7)
    printf("You entered Sunday");
    else
    printf("Enter a valid number");
}
