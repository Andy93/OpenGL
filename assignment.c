#include <GL/gl.h>
#include <GL/glext.h>
#include <H:/lab/glut.h>

GLfloat x1,x2,y3,y2;
GLfloat hh;

void display(void)
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(3.0);
	glColor3f(1.0,0.0,0.0);

	glBegin(GL_POLYGON);
		glVertex2f(x1,y3);
		glVertex2f(x1,y2);
		glVertex2f(x2,y2);
		glVertex2f(x2,y3);
	glEnd();
	
	//glutSwapBuffer();

	glFlush();
	return;
}

void MyMouse(GLint button, GLint state, GLint x, GLint y)
{
	static int first=1;

	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)
	{
		if (first)
		{
			x1=x; 
			y3=hh-y;
		}
		else
		{
			x2=x;
			y2=hh-y;
			glutPostRedisplay();
		}
		first = !first;
	}

	return;
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

void clearScreen(){
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}


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
		
		case 'b':
			exit(0);
			break;
		
		case 'c':
			exit(0);
			break;
		
		case 'd':
			exit(0);
			break;
		
		case 'e':
			exit(0);
			break;
		
		case 'f':
			exit(0);
			break;
	}
}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutCreateWindow("mouse");
	glutDisplayFunc(display);
	glutReshapeFunc(MyReshape);
	glutMouseFunc(MyMouse);
	
	//SUBMENU for Shape
	int clearSubMenu = glutCreateMenu(menu);
	glutAddMenuEntry("Clear Screen", 'z');
	
	//SUBMENU for Shape
	int shapeSubMenu = glutCreateMenu(menu);
	glutAddMenuEntry("Line", 'b');
	glutAddMenuEntry("Rectangle", 'c');
	glutAddMenuEntry("Polygon", 'd');
	
	//SUBMENU for Colour
	int colourSubMenu = glutCreateMenu(menu);
	glutAddMenuEntry("Colour", 'e');
	
	//SUBMENU for Transparency
	int transSubMenu = glutCreateMenu(menu);
	glutAddMenuEntry("Transparency", 'f');

	//MAIN MENU
	glutCreateMenu(menu);
	glutAddSubMenu("Clear", clearSubMenu);
	glutAddSubMenu("Shape", shapeSubMenu);
	glutAddSubMenu("Colour", colourSubMenu);
	glutAddSubMenu("Transparency", transSubMenu);
	glutAddMenuEntry("Quit", 'q');
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop();
}
