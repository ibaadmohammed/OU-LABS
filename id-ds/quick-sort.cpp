/* ========== PROGRAM 22: QUICK SORT ========== */

#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

class quick
{
    int a[50];
    public:
    void create(int);
    void sort(int,int);
    int partition(int *,int,int);
    void display(int);
};

void quick::create(int n)
{
    cout<<"Enter the numbers:"<<endl;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
}

void quick::sort(int p,int q)
{
    if(p<q)
    {
        int j=partition(a,p,q+1);
        sort(p,j-1);
        sort(j+1,q);
    }
}

int quick::partition(int *a,int m,int p)
{
    int v=a[m];
    int i=m,j=p;
    while(i<j)
    {
        do
        {
            i++;
        }
        while(a[i]<v);
        do
        {
            j--;
        }
        while(a[j]>v);
        if(i<j)
        {
            int t;
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    a[m]=a[j];
    a[j]=v;
    return j;
}

void quick::display(int n)
{
    cout<<"The sorted array is:"<<endl;
    for(int i=1;i<=n;i++)
        cout<<a[i]<<endl;
}

void menu()
{
    cout<<endl;
    cout<<"1.Create 2.Sort 3.Display 4.Exit"<<endl;
    cout<<"Enter the choice:"<<endl;
}

void main()
{
    quick q;
    int ch,n;
    clrscr();
    menu();
    cin>>ch;
    while(ch!=5)
    {
        switch(ch)
        {
            case 1:cout<<"Enter the size of array:";
                   cin>>n;
                   q.create(n);
                   break;
            case 2:q.sort(1,n);
                   cout<<"Array is sorted"<<endl;
                   break;
            case 3:q.display(n);
                   break;
            case 4:exit(0);
        }
        menu();
        cin>>ch;
    }
    getch();
}
