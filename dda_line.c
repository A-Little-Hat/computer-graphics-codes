// C++ program to implement DDA line algorithm
#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

int main(){
  int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    int x1, y1, x2, y2;
    cout << "Enter the coordinates of the first point: ";
    cin >> x1 >> y1;
    cout << "Enter the coordinates of the second point: ";
    cin >> x2 >> y2;
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xinc = dx / (float) steps;
    float yinc = dy / (float) steps;
    
    float x = x1;
    float y = y1;
    
    for (int i = 0; i <= steps; i++){
      cout << "(" << x << ", " << y<< ")" << endl;
        putpixel(round(x), round(y), WHITE);
        x += xinc;
        y += yinc;
       
    }
    getch();
    closegraph();
    return 0;
}