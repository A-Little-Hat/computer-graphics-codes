#include<iostream>
using namespace std;
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>

int main()
{
  int gd = DETECT, gm;
  initgraph(&gd, &gm,(char*)"");
  setcolor(GREEN);
  int arr[] ={50,400,50,300,150,350,250,300,250,400,50,400};
  drawpoly(6, arr);8
//  setfillstyle(WIDE_DOT_FILL,BLUE);
//  fillpoly(6,arr);
  setcolor(YELLOW);
  // line(10,350,450,350);
  int dx,dy,p,xEnd,x,y,x1=10,y1=340,x2=450,y2=340;
    dx=abs(x2-x1);  
    dy=abs(y2-y1);    
    p=2*dy-dx; 
    // Determine which point to start and which point to end
    if(x1 > x2)
  	{
      x = x2;
      y = y2;
      xEnd = x1;
  	}
    else
  	{
      x = x1;
      y = y1;
      xEnd = x2;
  	}
    // cout<<"\n("<<x<<","<<y<<")";
    // putpixel(x, y, WHITE);
//    bool flag=false;
  	while(x<xEnd)  
    {  
        if(p>=0)  
        {  
            y=y+1;  
            p=p+2*dy-2*dx;  
        }  
        else  
        {   
            p=p+2*dy;
        }  
    	x=x+1; 
        // cout<<"\n("<<x<<","<<y<<")";
        if(getpixel(x,y)==GREEN){
          putpixel(x,y,RED);
        }else{
          putpixel(x,y,WHITE);
        }
		    // putpixel(x,y,WHITE); 
    }
  getch();
  closegraph();
  return 0; 
}
