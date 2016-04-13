#include <GL/gl.h>
#include <stdio.h>
#include <GL/glext.h>
#include <H:/lab/glut.h>

GLfloat xi,xf,yi,yf;
GLfloat hh;

int first = 0;
int colour = 0;
float transparency = 1.0;

void display(void)
{
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(3.0);
	
	if(colour == 0){
		glColor4f(0.7,0.7,0.7, transparency);	
	}

	glFlush();
	return;
}

void colourPallette(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
       glBegin(GL_QUADS);
               glColor3f(0.5f, 0.0f, 1.0f); // make this vertex purple
               glVertex2f(-0.75, 0.75);
               glColor3f(1.0f, 0.0f, 0.0f); // make this vertex red
               glVertex2f(-0.75, -0.75);
               glColor3f(0.0f, 1.0f, 0.0f); // make this vertex green
               glVertex2f(0.75, -0.75);
               glColor3f(1.0f, 1.0f, 0.0f); // make this vertex yellow
               glVertex2f(0.75, 0.75);
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
		glVertex2f(xi,yi);
		glVertex2f(xi,yf);
		glVertex2f(xf,yf);
		glVertex2f(xf,yi);
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
				xi=x; 
				yi=hh-y;
				first = 1;
				break;
			case 1:
				xf=x;
				yf=hh-y;
				drawRectangle(xi, yi, xf, yf);
				first = 0;
		}
	}
	return;
}

void drawLine(int x1,int y1,int x2,int y2){
	
	glLineWidth(3.0); 
	glBegin(GL_LINES);
		glVertex2f(xi,yi);
		glVertex2f(xf,yf);
	glEnd();
	
	glFlush();
}

void createLine(GLint button, GLint state, GLint x, GLint y){
	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON){
		switch(first){		
				case 0:
					xi=x; 
					yi=hh-y;
					first = 1;
					break;
				case 1:
					xf=x;
					yf=hh-y;
					drawLine(xi, yi, xf, yf);
					first = 0;
		}
	}
	return;
}

void drawPoint(int x1,int y1){
	
	glLineWidth(3.0); 
	glBegin(GL_POINTS);
		glVertex2f(xi,yi);
	glEnd();
	
	glFlush();
}

void createPoint(GLint button, GLint state, GLint x, GLint y){
	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON){
					xi=x;
					yi=hh-y;
					drawPoint(xi, yi);
	}
	return;
}

void polygon(){
	//do later maybe triangle, pentagon, hexagon, heptagon, octagon, nonagon, decagon.
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
		
		//polygon
		case 'd':
			exit(0);
			break;
		
		//COLOURS - source : http://www.cs.brandeis.edu/~cs155/OpenGL%20Lecture_02.pdf
		//red
		case 'e':
			glColor4f(1.0,0.0,0.0,transparency);
			colour = 1;
			break;
		
		//orange
		case 'f':
			glColor4f(1.0,0.5,0.0,transparency);	
			colour = 1;
			break;
		
		//yellow
		case 'g':
			glColor4f(1.0,1.0,0.0,transparency);	
			colour = 1;
			break;
			
		//green
		case 'h':
			glColor4f(0.0,1.0,0.0,transparency);
			colour = 1;			
			break;
		
		//blue
		case 'i':
			glColor4f(0.0,0.0,1.0,transparency);
			colour = 1;
			break;
		
		//cyan
		case 'j':
			glColor4f(0.0,1.0,1.0,transparency);
			colour = 1;
			break;
		
		//magenta
		case 'k':
			glColor4f(1.0,0.0,1.0,transparency);
			colour = 1;
			break;
		
		//grey
		case 'l':
			glColor4f(0.5,0.5,0.5,transparency);
			colour = 1;
			break;
			
		//brown
		case 'm':
			glColor4f(0.5,0.0,0.0,transparency);
			colour = 1;
			break;
			
		//black
		case 'n':
			glColor4f(0.0,0.0,0.0,transparency);
			colour = 1;
			break;
		
		//white
		case 'o':
			glColor4f(1.0,1.0,1.0,transparency);
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
	
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
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
	glutAddMenuEntry("Rectangle", 'c');
	glutAddMenuEntry("Polygon", 'd');
	
	//SUBMENU for Colour
	int colourSubMenu = glutCreateMenu(menu);
	glutAddMenuEntry("Red", 'e');
	glutAddMenuEntry("Orange", 'f');
	glutAddMenuEntry("Yellow", 'g');
	glutAddMenuEntry("Green", 'h');
	glutAddMenuEntry("Blue", 'i');
	glutAddMenuEntry("Cyan", 'j');
	glutAddMenuEntry("Magenta", 'k');
	glutAddMenuEntry("Grey", 'l');
	glutAddMenuEntry("Brown", 'm');
	glutAddMenuEntry("Black", 'n');
	glutAddMenuEntry("White", 'o');
	
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

	//MAIN MENU w/ submenus
	glutCreateMenu(menu);
	glutAddMenuEntry("Clear", 'z');
	glutAddSubMenu("Shape", shapeSubMenu);
	glutAddSubMenu("Colour", colourSubMenu);
	glutAddSubMenu("Transparency", transSubMenu);
	glutAddMenuEntry("EXIT", 'q');
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	
	//Colour Pallete
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Colour Pallette to choose colour");
	glutDisplayFunc(colourPallette);
	//glutReshapeFunc(MyReshape);
	
	glutMainLoop();
}
