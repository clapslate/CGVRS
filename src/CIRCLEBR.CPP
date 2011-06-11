/**
*Copyright 2009, Mohit Gvalani

*This file is part of CGVRS.
*CGVRS is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
*CGVRS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
*You should have received a copy of the GNU General Public License along with CGVRS.  If not, see <http://www.gnu.org/licenses/>.
*/




#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include"gvalani.h"

void bCircle(double xc,double yc,double r)	// Bresenham Circle
{
    int d = round(3.0 - 2.0*r);        // Initial d i.e. d1
    int x = 0;
    int y = round(r);

    int px = round(xc);
    int py = round(yc);

    do
    {
	putpixel(px+x,py+y,WHITE);
	putpixel(px-x,py+y,WHITE);
	putpixel(px+x,py-y,WHITE);
	putpixel(px-x,py-y,WHITE);
	putpixel(px+y,py+x,WHITE);
	putpixel(px-y,py+x,WHITE);
	putpixel(px+y,py-x,WHITE);
	putpixel(px-y,py-x,WHITE);

	if(d>=0)
	{
		d+= 4*(x-y)+10;
		y--;
	}
	else
		d+= 4*x+6;

	x++;
    }
    while(x<=y);

}

/*void main()
{
    int gd = DETECT,gm,e;
    initgraph(&gd,&gm,"C:\\TC\\BGI");

    cout<<"Enter x and y co-ordinates for center followed by radius\n";
    double x,y,r;
    cin>>x>>y>>r;

    bCircle(x,y,r);

    getch();

} */
