// copyleft, Mohit Gvalani
// Lagrange Interpolation works for continuously increasing x.So, doesn't work for loops.

#include<stdio.h>
#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include"gvalani.h"

double pie(double x, double* xj,int n, double xi)
{
	double ans = 1.0;
	for(int j=0; j<n; j++)
	{
		if(xj[j]!=xi)
			ans*=(x-xj[j])/(xi-xj[j]);
	}
	return ans;
}


void Lagrange(double* xp, double* yp, int n)
{
	double x1,x2,ans;
	int i,j;

	//x1 = xp[i]<xp[i+1]?xp[i]:xp[i+1];
	//x2 = xp[i]>xp[i+1]?xp[i]:xp[i+1];
	//cout<<" x1:"<<x1<<" x2:"<<x2;
	x1 = xp[i];
	x2 = xp[n-1];

	double sf = 0.1;	//smoothness factor - smaller the value, better the smoothness (theoretically)
	double prex1=x1,prey1=yp[i];

	for(;x1<=x2;x1+=sf)
	{
		ans=0.0;
		for(j=0; j<n; j++)
			ans+=yp[j]*pie(x1,xp,n,xp[j]);

		//putpixel(round(x1),round(ans),WHITE); // gives much better smoothness. Curve continuity degrades with increase in 'sf' value.
		line(x1,ans,prex1,prey1);
		prex1 = x1;
		prey1 = ans;
	}

}
/*
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

	//getch();
	Lagrange(X,Y,n);
	getch();
}*/
