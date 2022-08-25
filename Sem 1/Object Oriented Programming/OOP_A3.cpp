#include<iostream>
#include<string.h>  //for string
#include<ctime>   //current date n time
using namespace std;

class student
{
    private:
    char *name,*blood,*address; 
    int dob;
    long int roll_no,tel,license;
    static int count;       //static variables
    float height,weight;
    public:
    
    student() //dynamic constructor
    {
        count++;
        cout<<"";
        name=new char[13]; 
        strcpy(name,"");
        blood=new char[3];
        strcpy(blood,"");
        address=new char[20];
        strcpy(address,"");
        roll_no=0;
        tel=0;
        license=0;
        height=0;
        weight=0;
        dob=0;
        display();
    }
    student(char n[],char b[],int yy,char add[],float w,long int in,long int tn,long int ln,float h)  //parameterized constructor
    {
        count++;
        int len;
        len=strlen(n);
        name=new char[len+1];
        strcpy(name,n);
        len=strlen(b);
        blood=new char[len+1];
        strcpy(blood,b);
        len=strlen(add);
        address=new char[len+1];
        strcpy(address,add);
        dob=yy;
        roll_no=in;
        tel=tn;
        license=ln;
        height=h;
        weight=w;
    }
    void display();     //display declaration
    static int displaycount()  //static member function
    {
        cout<<"\n NUMBER OF ENTRIES ARE:"<<count<<endl;
        return 0;
    }
    ~student()        //destructor having same name
    {
        cout<<"\n destructor called";
    }
};

int student::count=0;
void student::display()  //function definition
{
    cout<<"\n PERSON NAME:"<<name;
    cout<<"\n BLOOD GROUP:"<<blood;
    cout<<"\n DATE OF BIRTH:"<<dob;
    cout<<"\n CONTACT ADDRESS:"<<address;
    cout<<"\n ROLL NUMBER:"<<roll_no;
    cout<<"\n TELEPHONE NUMBER:"<<tel;
    cout<<"\n LICENSE NUMBER:"<<license;
    cout<<"\n HEIGHT:"<<height;
    cout<<"\n WEIGHT:"<<weight<<endl;
}

int main()
{
    int ch; 
    student *p[20],*temp;
    char pname[15],pblood[5],paddress[20];
    long int pinsurance,ptel,plicense;
    float pheight,pweight;
    int cnt=0,dd;
    do
    {
        cout<<"\n ——–MENU——–"<<endl;
        cout<<"\n 1.DEFAULT CONSTRUCTER";
        cout<<"\n 2.PARAMETERIZED CONSTRUCTOR";
        cout<<"\n 3.NUMBER OF ENTRIES";
        cout<<"\n 4.DISPLAY";
        cout<<"\n 5.EXIT";
        cout<<"\n ENTER THE CHOICE:";
        cin>>ch;
        switch(ch)
        {
            case 1:  //DEFAULT CONSTRUCTER INFORMATION
            p[cnt]=new student();
            cnt=cnt+1;
            break;
            case 2:  //PARAMETERIZED CONSTRUCTOR INFORMATION
            cout<<"\n ENTER THE STUDENT NAME:";
            cin>>pname;
            cout<<"\n ENTER THE STUDENT BLOOD GROUP:";
            cin>>pblood;
            cout<<"\n ENTER DATE OF BIRTH:";
            cin>>dd;
            cout<<"\n ENTER THE STUDENT CONTACT ADDRESS:";
            cin>>paddress;
            cout<<"\n ENTER THE STUDENT ROLL NUMBER:";
            cin>>pinsurance;
            cout<<"\n ENTER THE STUDENT MOBILE NUMBER:";
            cin>>ptel;
            cout<<"\n ENTER THE STUDENT LICENSE NUMBER:";
            cin>>plicense;
            cout<<"\n ENTER THE STUDENT HEIGHT:";
            cin>>pheight;
            cout<<"\n ENTER THE STUDENT WEIGHT:";
            cin>>pweight;
            p[cnt]=new student(pname,pblood,dd,paddress,pinsurance,ptel,plicense,pheight,pweight);
            cnt=cnt+1;
            break;
            case 3:  //NUMBER OF ENTRIES INFORMATION
            student::displaycount();
            break;
            case 4:
            for(int i=0;i<cnt;i++)
            {
                p[i]->display();
            }
            break;
            case 5:
            return 0;
        }
    } while(ch!=4);
}