include<iostream.h>
#include<stdlib.h>
#include<conio.h>
template<class T>
class circularqueue
{
T front;
T rear;
T a[5];
int count,i;
 public:
circularqueue();
T enque(T x);
void deque();
void frontele();
void rearele();
void display();
};
template<class T>
T circularqueue<T>::circularqueue()
{
front=0;
rear=-1;
count=0;
}
template<class T>
T circularqueue<T>::enque(T x)
{
if(count==5)
cout<<"the queue is full"<<endl;
else
{
rear=rear+1;
if(rear==5)
rear=0;
a[rear]=x;
count++;
cout<<x<<"is inserted"<<endl;
}
return x;
}
template<class T>
void circularqueue<T>::deque()
{
if(count==0)
cout<<"the queue is empty"<<endl;
else
{
int x=a[front];
front=front+1;
if(front==5)
front=0;
count--;
cout<<x<<"is deleted"<<endl;
}
}
template<class T>
void circularqueue<T>::frontele()
{
if( count==0)
cout<<"queue is empty"<<endl;
else
cout<<"the front element is:"<<a[front]<<endl;
}
template<class T>
void circularqueue<T>::rearele()
{
if(count==0)
cout<<"queue is empty"<<endl;
else
cout<<"the rear element is :"<<a[rear]<<endl;
}
template<class T>
void circularqueue<T>::display()
{
if(count==0)
cout<<"queue is empty"<<endl;
else
{
cout<<"the queue elements are:"<<endl;
if(front>rear)
{
for(i=front;i<5;i++)
cout<<a[i]<<"\t";
for(i=0;i<=rear;i++)
cout<<a[i]<<"\t	";
}
else
{
for(int i=front;i<=rear;i++)
cout<<a[i]<<"\t";
}
}
}
void menu()
{
cout<<endl;
cout<<"1.enque 2.dequeue 3.front element 4.rear element 5.display 6.exit"<<endl;
cout<<endl;
}
void main()
{
circularqueue<int>q;
int e,ch;
clrscr();
menu();
cin>>ch;
while(ch!=7)
{
switch(ch)
{
case 1:cout<<"eneter the element to be inserted"<<endl;
cin>>e;
q.enque(e);
break;
case 2:q.deque();
break;
case 3:q.frontele();
break;
case 4:q.rearele();
break;
case 5:q.display();
break;
case 6:exit(0);
}
menu();
cin>>ch;
}
getch();
}