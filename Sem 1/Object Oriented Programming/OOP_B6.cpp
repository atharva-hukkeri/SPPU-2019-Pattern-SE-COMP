#include<iostream>
using namespace std;

template<class T>
void sort(T a[10] , int n)
{
    int i,j;
    T temp;
    for ( i = 0; i < n; i++)
    {
        for ( j = i; j < n-1; j++)
        {
            if (a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}
template<class T>
void getdata(T a[10] , int n)
{
    int i;
    cout<<"\n Enter Array Elements ";
    for ( i = 0; i < n; i++)
    {
        cin>>a[i];
    }
}

template<class T>
void display(T a[10], int n)
{
    int i;
    cout<<"\n Display Array Elements ";
    for ( i = 0; i < n; i++)
    {
        cout<<" "<<a[i];
    }    
}

int main()
{
    int n;
    int a[10];
    float b[10];
    int ch;
    do
    {
        cout<<"\n 1.INTEGER ";
        cout<<"\n 2.FLOAT ";
        cout<<"\n ENTER YOUR CHOICE ";
        cin>>ch;
        switch (ch)
        {
        case 1:
        cout<<"\n Sort Integer Array ";
        cout<<"\n Enter Number of Elements in Integer Array ";
        cin>>n;
        getdata(a,n);
        sort(a,n);
        display(a , n);
        break;
        case 2:
        cout<<"\n Sort Float Array ";
        cout<<"\n Enter Number OF Elements in Float Array ";
        cin>>n;
        getdata(b,n);
        sort(b,n);
        display(b , n);
        case 3: exit(0);
        }
    } while (ch!=3);
    return 0;
}
