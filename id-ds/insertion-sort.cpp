/* ========== PROGRAM 25: INSERTION SORT ========== */

#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

class insort
{
    int a[50];
    public:
    void create(int);
    int sort(int);
    void display(int);
};

void insort::create(int n)
{
    cout<<"Enter the numbers:";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
}

int insort::sort(int n)
{
    for(int i=1;i<n;i++)
    {
        for(int j=i;j>0&&a[j-1]>a[j];j--)
        {
            int t;
            t=a[j-1];
            a[j-1]=a[j];
            a[j]=t;
        }
    }
    return 1;
}

void insort::display(int n)
{
    cout<<"The elements are:"<<endl;
    for(int k=0;k<n;k++)
        cout<<a[k]<<endl;
}

void menu()
{
    cout<<endl;
    cout<<"1.Create 2.Sort 3.Display 4.Exit"<<endl;
    cout<<"Enter the choice"<<endl;
}

void main()
{
    insort i;
    int ch,n;
    clrscr();
    menu();
    cin>>ch;
    while(ch!=5)
    {
        switch(ch)
        {
            case 1:cout<<"Enter the size of the array";
                   cin>>n;
                   i.create(n);
                   break;
            case 2:i.sort(n);
                   cout<<"The array is sorted"<<endl;
                   break;
            case 3:i.display(n);
                   break;
            case 4:exit(0);
        }
        menu();
        cin>>ch;
    }
    getch();
}
