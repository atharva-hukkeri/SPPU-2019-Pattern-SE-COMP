#include<iostream>
#include<map>
#include<iterator>
using namespace std;

int main()
{
    map<string,int>mym;
    map<string,int>::iterator it;
    mym["China"]=165;
    mym["India"]=135;
    mym["US"]=65;
    mym["Brazil"]=20;

    string n;
    cout<<"\nEnter Country Name: ";
    cin>>n;
    it=mym.find(n);
    if(it!=mym.end())
    {
        cout<<"Country name: "<<(*it).first<<"\nPopulation Is "<<(*it).second;
    }
    else
    {
        cout<<"\n Country Not Is Map Data";
    }
    cout<<"\nMap Data Size "<<mym.size();
    cout<<"\n---My Map--- ";
    cout<<"\nCOUNTRY DATA";
    for (it=mym.begin();it!=mym.end();it++)
    {
        cout<<"\nCOUNTRY NAME: "<<(*it).first<<"\nPopulation: "<<(*it).second;
    }
}