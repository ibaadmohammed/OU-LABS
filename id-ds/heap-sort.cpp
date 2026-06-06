/* ========== PROGRAM 24: HEAP SORT ========== */

#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

class heap
{
    int a[100];
    public:
    void create(int);
    void heaps(int);
    void hs(int *,int);
    void heapify(int *,int);
    void adjust(int *,int,int);
    void display(int);
};

void heap::create(int n)
{
    cout<<"Enter the numbers:"<<endl;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
}

void heap::heaps(int n)
{
    hs(a,n);
}

void heap::hs(int *a,int n)
{
    heapify(a,n);
    for(int i=n;i>=2;i--)
    {
        int t=a[i];
        a[i]=a[1];
        a[1]=t;
        adjust(a,1,i-1);
    }
}

void heap::heapify(int *a,int n)
{
    for(int i=n/2;i>=1;i--)
        adjust(a,i,n);
}

void heap::adjust(int *a,int i,int n)
{
    int j=2*i;
    int item=a[i];
    while(j<=n)
    {
        if((j<n)&&(a[j]<a[j+1]))
        {
            j++;
        }
        if(item>=a[j])
            break;
        a[j/2]=a[j];
        j=2*j;
    }
    a[j/2]=item;
}

void heap::display(int n)
{
    cout<<"The sorted array is:"<<endl;
    for(int i=1;i<=n;i++)
        cout<<a[i]<<endl;
}

void menu()
{
    cout<<endl;
    cout<<"1.Create 2.Sort 3.Display 4.Exit:"<<endl;
    cout<<"Enter the choice:"<<endl;
}

void main()
{
    heap h;
    int a[100];
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
                   h.create(n);
                   break;
            case 2:h.heaps(n);
                   cout<<"Array is sorted:"<<endl;
                   break;
            case 3:cout<<"Heap elements are :"<<endl;
                   h.display(n);
                   break;
            case 4:exit(0);
        }
        menu();
        cin>>ch;
    }
    getch();
}
