#include <GL/gl.h>
#include <GL/glext.h>
#include <H:/lab/glut.h>

/*
	Andrew O'Neill 
	-------------------------------
	All sections completed.
	Basics - Using the mouse, you can create a point, line, triangle, rectangle, pentagon, hexagon,
				heptagon, octagon, nonagon, decagon.
			- I created a menu to select a shape (one of above) and drawing colour(red,yellow,
				green,blue,black,white)
			- Also there is a Clear screen function.
	Advanced -  I created a seperate colour window that contains vertexs of colour(blue,red,green,yellow
					in each corner).
				I created a 'touchPalette' function to touch the colour window and a method called glReadPixels
					to get the rgb to be used as the new colour.
				To be able to vary the brightness, I set the brightness to vary the 
	Super-Advanced - I looked up transparency and found that transparency can be added if the glColor is 4f not 3f
					code snippet: 'glColor4f(r,g,b,transparency);' Transparency can be added through menu.
					
	------------GUIDE---------------
	Background color is White. default drawing colour is Red
	
	
	
	To Clear Screen : right click for menu then select 'CLEAR'
	
	****SHAPE*****
	To select shape - right click and select from submenu called "Shape"
	Point requires just one click
	Line requires 2 clicks before line appears
	Rectangle requires 2 clicks before rectangle appears
	Triangle requires 3 clicks before triangle appears
	The other Polygons appear as you click points (note final click will link to first click to connect
		and close the shape (Rectangle to Decagon has been created)
		
	********COLOUR******
	To select colour follow steps : MENU>>COLOUR>>CHOOSE COLOUR>>SHAPE>>CHOOSE SHAPE>>DRAW
	
	******COLOUR PALETTE****
	To select colour from colour pallete follow the steps below:
		TOUCH WINDOW COLOUR PALETTE>>GO TO DRAWING WINDOW>>MENU>>COLOUR>>SELECT PALETTE>>SHAPE>>CHOOSE SHAPE>>DRAW
		
	******BRIGHTNESS**********
	To select brightness follows the steps below:
		MENU>>CHOOSE COLOUR FIRST>>THEN CHOOSE BRIGHTNESS>>THEN GO TO PALETTE WINDOW>>CLICK COLOUR>>
			GO TO COLOUR IN MENU AND SELECT COLOUR PALETTE>>THEN SELECT SHAPE AND DRAW
			
	*******TRANSPARENCY**********
	To select Transparency follow the steps below:
		MENU>>CHOOSE COLOUR FIRST>>THEN CHOOSE TRANSPARENCY>>THEN GO TO SHAPE>>CHOOSE SHAPE>>DRAW
	
	*************************************
	andrew.oneill65@mail.dcu.ie
	*************************************
*/
GLfloat xa,xb,xc,xd,xe,xf,xg,xh,xi,xj,xk;
GLfloat ya,yb,yc,yd,ye,yf,yg,yh,yi,yj,yk;
GLfloat hh;
GLfloat array[3]; 

float r=0.5;
float g=0.5;
float b=0.5;

int MainID;

int width = 500;
int height = 500;

int first = 0;
int colour = 0;
float transparency = 1.0;

void display(void)
{
	glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(3.0);
	
	if(colour == 0){
		r=  1.0;
		g= 	0.0;
		b= 	0.0;
		glColor4f(r,g,b, transparency);	
	}

	glFlush();
	return;
}

void colourPalette(void){
	glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
       glBegin(GL_QUADS);
               glColor3f(r, 0.0f, 0.0f); // make this vertex red
               glVertex2f(-1.0, 1.0);
               glColor3f(0.0f, g, 0.0f); // make this vertex green
               glVertex2f(-1.0, -1.0);
               glColor3f(0.0f, 0.0, b); // make this vertex blue
               glVertex2f(1.0, -1.0);
               glColor3f(r, g, 0.0f); // make this vertex yellow
               glVertex2f(1.0, 1.0);
       glEnd();
       glutSwapBuffers();
}

void clearScreen(){
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void drawRectangle(int x1,int y1,int x2,int y2)
{
	glBegin(GL_POLYGON);
		glVertex2f(xa,ya);
		glVertex2f(xa,yb);
		glVertex2f(xb,yb);
		glVertex2f(xb,ya);
	glEnd();
	
	glFlush();
}

void createRectangle(GLint button, GLint state, GLint x, GLint y)
{
	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)
	{
		switch(first)
		{		
			case 0:
				xa=x; 
				ya=hh-y;
				first = 1;
				break;
			case 1:
				xb=x;
				yb=hh-y;
				drawRectangle(xa, ya, xb, yb);
				first = 0;
		}
	}
	return;
}

