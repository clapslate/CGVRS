// copyleft, Mohit Gvalani
// Some parts - © Jacob Joseph

#include<stdio.h>
#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include"gvalani.h"

void threeDdisplay(int obj[8][4])	// © Jacob Joseph
{

	int i,j,k,l,m;
	int obj2[8][4]={0};

	for(i=0;i<8;i++)
		for(j=0;j<2;j++)
			obj2[i][j]=obj[i][j];

	for(i=0;i<8;i++)
	{
		double temp1[1][3]={obj[i][0],obj[i][1]+obj[i][2],1};
		double temp2[3][3]={cos(45),sin(45),0,-sin(45),cos(45),0,-obj[i][0]*cos(45)+obj[i][1]*sin(45)+obj[i][0],-obj[i]	[0]*sin(45)-obj[i][1]*cos(45)+obj[i][1],1};
		double temp3[1][3]={0.0,0.0,0.0};
		for(k=0;k<1;k++)
			for(l=0;l<3;l++)
				for(m=0;m<3;m++)
					temp3[k][l]=temp3[k][l]+temp1[k][m]*temp2[m][l];

		obj2[i][0]=temp3[0][0];obj2[i][1]=temp3[0][1];

	}

	line(obj2[0][0],obj2[0][1],obj2[1][0],obj2[1][1]);
	line(obj2[1][0],obj2[1][1],obj2[2][0],obj2[2][1]);
	line(obj2[2][0],obj2[2][1],obj2[3][0],obj2[3][1]);
	line(obj2[3][0],obj2[3][1],obj2[0][0],obj2[0][1]);
	line(obj2[4][0],obj2[4][1],obj2[5][0],obj2[5][1]);
	line(obj2[5][0],obj2[5][1],obj2[6][0],obj2[6][1]);
	line(obj2[6][0],obj2[6][1],obj2[7][0],obj2[7][1]);
	line(obj2[7][0],obj2[7][1],obj2[4][0],obj2[4][1]);
	line(obj2[0][0],obj2[0][1],obj2[4][0],obj2[4][1]);
	line(obj2[1][0],obj2[1][1],obj2[5][0],obj2[5][1]);
	line(obj2[2][0],obj2[2][1],obj2[6][0],obj2[6][1]);
	line(obj2[3][0],obj2[3][1],obj2[7][0],obj2[7][1]);

	/*line(obj[0][0],obj[0][1],obj[2][0],obj[2][1]); // line 1-3
	line(obj[0][0],obj[0][1],obj[4][0],obj[4][1]); // line 1-5
	line(obj[4][0],obj[4][1],obj[5][0],obj[5][1]); // line 5-6
	line(obj[4][0],obj[4][1],obj[6][0],obj[6][1]); // line 5-7
	line(obj[5][0],obj[5][1],obj[7][0],obj[7][1]); // line 6-8
	line(obj[6][0],obj[6][1],obj[7][0],obj[7][1]); // line 7-8
	line(obj[2][0],obj[2][1],obj[6][0],obj[6][1]); // line 3-7
	line(obj[1][0],obj[1][1],obj[5][0],obj[5][1]); // line 2-6
	line(obj[0][0],obj[0][1],obj[1][0],obj[1][1]); // line 1-2
	setlinestyle(DOTTED_LINE,1,1);
	line(obj[3][0],obj[3][1],obj[7][0],obj[7][1]); // line 4-8  dotted
	line(obj[2][0],obj[2][1],obj[3][0],obj[3][1]); // line 3-4  dotted
	line(obj[1][0],obj[1][1],obj[3][0],obj[3][1]); // line 2-4  dotted
	setlinestyle(SOLID_LINE,1,1);*/
}

void threeDmul(int obj[8][4], int t[4][4])
{
	int r[8][4]={0};

	int i,j;
	for(i=0;i<8;i++)
		for(j=0;j<4;j++)
			for(int k=0;k<4;k++)
	  			r[i][j]+=obj[i][k]*t[k][j];

	for(i=0;i<8;i++)
		for(j=0;j<4;j++)
		{	obj[i][j] = r[i][j];
		       /*cout<<"obj["<<i<<"]["<<j<<"] = "<<obj[i][j]<<endl;*/}
}
void dthreeDmul(int obj[8][4], double t[4][4])
{
	double r[8][4]={0.0};
	int i,j;

	for(i=0;i<8;i++)
		for(j=0;j<4;j++)
			for(int k=0;k<4;k++)
	  			r[i][j]+=(double)obj[i][k]*t[k][j];

	for(i=0;i<8;i++)
		for(j=0;j<4;j++)
			obj[i][j] = round(r[i][j]);
}

