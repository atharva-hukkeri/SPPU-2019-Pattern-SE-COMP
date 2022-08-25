#include <iostream>
#include <string.h>
using namespace std;
class node
{
	friend class list;
	int prn;
	char name[30];
	node *next; //pointer to object
    public:
	node(int d,char s[10])
	{
	    prn=d;
		strcpy(name,s);
		next=NULL;
	}
};
class list
{
	node *start;
    public:
	list()
    {
		start=NULL;
    }

    void display()
    {
	    node *ptr;
	    ptr=start;
	    cout<<"\n info is : \n";
	    while(ptr!=NULL)
	    {
		    cout<<"\n"<<ptr->prn;
		    cout<<"\t"<<ptr->name;
		    ptr=ptr->next;
	    }
    }

	void insertMember();
	void createMember();
	void insertPresident();
	void insertSecretary();
	void deleteMember();
	void deleteNode();
	void deleteSecretary();
	void deletePresident();
	void count();
	void concatinate(list,list);
};

void list::insertMember()
{
	int prn;
	char name[30];
	node *ptr,*temp;
	cout<<"\n Enter PRN no. : ";
	cin>>prn;
	cout<<"\n Enter Name : ";
	cin>>name;
	temp=new node(prn,name);
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		ptr=start;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;
	}
}
void list::insertPresident()
{
	int prn;
	char name[30];
		node *temp;
		cout<<"\n Enter PRN no. of President : ";
		cin>>prn;
		cout<<"\n Enter Name of President : ";
		cin>>name;
		temp=new node(prn,name);
		temp->next=start;
		start=temp;
}
void list::insertSecretary()
{
	int prn;
	char name[30];
	node *ptr,*temp;
	cout<<"\n Enter PRN no. of Secretary : ";
	cin>>prn;
	cout<<"\n Enter Name of Secretary : ";
	cin>>name;
	temp=new node(prn,name);
	ptr=start;
	while(ptr->next!=NULL)
	{
    	ptr=ptr->next;
	}
	ptr->next=temp;
}
void list::createMember()
{
	int ch;
	char ans;
	do
	{
	    cout<<"\n Choose person to insert: ";
	    cout<<"\n 1-Member\n 2-Secretary\n 3-President"<<endl;
	    cin>>ch;
	    switch(ch)
	    {
	        case 1: insertMember();
		        break;
	        case 2: insertSecretary();
		        break;
	        case 3: insertPresident();
		        break;
	        default:cout<<"Invalid choice ! ";
    		    break;
	    }
	    cout<<"\n Do you want to insert more people? (y/n) ";
	    cin>>ans;
	}while(ans=='y');
}

void list::deleteNode()
{
		int ch;
		char ans;
		do
		{
		    cout<<"\n Choose person to delete : ";
		    cout<<"\n 1-Member\n 2-Secretary\n 3-President"<<endl;
		    cin>>ch;
		    switch(ch)
		    {
		        case 1:deleteMember();
			        break;
		        case 2:deleteSecretary();
			        break;
		        case 3:deletePresident();
			        break;
		        default:cout<<"Invalid choice ! ";
			        break;
		    }
		    cout<<"\n Do you want to delete more people? (y/n)";
		    cin>>ans;
		}while(ans=='y');
	}

void list::deleteSecretary()
{
	node *ptr,*prev;
	ptr=start;
	while(ptr->next!=NULL)
	{
		prev=ptr;
		ptr=ptr->next;
	}
	prev->next=NULL;
	delete ptr;
	cout<<"\n Deleted Secretary";
}
void list::deletePresident()
{
	node *ptr;
		ptr=start;
		start=start->next;
		delete ptr;
		cout<<"\n Deleted President";
}
void list::deleteMember()
{
	node *ptr,*prev;
	int p;
	cout<<"\n Enter PRN no. to delete : ";
	cin>>p;
	ptr=start;
	while(ptr->next!=NULL)
	{
		prev=ptr;
		ptr=ptr->next;
		if(ptr->prn==p)
	        break;
	}

	if(ptr->next==NULL)
	{
		cout<<"\n Data not found !";
	}
	else if(ptr->prn==p)
	{
		prev->next=ptr->next;
		ptr->next=NULL;
		delete ptr;
		cout<<"\n Deleted";
	}
}

void list::count()
{
	node *ptr;
	int cnt=0;
	ptr=start;
	while(ptr!=NULL)
	{
		cnt++;
		ptr=ptr->next;
	}
	cout<<"\n Total no. of member : "<<cnt;
}

void list::concatinate(list s1,list s2)
{
	node *ptr;
	ptr=s1.start;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
		ptr->next=s2.start;
		s1.display();
	}
}
int main()
{
	int ch;
	char ans;
	list sll1,sll2,s1,s2;
	do
	{
		cout<<"\n Enter your choice : ";
	    cout<<"\n 1-Create Member\n 2-Display all members\n 3-Delete a Member\n 4-Count all members\n 5-Concatenate"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1: sll1.createMember();
		        break;
            case 2: sll1.display();
		        break;
            case 3: cout<<"\n Enter the member to be deleted from list : ";
		        sll1.deleteNode();
		        break;
            case 4: cout<<"\n Counting all people: ";
		        sll1.count();
		        break;
            case 5: sll2.createMember();
		        sll1.concatinate(sll1,sll2);
		        break;
            default: cout<<"\n Invalid choice ! ";
		        break;
        }
		cout<<"\n\n Do you want to continue ? (y/n) ";
		cin>>ans;
	}while(ans=='y');
	return 0;
}
