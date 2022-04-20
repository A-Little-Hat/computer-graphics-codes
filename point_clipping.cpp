// C++ program for point clipping Algorithm
#include <bits/stdc++.h>
#include "graphics.h"
using namespace std;

// Function for point clipping
void pointClip(int XY[][2], int n, int Xmin, int Ymin, int Xmax, int Ymax)
{
    // graphics view
    // initialize graphics mode
    for (int i = 0; i < n; i++)
    {
        if ((XY[i][0] >= Xmin) && (XY[i][0] <= Xmax))
        {
            if ((XY[i][1] >= Ymin) && (XY[i][1] <= Ymax))
                putpixel(XY[i][0], XY[i][1], 15);
        }
    }

    /**** Arithmetic view ****/
    cout << "Point inside the viewing pane:" << endl;
    for (int i = 0; i < n; i++)
    {
        if ((XY[i][0] >= Xmin) && (XY[i][0] <= Xmax))
        {
            if ((XY[i][1] >= Ymin) && (XY[i][1] <= Ymax))
                cout << "[" << XY[i][0] << "," << XY[i][1] << "] ";
        }
    }

    // print point coordinate outside viewing pane
    cout << "\n"
         << endl;
    cout << "Point outside the viewing pane:" << endl;
    for (int i = 0; i < n; i++)
    {
        if ((XY[i][0] < Xmin) || (XY[i][0] > Xmax))
            cout << "[" << XY[i][0] << "," << XY[i][1] << "] ";
        if ((XY[i][1] < Ymin) || (XY[i][1] > Ymax))
            cout << "[" << XY[i][0] << "," << XY[i][1] << "] ";
    }
}

int main()
{
	// these are points to be checked if this is in the visible are or not... user input
    int XY[7][2] = {{10, 10},
    				{25, 105},
                    {-10, 10},
                    {400, 100},
                    {100, 400},
                    {400, 400},
                    {100, 40}};
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int Xmin = 0;
    int Xmax = getmaxx();
    int Ymin = 0;
    int Ymax = getmaxy();
    pointClip(XY, 7, Xmin, Ymin, Xmax, Ymax);
    getch();
    closegraph();
    return 0;
}
