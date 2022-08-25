
#include<iostream>
#include<graphics.h>
#include <conio.h>

using namespace std;


class lineClip {
	private :
		int RIGHT = 2,LEFT = 1,TOP = 8,BOTTOM = 4;//1-0001,2-0010,4-0100,8-1000;
		int x1,x2,y1,y2,x,y;
		int xmin=200,ymin=200,xmax=400,ymax=400;
	public : 
		int getcode(int x,int y);
		void clipping();
};

int lineClip :: getcode(int x,int y) {
	int code = 0;
	if(y>ymax)
		code=TOP;
	if(y<ymin)			
		code=BOTTOM;
	if(x<xmin)
		code=LEFT;
	if(x>xmax)
		code=RIGHT;
	return code;
}


void lineClip :: clipping() {
int code1,code2;


cout<<"Rectangle Window "<<endl;
setcolor(15);
rectangle(xmin,ymin,xmax,ymax);

cout<<"\n Enter the line coordinate :";
cout<<"\n Starting Coordinate :";// (100,300)
cin>>x1>>y1;
cout<<"\n Ending coordinate : ";//(500,300)
cin>>x2>>y2;

setcolor(15);
line(x1,y1,x2,y2);
getch();


code1 = getcode(x1,y1);
code2 = getcode(x2,y2);
int temp;

float m;
int accept = 0;
while(1) {
	m = (float)(y2-y1)/(x2-x1);
	
	if(code1 == 0 && code2 ==0) 
	{
		accept = 1;
		break;	
	} 
	else if((code1 & code2) != 0)
	{
		break;
	} 
	else {
		if(code1 == 0)
			temp = code2;
		else
			temp = code1;
		
		if(temp & TOP) {
			x = x1 + (ymax-y1)/m;
			y = ymax;
		}
		else if(temp & BOTTOM) {
			x = x1 + (ymin-y1)/m;
			y = ymin;	
		}
		else if(temp & LEFT){
			y = y1 + m*(xmin-x1);
			x = xmin; 	
		}
		else if(temp & RIGHT){
			y = y1 + m*(xmax-x1);
			x = xmax; 	
		}
		if(temp == code1){
			x1 = x;
			y1 = y;
			code1 = getcode(x1,y2);  
		}else {
			x2 = x;
			y2 = y;
			code2 = getcode(x2,y2);
		}
	}
}


if(accept == 1)
	cleardevice();
    rectangle(xmin,ymin,xmax,ymax);
    setcolor(5);
    line(x1,y1,x2,y2);
getch();
closegraph();



}
int main() 
{
int gd = DETECT,gm;
initgraph(&gd,&gm,NULL);
lineClip obj;
obj.clipping();


return 0;
}

  
