
// copyleft, Mohit Gvalani

#include<iostream.h>
#include"conio.h"
#include<graphics.h>
#include<dos.h>
#include"gvalani.h"

void getLCP(int&x1,int&y1,int&x2,int&y2,int&xmin,int&ymin,int&xmax,int&ymax);

void MSLclip() 	      // Midpoint Subdivision Line clipping function
{
	int x1,y1,x2,y2,xmin,ymin,xmax,ymax;

	getLCP(x1,y1,x2,y2,xmin,ymin,xmax,ymax);
	cout<<"\nx1="<<x1;
	cout<<"\ny1="<<y1;
	cout<<"\nx2="<<x2;
	cout<<"\ny2="<<y2<<endl;

	int mx,my,mb;
	do
	{
		getcood(&mb,&mx,&my);
	}
	while(mb!=1);
	setcolor(BLACK);
	line(x1,y1,x2,y2);
	setcolor(WHITE);
	call(x1,y1,x2,y2,xmin,ymin,xmax,ymax);
	rectangle(xmin,ymin,xmax,ymax);
}

void call(int x1,int y1,int x2,int y2,int xmin,int ymin,int xmax,int ymax)
{
	if((mod(x1-x2)<2)&&(mod(y1-y2)<2))
		return;

	int r1[4]={0};       // Region Code for point 1
	int r2[4]={0};       // Region Code for point 2

	regionCode(r1,x1,y1,xmin,ymin,xmax,ymax);
	regionCode(r2,x2,y2,xmin,ymin,xmax,ymax);

	int r1z = isRCzero(r1);
	int r2z = isRCzero(r2);

	if((r1z==0)&&(r2z==0))	// Line is visible (Cat 1)
	{
	     line(x1,y1,x2,y2);
	}
	else if(logicalAND(r1,r2)) //If [ r1&r2 !=0]  // Line is invisible (Cat 2)
	{
	    // Segment Invisible
	}
	else	// Line is partially visible or invisible (Cat 3)
	{
		int xm = round((double)(x1+x2)/2.0);
		int ym = round((double)(y1+y2)/2.0);
		call(x1,y1,xm,ym,xmin,ymin,xmax,ymax);
		call(xm,ym,x2,y2,xmin,ymin,xmax,ymax);
	}
}
/*
void main()
{
    int gd = DETECT,gm,e;
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    initmouse();
    showmptr();
    MSLclip();
    getch();
}*/