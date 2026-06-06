#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<stdlib.h>
template<class T>
class linearqueue
{
T front;
T rear;
T a[5];
public:
linearqueue();
T enque(T x);
T deque();
void display();
};
template<class T>
T linearqueue<T>::linearqueue()
{
front=0;
rear=-1;
}
template<class T>
T linearqueue<T>::enque(T x)
{
if(rear==4)
cout<<"the queue is full"<<endl;
else
{
rear=rear+1;
a[rear]=x;
cout<<x<<"is inserted"<<endl;
}
return 0;
}
template<class T>
T linearqueue<T>::deque()
{
if(front>rear)
cout<<"the queue is empty"<<endl;
else
{
int x=a[front];
front=front+1;
cout<<x<<"is deleted"<<endl;
}
return 0;
}
template<class T>
void linearqueue<T>::display()
{
for(int i=front;i<=rear;i++)
{
cout<<a[i]<<"\t";
}
}
void menu()
{
cout<<endl;
cout<<"1.enque 2.deque 3.display 4.exit"<<endl;
cout<<endl;
}
void main()
{
linearqueue<int>q;
int e,ch;
clrscr();
menu();
cin>>ch;
while(ch!=5)
{
switch(ch)
{
case 1:cout<<"enter the element to be inserted"<<endl;
cin>>e;
q.enque(e);
break;
case 2:q.deque();
break;
case 3:cout<<"the queue elements are:"<<endl;
q.display();
break;
case 4:exit(0);
break;
}
menu();
cin>>ch;
}
getch();
}
