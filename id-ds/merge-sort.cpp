/* ========== PROGRAM 23: MERGE SORT ========== */

#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

class mrgsrtdemo
{
    int a[50];
    public:
    void create(int);
    void merge_sort(int,int);
    void merge(int,int,int);
    void display(int);
};

void mrgsrtdemo::create(int n)
{
    cout<<"\nEnter the numbers to be sorted:"<<endl;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
}

void mrgsrtdemo::merge_sort(int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        merge_sort(low,mid);
        merge_sort(mid+1,high);
        merge(low,mid,high);
    }
}

void mrgsrtdemo::merge(int low,int mid,int high)
{
    int h,i,j,k,b[30];
    h=low;
    i=low;
    j=mid+1;
    while((h<=mid)&&(j<=high))
    {
        if(a[h]<=a[j])
        {
            b[i]=a[h];
            h++;
        }
        else
        {
            b[i]=a[j];
            j++;
        }
        i++;
    }
    if(h>mid)
    {
        for(k=j;k<=high;k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    else
    {
        for(k=h;k<=mid;k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    for(k=low;k<=high;k++)
        a[k]=b[k];
}

void mrgsrtdemo::display(int n)
{
    cout<<"\n The sorted array is :"<<endl;
    for(int i=1;i<=n;i++)
        cout<<a[i]<<endl;
}

void menu()
{
    cout<<endl;
    cout<<"1.Create 2.Sort 3.Display 4.Exit"<<endl;
    cout<<"Enter your choice"<<endl;
}

void main()
{
    mrgsrtdemo m;
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
                   m.create(n);
                   break;
            case 2:m.merge_sort(1,n);
                   cout<<"Array is sorted"<<endl;
                   break;
            case 3:m.display(n);
                   break;
            case 4:exit(0);
        }
        menu();
        cin>>ch;
    }
    getch();
}
