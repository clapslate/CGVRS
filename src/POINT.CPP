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
