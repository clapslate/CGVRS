/**
*Copyright 2009, Mohit Gvalani

*This file is part of CGVRS.
*CGVRS is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
*CGVRS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
*You should have received a copy of the GNU General Public License along with CGVRS.  If not, see <http://www.gnu.org/licenses/>.
*/



// Illegal Instruction Error for large polygons

#include<iostream.h>
#include"conio.h"
#include<graphics.h>
#include<dos.h>
//#include"gvalani.h"

void boundaryFill(int x, int y, int bc, int fc)  // 4-connected (8-connected not possible)
{
	int color = getpixel(x,y);
	if((color!=bc)&&(color!=fc))
	{
		putpixel(x,y,fc);
		//delay(1);

		boundaryFill(x+1,y,bc,fc);    // right
		boundaryFill(x,y+1,bc,fc);    // top
		boundaryFill(x-1,y,bc,fc);    // left
		boundaryFill(x,y-1,bc,fc);    // bottom
	}
	else
		return;
}
/*
void main()
{
	int gd = DETECT,gm,e;
	initgraph(&gd,&gm,"C:\\TC\\BGI");

	int n;
	cout<<"Your polygon has how many vertices? Ans - ";
	cin>>n;

	int* polygon = new int[2*n+2];
	cout<<"Enter vertex (x,y) co-ordinates one by one in order\n";

	for(int i=0; i<2*n; i++)
	     cin>>polygon[i];

	polygon[2*n] = polygon[0];
	polygon[2*n+1] = polygon[1];

	int bc;
	cout<<"Enter boundary color - 0 to 15: ";
	cin>>bc;
	setcolor(bc);

	drawpoly(n+1,polygon);

	int fc;
	cout<<"Enter fill color - 0 to 15: ";
	cin>>fc;

	int x,y;
	cout<<"Enter seed point: ";
	cin>>x>>y;
	putpixel(x,y,fc);

	getch();
	clrscr();
	drawpoly(n+1,polygon);
	boundaryFill(x,y,bc,fc);

	getch();

}*/