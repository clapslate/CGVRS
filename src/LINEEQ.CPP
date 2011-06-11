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

double mod(double a)
{
	if(a>0)
		return a;
	else
		return (-a);
}

int sign(double a)
{
	if(a>0)
		return 1;
	else if(a<0)
		return (-1);
	else
		return 0;
}

void eLine(double x1,double y1,double x2,double y2)	// Uses Line equation directly
{
    //line(x1+10,y1,x2+10,y2);
    double m=999999999999999999999999999999999999999999999999.0;
    if((x2-x1)!=0.0)
	m = (y2-y1)/(x2-x1);

    double b = y1 - m*x1;
    int sx = sign(x2-x1);
    int sy = sign(y2-y1);
    int x = round(x1);
    int y = round(y1);
    putpixel(round(x2),round(y2),WHITE);

    if(mod(m)<=1)
    {
	  do
	  {
		putpixel(x,y,WHITE);
		x=x+sx;
		y = round(m*x + b);

	  }
	  while(x!=round(x2));
    }
    else
    {
	  do
	  {
		putpixel(x,y,WHITE);
		y=y+sy;
		x = round((y-b)/m);

	  }
	  while(y!=round(y2));
    }
}

/*void main()
{
    int gd = DETECT,gm,e;
    initgraph(&gd,&gm,"C:\\TC\\BGI");

    cout<<"Enter x and y co-ordinates of the line endpoints\n";
    double x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    eLine(x1,y1,x2,y2);
    getch();

}*/
