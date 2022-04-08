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
  drawpoly(6, arr);
//  setfillstyle(WIDE_DOT_FILL,BLUE);
//  fillpoly(6,arr);
  setcolor(YELLOW);
  line(10,350,450,350);
  getch();
  closegraph();
  return 0;
  
}
