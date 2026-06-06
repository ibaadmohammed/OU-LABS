#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
class sortedlist
{
int a[10],count,i;
public:
sortedlist()
{
count=0;
i=0;
}
int insert(int);
int find(int);
void display();
};
int sortedlist::insert(int x)
{
if(count==10)
cout<<"The list is full"<<endl;
else
{
for(int i=count;i>0 && a[i-1]>x;i--)
{
a[i]=a[i-1];
}
a[i]=x;
count++;
cout<<x<<" is inserted at position:"<<i<<endl;
}
return i;
}
int sortedlist::find(int x)
{
int left=0;
int right=count;
while(left<=right)
{
int mid=(left+right)/2;
if(x>a[mid])
left=mid+1;
else if(x<a[mid])
right=mid-1;
else
{
cout<<x<<" is found at position "<<mid<<endl;
return mid;
}
}
cout<<x<<" is not found."<<endl;
return x;
}
void sortedlist::display()
{
if(count==0)
cout<<"The list is empty"<<endl;
else
{
cout<<"The list elements are:"<<endl;
for(int i=0;i<count;i++)
cout<<a[i]<<endl;
}
}
void menu()
{
cout<<endl;
cout<<"1.Insert 2.Find 3.Display 4.Exit"<<endl;
cout<<"Enter your choice: ";
}
void main()
{
sortedlist s;
int ch,el,e;
clrscr();
menu();
cin>>ch;
while(ch!=5)
{
switch(ch)
{
case 1:cout<<"Enter the element to be inserted"<<endl;
cin>>el;
s.insert(el);
break;
case 2:cout<<"Enter the element to be searched"<<endl;
cin>>el;
s.find(el);
break;
case 3:s.display();
break;
case 4:exit(0);
}
menu();
cin>>ch;
}
getch();
}
