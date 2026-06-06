#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
template<class T>
struct node
{
T coeff,expo;
node<T> *next;
};
template<class T>
class polynomial
{
private:
node<T> *exp1,*exp2,*result;
public:
polynomial();
void read();
void add();
void show();
};
template<class T>
polynomial<T>::polynomial()
{
exp1=NULL;
exp2=NULL;
result=NULL;
}
template<class T>
void polynomial<T>::read()
{
T m;
cout<<"enter the number of term in equation1:"<<endl;
cin>>m;
T c,e;
for(int i=0;i<m;i++)
{
cout<<"enter coefficient and exponent:"<<endl;
cin>>c>>e;
node<T> *n=new node<T>;
n->coeff=c;
n->next=NULL;
n->expo=e;
n->next=NULL;
if(exp1==NULL)
exp1=n;
else
{
n->next=exp1;
exp1=n;
}
}
cout<<"enter the number of term in equation2:"<<endl;
cin>>m;
for(int j=0;j<m;j++)
{
cout<<"enter coefficient and exponent:"<<endl;
cin>>c>>e;
node<T> *n=new node<T>;
n->coeff=c;
n->next=NULL;
n->expo=e;
n->next=NULL;
if(exp2==NULL)
exp2=n;
else
{
n->next=exp2;
exp2=n;
}
}
}
template<class T>
void polynomial<T>::add()
{
node<T>*t1,*t2;
for(t1=exp1;t1;t1=t1->next)
{
for(t2=exp2;t2;t2=t2->next)
{
if(t1->expo==t2->expo)
{
node<T> *n=new node<T>;
n->expo=t1->expo;
n->coeff=t1->coeff+t2->coeff;
n->next=NULL;
if(result==NULL)
result=n;
else
{
n->next=result;
result=n;
}
t1->expo=0;
t2->expo=0;
}
}
}
for(t1=exp1;t1;t1=t1->next)
{
if(t1->expo!=0)
{
node<T> *n=new node<T>;
n->expo=t1->expo;
n->coeff=t1->coeff;
n->next=result;
result=n;
}
}
for(t1=exp2;t1;t1=t1->next)
{
if(t1->expo!=0)
{
node<T> *n=new node<T>;
n->expo=t1->expo;
n->coeff=t1->coeff;
n->next=result;
result=n;
}
}
}
template<class T>
void polynomial<T>::show()
{
node<T> *t;
cout<<"result of polynomial addition is:"<<endl;
for(t=result;t;t=t->next)
{
if(t->coeff>0)
{
cout<<"+"<<t->coeff<<"x"<<t->expo;
}
else
cout<<t->coeff<<"x"<<t->expo;
}
}
void main()
{
clrscr();
polynomial<int> p;
p.read();
p.add();
p.show();
getch();
}
