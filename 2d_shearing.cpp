// C++ program to implement 2D shearing 
#include<iostream>
#include<graphics.h>
using namespace std;
int main()
{
  int gd=DETECT,gm;
  int x1,y1,x2,y2,x3,y3,x4, y4, shear_factor, choice;
  initgraph(&gd,&gm,(char*)"");
  cout << "Enter four coordinates(x, y) : ";
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
  cout<< "Do you want to.." <<endl<<"1. Shear along x-axis"<<endl<<"2. Shear along y-axis"<<endl<<"Enter your choice: ";
  cin >> choice;
  cout<<"Enter the shearing factor: ";
  cin >>shear_factor;
  
  cout<<"Original object - WHITE"<<endl;
  line(x1,y1,x2,y2);
  line(x1,y1,x3,y3);
  line(x3,y3,x4,y4);
  line(x2,y2,x4,y4);

  switch(choice) {
    case 1:
      cout<<"Object after shearing through x-axis - RED"<<endl;
      setcolor(RED);
      x1=x1+ y1*shear_factor;
      x2=x2+ y2*shear_factor;
      x3=x3+ y3*shear_factor;
      x4=x4+ y4*shear_factor;
  
      line(x1,y1,x2,y2);
      line(x1,y1,x3,y3);
      line(x3,y3,x4,y4);
      line(x2,y2,x4,y4);
      getch();
      break;
      
    case 2:
      cout<<"Object after shearing through y-axis - RED"<<endl;
      setcolor(RED);
      y1=y1+ x1*shear_factor;
      y2=y2+ x2*shear_factor;
      y3=y3+ x3*shear_factor;
      y4=y4+ x4*shear_factor;
      
      line(x1,y1,x2,y2);
      line(x1,y1,x3,y3);
      line(x3,y3,x4,y4);
      line(x2,y2,x4,y4);
      getch();
      break;
    default: 
      cout<<"Invalid choice!!";
  }
  closegraph();
  return 0;
}