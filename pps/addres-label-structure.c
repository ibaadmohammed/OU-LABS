/* Program to generate address labels using structure */
#include <stdio.h>
struct address
{
char name [20];
charhno [20];
char city [20];
char state [20];
char country [20];
long int pcode;
};
void main ( )
{
int size, i;
struct address a[60];
printf (“Enter no. of students you want to store details for: \n”);
scanf (“%d”, & size);
printf (“Enter data for %d students: \n”, size);
for (i = 0; i < size; i + +)
{
printf (“Enter name, house no, city: \n”);
scanf (“%s %s %s”, a [i].name, a[i].hno, a[i].city);
printf (“Enter state, country and pincode: \n”);
scanf (“%s %s %ld”, a [i].state, a[i].country, &a[i].pcode);
}
printf( "Entered details of %d students: \n", size);
for (i = 0; i < size; i + +)
{
printf (“Student %d \n”, i+1);
printf (“name \t %s \n house no \t%s\ncity\t%s \n state \t %s \n country \t %s \n pincode \t %ld
\n”, a [i].name, a[i]. hno, a[i].city, [i].state, a[i]. country, a[i].pcode);
}
}