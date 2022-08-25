#include <iostream>
#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>

 //for early binding  ball comes from the top and starts bouncing i (ie.without using virtual function).
//for late binding  ball comes from the bottom and starts bouncing i (ie. using virtual function).
class bouncing_1                    
{

    private:
	float x=1,y,j=0.5,count=0.1,i;
    int k;
    
	public:
    virtual void ball()
    {

 
		 setcolor(BLUE);
		 for( k=0;k<7;k++)
		 {
		  for(i=90;i<270;i+=10)
		  {
		   y=sin(i*3.14/180)/j;
		   if(y>0)
			    y=-y;
			    x+=5;
		       setfillstyle(1,BLUE);
			   circle(x,y*100+200,15);
			   floodfill(x,y*100+200,01);
			   line(0,215,800,215);
			   delay(50);
			   cleardevice();
			   
			   
	

	        
		   
		  }
		 j+=count;
		 count+=0.1;
		 }
		 getch();
		
	 }
	
};

    
    	
    
class bouncing_2 :public bouncing_1
{
	
	private:
	float x=1,y,j=0.5,count=0.1,i;
    int k;
    
	public:
	void ball()
    {

 
		 setcolor(01);
		 for( k=0;k<7;k++)
		 {
		  for(i=0;i<180;i+=10)
		  {
		   y=sin(i*3.14/180)/j;
		   if(y>0)
			    y=-y;
			    x+=5;
		       setfillstyle(1,BLUE);
			   circle(x,y*100+200,15);
			   floodfill(x,y*100+200,01);
			   line(0,215,800,215);
			   delay(50);
			   cleardevice();
			   

	        
		   
		  }
		 j+=count;
		 count+=0.1;
		 }
		 getch();
		
	 }

};

int main()
 {
	 int gd=DETECT,gm ;
	 initgraph(&gd,&gm,NULL);
	 
	 
	 bouncing_1 *ptr1;
	 bouncing_1 obj1;
	 bouncing_2 obj2;
	 
	 ptr1= &obj2;
	 ptr1->ball();
	 
	 closegraph();
	 
	 return 0;

 }




