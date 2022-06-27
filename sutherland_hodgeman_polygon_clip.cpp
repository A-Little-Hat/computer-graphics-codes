#include<stdio.h>
// #include<iostream>
// using namespace std;
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
 	int gd,gm,n,*x,i,k=0;
	//window coordinates int wx1=220,wy1=140,wx2=420,wy2=140,wx3=420,wy3=340,wx4=220,wy4=340;
	int w[]={220,140,420,140,420,340,220,340,220,140};//array for drawing window
	detectgraph(&gd,&gm); 
	initgraph(&gd,&gm,""); //initializing graphics
	printf("Window:-");
	setcolor(RED); //red colored window
	drawpoly(5,w); //window drawn
	printf("Enter the no. of vertices of polygon: ");
	scanf("%d",&n);
	x = malloc(n*2+1);
	printf("Enter the coordinates of points:\n");
	k=0;
	for(i=0;i<n*2;i+=2) //reading vertices of polygon
	{
		printf("(x%d,y%d): ",k,k);
		scanf("%d,%d",&x[i],&x[i+1]);
		k++;
	}
	x[n*2]=x[0]; //assigning the coordinates of first vertex to last additional vertex for drawpoly method.
	x[n*2+1]=x[1];
	setcolor(WHITE);
	drawpoly(n+1,x);
	printf("\nPress a button to clip a polygon..");
	getch();
 	setcolor(RED);
 	drawpoly(5,w);
 	setfillstyle(SOLID_FILL,BLACK);
 	floodfill(2,2,RED);
 	gotoxy(1,1); //bringing cursor at starting position
 	printf("\nThis is the clipped polygon..");
 	getch();

 	cleardevice();
 	closegraph();
 	return 0;
}
