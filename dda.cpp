// C++ program to implement DDA algorithm
#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <math.h>
using namespace std;
int main(){
    int xa,xb,ya,yb,steps,gd=DETECT,gm;
    cout<<"\n enter the 1st point: ";
    cin>>xa>>ya;
    cout<<"\n enter the 2nd point: ";
    cin>>xb>>yb;
    initgraph(&gd,&gm,(char*)"");
    int dx=xb-xa, dy=yb-ya;
    if(abs(dx)>abs(dy)){
        steps = dx;
    }else{
        steps = dy;
    }
    float Xinc = (float)dx/(float)steps;
    float Yinc = (float)dy/(float)steps;
    float X = (float)xa, Y = (float)ya;
    for(int i=0;i<=steps;i++){
        cout<<"("<<round(X)<<","<<round(Y)<<")"<<endl;
        putpixel(round(X), round(Y), WHITE);
        X += Xinc;
        Y += Yinc;
    }
    getch();
    closegraph();
    return 0;
}
