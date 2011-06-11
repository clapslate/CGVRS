// copyleft, Mohit Gvalani

#include<iostream.h>
#include"conio.h"
#include<graphics.h>

int round(double a)
{
	int i;
	if(a>=0)
		i = a+0.5;
	else
		i = a-0.5;
	return i;
}

/*void main()
{
    int gd = DETECT,gm,e;
    initgraph(&gd,&gm,"C:\\TC\\BGI");

    cout<<"Enter x and y co-ordinates of the point to be plotted\n";
    double x,y;
    cin>>x>>y;
    int cx = round(x);
    int cy = round(y);
    putpixel(cx,cy,WHITE);
    getch();

}*/
