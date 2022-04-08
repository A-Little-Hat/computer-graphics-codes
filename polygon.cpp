// polygon drawing
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

int main()
{
    int gdriver = DETECT, gmode, errorcode;
    int maxx, maxy;
    int poly[] = {110, 240, 130, 440, 150, 260, 170, 280, 190, 260, 110, 240};
    initgraph(&gdriver, &gmode, "");
    drawpoly(6, poly);
    getch();
    closegraph();
    return 0;
}
