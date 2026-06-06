#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
class stack
{
public:
int top;
char *stk;
stack(int stacksize)
{
stk=new char[stacksize];
}
char push(char x)
{
top=top+1;
stk[top]=x;
return 1;
}
char pop()
{
char x=stk[top];
top=top-1;
return x;
}
};
class exp
{
private:
char *infix;
public:
exp();
int prec(char);
int rank(char);
char nextchar(int);
void intopost(void);
char *append(char *,char);
};
exp::exp()
{
cout<<"Enter any unparanthesized expression in infix notation:"<<endl;
cout<<"Delimited by #";
cin>>infix;
}
char *exp::append(char *postfix,char ch)
{
int len=strlen(postfix);
postfix[len++]=ch;
postfix[len++]='\0';
return postfix;
}
int exp::prec(char ch)
{
switch(ch)
{
case '+':
case '-':return 1;
case '*':
case '/':
case '%':return 2;
case '$':return 3;
case '#':return 0;
default:return 4;
}
}
int exp::rank(char ch)
{
switch(ch)
{
case '+':
case '-':
case '*':
case '/':
case '%':
case '$':return -1;
default:return 1;
}
}
