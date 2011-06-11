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
#include<dos.h>
#include"gvalani.h"

int mousex,mousey,mousebutton;

void getLCP(int&x1,int&y1,int&x2,int&y2,int&xmin,int&ymin,int&xmax,int&ymax )     // get Line Clipping parameters
{
   int ms = 200;           // Delay between 2 clicks = 'ms' milliseconds

//------------------------- FIRST CLICK ------------------------------
   do
   {
		getcood(&mousebutton,&x1,&y1);
   }
   while(mousebutton!=1);
   delay(ms);

//------------------------- SECOND CLICK ------------------------------
   do
   {
		hidemptr();
		setcolor(BLACK);
		line(x1,y1,x2,y2);
		getcood(&mousebutton,&x2,&y2);
		setcolor(WHITE);
		line(x1,y1,x2,y2);
		showmptr();
   }
   while(mousebutton!=1);

   hidemptr();
   delay(ms);
   dLine(x1,y1,x2,y2);
   showmptr();

//------------------------- THIRD CLICK ------------------------------
   do
   {
		getcood(&mousebutton,&xmin,&ymin);
   }
   while(mousebutton!=1);

   cout<<"The 2nd click for rectangle should be to the right-bottom of 1st click";
   delay(ms);

//------------------------- FOURTH CLICK ------------------------------
   do
   {
		hidemptr();
		setcolor(BLACK);
		rectangle(xmin,ymin,xmax,ymax);
		getcood(&mousebutton,&xmax,&ymax);
		setcolor(WHITE);
		line(x1,y1,x2,y2);
		rectangle(xmin,ymin,xmax,ymax);
		showmptr();
   }
   while(mousebutton!=1);

   hidemptr();
   delay(ms);
   rectangle(xmin,ymin,xmax,ymax);
   showmptr();
}
//-----------------------------------------------------------------------

void regionCode(int r[4],int x,int y,int xmin,int ymin,int xmax,int ymax )
{
     r[0] = y>ymax? 1:0; // A  //cout<<"\nRC  r[0]: "<<r[0];
     r[1] = y<ymin? 1:0; // B  //cout<<"/r[1]: "<<r[1];
     r[2] = x>xmax? 1:0; // R  //cout<<"/r[2]: "<<r[2];
     r[3] = x<xmin? 1:0; // L  //cout<<"/r[3]: "<<r[3];
}
//--------------------------------------------------------------------

int isRCzero(int r[4])	//is Region Code zero?
{
	for(int i=0; i!=4; i++)
	{
		//cout<<endl<<"r["<<i<<"]: "<<r[i];
		if(r[i]==1)
			return 1;
	}
	return 0;
}
//--------------------------------------------------------------------
/*
void reinit(int r[4])
{
	for(int i=0; i!=4; i++)
		r[i] = 0;
}

int isRCsame(int r1[4], int r2[4])
{
	for(int i=0; i!=4; i++)
		if(r1[i]!=r2[i])
			return 0;

	return 1;
}
*/
//--------------------------------------------------------------------

int logicalAND(int r1[4], int r2[4])
{
	for(int i=0; i!=4; i++)
		if((r1[i]&r2[i])==1)
			return 1;

	return 0;
}
//--------------------------------------------------------------------

void CSLclip()  // Cohen - Sutherland Line Clipping function
{
	int x1,y1,x2,y2,xmin,ymin,xmax,ymax;
	int r1[4]={0};       // Region Code for point 1
	int r2[4]={0};       // Region Code for point 2

	getLCP(x1,y1,x2,y2,xmin,ymin,xmax,ymax);

	do
	{
		getcood(&mousebutton,&mousex,&mousey);
	}
	while(mousebutton!=1);
	//prtscr("CSclipB5.bmp");
	regionCode(r1,x1,y1,xmin,ymin,xmax,ymax);
	regionCode(r2,x2,y2,xmin,ymin,xmax,ymax);

	int r1z = isRCzero(r1);
	int r2z = isRCzero(r2);

	//cout<<endl<<"r1z & r2z: "<<r1z<<r2z;
	//cout<<"\nxmin: "<<xmin<<"\nymin: "<<ymin<<"\nxmax: "<<xmax<<"\n ymax: "<<ymax;
	//cout<<"\nx1: "<<x1<<"\ny1: "<<y1<<"\nx2: "<<x2<<"\ny2: "<<y2;

	if((r1z==0)&&(r2z==0))	// Line is visible (Cat 1)
	{}
	else if(logicalAND(r1,r2)) //If [ r1&r2 !=0]  // Line is invisible (Cat 2)
	{
		setcolor(BLACK);
		line(x1,y1,x2,y2);
		cout<<"Invisible\n";
	}
	else	// Line is partially visible or invisible (Cat 3)
	{
	     double m = (double)(y2-y1)/(double)(x2-x1);      // slope

	     setcolor(BLACK);
	     line(x1,y1,x2,y2);

	     //cout<<endl<<x1<<endl<<y1<<endl<<m;

//--------------------------POINT 1-----------------------------

	     int count = 2;       // refer gvalani notes for explanation of count
	     do
	     {
			 if(r1[0]==1)
			 {
				x1 = x1 + round((double)(ymax - y1)/m);     //Intersection with y = ymax
				y1 = ymax;
			 }
			 if(r1[1]==1)
			 {
				x1 = x1 + round((double)(ymin - y1)/m);    //Intersection with y = ymin
				y1 = ymin;
			 }
			 if(r1[2]==1)
			 {
				y1 = y1 + round((double)(xmax - x1)*m);   //Intersection with x = xmax
				x1 = xmax;
			 }
			 if(r1[3]==1)
			 {
				y1 = y1 + round((double)(xmin - x1)*m);   //Intersection with x = xmin
				x1 = xmin;
			 }

			 count--;
			 regionCode(r1,x1,y1,xmin,ymin,xmax,ymax);
	     }
	     while(count);

	     regionCode(r1,x1,y1,xmin,ymin,xmax,ymax);
	     if(isRCzero(r1)==0)
		 dLine(x1,y1,x2,y2);

	     //cout<<endl<<x1<<endl<<y1<<endl<<m<<endl;

//---------------------------POINT 2----------------------------------

		 setcolor(BLACK);
	     line(x1,y1,x2,y2);
	     //cout<<endl<<x2<<endl<<y2<<endl<<m;

	     count = 2;

	     do
	     {
			 if(r2[0]==1)
			 {
				x2 = x2 + round((double)(ymax - y2)/m);      //Intersection with y = ymax
				y2 = ymax;
			 }
			 if(r2[1]==1)
			 {
				x2 = x2 + round((double)(ymin - y2)/m);     //Intersection with y = ymin
				y2 = ymin;
			 }
			 if(r2[2]==1)
			 {
				y2 = y2 + round((double)(xmax - x2)*m);     //Intersection with x = xmax
				x2 = xmax;
			 }
			 if(r2[3]==1)
			 {
				y2 = y2 + round((double)(xmin - x2)*m);     //Intersection with x = xmin
				x2 = xmin;
			 }

			 count--;
			 regionCode(r2,x2,y2,xmin,ymin,xmax,ymax);
	     }
	     while(count);

	     regionCode(r2,x2,y2,xmin,ymin,xmax,ymax);
	     if(isRCzero(r2)==0)
		 dLine(x1,y1,x2,y2);
	}
	//prtscr("CSclipA5.bmp");
}
/*
void main()
{
    int gd = DETECT,gm,e;
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    initmouse();
    showmptr();
    CSLclip();
    getch();
}
*/