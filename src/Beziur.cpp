/**
*Copyright 2009, Mohit Gvalani

*This file is part of CGVRS.
*CGVRS is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
*CGVRS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
*You should have received a copy of the GNU General Public License along with CGVRS.  If not, see <http://www.gnu.org/licenses/>.
*/



// Bézier-Bernstein Approximation. Faster than Lagrange interpolation, but its not right to compare as they are algorithms that serve differnt purposes.
// loops are possible

#include<stdio.h>
#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include"gvalani.h"

double fact(double n)
{
	if(n<0.0)
		return -1;
	else if(round(n)<2)
		return 1;
	else
	{
		int ans = 1;
		for(int i=1; i<=round(n); i++)
			ans*=i;

		return ans;
	}
}


double Bernstein(double i, double n, double t)
{
	return( fact(n)*pow(t,i)*pow(1.0-t,n-i)/fact(i)/fact(n-i) );
}

void Beziur(double* xp, double* yp, int n)
{
	int i;
	double t,ansx,ansy;
	double prex=xp[0],prey=yp[0];

	for(t=0.01; t<=1; t+=0.01) // Smoothness factor does not has to be as small as in Lagrange and it works.
	{
		ansx=0.0,ansy=0.0;
		for(i=0; i<n; i++)
		{
			ansx+= xp[i]*Bernstein(i,n-1,t);
			ansy+= yp[i]*Bernstein(i,n-1,t);
		}

		//putpixel(round(ansx),round(ansy),WHITE);
		line(round(ansx),round(ansy),round(prex),round(prey));
		prex = ansx;
		prey = ansy;

	}
}

void main()
{
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "");

	cout<<"How many control points? Ans - ";
	int n;
	cin>>n;
	double* X = new double[n];
	double* Y = new double[n];
	cout<<"Enter (x,y) co-ordinates of in order\n";
	int i;
	for(i=0; i<n; i++)
	{
		cin>>X[i];
		cin>>Y[i];
		putpixel(round(X[i]),round(Y[i]),CYAN);
	}

	setcolor(CYAN);
	for(i=0; i<n-1; i++)
		line(round(X[i]),round(Y[i]),round(X[i+1]),round(Y[i+1]));

	getch();

	setcolor(WHITE);
	Beziur(X,Y,n);
	getch();
	prtscr("Beziur.bmp");
}


