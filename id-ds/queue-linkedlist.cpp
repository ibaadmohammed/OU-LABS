#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
template<class T>
class queueelement
{
T data;
queueelement<T> *next;
friend linkedqueue<T>;
};
template<class T>
class linkedqueue
{
queueelement<T> *front;
queueelement<T> *rear;
public:
linkedqueue();
T frontele();
T rearele();
T enque(T &);
T deque();
void display();
};
template<class T>
T linkedqueue<T>::linkedqueue()
{
front=0;
rear=0;
}
template<class T>
T linkedqueue<T>::frontele()
{
if(front==0)
return 0;
else
return front->data;
}
template<class T>
T linkedqueue<T>::rearele()
{
if(rear==0)
return 0;
else
return rear->data;
}
template<class T>
T linkedqueue<T>::enque(T &x)
{
queueelement<T> *p=new queueelement<T>;
p->data=x;
p->next=0;
rear->next=p;
if(front==0)
front=p;
rear=p;
cout<<x<<"is inserted"<<endl;
return p->data;
}
template<class T>
T linkedqueue<T>::deque()
{
if(front==0)
cout<<"the queue is empty"<<endl;
else
{
queueelement<T> *temp;
temp=front;
front=front->next;
cout<<temp->data<<"is deleted"<<endl;
delete temp;
}
return 0;
}
template<class T>
void linkedqueue<T>::display()
{
queueelement<T> *current;
if(front==0)
cout<<"queue is empty"<<endl;
else
{
cout<<"the queue element are:"<<endl;
for(current=front;current!=0;current=current->next)
cout<<current->data<<endl;
}
}
void menu()
{
cout<<endl;
cout<<"1.front element 2.rear element 3.enque 4.deque 5.display 6.exit"<<endl;
cout<<"enter your choice"<<endl;
}
void main()
{
linkedqueue<int>q;
int fe,re,e,ch;
clrscr();
menu();
cin>>ch;
while(ch!=7)
{
switch(ch)
{
case 1:fe=q.frontele();
cout<<"the first element is:"<<fe<<endl;
break;
case 2:re=q.rearele();
cout<<"the last element is:"<<re<<endl;
break;
case 3:cout<<"enter the elment to be inserted "<<endl;
cin>>e;
q.enque(e);
break;
case 4:q.deque();
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
