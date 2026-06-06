#include<iostream.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
enum bool{false,true};
class stack
{
public:
int top;
char *stk;
stack(int stacksize)
{
stk=new char[stacksize];
top=-1;
}
char *push(char x)
{
stk[++top]=x;
return stk;
}
char pop()
{
char x=stk[top--];
return x;
}
};
bool isop(int ch)
{
switch(ch)
{
case '+':
case '-':
case '*':
case '/':
case '$':return true;
default:return false;
}
}
float evaluate(char *p)
{
float res,t1,t2;
stack s(strlen(p));
for(int i=0;i<strlen(p);i++)
{
if(!isop(p[i]))
{
s.push(float(p[i]-'0'));
}
else
{
t1=s.pop();
t2=s.pop();
switch(p[i])
{
case '+':res=t2+t1;
break;
case '-':res=t2-t1;
break;
case '*':res=t2*t1;
break;
case '/':res=t2/t1;
break;
case '$':res=pow(t2,t1);
break;
default:cout<<"invalid statement"<<endl;
exit(0);
}
s.push(res);
}
}
return((float)s.stk[s.top]);
}
void main()
{
char *p;
clrscr();
cout<<"enter a postfix expression:"<<endl;
cin>>p;
cout<<"expression value is:"<<evaluate(p)<<endl;
getch();
}