void touchPalette(GLint button, GLint state, GLint x, GLint y){
	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)
	{	
		ya=hh-y;
		glReadPixels(x,ya,1,1,GL_RGB,GL_FLOAT,array);
			r = array[0];
			g = array[1];
			b = array[2];
	}
	return;
}

void drawLine(int x1,int y1,int x2,int y2){
	
	glLineWidth(3.0); 
	glBegin(GL_LINES);
		glVertex2f(x1,y1);
		glVertex2f(x2,y2);
	glEnd();
	
	glFlush();
}

void createLine(GLint button, GLint state, GLint x, GLint y){
	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON){
		switch(first){		
			case 0:
				xa=x; 
				ya=hh-y;
				first = 1;
				break;
			case 1:
				xb=x;
				yb=hh-y;
				drawLine(xa, ya, xb, yb);
				first = 0;
		}
	}
	return;
}

void drawPoint(int x1,int y1){
	
	glLineWidth(3.0); 
	glBegin(GL_POINTS);
		glVertex2f(xa,ya);
	glEnd();
	
	glFlush();
}

void createPoint(GLint button, GLint state, GLint x, GLint y){
	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON){
		xa=x;
		ya=hh-y;
		drawPoint(xa, ya);
	}
	return;
}

void drawTriangle(int x1, int x2, int x3, int y1, int y2, int y3){
	glLineWidth(3.0); 
	glBegin(GL_TRIANGLES);
		glVertex2f(x1,y1);
		glVertex2f(x2,y2);
		glVertex2f(x3,y3);
	glEnd();
	
	glFlush();
}

void createTriangle(GLint button, GLint state, GLint x, GLint y){
	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON){
		switch(first){		
			case 0:
				xa=x; 
				ya=hh-y;
				first = 1;
				break;
			case 1:
				xb=x;
				yb=hh-y;
				first = 2;
				break;
			case 2:
				xc=x;
				yc=hh-y;
				first =0;
				drawTriangle(xa,xb,xc,ya,yb,yc);
				break;
		}
	}
	return;
}

void createPentagon(GLint button, GLint state, GLint x, GLint y){
	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON){
		switch(first){	
		
			case 0:
				xa=x; 
				ya=hh-y;
				first = 1;
				break;
			case 1:
				xb=x;
				yb=hh-y;
				first = 2;
				drawLine(xa,ya,xb,yb);
				break;
			case 2:
				xc=x;
				yc=hh-y;
				first = 3;
				drawLine(xb,yb,xc,yc);
				break;
			case 3:
				xd=x;
				yd=hh-y;
				first = 4;
				drawLine(xc,yc,xd,yd);
				break;
			case 4:
				xe=x;
				ye=hh-y;
				first = 5;
				drawLine(xd,yd,xe,ye);
				break;
			case 5:
				drawLine(xe,ye,xa,ya);
				first = 0;
				break;
		}
	}
	return;
}

void createHexagon(GLint button, GLint state, GLint x, GLint y){
	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON){
		switch(first){	
		
			case 0:
				xa=x; 
				ya=hh-y;
				first = 1;
				break;
			case 1:
				xb=x;
				yb=hh-y;
				first = 2;
				drawLine(xa,ya,xb,yb);
				break;
			case 2:
				xc=x;
				yc=hh-y;
				first = 3;
				drawLine(xb,yb,xc,yc);
				break;
			case 3:
				xd=x;
				yd=hh-y;
				first = 4;
				drawLine(xc,yc,xd,yd);
				break;
			case 4:
				xe=x;
				ye=hh-y;
				first = 5;
				drawLine(xd,yd,xe,ye);
				break;
			case 5:
				xf=x;
				yf=hh-y;
				first = 6;
				drawLine(xe,ye,xf,yf);
				break;
			case 6:
				drawLine(xf,yf,xa,ya);
				first = 0;
				break;
		}
	}
	return;
}

