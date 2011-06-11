/**
*Copyright 2009, Mohit Gvalani

*This file is part of CGVRS.
*CGVRS is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
*CGVRS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
*You should have received a copy of the GNU General Public License along with CGVRS.  If not, see <http://www.gnu.org/licenses/>.
*/



#include<iostream.h>
#include"conio.h"
#include<graphics.h>
#include"gvalani.h"

void bLine(double x1,double y1,double x2,double y2)   // Bresenham Line
{
	double dx = x2 - x1;
	double dy = y2 - y1;

	int d = round(2*dy-dx);

	int x = round(x1);
	int y = round(y1);

	int dg0 = round(2*(dy-dx));
	int dl0 = round(2*dy);

	do
	{
		putpixel(x,y,WHITE);
		if(d>=0)
		{
			d+= dg0;
			y++;
		}
		else
			d+= dl0;

		x++;
	}
	while(x!=round(x2));
}

void swap(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}

void gbLine(double x1,double y1,double x2,double y2)  // Generalized Bresenham Line
{
	/*line(0,y1,getmaxx(),y1);
	line(0,y2,getmaxx(),y2);
	line(x1,0,x1,getmaxy());
	line(x2,0,x2,getmaxy());*/

	double dx = mod(x2 - x1);       // delta x
	double dy = mod(y2 - y1);       // delta y

	double m=999999999999999999999999999999.0;

	if(dx!=0)
		m = dy/dx;           // slope of line

	int e = 0;               // flag for exchange
	if(m>1)
	{
		swap(dx,dy);
		swap(x1,y1);     // switch roles of x and y
		swap(x2,y2);
		e = 1;
	}

	int sx = sign(x2-x1);         // gives +1,-1 or 0
	int sy = sign(y2-y1);

	int d = round(2*dy-dx);           // Initial d i.e. d1

	int x = round(x1);         // Scan conversion of (x1,y1)
	int y = round(y1);

	int dg0 = round(2*(dy-dx));   // if d >= 0
	int dl0 = round(2*dy);        // if d < 0

	do
	{
		if(e==0)
			putpixel(mapx(x),mapy(y),WHITE);
		else
			putpixel(mapx(y),mapy(x),WHITE);    // if x,y roles are switched

		if(d>=0)
		{
			d+= dg0;
			y+=sy;
		}
		else
			d+= dl0;

		x+=sx;
	}
	while(x!=round(x2));
}

/*void main()
{
    int gd = DETECT,gm,e;
    initgraph(&gd,&gm,"C:\\TC\\BGI");

    cout<<"Enter min & max x&y coods of window\n";
    double xmin,ymin,xmax,ymax;
    cin>>xmin>>ymin>>xmax>>ymax;
    setViewPort(xmin,ymin,xmax,ymax);
    cout<<"Enter x and y co-ordinates of the line endpoints\n";
    double x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    //bLine(x1,y1,x2,y2);    		Tested for (10,10) to (10000,100000);
    gbLine(x1,y1,x2,y2);            //  Highly inaccurate
    //dLine(x1+10,y1+10,x2+10,y2+10); //  Proper [Aliasing effect]
    //eLine(x1+20,y1+20,x2+20,y2+20); //  Proper [Aliasing effect]
    //line(x1+30,y1+30,x2+30,y2+30);  //  Insanely inaccurate
    //prtscr("Bline6.bmp");
    getch();

	//CONCLUSION - For High resolutions, DDA is better than the rest.
	//	     - For Low resolutions, Bresenham is better than the rest.

} */
