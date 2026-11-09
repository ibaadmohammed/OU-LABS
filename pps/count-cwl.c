/* C program for counting number of characters, words and lines in the given text file*/
#include <stdio.h>
void main ( )
{
int nc=0, nw = 0, nl = 1;
int s = 0;
char ch;
printf("Enter lines of text and press F6. Press enter to see the output:\n");
while ( (ch = getchar( ) ) != EOF)
{
nc++;
if (ch == '\n')
nl++;
if ((ch == ' ') || (ch == '\n'))
s = 0;
else if ( s == 0)
{
s = 1;
nw ++;
}
}
printf("Characters =%d\n",nc);
printf("Words =%d\n",nw);
printf("Lines =%d\n",nl);
}