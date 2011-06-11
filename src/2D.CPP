/**
*Copyright 2009, Mohit Gvalani

*This file is part of CGVRS.
*CGVRS is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
*CGVRS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
*You should have received a copy of the GNU General Public License along with CGVRS.  If not, see <http://www.gnu.org/licenses/>.
*/




#include<stdio.h>
#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include"gvalani.h"

void twoDdisplay(int obj[4][3])
{
	 line(obj[0][0],obj[0][1],obj[1][0],obj[1][1]);
	 line(obj[3][0],obj[3][1],obj[1][0],obj[1][1]);
	 line(obj[2][0],obj[2][1],obj[3][0],obj[3][1]);
	 line(obj[0][0],obj[0][1],obj[2][0],obj[2][1]);
}

void twoDmul(int obj[4][3], int t[3][3])
{
	int r[4][3]={0};

	int i,j;
	for(i=0;i<4;i++)
		for(j=0;j<3;j++)
			for(int k=0;k<3;k++)
	  			r[i][j]+=obj[i][k]*t[k][j];

	for(i=0;i<4;i++)
		for(j=0;j<3;j++)
		{	obj[i][j] = r[i][j];
		       cout<<"obj["<<i<<"]["<<j<<"] = "<<obj[i][j]<<endl;}
}
void dtwoDmul(int obj[4][3], double t[3][3])
{
	double r[4][3]={0.0};
	int i,j;

	for(i=0;i<4;i++)
		for(j=0;j<3;j++)
			for(int k=0;k<3;k++)
	  			r[i][j]+=(double)obj[i][k]*t[k][j];

	for(i=0;i<4;i++)
		for(j=0;j<3;j++)
			obj[i][j] = round(r[i][j]);
}

void twoD(int obj[4][3], int opt)
{
	switch(opt)
	{
		case 1:{	cout<<"Enter translation factor in x & y direction\n";
					int tx,ty;
					cin>>tx>>ty;
					twoDtrans(obj,tx,ty);			// Translation
					twoDdisplay(obj);
					/*char ch;
					if(getch()=='p')
						prtscr("2D-1.bmp");
					break;*/
				}

		case 2:{	cout<<"Enter scaling factor in x & y direction\n";
					int sx,sy;
					cin>>sx>>sy;
					twoDscale(obj,sx,sy);			// Scaling
					twoDdisplay(obj);
					char ch;
					/*if(getch()=='p')
					prtscr("2D-2.bmp");
					break;*/
				}

		case 3:{	cout<<"Enter angle of rotation\n";
					double r,theta;
					cin>>theta;
					r = theta*3.14/180.0;
					twoDrotate(obj,r,(double)obj[0][0],(double)obj[0][1]);	// Rotation
					twoDdisplay(obj);
					char ch;
					/*if(getch()=='p')
					prtscr("2D-3.bmp");
					break;*/
				}

		case 4:{	cout<<"Enter shearing factor in x-direction\n";
					int sx;
					cin>>sx;
					twoDshearX(obj,sx);				// Shearing
					twoDdisplay(obj);
					char ch;
					/*if(getch()=='p')
					prtscr("2D-4.bmp");
					break;*/
				}

		case 5:{	line(0,0,getmaxy(),getmaxy());
					twoDreflect(obj);				// Reflection
					twoDdisplay(obj);
					/*char ch;
					if(getch()=='p')
					prtscr("2D-5.bmp");*/
				}
	}
}


void twoDtrans(int obj[4][3],int tx,int ty)			// Translation function
{
 	int t[3][3]={ {1,0,0},{0,1,0},{tx,ty,1}};
 	twoDmul(obj,t);
}

void twoDscale(int obj[4][3],int sx,int sy)			// Scaling function
{
 	int rx = obj[0][0]*(sx-1);
 	int ry = obj[0][1]*(sy-1);

 	int t[3][3]={ {sx,0,0},{0,sy,0},{0,0,1}};
 	twoDmul(obj,t);
 	twoDtrans(obj,-rx,-ry);
}

void twoDshearX(int obj[4][3],int sx)				// Shearing function
{
	int t[3][3]={{1,0,0},{sx,1,0},{0,0,1}};
	twoDmul(obj,t);
}

void twoDreflect(int obj[4][3])					// Reflection function
{
	int t[3][3]={{0,1,0},{1,0,0},{0,0,1}};
	twoDmul(obj,t);
}

void twoDrotate(int obj[4][3],double x, double xp, double yp)				// Rotation function
{
	double t[3][3]={ {cos(x),sin(x),0},{-sin(x),cos(x),0},{-xp*cos(x)+yp*sin(x)+xp,-xp*sin(x)-yp*cos(x)+yp,1}};
	dtwoDmul(obj,t);
}
/*
void main()
{

  	int j,k;
  	int left,top,right,bottom;

	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "");

  	cout<<"Enter the left, top, right, bottom points of Rectangle"<<endl;
  	cin>>left>>top>>right>>bottom;

	clrscr();
	setlinestyle(0,1,3);
	rectangle(left,top,right,bottom);

	int obj[4][3]={{left,top,1},{right,top,1},{left,bottom,1},{right,bottom,1}};

 	int ch;

    cout<<"1) Translation "<<endl;
	cout<<"2) Scaling "<<endl;
	cout<<"3) Rotation about top-left corner"<<endl;
	cout<<"4) Shearing"<<endl;
	cout<<"5) Reflection about y=x"<<endl;
	cout<<"6)exit "<<endl;
	cout<<"Enter your choice ";
	cin>>ch;

	do
	{
		clrscr();
		setlinestyle(1,1,1);
		twoDdisplay(obj);
		setlinestyle(0,1,3);
		twoD(obj,ch);
		cout<<"Enter your choice ";
		cin>>ch;
	}
	while(ch!=6);

}*/
