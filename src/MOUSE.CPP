/**
*Copyright 2009, Mohit Gvalani

*This file is part of CGVRS.
*CGVRS is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
*CGVRS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
*You should have received a copy of the GNU General Public License along with CGVRS.  If not, see <http://www.gnu.org/licenses/>.
*/



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
