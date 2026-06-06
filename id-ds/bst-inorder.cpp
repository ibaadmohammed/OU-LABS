#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
class btnode
{
int data;
btnode *lchild;
btnode *rchild;
public:
btnode(int item)
{
data=item;
lchild=0;
rchild=0;
}
friend btree;
};
class btree
{
public:
btnode *root;
btree()
{
root=NULL;
}
void create(int);
void insert(int);
void inorder(btnode *);
};
void btree::create(int n)
{
int item;
if(n<=0)
return;
cout<<"Enter the root node:";
cin>>item;
root=new btnode(item);
int i=2;
cout<<"Input the remaining child nodes:"<<endl;
while(i<=n)
{
cin>>item;
insert(item);
i++;
}
}
void btree::insert(int item)
{
btnode *p=root;
btnode *q=0;
while(p)
{
q=p;
if(item==p->data)
{
cout<<"Duplicates are not allowed"<<endl;
cout<<"Insert another value"<<endl;
cin>>item;
insert(item);
return;
}
if(item<p->data)
p=p->lchild;
else
p=p->rchild;
}
p=new btnode(item);
if(root==NULL)
root=p;
else
{
if(item<q->data)
q->lchild=p;
else
q->rchild=p;
}
}
void btree::inorder(btnode *current)
{
if(root==NULL)
cout<<"Tree is empty."<<endl;
else
{
if(current!=NULL)
{
inorder(current->lchild);
cout<<current->data<<endl;
inorder(current->rchild);
}
}
}
void menu()
{
cout<<endl;
cout<<"1.Create Tree 2.Insert 3.Display in INORDER 4.Exit"<<endl;
cout<<"Enter your choice."<<endl;
}
void main()
{
btree b;
int ch,n;
clrscr();
menu();
cin>>ch;
while(ch!=5)
{
switch(ch)
{
case 1:cout<<"Enter the nodes to create a tree:";
cin>>n;
b.create(n);
break;
case 2:if(b.root==NULL)
cout<<"Create the tree first."<<endl;
else
{
cout<<"Enter the node value to be inserted:";
cin>>n;
b.insert(n);
}
break;
case 3:cout<<"Tree nodes after traversing in INORDER are:"<<endl;
b.inorder(b.root);
break;
case 4:exit(0);
}
menu();
cin>>ch;
}
getch();
}
