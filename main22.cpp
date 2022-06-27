#include<iostream>
#include<graphics.h>
using namespace std;

struct vertex
{
    float x;
    float y;
};

vertex sp[40], cw[20];
int n_sp, n_cw;

void draw_poly(vertex vlist[], int n)
{
    for(int i=0; i<n; i++)
        line(vlist[i].x, vlist[i].y, vlist[(i+1)%n].x, vlist[(i+1)%n].y);
}

int in_out(float x, float y, int x1, int y1, int x2, int y2)
{
    float p = (y-y1)*(x2-x1) - (x-x1)*(y2-y1);
    if (p<0)
        return 0;  //for out
    return 1;    //for in
}

void intersection_line(float &x, float &y, float x1, float y1, float x2, float y2, int xa, int ya, int xb, int yb)
{
    if (x2==x1)
    {
        float m2 = (yb-ya) / (xb-xa);
        x = x1;
        y = ya - m2*(xa-x1);
    }
    else if (xb==xa)
    {
        float m1 = (y2-y1) / (x2-x1);
        x = xa;
        y = y1 + m1*(xa-x1);
    }
    else
    {
        float m1 = (y2-y1) / (x2-x1);
        float m2 = (yb-ya) / (xb-xa);
        x = (ya-y1 + m1*x1 - m2*xa) / (m1-m2);
        y = (m1*m2*(xa-x1) + m2*y1 - m1*ya) / (m2-m1);
    }
}

void edge_clip(int cw_x1, int cw_y1, int cw_x2, int cw_y2)
{
    vertex temp[40];
    int j=-1;
    int p1, p2;
    for(int i=0; i<n_sp; i++)
    {
        p1 = in_out(sp[i].x, sp[i].y, cw_x1, cw_y1, cw_x2, cw_y2);
        p2 = in_out(sp[(i+1)%n_sp].x, sp[(i+1)%n_sp].y, cw_x1, cw_y1, cw_x2, cw_y2);
        if (p1==1 && p2==0)
        {
            j++;
            intersection_line(temp[j].x, temp[j].y, sp[i].x, sp[i].y, sp[(i+1)%n_sp].x, sp[(i+1)%n_sp].y, cw_x1, cw_y1, cw_x2, cw_y2);
        }
        else if (p1==0 && p2==1)
        {
            j++;
            intersection_line(temp[j].x, temp[j].y, sp[i].x, sp[i].y, sp[(i+1)%n_sp].x, sp[(i+1)%n_sp].y, cw_x1, cw_y1, cw_x2, cw_y2);
            j++;
            temp[j].x = sp[(i+1)%n_sp].x;
            temp[j].y = sp[(i+1)%n_sp].y;
        }
        else if (p1==1 && p2==1)
        {
            j++;
            temp[j].x = sp[(i+1)%n_sp].x;
            temp[j].y = sp[(i+1)%n_sp].y;
        }
        else
        {
            ;
        }
    }

    for (int i=0; i<=j; i++)
    {
        sp[i].x = temp[i].x;
        sp[i].y = temp[i].y;
    }
    n_sp = j+1;
}

int main()
{
    int gd=DETECT, gm=0;
    initgraph(&gd, &gm,(char*)"");

    cout<<"Enter no. of vertices of clipping window"<<endl;
    cin>>n_cw;
    cout<<"Enter vertices (x,y) clockwise"<<endl;
    for (int i=0; i<n_cw; i++)
        cin>>cw[i].x>>cw[i].y;
    draw_poly(cw, n_cw);
    cout<<"Enter no. of vertices of subject polygon"<<endl;
    cin>>n_sp;
    cout<<"Enter vertices (x,y) clockwise"<<endl;
    for (int i=0; i<n_sp; i++)
        cin>>sp[i].x>>sp[i].y;
    draw_poly(sp, n_sp);

    char ch;
    cout<<"Press a key to clip from an edge of clipping window"<<endl;
    for(int i=0; i<n_cw; i++)
    {
        cin>>ch;
        edge_clip(cw[i].x, cw[i].y, cw[(i+1)%n_cw].x, cw[(i+1)%n_cw].y);
        cleardevice();
        draw_poly(cw, n_cw);
        draw_poly(sp, n_sp);
    }

    getch();
    closegraph();
    return 0;
}