void createHeptagon(GLint button, GLint state, GLint x, GLint y){
	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON){
		switch(first){	
		
			case 0:
				xa=x; 
				ya=hh-y;
				first = 1;
				break;
			case 1:
				xb=x;
				yb=hh-y;
				first = 2;
				drawLine(xa,ya,xb,yb);
				break;
			case 2:
				xc=x;
				yc=hh-y;
				first = 3;
				drawLine(xb,yb,xc,yc);
				break;
			case 3:
				xd=x;
				yd=hh-y;
				first = 4;
				drawLine(xc,yc,xd,yd);
				break;
			case 4:
				xe=x;
				ye=hh-y;
				first = 5;
				drawLine(xd,yd,xe,ye);
				break;
			case 5:
				xf=x;
				yf=hh-y;
				first = 6;
				drawLine(xe,ye,xf,yf);
				break;
			case 6:
				xh=x;
				yh=hh-y;
				first = 7;
				drawLine(xf,yf,xh,yh);
				break;
			case 7:
				drawLine(xh,yh,xa,ya);
				first = 0;
				break;
		}
	}
	return;
}

void createOctagon(GLint button, GLint state, GLint x, GLint y){
	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON){
		switch(first){	
		
			case 0:
				xa=x; 
				ya=hh-y;
				first = 1;
				break;
			case 1:
				xb=x;
				yb=hh-y;
				first = 2;
				drawLine(xa,ya,xb,yb);
				break;
			case 2:
				xc=x;
				yc=hh-y;
				first = 3;
				drawLine(xb,yb,xc,yc);
				break;
			case 3:
				xd=x;
				yd=hh-y;
				first = 4;
				drawLine(xc,yc,xd,yd);
				break;
			case 4:
				xe=x;
				ye=hh-y;
				first = 5;
				drawLine(xd,yd,xe,ye);
				break;
			case 5:
				xf=x;
				yf=hh-y;
				first = 6;
				drawLine(xe,ye,xf,yf);
				break;
			case 6:
				xh=x;
				yh=hh-y;
				first = 7;
				drawLine(xf,yf,xh,yh);
				break;
			case 7:
				xi=x;
				yi=hh-y;
				first = 8;
				drawLine(xh,yh,xi,yi);
				break;	
			case 8:
				drawLine(xi,yi,xa,ya);
				first = 0;
				break;
		}
	}
	return;
}

void createNonagon(GLint button, GLint state, GLint x, GLint y){
	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON){
		switch(first){	
		
			case 0:
				xa=x; 
				ya=hh-y;
				first = 1;
				break;
			case 1:
				xb=x;
				yb=hh-y;
				first = 2;
				drawLine(xa,ya,xb,yb);
				break;
			case 2:
				xc=x;
				yc=hh-y;
				first = 3;
				drawLine(xb,yb,xc,yc);
				break;
			case 3:
				xd=x;
				yd=hh-y;
				first = 4;
				drawLine(xc,yc,xd,yd);
				break;
			case 4:
				xe=x;
				ye=hh-y;
				first = 5;
				drawLine(xd,yd,xe,ye);
				break;
			case 5:
				xf=x;
				yf=hh-y;
				first = 6;
				drawLine(xe,ye,xf,yf);
				break;
			case 6:
				xh=x;
				yh=hh-y;
				first = 7;
				drawLine(xf,yf,xh,yh);
				break;
			case 7:
				xi=x;
				yi=hh-y;
				first = 8;
				drawLine(xh,yh,xi,yi);
				break;
			case 8:
				xj=x;
				yj=hh-y;
				first = 9;
				drawLine(xi,yi,xj,yj);
				break;	
			case 9:
				drawLine(xj,yj,xa,ya);
				first = 0;
				break;
		}
	}
	return;
}

void createDecagon(GLint button, GLint state, GLint x, GLint y){
	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON){
		switch(first){	
		
			case 0:
				xa=x; 
				ya=hh-y;
				first = 1;
				break;
			case 1:
				xb=x;
				yb=hh-y;
				first = 2;
				drawLine(xa,ya,xb,yb);
				break;
			case 2:
				xc=x;
				yc=hh-y;
				first = 3;
				drawLine(xb,yb,xc,yc);
				break;
			case 3:
				xd=x;
				yd=hh-y;
				first = 4;
				drawLine(xc,yc,xd,yd);
				break;
			case 4:
				xe=x;
				ye=hh-y;
				first = 5;
				drawLine(xd,yd,xe,ye);
				break;
			case 5:
				xf=x;
				yf=hh-y;
				first = 6;
				drawLine(xe,ye,xf,yf);
				break;
			case 6:
				xh=x;
				yh=hh-y;
				first = 7;
				drawLine(xf,yf,xh,yh);
				break;
			case 7:
				xi=x;
				yi=hh-y;
				first = 8;
				drawLine(xh,yh,xi,yi);
				break;
			case 8:
				xj=x;
				yj=hh-y;
				first = 9;
				drawLine(xi,yi,xj,yj);
				break;
			case 9:
				xk=x;
				yk=hh-y;
				first = 10;
				drawLine(xj,yj,xk,yk);
				break;
			case 10:
				drawLine(xk,yk,xa,ya);
				first = 0;
				break;
		}
	}
	return;
}

