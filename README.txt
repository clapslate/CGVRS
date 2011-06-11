This is a collection of Computer Graphics programs that are part of the Mumbai University syllabus for CGVRS(semester 5-IT).
These programs were developed using Turbo C++ 3.0
To use these programs, place all the files from 'src', 'include' and 'obj' folders, directly in the 'bin' folder of TC.


_______________________________________________________________________________________________

This project contains programs for -
- Scan conversion of:
	-Point
	-Line : DDA, Bresenham, Line Equation
	-Circle : DDA, Bresenham, Midpoint
- 2D
- 3D
- Line Clipping : Cohen-Sutherland, Liang-Barsky, Midpoint subdivision
- Polygon Clipping : Sutherland-Hodgeman
- Polygon Filling : Flood fill, Boundary fill, Scan line
- 2D Curves : Lagrange, Béziur
- Fractals : Algae, Spiral

It also contains utility programs -
- Mouse
- Viewport
- BMP : Takes screen-shot and saves it as Bitmap image. The function which does that - prtscr(char name[]);
   A use-case: prtscr("Output.bmp");
   -Takes screenshot and saves it as 'Output.bmp' in BIN folder.

_______________________________________________________________________________________________

To use these programs as they are, you need to know about the 'project' feature in TC.
- Extract all files to BIN folder.
- Make sure that there is a 'SOURCE' folder in 'TC' folder. If there is no such folder, then create one. This folder is used by TC to store the .obj and .exe files of my program.
- Run TC.exe. From the MENU bar at the top, Go to the 'Project' option and click on 'Open Project'. You'll get a dialogue box with a list of files having .prj extension. '.prj' stands for 'project'. From the list, select 'CG.prj' and click OK.
- The project is now open. It contains all the CG programs. To see the list of programs, view the project window. To do that, from the MENU bar at the top, Go to the 'Window' option, and click on 'Project'. You'll see the project window with all the files it contains. To view any file, just double-click on it.
- Of all the cpp files in CG.prj(i.e. the project), only 1 file can have the 'main()' method. Because when you click on the 'Compile' and 'Run' options when the project is open, the project as a whole is compiled and run. So the project as a whole can have only one main() method.
- All cpp files have a main() method which is commented entirely (block commented)
	  
	  /* 
	  void main()
	  {
	  ........
	  .......
	  }*/
	  
- Only Beziur.cpp has an uncommented main(). So when you open CG.prj and run it, Beziur.cpp will be executed.
- To run any other program, comment the main() in Beziur.cpp and uncomment the main() of the program you want to run.

______________________________________________________________________________________________

To use any program independent of CG.prj :
- Go through the entire program and search for functions which are not library functions and which are not defined in that program.
- These functions are defined in some other cpp file and are linked to this file with the help CG.prj.
- So to use these functions, copy them in this file from whichever file they are in.
- You have to take the pain of finding out which function is in which file.
- If you haven't copied all the functions, you'll get LINKER errors for those uncopied functions.

_______________________________________________________________________________________________

These programs look better in TextPad. In notepad or TC, they look messy.
_______________________________________________________________________________________________

 copyleft Mohit Gvalani. 
_______________________________________________________________________________________________
