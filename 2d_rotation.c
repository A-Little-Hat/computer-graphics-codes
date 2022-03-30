// 2d rotation
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
int x1,y1,x2,y2;

void rotation()
{
int r;
float rx,xn1,xn2,yn1,yn2;
printf("\n enter the angle for rotation");
scanf("%d",&r);
cleardevice();
outtextxy(500,200,"ROTATION");
rx=(r*3.14)/180;
xn1=x1*cos(rx)-y1*sin(rx);
yn1=y1*cos(rx)+x1*sin(rx);
xn2=x2*cos(rx)-y2*sin(rx);
yn2=y2*cos(rx)+x2*sin(rx);
line(x1,y1,x2,y2);
line(xn1,yn1,xn2,yn2);
getch();
}

void get()
{
printf("\n Enter the coordinates x1,y1,x2,y2");
scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
outtextxy(200,100,"ORIGINAL OBJECT");
line(x1,y1,x2,y2);
getch();
}

void main()
{
int ch,gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\tc\\bgi");
get();
rotation();
}