//grp A ASSIGNMENT 1 
/*
Implement a class Complex which represents the Complex Number data type. Implement the following operations:
Constructor (including a default constructor which creates the complex number 0+0i).
Overloaded operator+ to add two complex numbers.
Overloaded operator * to multiply two complex numbers. 
Overloaded << and >> to print and read Complex Numbers
*/
#include<iostream>
using namespace std;
class complex
{
public:
float real,imag;//real no and imaginary no 
complex()   //default constructor
{
real=0;//initialization
imag=0;
}
//declare the functions
//4 functions required= +(friend],*,<<,>>
friend complex operator + (complex,complex);
friend complex operator * (complex,complex);  //com;lex obj ;assing on ()
friend istream & operator >> (istream &,complex &);//istream obj passing in ()
friend ostream & operator << (ostream &,complex &);
};//end class
//without using scope resolution operator
complex operator + (complex obj1, complex obj2)
{
complex temp;
temp.real=obj1.real+obj2.real;
temp.imag=obj1.imag+obj2.imag;
return temp;  //C3=C1+C2
}

complex operator * (complex obj1,complex obj2)
{
complex temp;
temp.real = obj1.real*obj2.real - obj1.imag*obj2.imag;
temp.imag = obj1.real*obj2.imag + obj1.imag*obj2.real;
return temp;
}

//>> istream(keyboard input,<<ostream (monitor)
istream & operator >> (istream &in,complex &obj)
{ 
    cout<<"Enter Real Part";//cin
    in>>obj.real;
    cout<<"Enter Imaginary Part";
    in>>obj.imag;
    return in;

}

ostream & operator << (ostream &out,complex &obj)
{//cout  out
	if(obj.imag>=0)
		out<<obj.real<<"+"<<obj.imag<<"i\n";
	else
		out<<obj.real<<obj.imag<<"i\n";
	return out;
}

int main()
{
complex c1,c2,c3; //objects
cout<<"Initialize c1"<<endl;
cout<<c1; //default constructor //cout<<object
cout<<"initialize c2"<<endl;
cout<<c2;//0,0 //ostream
cout<<"\nEnter Complex Number c1"<<endl;
cin>>c1; //overload operator //istream
cout<<"C1 is "<<c1;
cout<<"\nEnter Complex Num c2"<<endl;
cout<<c2; //real imaginary
cout<<"c2 is"<<c2;
//menu driven code
//ask choices 1.addition 2.multi...(do while switch)


int ch;
do
{
cout<<"\n1.addition\n2.multiplication \n0.Exit"<<endl;
cout<<"Enter your choice";
cin>>ch;
switch(ch)
{
case 0:
break;
case 1:
c3=c1+c2;
cout<<"Addition is : "<<endl;
cout<<c3;
break;   //addition is over
case 2:
c3=c1*c2;
cout<<"multiplication is : "<<endl;
cout<<c3;
break; //multi over
default:
cout<<"Invalid choice"<<endl; 
}//switch
}//do
while(ch!=0);
return 0; //main 
}
