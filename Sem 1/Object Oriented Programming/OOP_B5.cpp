#include<iostream>
#include<fstream>
using namespace std;

class student
{
    public:
    int roll_no;
    float marks;
    char name[30];
    
    void getdata()
    {
        cout<<"\n Enter Student Information ";
        cout<<"\n Enter Roll Number ";
        cin>>roll_no;
        cout<<" MARKS ";
        cin>>marks;
        cout<<"\n NAME ";
        cin>>name;
    }
    void display()
    {
        cout<<"\n ---Student Data--- ";
        cout<<"\n ROLL NUMBER "<<roll_no;
        cout<<"\n MARKS "<<marks;
        cout<<"\n NAME "<<name;
    }
};
int main()
{
    student s[10];
    fstream f;
    int n;
    f.open("student.txt",ios::out);
    if (!f)
    {
        cout<<"\n File Not Created ";
    }
    else
    {
        cout<<"\n Enter Number of Students ";
        cin>>n;
        for (int i = 0; i < n; i++)
        {
            s[i].getdata();
            f.write((char *)&s[i],sizeof(s[i]));
        }
        f.close();
        f.open("student.txt",ios::in);
        if(!f)
        {
            cout<<"\n File not Created ";
        }
        else
        {
            cout<<"\n Display ";
            for(int i=0 ; i<n ; i++)
            {
                f.read((char *)&s[i],sizeof(s[i]));
                s[i].display();
            }
        }
        f.close();
        return 0;
    }
}