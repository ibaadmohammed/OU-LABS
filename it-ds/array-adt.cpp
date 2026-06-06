#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
class array_adt
{
int a,b[100],count,n;
public:
array_adt();
void create();
void store(int,double);
void retrieve(int);
};
array_adt::array_adt()
{
count=0;
}
void array_adt::create()
{
cout<<"enter the size of array"<<endl;
cin>>a;
for(int i=0;i<a;i++)
b[i]=1;
cout<<"array has been created"<<endl;
}
void array_adt::store(int index,double value)
{
if(index<a)
{
b[index]=value;
count++;
}
else
cout<<"index out of range";
}
void array_adt::retrieve(int index)
{
if(b[index]==-1)
cout<<"no data is available at this index";
else
{
if(count==0)
cout<<"list is empty"<<endl;
else
cout<<"the value is at the index"<<index<<"is:"<<b[index];
}
}
void menu()
{
cout<<"\n 1.create 2.store 3.retrieve 4.exit"<<endl;
cout<<"enter your choice"<<endl;
}
void main()
{
int ch,i;
double v;
array_adt q;
clrscr();
menu();
cin>>ch;
while(ch!=5)
{
switch(ch)
{
case 1:q.create();
break;
case 2:cout<<"enter the index and the value you want to store"<<endl;
cin>>i>>v;
q.store(i,v);
break;
case 3:cout<<"enter the index whose value you want to check"<<endl;
cin>>i;
q.retrieve(i);
break;
case 4:exit(0);
}
menu();
cin>>ch;
}
getch();
}
