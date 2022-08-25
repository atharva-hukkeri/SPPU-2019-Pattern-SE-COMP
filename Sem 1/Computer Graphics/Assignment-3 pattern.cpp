#include <iostream>
#include <graphics.h>
#include <math.h>
#include <conio.h>
using namespace std;
void plotpix(int,int,int,int);

 class patternB
{
	private:
	float x,y,dx,dy,xincr,yincr;
	int x1,x2,y1,y2,i,r,d,length;
	
	public:
	
	void get_rectangle(int a,int b,int c,int d)
	{
		
	
		x1=a,y1=b;
		x2=c,y2=d;
		dx=(x2-x1);
		dy=(y2-y1);
		
		if(dx>=dy)
		{
			length=dx;
			
		}
		
		else
		{
			length=dy;
			
		}
		
		xincr=dx/length;
		yincr=dy/length;
		
		x=x1;
		y=y1;
		
		i=1;
		while(i<=length)
		{
			putpixel(x,y,15);
			x=x+xincr;
			y=y+yincr;
			i=i+1;
		   // delay(1);
			
			
		}
		
    }
		
		
	

    void get_circle(int a,int b,int radius)
	{
		
		x1=a,y1=b;
		r=radius;
		x=0;
		y=r;
		d=3-2*r;
		
		plotpix( x, y, x1, y1);
		
		while(x<y)
		{
			if(d<0)
			{
				d=d+4*x+6;
				x=x+1;
				y=y;
			}
			
			else
			{
				d=d+4*(x-y)+10;
				x=x+1;
				y=y-1;
				
			}
			
		   // delay(1);
		    plotpix(x,y,x1,y1);
		
		}
	
		
		
	}
	

	
};

void plotpix(int x,int y,int x1,int y1)
{
		putpixel(x1+x,y1+y,15);
		putpixel(x1-x,y1+y,15);
		putpixel(x1+x,y1-y,15);
		putpixel(x1-x,y1-y,15);
		putpixel(x1+y,y1+x,15);
		putpixel(x1-y,y1+x,15);
		putpixel(x1+y,y1-x,15);
		putpixel(x1-y,y1-x,15);
		
		
		
		
}


int main()
{
	int gd=DETECT,gm;
	char driver[]="C:\\TC\\BGI";
	initgraph(&gd,&gm,driver);
	patternB obj1,obj2;
	//outer rectangle
	obj1.get_rectangle(200,100,500,100);
	obj1.get_rectangle(200,100,200,300);
	obj1.get_rectangle(200,300,500,300);
	obj1.get_rectangle(500,100,500,300);

	
	//inner figure
	obj2.get_rectangle(200,200,350,300);
	obj2.get_rectangle(350,100,500,200); 
	obj2.get_rectangle(200,200,350,100);
	obj2.get_rectangle(350,300,500,200);
	
	//inner circle
	patternB obj3;
	obj3.get_circle(350,200,84);
	

	getch();
    closegraph();
	return 0;

}