//menu options for all cases
void menu(int op) {
 
	switch(op){
		
		case 'Q':
		case 'q':
			exit(0);
			break;
		
		case 'Z':
		case 'z':	
			clearScreen();
			break;
			
		//SHAPES
		
		//point
		case 'a':
			glutMouseFunc(createPoint);
			break;
		//line
		case 'b':
			glutMouseFunc(createLine);
			break;
		
		// rectangle
		case 'c':
			glutMouseFunc(createRectangle);
			break;
		
		//Pentagon		
		case 'r':
			glutMouseFunc(createPentagon);
			break;
			
		//Hexagon		
		case 's':
			glutMouseFunc(createHexagon);
			break;
			
		//Heptagon		
		case 't':
			glutMouseFunc(createHeptagon);
			break;
			
		//Octagon
		case 'u':
			glutMouseFunc(createOctagon);
			break;
		
		//Nonagon
		case 'v':
			glutMouseFunc(createNonagon);
			break;
			
		//Decagon
		case 'w':
			glutMouseFunc(createDecagon);
			break;
		
		//triangle
		case 'd':
			glutMouseFunc(createTriangle);
			break;
		
		//COLOURS - source : http://www.cs.brandeis.edu/~cs155/OpenGL%20Lecture_02.pdf
		//red
		case 'e':
			r=1.0;
			g=0.0;
			b=0.0;
			glColor4f(r,g,b,transparency);
			colour = 1;
			break;
		
		//yellow
		case 'g':
			r=1.0;
			g=1.0;
			b=0.0;
			glColor4f(r,g,b,transparency);	
			colour = 1;
			break;
			
		//green
		case 'h':
			r=0.0;
			g=1.0;
			b=0.0;
			glColor4f(r,g,b,transparency);
			colour = 1;			
			break;
		
		//blue
		case 'i':
			r=0.0;
			g=0.0;
			b=1.0;
			glColor4f(r,g,b,transparency);
			colour = 1;
			break;
			
		//black
		case 'n':
			r=0.0;
			g=0.0;
			b=0.0;
			glColor4f(r,g,b,transparency);
			colour = 1;
			break;
		
		//white
		case 'o':
			r=1.0;
			g=1.0;
			b=1.0;
			glColor4f(r,g,b,transparency);
			colour = 1;
			break;
		
		//Pallette Selection
		case 'y':
			glColor4f(r,g,b,transparency);
			colour = 1;
			break;
			
		//TRANSPARENCY
		//1.0
		case 'x':
			transparency = 1.0;
			break;
			
		//0.9
		case '9':
			transparency = 0.9;
			break;
			
		//0.8
		case '8':
			transparency = 0.8;
			break;
			
		//0.7
		case '7':
			transparency = 0.7;
			break;
			
		//0.6
		case '6':
			transparency = 0.6;
			break;
			
		//0.5
		case '5':
			transparency = 0.5;
			break;
			
		//0.4
		case '4':
			transparency = 0.4;
			break;
			
		//0.3
		case '3':
			transparency = 0.3;
			break;
			
		//0.2
		case '2':
			transparency = 0.2;
			break;
		
		//0.1
		case '1':
			transparency = 0.1;
			break;
			
	}
}


//brightness submenu
void brightness(int op) {
	switch(op) 
	{	
		case '0':
			glutSetWindow(MainID);
			r = 0.1;
			g = 0.1;
			b = 0.1;
			colourPalette();
			glFlush();
			break;
		case '1':
			glutSetWindow(MainID);
			r = 0.2;
			g = 0.2;
			b = 0.2;
			colourPalette();
			glFlush();
			break;
		case '2':
			glutSetWindow(MainID);
			r = 0.3;
			g = 0.3;
			b = 0.3;
			colourPalette();
			glFlush();
			break;
		case '3':
			glutSetWindow(MainID);
			r = 0.4;
			g = 0.4;
			b = 0.4;
			colourPalette();
			glFlush();
			break;
		case '4':
			glutSetWindow(MainID);
			r = 0.5;
			g = 0.5;
			b = 0.5;
			colourPalette();
			glFlush();
			break;
		case '5':
			glutSetWindow(MainID);
			r = 0.6;
			g = 0.6;
			b = 0.6;
			colourPalette();
			glFlush();
			break;
		case '6':
			glutSetWindow(MainID);
			r = 0.7;
			g = 0.7;
			b = 0.7;
			colourPalette();
			glFlush();
			break;
		case '7':
			glutSetWindow(MainID);
			r = 0.8;
			g = 0.8;
			b = 0.8;
			colourPalette();
			glFlush();
			break;
		case '8':
			glutSetWindow(MainID);
			r = 0.9;
			g = 0.9;
			b = 0.9;
			colourPalette();
			glFlush();
			break;
		case '9':
			glutSetWindow(MainID);
			r = 0.9;
			g = 0.9;
			b = 0.9;
			colourPalette();
			glFlush();
			break;
	}
}


void MyReshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,(GLfloat)w,0.0,(GLfloat)h);
	glViewport(0,0,w,h);
	hh=h;
	return;
}

int main(int argc, char **argv){
	//main window
	glutInit(&argc, argv);
	glutInitWindowSize(width,height);
	glutInitWindowPosition(550,100);
	glutCreateWindow("Andrew O'Neill - 11424222");
	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glutDisplayFunc(display);
	glutReshapeFunc(MyReshape);
	
	//SUBMENU for Clear Screen
	int clearSubMenu = glutCreateMenu(menu);
	glutAddMenuEntry("Clear Screen", 'z');
	
	//SUBMENU for Shape
	int shapeSubMenu = glutCreateMenu(menu);
	glutAddMenuEntry("Point", 'a');
	glutAddMenuEntry("Line", 'b');
	glutAddMenuEntry("Triangle", 'd');
	glutAddMenuEntry("Rectangle", 'c');
	glutAddMenuEntry("Pentagon", 'r');
	glutAddMenuEntry("Hexagon", 's');
	glutAddMenuEntry("Heptagon", 't');
	glutAddMenuEntry("Octagon", 'u');
	glutAddMenuEntry("Nonagon", 'v');
	glutAddMenuEntry("Decagon", 'w');
	
	//SUBMENU for Colour
	int colourSubMenu = glutCreateMenu(menu);
	glutAddMenuEntry("Red", 'e');
	glutAddMenuEntry("Yellow", 'g');
	glutAddMenuEntry("Green", 'h');
	glutAddMenuEntry("Blue", 'i');
	glutAddMenuEntry("Black", 'n');
	glutAddMenuEntry("White", 'o');
	glutAddMenuEntry("Palette", 'y'); //i.e. the colour wheel
	
	//SUBMENU for Transparency
	int transSubMenu = glutCreateMenu(menu);
	glutAddMenuEntry("1.0", 'x');
	glutAddMenuEntry("0.9", '9');
	glutAddMenuEntry("0.8", '8');
	glutAddMenuEntry("0.7", '7');
	glutAddMenuEntry("0.6", '6');
	glutAddMenuEntry("0.5", '5');
	glutAddMenuEntry("0.4", '4');
	glutAddMenuEntry("0.3", '3');
	glutAddMenuEntry("0.2", '2');
	glutAddMenuEntry("0.1", '1');
	
	int brightnessSubMenu = glutCreateMenu(brightness);
	glutAddMenuEntry("0.1", '0');
	glutAddMenuEntry("0.2", '1');
	glutAddMenuEntry("0.3", '2');
	glutAddMenuEntry("0.4", '3');
	glutAddMenuEntry("0.5", '4');
	glutAddMenuEntry("0.6", '5');
	glutAddMenuEntry("0.7", '6');
	glutAddMenuEntry("0.8", '7');
	glutAddMenuEntry("0.9", '8');
	glutAddMenuEntry("1.0", '9');

	//MAIN MENU w/ submenus
	glutCreateMenu(menu);
	glutAddMenuEntry("Clear", 'z');
	glutAddSubMenu("Shape", shapeSubMenu);
	glutAddSubMenu("Colour", colourSubMenu);
	glutAddSubMenu("Transparency", transSubMenu);
	glutAddSubMenu("Brightness", brightnessSubMenu);
	glutAddMenuEntry("EXIT", 'q');
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	
	//Colour Palette
	glutInitWindowSize(width,height);
	glutInitWindowPosition(0,100);
	MainID = glutCreateWindow("Colour Pallette");
	glutDisplayFunc(colourPalette);
	glutMouseFunc(touchPalette);
	//glutReshapeFunc(MyReshape);
	
	glutMainLoop();
}
