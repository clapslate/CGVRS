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
#include<math.h>

void dCircle(double xc,double yc, double r)      // DDA Circle
{
     double n = 0;
     while(r>pow(2.0,n))
	n++;

     double e = pow(2.0,-n);

     double x=0,y=r,x2,y2;

     double px = xc;
     double py = yc;

     do
     {
	putpixel(round(px+x),round(py+y),WHITE);
	x2 = x + e*y;
	y2 = y - e*x2;
	x = x2;
	y = y2;

     }while(((r-y)>e)||(x>e));
}
/*
void main()
{
    int gd = DETECT,gm,e;
    initgraph(&gd,&gm,"C:\\TC\\BGI");

    cout<<"Enter x and y co-ordinates for center followed by radius\n";
    double x,y,r;
    cin>>x>>y>>r;

    dCircle(x,y,r);

    getch();

}*/
