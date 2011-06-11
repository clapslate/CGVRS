// copyleft, Mohit Gvalani
// Anant se bhi aage (To Infinty and Beyond)
#include<stdio.h>
#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include"gvalani.h"

class Edges
{
public:	int ymin;
	int ymax;
	double x;
	double m;
	int activated;
	int index;

	void nextX()
	{
		//cout<<"\nm = "<<m;
		//cout<<"\nx = "<<x;
		if(m!=0)
			x = x + 1.0/m;
		delay(10);
		//getch();
	}

	void activate()
	{
		activated = 1;
	}

	int Activated()
	{
		return activated;
	}

	void deactivate()
	{
		activated = 0;
	}
};

void SCfill(int* polygonX,int* polygonY,int n)	  // Scan Line fill function
{
	       Edges* e = new Edges[n-1];

	       int i,j,k;
	       for(i=0;i<n-1;i++)
	       {
			//cout<<e[i].Activated()<<" ";
			e[i].deactivate(); // IMPORTANT STEP cause TC 3.0 is tricky! - variables are not always initialzed to zero.
			if(polygonY[i]<polygonY[i+1])
			{
				e[i].ymin = polygonY[i];
				e[i].ymax = polygonY[i+1];
				e[i].x = (double)polygonX[i];//cout<<"here2 ";
				//cout<<"ymin="<<e[i].ymin<<" ymax="<<e[i].ymax<<" x1="<<e[i].x<<" x2="<<polygonX[i+1];
				if(polygonX[i+1]!=(int)e[i].x)
					e[i].m = (double)(e[i].ymax - e[i].ymin)/((double)polygonX[i+1]-e[i].x);
				else
					e[i].m = 0.0;   // Actual m = infinity
				//cout<<" m="<<e[i].m;
				//cout<<"here3\n";
				//getch();
			}
			else if(polygonY[i]>polygonY[i+1])
			{
				e[i].ymax = polygonY[i];
				e[i].ymin = polygonY[i+1];
				e[i].x = (double)polygonX[i+1];//cout<<"here4 ";
				if(polygonX[i]!=(int)e[i].x)
					e[i].m = (double)(e[i].ymax - e[i].ymin)/((double)polygonX[i]-e[i].x);
				else
					e[i].m = 0.0;   // Actual m = infinity
				//cout<<"here5\n";
			}
			else // if they are equal i.e. line is horizontal
			{
				line(polygonX[i],polygonY[i+1],polygonX[i],polygonY[i+1]);
				e[i].activated = 2;
			}
	       }

	       int maxy = 0, miny = getmaxy();
	       for(i=0; i<n-1; i++)
	       {
			miny = e[i].ymin<miny ? e[i].ymin : miny;
			maxy = e[i].ymax>maxy ? e[i].ymax : maxy;
			//cout<<"\n"<<e[i].ymin<<" "<<e[i].ymax;
	       }
	       //cout<<"\nminy="<<miny<<" maxy="<<maxy;

	       int fillX[100]={0},size=0,temp;
	       for(i=miny; i<=maxy; i++)
	       {
			//delay(1000);
			for(j=0; j<n-1; j++)
			{
			    if((e[j].ymin==i)&&(e[j].Activated()!=2))
			    {
				e[j].activate();
				/*e[j].index = size;
				fillX[size++]=round(e[j].x);*/

				//cout<<"\nactivated"<<j;
			    }
			    else if(e[j].ymax==i)
			    {
					e[j].deactivate();
			    }
			    else{}
			}

			size = 0;
			for(j=0; j<n-1; j++)
				if(e[j].Activated()==1)
				{
					fillX[size] = round(e[j].x);
					size++;
					//cout<<"size: "<<size;
					//cout<<"x: "<<e[j].x;
					//cout<<"fx: "<<fillX[size-1];
				}

				for(j=0; j<size; j++)
					for(k=j+1; k<size; k++)
						if(fillX[k]<fillX[j])
						{
							temp = fillX[j];
							fillX[j] = fillX[k];
							fillX[k] = temp;
						}


			for(j=0; j<size; j+=2)
			{
				//cout<<"x1="<<fillX[j]<<" x2="<<fillX[j+1]<<endl;
				//cout<<"j="<<j<<","<<fillX[j]<<","<<fillX[j+1];
				line(fillX[j],i,fillX[j+1],i);
				fillX[j] = 0;
				fillX[j+1] = 0;
			}


			for(j=0; j<n-1; j++)
				if(e[j].Activated()==1)
				{
					//cout<<" j="<<j;
					e[j].nextX();
				}
			}
}

/*
int main()
{
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "");

	cout<<"How many edges does your polygon has? Ans - ";
	long pn;
	cin>>pn;
	int* polygonX = new int[pn+1];
	int* polygonY = new int[pn+1];
	cout<<"Enter (x,y) co-ordinates of vertices in clockwise order\n";
	long i;
	for(i=0; i<pn; i++)
	{
		cin>>polygonX[i];
		cin>>polygonY[i];
	}
	polygonX[pn] = polygonX[0];
	polygonY[pn] = polygonY[0];

	for(i=0; i<pn; i++)
		{line(polygonX[i],polygonY[i],polygonX[i+1],polygonY[i+1]);delay(300);}

	prtscr("SCfillB.bmp");

	getch();
	cleardevice();

	SCfill(polygonX,polygonY,pn+1);
	prtscr("SCfillA.bmp");

	getch();

	return 0;
} */







