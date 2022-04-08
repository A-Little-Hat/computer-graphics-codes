// implement a Bézier curve in C++

#include <iostream>
#include <graphics.h>
using namespace std;

int main(){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    // user input x1, y1, x2, y2, x3, y3, x4, y4
    int x1 = 100, y1 = 0, x2 = 300, y2 = 300, x3 = 400, y3 = 300, x4 = 400, y4 = 100;
    int x, y;
    // original form according to the formula
    // for(int i=0;i<=1;i+=0.01){
    //     x = (1-i)*(1-i)*(1-i)*x1 + 3*i*(1-i)*(1-i)*x2 + 3*i*i*(1-i)*x3 + i*i*i*x4;
    //     y = (1-i)*(1-i)*(1-i)*y1 + 3*i*(1-i)*(1-i)*y2 + 3*i*i*(1-i)*y3 + i*i*i*y4;
    //     putpixel(x, y, WHITE);
    // }
    for (int i = 0; i <= 100; i += 1){ 
        x = (1 - i / 100.0) * (1 - i / 100.0) * (1 - i / 100.0) * x1 + 3 * (1 - i / 100.0) * (1 - i / 100.0) * i / 100.0 * x2 + 3 * (1 - i / 100.0) * i / 100.0 * i / 100.0 * x3 + i / 100.0 * i / 100.0 * i / 100.0 * x4;
        y = (1 - i / 100.0) * (1 - i / 100.0) * (1 - i / 100.0) * y1 + 3 * (1 - i / 100.0) * (1 - i / 100.0) * i / 100.0 * y2 + 3 * (1 - i / 100.0) * i / 100.0 * i / 100.0 * y3 + i / 100.0 * i / 100.0 * i / 100.0 * y4;
        putpixel(x, y, WHITE);
    }
    getch();
    closegraph();
    return 0;
}
