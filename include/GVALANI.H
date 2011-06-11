// copyleft, Mohit Gvalani

#include<dos.h>
int round(double);    // Rounds floating point number to nearest integer value
void eLine(double x1,double y1,double x2,double y2);   // Line drawn from Line Equation
int sign(double a);     // Returns +1,-1,0 indicating the sign of 'a'
double mod(double a);   // Gives magnitude of 'a'
void dLine(double x1,double y1,double x2,double y2);   // DDA Line
void bLine(double x1,double y1,double x2,double y2);   // Bresenham Line
void swap(double* a,double* b);	// Swaps 'a' and 'b' by reference
void gbLine(double x1,double y1,double x2,double y2);  // Generalized Bresenham Line
void mCircle(double xc,double yc, double r);      // Midpoint Circle
void bCircle(double xc,double yc, double r);      // Bresenham Circle
void dCircle(double xc,double yc, double r);      // DDA Circle
void boundaryFill(int x, int y, int bc, int fc);  // Boundary Fill
void floodFill(int x, int y, int bkc);  // Flood Fill
void setViewPort(int minx, int miny, int maxx, int maxy); // Windows extremeties are passed
int mapx(int x); // Map x-cood of window to viewport
int mapy(int y); // Map y-cood of window to viewport
void initmouse();   // Initialize Mouse
void showmptr();    // Make mouse pointer visible
void hidemptr();   // Hide mouse pointer
void getcood(int *butt, int *xi, int*yi);   // Get mouse co-ods
void CSLclip();  // Cohen - Sutherland Line Clipping function
int logicalAND(int r1[4], int r2[4]);
int isRCzero(int r[4]);	//is Region Code zero?
void regionCode(int r[4],int x,int y,int xmin,int ymin,int xmax,int ymax);
//void getLCP(int& x1,int& y1,int& x2,int& y2,int& xmin,int& ymin,int& xmax,int& ymax);
void call(int x1,int y1,int x2,int y2,int xmin,int ymin,int xmax,int ymax);	// Recursive call for MSLclip.
void LBLclip(); 	      // Liang-Barsky Line clipping function
void MSLclip(); 	      // Midpoint Subdivision Line clipping function

void twoDdisplay(int obj[4][3]);	// Display 2D rectangle
void twoDmul(int obj[4][3], int t[3][3]);		// 2D matrix
void dtwoDmul(int obj[4][3], double t[3][3]);	// multiplication
void twoD(int obj[4][3], int opt);		// main 2D function
void twoDtrans(int obj[4][3],int tx,int ty);		// Rectangle Translation function
void twoDscale(int obj[4][3],int sx,int sy);		// Rectangle Scaling function
void twoDshearX(int obj[4][3],int sx);		// Rectangle Shearing function
void twoDreflect(int obj[4][3]);			// Rectangle Reflection function
void twoDrotate(int obj[4][3],double x,double xp,double yp);		// Rectangle Rotation function

void threeDdisplay(int obj[8][4]);	// Display 3D rectangle
void threeDmul(int obj[8][4], int t[4][4]);		// 3D matrix
void dthreeDmul(int obj[8][4], double t[4][4]);	// multiplication
void threeD(int obj[8][4], int opt);		// main 3D function
void threeDtrans(int obj[8][4],int tx,int ty,int tz);		// Parallelopiped Translation function
void threeDscale(int obj[8][4],int sx,int sy,int sz);		// Parallelopiped Scaling function
void threeDshearXY(int obj[8][4],int sx,int sy);		// Parallelopiped Shearing function
void threeDreflect(int obj[8][4]);			// Parallelopiped Reflection function
void threeDrotate(int obj[8][4],double x);		// Parallelopiped Rotation function

int prtscr(char name[]);         // Takes Screen shot and saves it with 'name' name in bitmap format

double pie(double x, double* xj,int n, double xi);
void Lagrange(double* xp, double* yp, int n);

double fact(double n);	// Factorial
double Bernstein(double i, double n, double t);
void Beziur(double* xp, double* yp, int n);

void SHPclip(long* polygonX,long* polygonY,long n,long* windowX, long*windowY,long wsize); // Sutherland-Hodgeman Polygon Clipping function
void SCfill(int* polygonX,int* polygonY,int n);	  // Scan Line fill function

void algae(int l,double a,int x,int y);
void printScreen(); // Produces an invalid GIF87a image.


