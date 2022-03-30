// 2d scaling

#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
int x1, y1, x2, y2;

void scaling()
{
    int xn1, xn2, yn1, yn2;
    float sx, sy;
    printf("Enter the scaling factor");
    scanf("%f%f", &sx, &sy);
    cleardevice();
    outtextxy(300, 200, "SCALING");
    xn1 = x1 * sx;
    yn1 = y1 * sy;
    xn2 = x2 * sx;
    yn2 = y2 * sy;
    line(x1, y1, x2, y2);
    line(xn1, yn1, xn2, yn2);
    getch();
}

void get()
{
    printf("\n Enter the coordinates x1,y1,x2,y2");
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    outtextxy(200, 100, "ORIGINAL OBJECT");
    line(x1, y1, x2, y2);
    getch();
}

void main()
{
    int ch, gd = DETECT, gm;
    initgraph(&gd, &gm, "c:\\tc\\bgi");
    get();
    cleardevice();
    scaling();
}