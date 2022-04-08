// C++ program to implement Bresenham's Line Algorithm
#include<iostream>  
#include<graphics.h>
#include<math.h> 
using namespace std; 
int main()  
{  
    int gd=DETECT, gm, x1, y1, x2, y2, dx, dy, p, x, y, xEnd;  
    initgraph(&gd, &gm, (char*)"");  
    cout<<"Enter co-ordinates of first point: ";  
    cin>> x1 >> y1;  
     cout<<"Enter co-ordinates of second point: ";  
    cin>> x2 >> y2;   
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
    cout<<"\n("<<x<<","<<y<<")";
    putpixel(x, y, WHITE);
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
        cout<<"\n("<<x<<","<<y<<")";
		putpixel(x,y,WHITE); 
    }
    getch();
    closegraph();
    return 0;  
}
