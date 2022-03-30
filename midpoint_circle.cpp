// C++ program to implement Midpoint circle drawing algorithm
#include <iostream>
#include <graphics.h>
using namespace std;
int main(){
    int gd = DETECT, gm, xc, yc, r;  
    initgraph(&gd, &gm, (char*)"");
    cout << "Enter the coordinates of the center: ";
    cin >> xc >> yc;
    cout << "Enter the radius: ";
    cin >> r;
    int x = 0, y = r, p = 1 - r;
    while (x < y){
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
        if (p < 0){
            p += 2 * x + 3;
        }
        else{
            p += 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
    getch();
    closegraph();
    return 0;
}