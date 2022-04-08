// C++ program for reflection through x-axis
#include <graphics.h>
#include <iostream>
using namespace std;
int main()
{
  int gm, gd = DETECT, x1, y1, x2, y2, x3, y3, x4, y4;
  initgraph(&gd, &gm, (char*)"");
  line(getmaxx() / 2, 0, getmaxx() / 2, getmaxy());
  line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2);
  cout<<"Enter four coordinates(x, y) : ";
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
  cout << "Original object - GREEN" << endl;
  setcolor(2);
  line(x1,y1,x2,y2);
    line(x1,y1,x3,y3);
    line(x3,y3,x4,y4);
    line(x2,y2,x4,y4);
  cout<<"Object after reflection through x-axis - YELLOW";
  setcolor(14);
  line(x1, getmaxy() -y1,x2, getmaxy() -y2);
  line(x1, getmaxy() -y1,x3, getmaxy() -y3);             
  line(x3, getmaxy() -y3,x4, getmaxy() -y4);
    line(x2, getmaxy() -y2,x4, getmaxy() -y4);
  getch();
  closegraph();
  return 0;
}