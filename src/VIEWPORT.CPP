/**
*Copyright 2009, Mohit Gvalani

*This file is part of CGVRS.
*CGVRS is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
*CGVRS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
*You should have received a copy of the GNU General Public License along with CGVRS.  If not, see <http://www.gnu.org/licenses/>.
*/




#include<graphics.h>
#include"gvalani.h"

double rx,ry;
int mix,miy;

void setViewPort(int minx, int miny, int maxx, int maxy)
{
      rx = (double)getmaxx()/(double)(maxx-minx);
      ry = (double)getmaxy()/(double)(maxy-miny);
      mix = minx;
      miy = miny;


		// Y-axis
		for(int j=miny;j<maxy;j++)
			putpixel((int)mapx(0),(int)mapy(j),10);

		// X-axis
		for(int k=minx;k<maxx;k++)
			putpixel((int)mapx(k),(int)mapy(0),10);

}

int mapx(int x)
{
	int u = round(rx*(double)(x-mix));
	return u;
}

int mapy(int y)
{
	int v = getmaxy()-round(ry*(double)(y-miy));
	return v;
}
