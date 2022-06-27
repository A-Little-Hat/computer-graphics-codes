/*
	Program to draw Ellipse using Ellipse Algorithm
	**Check the initgraph() path in your directory if this programs generates error**
	Author: Darshan Gajara		Author Link: http://darshangajara.wordpress.com/
	www.pracspedia.com
*/
#include<graphics.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#include<conio.h>
int main()
{
   int gd = DETECT, gm;
   int xc,yc,x,y;float p;
   long rx,ry;
   initgraph(&gd, &gm,(char*)"");
   cout<<"Enter coordinates of focus : ";
   cin>>xc>>yc;
   cout<<"Enter x,y radius of ellipse: ";
   cin>>rx>>ry;

   //Region 1
   p=ry*ry-rx*rx*ry+rx*rx/4;
   x=0;y=ry;
   while(2.0*ry*ry*x <= 2.0*rx*rx*y)
   {
	if(p < 0)
	{
		x++;
		p = p+2*ry*ry*x+ry*ry;
	}
	else
	{
		x++;y--;
		p = p+2*ry*ry*x-2*rx*rx*y-ry*ry;
	}
	putpixel(xc+x,yc+y,RED);
	putpixel(xc+x,yc-y,RED);
	putpixel(xc-x,yc+y,RED);
	putpixel(xc-x,yc-y,RED);
   }

  //Region 2
   p=ry*ry*(x+0.5)*(x+0.5)+rx*rx*(y-1)*(y-1)-rx*rx*ry*ry;
   while(y > 0)
   {
	if(p <= 0)
	{
		x++;y--;
		p = p+2*ry*ry*x-2*rx*rx*y+rx*rx;
	}
	else
	{
		y--;
		p = p-2*rx*rx*y+rx*rx;
	}
	putpixel(xc+x,yc+y,RED);
	putpixel(xc+x,yc-y,RED);
	putpixel(xc-x,yc+y,RED);
	putpixel(xc-x,yc-y,RED);
   }
   getch();
   closegraph();
}