void threeD(int obj[8][4], int opt)
{
	switch(opt)
	{
		case 1:{	cout<<"Enter translation factor in x,y,z direction\n";
					int tx,ty,tz;
					cin>>tx>>ty>>tz;
					threeDtrans(obj,tx,ty,tz);			// Translation
					threeDdisplay(obj);
					/*char ch;
					if(getch()=='p')
						prtscr("3D-1.bmp");*/
					break;
				}

		case 2:{	cout<<"Enter scaling factor in x,y,z direction\n";
					int sx,sy,sz;
					cin>>sx>>sy>>sz;
					threeDscale(obj,sx,sy,sz);			// Scaling
					threeDdisplay(obj);
					/*char ch;
					if(getch()=='p')
						prtscr("3D-2.bmp");*/
					break;
				}

		case 3:{	cout<<"Enter angle of rotation\n";
					double r,theta;
					cin>>theta;
					r = theta*3.14/180.0;
					threeDrotate(obj,r);	// Rotation
					threeDdisplay(obj);
					/*char ch;
					if(getch()=='p')
						prtscr("3D-3.bmp");*/
					break;
				}

		case 4:{	cout<<"Enter shearing factors in xy-direction\n";
					int sx,sy;
					cin>>sx>>sy;
					threeDshearXY(obj,sx,sy);				// Shearing
					threeDdisplay(obj);
					/*char ch;
					if(getch()=='p')
						prtscr("3D-4.bmp");*/
					break;
				}

		case 5:{
					threeDreflect(obj);				// Reflection
					threeDdisplay(obj);
					/*char ch;
					if(getch()=='p')
						prtscr("3D-5.bmp");*/
				}
	}
}


void threeDtrans(int obj[8][4],int tx,int ty, int tz)			// Translation function
{
 	int t[4][4]={ {1,0,0,0},{0,1,0,0},{0,0,1,0},{tx,ty,tz,1}};
 	threeDmul(obj,t);
}

void threeDscale(int obj[8][4],int sx,int sy,int sz)			// Scaling function
{
	int rx = obj[0][0]*(sx-1);
 	int ry = obj[0][1]*(sy-1);
	int rz = obj[0][2]*(sz-1);

 	int t[4][4]={ {sx,0,0,0},{0,sy,0,0},{0,0,sz,0},{0,0,0,1}};
 	threeDmul(obj,t);
	threeDtrans(obj,-rx,-ry,-rz);
}

void threeDshearXY(int obj[8][4],int sx,int sy)	// © Jacob Joseph  // Shearing(in XY direction) function
{
	int t[4][4]={{1,0,0,0},{0,1,0,0},{sx,sy,1,0},{0,0,0,1}};
	threeDmul(obj,t);
}

void threeDreflect(int obj[8][4])// © Jacob Joseph  // Reflection(about XY plane) function
{
	int t[4][4]={{1,0,0,0},{0,1,0,0},{0,0,-1,0},{0,0,0,1}};
	threeDmul(obj,t);
}

void threeDrotate(int obj[8][4],double x)// © Jacob Joseph		// Rotation(about z-axis) function
{
	double t[4][4]={ {cos(x),sin(x),0,0},{-sin(x),cos(x),0,0},{0,0,1,0},{0,0,0,1}};
	dthreeDmul(obj,t);
}
/*
void main()
{
  	int x,y,z,x1,y1;

	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "");

  	cout<<"Enter length in x,y,z direction"<<endl;
  	cin>>x>>y>>z;
  	cout<<"Enter x,y cood of top-left corner\n";
  	cin>>x1>>y1;

	clrscr();
	setlinestyle(0,1,3);

	//int obj[8][4]={{x1,y1,0,1},{x1+x,y1,0,1},{x1,y1+y,0,1},{x1+x,y1+y,0,1},{x1,y1,z,1},{x1+x,y1,z,1},{x1,y1+y,z,1},{x1+x,y1+y,z,1}};
	int obj[8][4]={x1,y1+y,0,1,x1+x,y1+y,0,1,x1+x,y1,0,1,x1,y1,0,1,x1,y1+y,z,1,x1+x,y1+y,z,1,x1+x,y1,z,1,x1,y1,z,1};	// © Jacob Joseph
	threeDdisplay(obj);

 	int ch;

    cout<<"1) Translation "<<endl;
	cout<<"2) Scaling "<<endl;
	cout<<"3) Rotation about z-axis"<<endl;
	cout<<"4) Shearing in xy-direction"<<endl;
	cout<<"5) Reflection about YZ"<<endl;
	cout<<"6)exit "<<endl;
	cout<<"Enter your choice ";
	cin>>ch;

	do
	{
		clrscr();
		setlinestyle(1,1,1);
		threeDdisplay(obj);
		setlinestyle(0,1,3);
		threeD(obj,ch);
		cout<<"Enter your choice ";
		cin>>ch;
	}
	while(ch!=6);

}*/
