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

void getLCP(int&x1,int&y1,int&x2,int&y2,int&xmin,int&ymin,int&xmax,int&ymax);

void LBLclip() 	      // Liang-Barsky Line clipping function
{
	int x1,y1,x2,y2,xmin,ymin,xmax,ymax,flag=0;

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
	prtscr("LBLclipBefore.bmp");

	int p[4],q[4];

	q[0] = x1 - xmin;	p[0] = x1-x2;
	q[1] = xmax - x1;	p[1] = x2-x1;
	q[2] = y1 - ymin;	p[2] = y1-y2;
	q[3] = ymax - y1;	p[3] = y2-y1;

	double r[4];
	for(int i=0; i!=4; i++)
		r[i] = (double)q[i]/(double)p[i];

	setcolor(BLACK);
	line(x1,y1,x2,y2);

	for(i=0; i!=4; i++)
	      if(p[i]==0)
		   if(q[i]<0)
		   {
			cout<<" Line is invisible\n";
			flag = 1;
		   }

	double u1 = 0.0;
	for(i=0; i!=4; i++)
	      if(p[i]<0)
		  if(r[i]>u1)
			u1 = r[i];

	double u2 = 1.0;
	for(i=0; i!=4; i++)
	      if(p[i]>0)
		  if(r[i]<u2)
			u2 = r[i];

	for(i=0; i!=4; i++)
		cout<<"p["<<i<<"]="<<p[i]<<" q["<<i<<"]="<<q[i]<<" r["<<i<<"]="<<r[i]<<"\n";
	cout<<"u1="<<u1<<" u2="<<u2;

	if((u1<u2)&&(flag==0))
	{
		double dx =(double)x2-x1;
		double dy =(double)y2-y1;

		int xa = x1 + round(dx*u1);   cout<<"\nxa="<<xa;
		int ya = y1 + round(dy*u1);   cout<<"\nya="<<ya;
		int xb = x1 + round(dx*u2);   cout<<"\nxb="<<xb;
		int yb = y1 + round(dy*u2);   cout<<"\nyb="<<yb;

		dLine(xa,ya,xb,yb);
	}
	prtscr("LBLclipAfter.bmp");
}
/*
void main()
{
    int gd = DETECT,gm,e;
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    initmouse();
    showmptr();
    LBLclip();
    getch();
}*/