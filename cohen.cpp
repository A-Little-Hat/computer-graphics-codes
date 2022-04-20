#include <iostream>
#include <graphics.h>
using namespace std;

int getRegionCode(double x, double y,double x_min,double x_max,double y_min,double y_max)
{
	int code = 0;

	if (x < x_min)
		code = code | 1;
	else if (x > x_max)
		code = code | 2;
	if (y < y_min)
		code = code | 4;
	else if (y > y_max)
		code = code | 8;

	return code;
}

string CSAlgorithm(int code1, int code2, double x1, double y1, double x2, double y2,double x_min,double x_max,double y_min,double y_max){

    //bool clip=true;
    bool outside=false;
    bool inside=false;

    if(code1==0 && code2==0){
    //inside=true;
    return "inside";
    }
    else
    if(code1 & code2){
      return "outside";
    }
    else{
        cout <<"\n\tLine is partially inside and needs to be clipped...\n";

    while(true)
	{
		if(code1==0 && code2==0){
    	break;
        }
        else if (code1 & code2)
		{
			break;
		}
        else{
			double x, y;
			int code;
			if (code1 != 0)
				code = code1;
			else
				code = code2;

			if (code & 8)
			{
				x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
				y = y_max;
			}
			else if (code & 4)
			{
				x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
				y = y_min;
			}
			else if (code & 2)
			{
				y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
				x = x_max;
			}
			else if (code & 1)
			{
				y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
				x = x_min;
			}

			if (code == code1)
			{
				x1 = x;
				y1 = y;
				code1 = getRegionCode(x1, y1,x_min,x_max,y_min,y_max);
			}
			else
			{
				x2 = x;
				y2 = y;
				code2 = getRegionCode(x2, y2,x_min,x_max,y_min,y_max);
			}
        }

	}
        cout <<"\tLine clipped from P(" << x1 << "," << y1 << ") to Q("<< x2 << "," << y2 << ")."<< endl;

    }

return "clipped";
}


int main()
{
    cout<<"\n\t *****************Cohen Sutherland Line Clipping Algorithm *****************\n\n";

    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    double x_max,y_max,x_min,y_min;
    double px,py,qx,qy;

    cout<<"\tEnter the window coordinates : \n";
    cout<<"\tx_min : ";
    cin>>x_min;
    cout<<"\ty_min : ";
    cin>>y_min;
    cout<<"\tx_max : ";
    cin>>x_max;
    cout<<"\tx_max : ";
    cin>>y_max;

    cout <<"\n\tWindow Coordinates:";
    cout <<"\n\tx_min= " << x_min << " , y_min= " << y_min << " , x_max= "<< x_max << " , y_max= " << y_max << "\n" << endl;

    cout<<"\tEnter the line coordinates : \n";
    cout<<"\tPx : ";
    cin>>px;
    cout<<"\tPy : ";
    cin>>py;
    cout<<"\tQx : ";
    cin>>qx;
    cout<<"\tQy : ";
    cin>>qy;

    cout <<"\n\tLine P(" << px << "," << py << ") to Q("<< qx << "," << qy << ") \n"<< endl;

    int code1=getRegionCode(px,py,x_min,x_max,y_min,y_max);
    int code2=getRegionCode(qx,qy,x_min,x_max,y_min,y_max);

    string result=CSAlgorithm(code1,code2,px,py,qx,qy,x_min,x_max,y_min,y_max);


    if(result=="inside"){
        cout <<"\n\tLine P(" << px << "," << py << ") to Q("<< qx << "," << qy << ") is inside the window coordinates. No need to clip"<< endl;
        // draw the output line and the window
        line(px,py,qx,qy);
        rectangle(x_min,y_min,x_max,y_max);
    }
    else if(result=="outside"){
        cout <<"\n\tLine P(" << px << "," << py << ") to Q("<< qx << "," << qy << ") is outside the window coordinates. No need to clip"<< endl;
        // draw the output line and the window
        line(px,py,qx,qy);
        rectangle(x_min,y_min,x_max,y_max);
    } else{
        cout <<"\n\tLine P(" << px << "," << py << ") to Q("<< qx << "," << qy << ") is partially inside and needs to be clipped"<< endl;
        // draw the output line and the window
        line(px,py,qx,qy);
        rectangle(x_min,y_min,x_max,y_max);
    }
    // if(result=="outside")
    //     cout <<"\n\tLine P(" << px << "," << py << ") to Q("<< qx << "," << qy << ") is outside the window coordinates."<< endl;
    getch();
    closegraph();
	return 0;
}