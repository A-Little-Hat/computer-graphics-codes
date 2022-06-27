#include <iostream>
#include <math.h>
#include <graphics.h>
using namespace std;

int x1, x2, y3, y4, mx, my, depth;

void draw(){
   bar3d(x1, y3, x2, y4, depth, 1);
}

void rotate(){
   float t; int a1, b1, a2, b2, dep;
   printf("Enter the angle to rotate: ");
   scanf("%f", &t);
   t = t * (3.14 / 180);
   a1 = mx + (x1 - mx) * cos(t) - (y3 - my) * sin(t);
   a2 = mx + (x2 - mx) * cos(t) - (y4 - my) * sin(t);
   b1 = my + (x1 - mx) * sin(t) - (y3 - my) * cos(t);
   b2 = my + (x2 - mx) * sin(t) - (y4 - my) * cos(t);
   if (a2 > a1)
      dep = (a2 - a1) / 4;
   else
      dep = (a1 - a2) / 4;
   bar3d(a1, b1, a2, b2, dep, 1);
   setcolor(5);
   draw();
}

void trans(){
   int a1, a2, b1, b2, dep, x, y;
   printf("Enter the transition coordinates:");
   scanf("%d%d", &x, &y);
   a1 = x1 + x;
   a2 = x2 + x;
   b1 = y3 + y;
   b2 = y4 + y;
   dep = (a2 - a1) / 4;
   bar3d(a1, b1, a2, b2, dep, 1);
   setcolor(5);
   draw(); 
}

void scale(){
   int x, y, a1, a2, b1, b2, dep;
   printf("Enter scalling coordinates: ");
   scanf("%d%d", &x, &y);
   a1 = mx + (x1 - mx) * x;
   a2 = mx + (x2 - mx) * x;
   b1 = my + (y3 - my) * y;
   b2 = my + (y4 - my) * y;
   dep = (a2 - a1) / 4;
   bar3d(a1, b1, a2, b2, dep, 1);
   setcolor(5);
   draw();
}

int main(){
   int gd = DETECT, gm, c, choice;
   bool continueLoop = true;
   initgraph(&gd, &gm, (char *)"");
   printf("3D Transformations\n");
   printf("Enter 1st top value(x1,y1): ");
   scanf("%d%d", &x1, &y3);
   printf("Enter right bottom value(x2,y2): ");
   scanf("%d%d", &x2, &y4);
   depth = (x2 - x1) / 4;
   mx = (x1 + x2) / 2;
   my = (y3 + y4) / 2;
   do
   {
   	  draw();
      cout << "Choose an option.." << endl;
      cout << "1. Translation" << endl;
      cout << "2. Rotation" << endl;
      cout << "3. Scaling" << endl;
      cout << "4. Exit" << endl;
      cout << "Enter your choice: ";
      cin >> choice;
      switch (choice)
      {
      case 1:
         trans();
         break;
      case 2:
         rotate();
         break;
      case 3:
         scale();
         break;
      case 4:
         continueLoop = false;
         exit (0);
         break;
      default:
         cout << "Invalid choice!!";
         break;
      }
      getch();
      cleardevice();
   } while (continueLoop);
   return 0;
}