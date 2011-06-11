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

void dLine(double x1,double y1,double x2,double y2)
{
	double dx = x2 - x1;
	double dy = y2 - y1;
	double max;
	if(mod(dx)>mod(dy))
		max = dx;
	else
		max = dy;

	double inx = dx/max;
	double iny = dy/max;

	/*if(inx==0)
		inx++;

	if(iny==0)
		iny++;*/


	//double m = (y2-y1)/(x2-x1);
	putpixel(round(x2),round(y2),WHITE);

	int sx = sign(x2-x1);
	int sy = sign(y2-y1);

	double x = x1;
	double y = y1;

	do
	{
		putpixel(round(x),round(y),WHITE);
		x = x + mod(inx)*sx;
		y = y + mod(iny)*sy;
	}
	while(((x!=x2)||(x1==x2))&&((y!=y2)||(y1==y2)));
}
// x1 == x2 if for vertical lines
// y1 == y2 if for horizontal lines
// If these conditions are removed, we'll get only 2 endpoints as our output.


/*void main()
{
    int gd = DETECT,gm,e;
    initgraph(&gd,&gm,"C:\\TC\\BGI");

    cout<<"Enter x and y co-ordinates of the line endpoints\n";
    double x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    dLine(x1,y1,x2,y2);
    getch();

}*/
