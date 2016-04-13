#include <GL/gl.h>
#include <GL/glext.h>
#include <H:/lab/glut.h>

GLfloat xi,xf,yi,yf;
GLfloat hh;

int first = 0;
int colour = 0;

void display(void)
{
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(3.0);
	
	if(colour == 0){
		glColor3f(0.7,0.7,0.7);	
	}

	glFlush();
	return;
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
		
		//COLOURS
		//red
		case 'e':
			glColor3f(1.0,0.0,0.0);
			colour = 1;
			break;
		
		//orange
		case 'f':
			glColor3f(0.5,0.0,0.0);	
			colour = 1;
			break;
		
		//yellow
		case 'g':
			glColor3f(1.0,1.0,0.0);	
			colour = 1;
			break;
			
		//green
		case 'h':
			glColor3f(0.0,1.0,0.0);
			colour = 1;			
			break;
		
		//blue
		case 'i':
			glColor3f(0.0,0.0,1.0);
			colour = 1;
			break;
		
		//cyan
		case 'j':
			glColor3f(0.0,1.0,1.0);
			colour = 1;
			break;
		
		//magenta
		case 'k':
			glColor3f(1.0,0.0,1.0);
			colour = 1;
			break;
		
		//grey
		case 'l':
			glColor3f(0.5,0.5,0.5);
			colour = 1;
			break;
			
		//brown
		case 'm':
			glColor3f(1.0,1.0,1.0);
			colour = 1;
			break;
			
		//black
		case 'n':
			glColor3f(0.0,0.0,0.0);
			colour = 1;
			break;
		
		//white
		case 'o':
			glColor3f(1.0,1.0,1.0);
			colour = 1;
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
	
	//MAIN WINDOW
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutCreateWindow("simple");
	glutDisplayFunc(display);
	glutReshapeFunc(MyReshape);
	
	//SUBMENU for Clear Screen
	int clearSubMenu = glutCreateMenu(menu);
	glutAddMenuEntry("Clear Screen", 'z');
	
	//SUBMENU for Shapes
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
	glutAddMenuEntry("Transparency", 'p');

	//MAIN MENU w/ submenus
	glutCreateMenu(menu);
	glutAddSubMenu("Clear", clearSubMenu);
	glutAddSubMenu("Shape", shapeSubMenu);
	glutAddSubMenu("Colour", colourSubMenu);
	glutAddSubMenu("Transparency", transSubMenu);
	glutAddMenuEntry("Quit", 'q');
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	
	//Colour Pallete
	//glutCreateWindow("Colour Pallete");
	//glutDisplayFunc(colourPallete);

	//end
	glutMainLoop();
}
