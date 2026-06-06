#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<stdlib.h>
template <class T>
class linearstack
{
T top;
T a[5];
public:
linearstack();
T topele();
T push(T x);
T pop();
void display();
};
template<class T>
T linearstack<T>::linearstack()
{
top=-1;
}
template<class T>
T linearstack<T>::topele()
{
if(top==-1)
return 0;
else
return a[top];
}
template<class T>
T linearstack<T>::push(T x)
{
if(top==4)
cout<<"the stack is overflow"<<endl;
else
{
top=top+1;
a[top]=x;
cout<<x<<"is inserted"<<endl;
}
return 0;
}
template<class T>
T linearstack<T>::pop()
{
T x;
if(top==-1)
cout<<"the stack is underflow"<<endl;
else
{
x=a[top];
top=top-1;
cout<<x<<"is deleted"<<endl;
}
return 0;
}
template<class T>
void linearstack<T>::display()
{
if(top==-1)
cout<<"stack is empty"<<endl;
else
{
cout<<"the stack elements are:"<<endl;
for(T x=top;x>=0;x--)
cout<<a[x]<<endl;
}
}
void menu()
{
cout<<endl;
cout<<"1.top element 2.push 3.pop 4.display 5.exit"<<endl;
cout<<"enter your choice"<<endl;
}
void main()
{
linearstack<int>s;
int te,e,ch;
clrscr();
menu();
cin>>ch;
while(ch!=6)
{
switch(ch)
{
case 1:te=s.topele();
cout<<"the top element is :"<<te<<endl;
case 2:cout<<"enter the element to be inserted"<<endl;
cin>>e;
s.push(e);
break;
case 3:s.pop();
break;
case 4:s.display();
break;
case 5:exit(0);
break;
}
menu();
cin>>ch;
}
getch();
}
