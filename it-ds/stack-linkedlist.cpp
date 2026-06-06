#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
template<class T>
class stackelement
{
T data;
stackelement<T> *next;
friend linkedstack<T>;
};
template<class T>
class linkedstack
{
stackelement<T> *top;
public:
linkedstack();
T topele();
T push(T &);
T pop();
void display();
};
template<class T>
T linkedstack<T>::linkedstack()
{
top=0;
}
template<class T>
T linkedstack<T>::topele()
{
if(top==0)
return 0;
else
return top->data;
}
template<class T>
T linkedstack<T>::push(T &x)
{
stackelement<T> *p=new stackelement<T>;
p->data=x;
p->next=top;
top=p;
cout<<x<<"is pushed into the stack"<<endl;
return p->data;
}
template<class T>
T linkedstack<T>::pop()
{
stackelement<T> *temp=top;
if(top==0)
cout<<"the stack is underflow"<<endl;
else
{
top=top->next;
cout<<temp->data<<"is deleted from the stack"<<endl;
delete temp;
}
return 0;
}
template<class T>
void linkedstack<T>::display()
{
stackelement<T> *current;
if(top==0)
cout<<"the stack is empty"<<endl;
else
{
cout<<"the stack elements are:"<<endl;
for(current=top;current!=0;current=current->next)
cout<<current->data<<endl;
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
linkedstack<int>s;
int te,e,ch;
clrscr();
menu();
cin>>ch;
while(ch!=6)
{
switch(ch)
{
case 1:te=s.topele();
cout<<"the top element is:"<<te<<endl;
break;
case 2:cout<<"enter the elements to be inserted"<<endl;
cin>>e;
s.push(e);
break;
case 3:s.pop();
break;
case 4:s.display();
break;
case 5:exit(0);
}
menu();
cin>>ch;
}
getch();
}
