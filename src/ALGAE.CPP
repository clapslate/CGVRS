/**
*Copyright 2009, Mohit Gvalani

*This file is part of CGVRS.
*CGVRS is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
*CGVRS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
*You should have received a copy of the GNU General Public License along with CGVRS.  If not, see <http://www.gnu.org/licenses/>.
*/


#include<graphics.h>
#include<dos.h>
#include<math.h>
#include<iostream.h>
#include<conio.h>
#include<stdio.h>


void printScreen()
{

	cout<<"Screen shot..";
	FILE* writer;

	writer = fopen("CGoutput.gif","wb");

	if(writer==NULL)
		cout<<"Cannot create file!";

		char* gifsign = "GIF87a";
		fwrite(gifsign,sizeof(char),6,writer);
		unsigned char a[23];

	//-----Width of screen(640 pixels)----
		a[0] = 128;
		a[1] = 2;
	//-----Height of screen(480 pixels)----
		a[2] = 224;
		a[3] = 1;
	//-----Resolution & declaration of color map------
		a[4] = 128;
	//-----Background color index in global map------
		a[5] = 0;
	//-----Reserved for future use------
		a[6] = 0;
	//-----Global color map (RGB values)-------
		//---Index 0 - White---
		a[7] = 255;
		a[8] = 255;
		a[9] = 255;
		//---Index 1 - Black---
		a[10] = 0;
		a[11] = 0;
		a[12] = 0;
	//-----Image separator-----
		a[13] = 44;
	//-----Image left co-ordinate------
		a[14] = 0;
		a[15] = 0;
	//-----Image right co-ordinate------
		a[16] = 0;
		a[17] = 0;
	//-----Width of image(640 pixels)----
		a[18] = 128;
		a[19] = 2;
	//-----Height of image(480 pixels)----
		a[20] = 224;
		a[21] = 1;
	//-----Image parameters------
		a[22] = 0;

		fwrite(a,sizeof(char),23,writer);

	//----- Pixel values-------

	int color;
	long count=0;
	unsigned char value=0;

	for(int i=0; i<480; i++)
		for(int j=1; j<=80; j++)
		{
			value = 0;
			for(int k=1;k<=8; k++)
			{
				color = getpixel(j*k,i);
				if(color!=0)
				{
					value+=(unsigned char)pow(2,(8-k));
				}
			}
			fwrite(&value,sizeof(value),1,writer);
			count++;
		}

/*for(int i=0; i<480; i++)
		for(int j=0; j<640; j++)
		{
				color = getpixel(j,i);
				if(color!=0)
					value=0;
				else
					value = 255;
			fwrite(&value,sizeof(value),1,writer);
		}*/

	//-----Terminator------

	value = 59;
	fwrite(&value,sizeof(value),1,writer);
	fclose(writer);
	cout<<"DONE "<<count;
}








double angle = 3.14*30/180;
int x1,y1,theta;
int color = 2;

void algae(int l,double a,int x,int y)
{

	if(l!=0)
	{
	   double a1 = a+angle;
	   double a2 = a-angle;
	   //cout<<"a:"<<a<<" angle:"<<angle;
	   int x1 = x + l*cos(a1);
	   int y1 = y + l*sin(a1);
	   delay(0);
	   setcolor(++color);
	   color = color % 16;
	   if(color==0)color++;
	   line(x,y,x1,y1);
	   algae(l/2,a1,x1,y1);

	   x1 = x + l*cos(a2);
	   y1 = y + l*sin(a2);
	   setcolor(++color);
	   color = color % 16;
	   if(color==0)color++;
	   delay(0);
	   line(x,y,x1,y1);
	   algae(l/2,a2,x1,y1);

	   a1 = a1+angle;
	   a2 = a2-angle;
	   x1 = x + l*cos(a1);
	   y1 = y + l*sin(a1);
	   setcolor(++color);
	   color = color % 16;
	   if(color==0)color++;
	   delay(0);
	   line(x,y,x1,y1);
	   algae(l/2,a1,x1,y1);

	   x1 = x + l*cos(a2);
	   y1 = y + l*sin(a2);
	   setcolor(++color);
	   if(color==0)color++;
	   color = color % 16;
	   delay(0);
	   line(x,y,x1,y1);
	   algae(l/2,a2,x1,y1);
	}
}
/*
void main()
{
	int len=0;
	int gd = DETECT,gm;
	initgraph(&gd,&gm,"");
	cout<<"Enter lenght\n";
	cin>>len;
	int x = getmaxx();
	int y = getmaxy();
	cout<<"max x: "<<x;
	cout<<"max y: "<<y;
	putpixel(x+1,y+1,GREEN);
	putpixel(x-1,y-1,GREEN);
	double ang = 3.14*90/180;
	setcolor(color);
	line(getmaxx()/2,0,getmaxx()/2,len);
	algae(len,ang,getmaxx()/2,len);
	printScreen();
	getch();
}*/
