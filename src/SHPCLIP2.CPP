/**
*Copyright 2009, Mohit Gvalani

*This file is part of CGVRS.
*CGVRS is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
*CGVRS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
*You should have received a copy of the GNU General Public License along with CGVRS.  If not, see <http://www.gnu.org/licenses/>.
*/



// There's some distortion after clipping!
// Horizontal lines would give divide by zero error. make sure no two x values are same,
// Else modify the code appropriately - intersection point wala section

#include<stdio.h>
#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include"gvalani.h"

enum relWinPos {IN,OUT};	// relative Window Position (of polygon polong)

void SHPclip(long* polygonX,long* polygonY,long n,long* windowX, long*windowY,long wsize) // Sutherland-Hodgeman Polygon Clipping function
{
	//long n = sizeof(*polygonX)+1;//sizeof(long);
	long* outputX = new long[n];
	long* outputY = new long[n];
	long* position = new long[n];
	long size = 0;

	//long wsize =  sizeof(windowX)+1;//sizeof(long);

	//cout<<"n = "<<n<<"\nwsize = "<<wsize;

	long i,j;
	for(i=0; i<wsize-1; i++)
	{
		//cout<<"\nwindowX["<<i<<"] = "<<windowX[i];
		for(j=0; j<n; j++)
		{
		      long pos = ((windowY[i+1]-windowY[i])*(polygonX[j]-windowX[i]))-((windowX[i+1]-windowX[i])*(polygonY[j]-windowY[i]));
		      /*if(j==6)
		      {

			cout<<"y2-y1="<<(windowY[i+1]-windowY[i])<<" x-x1="<<(polygonX[j]-windowX[i])<<" x2-x1= "<<(windowX[i+1]-windowX[i])<<" y-y1="<<(polygonY[j]-windowY[i]);
			long x1,x2,y1,y2,x,y;
			x1 = windowX[i];
			x2 = windowX[i+1];
			y1 = windowY[i];
			y2 = windowY[i+1];
			x = polygonX[j];
			y = polygonY[j];
			cout<<" x1="<<x1<<" x2="<<x2<<" y1="<<y1<<" y2="<<y2<<" x="<<x<<" y="<<y<<endl;
			cout<<"y2-y1="<<(y2-y1)<<" x-x1="<<(x-x1)<<" x2-x1= "<<(x2-x1)<<" y-y1="<<(y-y1);
			cout<<" (y2-y1)*(x-x1)="<<(y2-y1)*(x-x1);
			cout<<" (x2-x1)(y-y1)="<<(x2-x1)*(y-y1);
			cout<<" (y2-y1)*(x-x1)-(x2-x1)(y-y1)="<<(y2-y1)*(x-x1)-(x2-x1)*(y-y1);  //long

		      }*/
		      if(pos>0)
				{position[j] = OUT;/*cout<<" OUT"<<pos<<"j="<<j;*/}
		      else//pos<=0	-ve orientation of window
				{position[j] = IN;/*cout<<" IN"<<pos;*/}
		}

	       // FEEDing the Output Vertex List
		for(j=0; j<n-1; j++)
		{
		     if((position[j]==OUT)&&(position[j+1]==OUT))
		     {
			// Line to the left of window edge-i. IGNORE.
			//cout<<"\nOUT-OUT";
		     }
		     else if((position[j]==IN)&&(position[j+1]==IN))
		     {
			// Line to the right of window edge-i. SAVE P(j+1).
			outputX[size] = polygonX[j+1];
			outputY[size] = polygonY[j+1];
			size++;
			//cout<<"\nIN-IN x="<<polygonX[j+1]<<" y="<<polygonY[j+1];
		     }
		     else	// Line intersects with (possibly extended)window edge i.
		     {
				double m1 = (double)(windowY[i+1] - windowY[i])/(double)(windowX[i+1] - windowX[i]);
				double c1 = (double)windowY[i] - m1*(double)windowX[i];

				//windowX[i+1] - windowX[i]

				double m2 = (double)(polygonY[j+1] - polygonY[j])/(double)(polygonX[j+1] - polygonX[j]);
				double c2 = (double)polygonY[j] - m2*(double)polygonX[j];

				//cout<<"\nm1="<<m1<<" c1="<<c1<<" m2="<<m2<<" c2="<<c2;

				long xi = round((c2-c1)/(m1-m2));
				long yi = round(m1*(double)xi + c1);

				outputX[size] = xi;
				outputY[size] = yi;
				size++;

				if((position[j]==IN)&&(position[j+1]==OUT))
				{
					// Save intersection point. Already DONE.
					//cout<<"\nIN-OUT x="<<xi<<" y="<<yi;
				}
				else //if((position[j]==OUT)&&(position[j+1]==IN))
				{
					// Save longersection polong(already done) and P(j+1)
					outputX[size] = polygonX[j+1];
					outputY[size] = polygonY[j+1];
					size++;
					//cout<<"\nOUT-IN x="<<polygonX[j+1]<<" y="<<polygonY[j+1];
					//cout<<" x="<<xi<<" y="<<yi;
				}
		     }
		}
		if(size!=0)
		{
			if((outputX[size-1]!=outputX[0])&&(outputY[size-1]!=outputY[0]))
			{
				outputX[size] = outputX[0];
				outputY[size] = outputY[0];
				size++;
				//cout<<"\nsize here = "<<size;
			}
		}

		n = size;
		size = 0;
		for(j=0; j<n; j++)
		{
			polygonX[j] = outputX[j];
			polygonY[j] = outputY[j];
		}
	}

	//cleardevice();
	for(i=0; i<wsize-1; i++)
		dLine(windowX[i],windowY[i],windowX[i+1],windowY[i+1]);

	//getch();
	setcolor(RED);
	for(i=0; i<n-1; i++)
		line(polygonX[i],polygonY[i],polygonX[i+1],polygonY[i+1]);

	//cout<<"\nsize = "<<n;
}
/*
int main()
{
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "");

	cout<<"How many edges does your polygon has? Ans - ";
	long pn;
	cin>>pn;
	long* polygonX = new long[pn+1];
	long* polygonY = new long[pn+1];
	cout<<"Enter (x,y) co-ordinates of vertices in clockwise order\n";
	long i;
	for(i=0; i<pn; i++)
	{
		cin>>polygonX[i];
		cin>>polygonY[i];
	}
	polygonX[pn] = polygonX[0];
	polygonY[pn] = polygonY[0];

	cout<<"How many edges does your CONVEX clipping window has? Ans - ";
	long wn;
	cin>>wn;
	long* windowX = new long[wn+1];
	long* windowY = new long[wn+1];
	cout<<"Enter (x,y) co-ordinates of vertices\n";
	for(i=0; i<wn; i++)
	{
		cin>>windowX[i];
		cin>>windowY[i];
	}
	windowX[wn] = windowX[0];
	windowY[wn] = windowY[0];

	for(i=0; i<wn; i++)
		dLine(windowX[i],windowY[i],windowX[i+1],windowY[i+1]);

	for(i=0; i<pn; i++)
		{dLine(polygonX[i],polygonY[i],polygonX[i+1],polygonY[i+1]);delay(300);}

	//prtscr("SHPclipB.bmp");*/

	/*long* px = new long[5];
	long* py = new long[5];
	long* wx = new long[5];
	long* wy = new long[5];

	px[0]=100;py[0]=100;
	px[1]=200;py[1]=70;
	px[2]=230;py[2]=230;
	px[3]=70;py[3]=170;
	px[4]=100;py[4]=100;

	wx[0]=150;wy[0]=150;
	wx[1]=250;wy[1]=140;
	wx[2]=260;wy[2]=260;
	wx[3]=140;wy[3]=240;
	wx[4]=150;wy[4]=150;*/

	/*long i;
	for(i=0; i<4; i++)
		dLine(wx[i],wy[i],wx[i+1],wy[i+1]);

	for(i=0; i<4; i++)
		dLine(px[i],py[i],px[i+1],py[i+1]);*/

	/*

	long* px = new long[9];
	long* py = new long[9];
	long* wx = new long[5];
	long* wy = new long[5];

	px[0]=10;py[0]=10;
	px[1]=150;py[1]=30;
	px[2]=190;py[2]=120;
	px[3]=30;py[3]=70;
	px[4]=90;py[4]=170;
	px[5]=160;py[5]=150;
	px[6]=180;py[6]=250;
	px[7]=20;py[7]=230;
	px[8]=10;py[8]=10;

	wx[0]=50;wy[0]=50;
	wx[1]=250;wy[1]=80;
	wx[2]=260;wy[2]=260;
	wx[3]=30;wy[3]=300;
	wx[4]=50;wy[4]=50;

	long i;
	for(i=0; i<4; i++)
		dLine(wx[i]+150,wy[i]+150,wx[i+1]+150,wy[i+1]+150);

	for(i=0; i<8; i++)
		dLine(px[i]+150,py[i]+150,px[i+1]+150,py[i+1]+150);*/



	/*getch();
	cleardevice();

	//SHPclip(px,py,9,wx,wy,5);
	SHPclip(polygonX,polygonY,pn+1,windowX,windowY,wn+1);
	//prtscr("SHPclipA.bmp");
	getch();
	return 0;
}*/




