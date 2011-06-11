#include<dos.h>

void initmouse()
{
	union REGS mousei,mouseo;
	mousei.x.ax = 0;
	int86(0x33, &mousei, &mouseo);
	//return (o.x.ax);
}

void getcood(int *butt, int *xi, int*yi)
{
	union REGS mousei,mouseo;
	mousei.x.ax = 3;
	int86(0x33,&mousei,&mouseo);
	*butt = mouseo.x.bx;
	*xi = mouseo.x.cx;
	*yi = mouseo.x.dx;
}

void showmptr()
{
	union REGS mousei,mouseo;
	mousei.x.ax = 1;
	int86(0x33,&mousei,&mouseo);
}

void hidemptr()
{
	union REGS mousei,mouseo;
	mousei.x.ax = 2;
	int86(0x33,&mousei,&mouseo);
}
