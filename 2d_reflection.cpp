#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
int main()
{
    int gd=DETECT,gm,s;
    initgraph(&gd,&gm,(char*)"");
    int x1,y1,x2,y2,x3,y3,x4,y4;
    cout<<"Enter the coordinates of the first point: ";
    cin>>x1>>y1;
    cout<<"Enter the coordinates of the second point: ";
    cin>>x2>>y2;
    cout<<"Enter the coordinates of the third point: ";
    cin>>x3>>y3;
    cout<<"Enter the coordinates of the fourth point: ";
    cin>>x4>>y4;
	setcolor(3);
    line(x1,y1,x2,y2);
    line(x1,y1,x3,y3);
    line(x3,y3,x4,y4);
    line(x2,y2,x4,y4);
    getch();
    cout<<"rectangle after reflection"<<endl;
    setcolor(5);
    line(x1,-y1,x2,-y2);
    line(x1,-y1,x3,-y3);
    line(x3,-y3,x4,-y4);
    line(x2,-y2,x4,-y4);
    getch();
}
