#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

class ITEM
{
    public:
    char name[20];
    int code;
    double cost;
    int qua;
    bool operator ==(const ITEM &i1)
    {
        if (code==i1.code)
        {
            return 1;
            return 0;
        }return 0;
    }
    bool operator<(const ITEM &i1)
    {
        if (code<i1.code)
        {
            return 1;
            return 0;
        }
    }
};

vector<ITEM> v;
void insert()
{
    ITEM i1;
    cout<<"ENTER ITEM DETAILS ";
    cout<<"\nENTER NAME ";
    cin>>i1.name;
    cout<<"\nENTER CODE ";
    cin>>i1.code;
    cout<<"\nENTER COST ";
    cin>>i1.cost;
    cout<<"\nENTER QUANTITY ";
    cin>>i1.qua;
    v.push_back(i1);
}

void print( ITEM &i1)
{
    cout<<"\nDISPLAY ITEM RECORDS ";
    cout<<"\nITEM NAME "<<i1.name<<endl;
    cout<<"\nITEM CODE "<<i1.code<<endl;
    cout<<"\nITEM COST "<<i1.cost<<endl;
    cout<<"\nITEM QUANTITY "<<i1.qua<<endl;
}

void display()
{
    for_each(v.begin(),v.end(),print);
} 

void search()
{
    ITEM i1;
    vector<ITEM>::iterator it;
    cout<<"\nENTER ITEM CODE ";
    cin>>i1.code;
    it=find(v.begin(),v.end(),i1);
    if (it==v.end())
    {
        cout<<"\nITEM NOT FOUND ";
    }
    else
    {
        cout<<"\nITEM FOUND ";
    }
}

void del()
{
    ITEM i1;
    vector<ITEM>::iterator it;
    cout<<"\nENTER CODE ";
    cin>>i1.code;
    it=find(v.begin(),v.end(),i1);
    if (it==v.end())
    {
        cout<<"\nITEM NOT FOUND ";
    }
    else
    {
        cout<<"\n ITEM FOUND ";
        v.erase(it);
    }
}
bool compare(const ITEM &i1 , const ITEM &i2)
{
    return i1.cost<i2.cost;
}

void sortITEM()
{
    sort(v.begin(),v.end(),compare);
}

int main()
{
    int ch;
    do
    {
        cout<<"\n 1.INSERT ";
        cout<<"\n 2.SEARCH ";
        cout<<"\n 3.SORT ";
        cout<<"\n 4.DELETE ";
        cout<<"\n 5.EXIT ";
        cout<<"\n ENTER YOUR CHOICE ";
        cin>>ch;
        switch (ch)
        {
            case 1:
            insert();
            display();
            break;
            case 2:
            search();
            break;
            case 3:
            sortITEM();
            display();
            break;
            case 4:
            del();
            display();
            break;
            case 5: exit(0);
        }
    } while (ch!=5);
return 0;
}