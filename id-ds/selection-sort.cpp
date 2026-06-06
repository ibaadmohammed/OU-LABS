/* ========== PROGRAM 21: SELECTION SORT ========== */

#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

class selectsort
{
    int a[50];
    public:
    void create(int);
    int sort(int);
    void display(int);
};

void selectsort::create(int n)
{
    cout<<"Enter the numbers:";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
}

int selectsort::sort(int n)
{
    for(int i=n;i>1;i--)
    {
        int max=0;
        for(int j=1;j<i;j++)
        {
            if(a[j]>a[max])
                max=j;
        }
        int t;
        t=a[i-1];
        a[i-1]=a[max];
        a[max]=t;
    }
    return 1;
}

void selectsort::display(int n)
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
    selectsort s;
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
                   s.create(n);
                   break;
            case 2:s.sort(n);
                   cout<<"The array is sorted"<<endl;
                   break;
            case 3:s.display(n);
                   break;
            case 4:exit(0);
        }
        menu();
        cin>>ch;
    }
    getch();
}
