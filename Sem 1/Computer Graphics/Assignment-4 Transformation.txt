#include<iostream>
#include<graphics.h>
using namespace std;

/************************************* TRANSLATION *****************************/

class tras
{
  int val;
   public:
        
         void setvalue(int temp)
          {
             val=temp;
          }
          
        int disp()
         {
            return(val);
         }
       tras operator+(tras o)
        {
           tras t;
            t.val=val+o.val;
            return(t);
        }
};

/****************************SCALING*********************************/

class scale
{
  int val;
   public:
        
         void setvalue(int temp)
          {
             val=temp;
          }
          
        int disp()
         {
            return(val);
         }
       scale operator*(scale o)
        {
           scale s;
            s.val=val*o.val;
            return(s);
        }
};

/************************************ ROTATION *********************************/

class roto
{

   public:
     
      float b[3][3],a[3][3];
      int x1,y1,x2,y2,x3,y3;
       roto()
       {
         x1=100,y1=100,x2=300,y2=100,x3=150,y3=50;
        
       }      
      
      roto ret()
       {
        roto t1;
         t1.b[0][0]=x1;
         t1.b[0][1]=y1;
         t1.b[0][2]=0;
         t1.b[1][0]=x2;
         t1.b[1][1]=y2;
         t1.b[1][2]=0;
         t1.b[2][0]=x3;
         t1.b[2][1]=y3;
         t1.b[2][2]=1;  
          return(t1);
         
        }
       roto ret1()
     {
       roto t2;
       float t;
       float a1,a2,a3;
         t=45;
         t=t*3.14/180;
         a1=cos(t); 
         a2=sin(t);
         a3=-sin(t);
         t2.a[0][0]=a1;
         t2.a[0][1]=a2;
         t2.a[0][2]=0;
         t2.a[1][0]=a3;
         t2.a[1][1]=a1;
         t2.a[1][2]=0;
         t2.a[2][0]=0;
         t2.a[2][1]=0;
         t2.a[2][2]=1;
        return(t2);
     }
      roto operator*(roto o)
       {
           roto t;
           t.b[0][0]=((b[0][0]*o.a[0][0])+(b[0][1]*o.a[1][0])+(b[0][2]*o.a[2][0]));
           t.b[0][1]=((b[0][0]*o.a[0][1])+(b[0][1]*o.a[1][1])+(b[0][2]*o.a[2][1]));
           t.b[0][2]=((b[0][0]*o.a[0][2])+(b[0][1]*o.a[1][2])+(b[0][2]*o.a[2][2]));
           
           t.b[1][0]=((b[1][0]*o.a[0][0])+(b[1][1]*o.a[1][0])+(b[1][2]*o.a[2][0]));
           t.b[1][1]=((b[1][0]*o.a[0][1])+(b[1][1]*o.a[1][1])+(b[1][2]*o.a[2][1]));
           t.b[1][2]=((b[1][0]*o.a[0][2])+(b[1][1]*o.a[1][2])+(b[1][2]*o.a[2][2]));
           
           t.b[2][0]=((b[2][0]*o.a[0][0])+(b[2][1]*o.a[1][0])+(b[2][2]*o.a[2][0]));
           t.b[2][1]=((b[2][0]*o.a[0][0])+(b[2][1]*o.a[1][0])+(b[2][2]*o.a[2][0]));
           t.b[2][2]=((b[2][0]*o.a[0][0])+(b[2][1]*o.a[1][0])+(b[2][2]*o.a[2][0]));
         
          return(t);
       }
};


/***************************************** MAIN FUNCTION ******************************************/


int main()
 {

/***************************************** TRANSFORMATION ****************************************/
   int gd=DETECT,gm=0;
  int ch;
int x1=100,y1=100,x2=300,y2=100,x3=150,y3=50,tx=50,ty=50;
int a1=100,b1=100,a2=300,b2=100,a3=150,b3=50,sx=2,sy=3;
tras t1,t2,t3,t4,t5,t6,t7,t8;
roto r1,r2,r3,r4;
scale s1,s2,s3,s4,s5,s6,s7,s8;
  do
   {
      cout<<"\n\t\t M E N U";
      cout<<"\n 1.Translation \n 2.Scaling \n 3.Rotation \n Please Enter Your Choice: ";
      cin>>ch;
     switch(ch)
      {
        case 1: 
                 
    		
    
   		
  		  initgraph(&gd,&gm,NULL);
    
    		t1.setvalue(x1);
    		t2.setvalue(y1);
    		t3.setvalue(x2);
    		t4.setvalue(y2);
    		t5.setvalue(x3);
    		t6.setvalue(y3);
    
    		line(x1,y1,x2,y2);
    		line(x2,y2,x3,y3);
    		line(x1,y1,x3,y3);
    
     		t7.setvalue(tx);
     		t8.setvalue(ty);
    
   		setcolor(GREEN);
   
    		t1=t1+t7;
    		t2=t2+t8;
    		t3=t3+t7;
    		t4=t4+t8;
    		t5=t5+t7;
    		t6=t6+t8;
    
     		line(t1.disp(),t2.disp(),t3.disp(),t4.disp());
     		line(t3.disp(),t4.disp(),t5.disp(),t6.disp());
     		line(t1.disp(),t2.disp(),t5.disp(),t6.disp());
    
   		
              break;
      case 2: 
/*********************  SCALING*********************/    		
    		
                initgraph(&gd,&gm,NULL);
    		s1.setvalue(a1);
    		s2.setvalue(b1);
    		s3.setvalue(a2);
    		s4.setvalue(b2);
    		s5.setvalue(a3);
    		s6.setvalue(b3);
    
    		line(a1,b1,a2,b2);
    		line(a2,b2,a3,b3);
    		line(a1,b1,a3,b3);
    
     		s7.setvalue(sx);
     		s8.setvalue(sy);
    
   		setcolor(GREEN);
   
    		s1=s1*s7;
    		s2=s2*s8;
    		s3=s3*s7;
    		s4=s4*s8;
    		s5=s5*s7;
    		s6=s6*s8;
    
     		line(s1.disp(),s2.disp(),s3.disp(),s4.disp());
     		line(s3.disp(),s4.disp(),s5.disp(),s6.disp());
     		line(s1.disp(),s2.disp(),s5.disp(),s6.disp());
    
   	

          break;
/************************************ ROTATION ******************************/

  case 3: 

    		initgraph(&gd,&gm,NULL);
      		r2=r1.ret();
      		r3=r1.ret1();
      		int nx1,ny1,nx2,ny2,nx3,ny3;
      		r4=r2*r3;

		      nx1=r4.b[0][0];     
		      ny1=r4.b[0][1];
		      nx2=r4.b[1][0];
		      ny2=r4.b[1][1];
		      nx3=r4.b[2][0];
		      ny3=r4.b[2][1];
		      
	
		      line(nx1,ny1,nx2,ny2);
		      line(nx2,ny2,nx3,ny3);
		      line(nx3,ny3,nx1,ny1);
		      
		    

           break;

case 4: cout<<"\n\t Thank YOu";
      break;

default: cout<<"\n\t INVALID";
      break;

 }
 getch();
closegraph();
}while(ch!=3);

  return 0;
}
    
         
