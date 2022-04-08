// C++ program to implement midpoint ellipse algorithm
#include <iostream>
#include <graphics.h>
using namespace std;
int main()
{
   int gm = DETECT, gd, xc, yc, rx, ry;
   int x, y, p;
   cout << "Enter Xc, Yc, Rx, Ry : ";
   cin >> xc >> yc >> rx >> ry;
   x = 0;
   y = ry;
   initgraph(&gm, &gd, (char *)"");

   p = (ry * ry) - (rx * rx * ry) + ((rx * rx) / 4);
   while ((2 * x * ry * ry) < (2 * y * rx * rx))
   {
      putpixel(xc + x, yc - y, WHITE);
      putpixel(xc - x, yc + y, WHITE);
      putpixel(xc + x, yc + y, WHITE);
      putpixel(xc - x, yc - y, WHITE);
      if (p < 0)
      {
         x = x + 1;
         p = p + (2 * ry * ry * x) + (ry * ry);
      }
      else
      {
         x = x + 1;
         y = y - 1;
         p = p + (2 * ry * ry * x + ry * ry) - (2 * rx * rx * y);
      }
   }
   p = ((float)x + 0.5) * ((float)x + 0.5) * ry * ry + (y - 1) * (y - 1) * rx * rx - rx * rx * ry * ry;

   while (y >= 0)
   {
      putpixel(xc + x, yc - y, WHITE);
      putpixel(xc - x, yc + y, WHITE);
      putpixel(xc + x, yc + y, WHITE);
      putpixel(xc - x, yc - y, WHITE);

      if (p > 0)
      {
         y = y - 1;
         p = p - (2 * rx * rx * y) + (rx * rx);
      }
      else
      {
         y = y - 1;
         x = x + 1;
         p = p + (2 * ry * ry * x) - (2 * rx * rx * y) - (rx * rx);
      }
   }
   getch();
   closegraph();
   return 0;
}