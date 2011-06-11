// copyleft, Mohit Gvalani

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
