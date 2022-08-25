#include<iostream>
using namespace std;

class Publication    //Base Class
{
    protected:
    string title;
    float price;
    public:
    void getdata()
    {
        cout<<"\n ENTER TITLE";
        cin>>title;
        cout<<"\n ENTER PRICE";
        cin>>price;
    }
    
    void display()
    {
        try         //try catch mechanism for exception
        {
            if(title.length()<=2)
            {
                throw title;
            }
        }
        catch(string s)
        {
            cout<<"\n Title Should be Greater than 2 Characters";
            title="";
        }
        try
        {
            if(price<=0.0)
            {
                throw price;
            }
        }
        catch(float p)
        {
            cout<<"\n Price Is Zero";
            price=0.0;
        }
        cout<<"\n TITLE IS: "<<title;
        cout<<"\n PRICE IS: "<<price;
    }
};

class Book : public Publication    //Drived class
{
    private:
    int pagecount;
    public:
    void getdata()
    {
        Publication::getdata();
        cout<<"\n ENTER PAGE COUNT ";
        cin>>pagecount;
    }
    void display()
        {
            Publication::display();
            try
            {
                if(pagecount<=0)
                {
                    throw pagecount;
                }
            }
            catch(int pc)
            {
                cout<<"\n Pagecount Is ZERO";
                pagecount=0;
            }
            cout<<"\n PAGECOUNT IS: "<<pagecount;
        }
};

class Cassette : public Publication      //Derived Class
{
    private:
    float ptime;
    public:
    void getdata()
    {
        Publication::getdata();
        cout<<"\n PLAY TIME ";
        cin>>ptime;
    }
    void display()
    {
        Publication::display();
        try      //Exception Case
        {
            if(ptime<=0)
            {
                throw ptime;
            }
        }
        catch(float pt)
        {
            cout<<"\n Play Time Exception ";
            ptime=0.0;
        }
        cout<<"\n PLAY TIME OF CASSETTE "<<ptime;
    }
};

int main()
{
    Book b;
    Cassette c;
    b.getdata();
    b.display();
    c.getdata();
    c.display();
    return 0;
}