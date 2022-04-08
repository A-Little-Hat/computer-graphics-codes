// 2d translation
#include<iostream>
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
int x1, y1, x2, y2;

void translation()
{
    int tx, ty, xn1, xn2, yn1, yn2;
    printf("\n Enter the translation\n");
    scanf("%d%d", &tx, &ty);
    cleardevice();
    outtextxy(400, 100, "TRANSLATION");
    xn1 = x1 + tx;
    yn1 = y1 + ty;
    xn2 = x2 + tx;
    yn2 = y2 + ty;
    line(x1, y1, x2, y2);
    line(xn1, yn1, xn2, yn2);
    getch();
}

void get()
{
    printf("\n Enter the coordinates x1,y1,x2,y2 : ");
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    outtextxy(200, 100, "ORIGINAL OBJECT");
    line(x1, y1, x2, y2);
    getch();
}

int main()
{
    int ch, gd = DETECT, gm;
    initgraph(&gd, &gm, "c:\\tc\\bgi");
    get();
    cleardevice();
    translation();
    return 0;
}