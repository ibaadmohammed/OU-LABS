#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
class string
{
char *str1,*str2;
public:
void concat();
void insert();
int find();
};
void string::concat()
{
char str[80];
cout<<"enter the first string"<<endl;
cin>>str1;
cout<<"enter the second string"<<endl;
cin>>str2;
strcpy(str,str1);
strcpy(str,str2);
cout<<"concatenation string is:"<<str<<endl;
}
void string::insert()
{
cout<<"enter 5 letter and any letter string"<<endl;
cin>>str1>>str2;
}
int string::find()
{
int length1=5,length2=2;
for(int start=0;start<=length1-length2;start++)
{
int j;
for(j=0;j<length2&&str1[start+j]==str2[j];j++)
{
if(j==length2-1)
{
cout<<"pattern matched at position:";
return start;
}
}
}
cout<<"pattern did not match!";
return -1;
}
void menu()
{
cout<<endl;
cout<<"enter your choice"<<endl;
cout<<"1.concatenate 2.pattern matching 3.exit"<<endl;
cout<<endl;
}
void main()
{
int ch;
string s;
clrscr();
menu();
cin>>ch;
while(ch!=4)
{
switch(ch)
{
case 1:s.concat();
break;
case 2:s.insert();
cout<<s.find();
break;
case 3:exit(0);
}
menu();
cin>>ch;
}
getch();
}
