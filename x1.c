#include <GL/gl.h>
#include <GL/glext.h>
#include <H:/lab/glut.h>

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glFlush();
	return;
}

void clearScreen(){
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void createRectangle(){
	
}

void line(){
	
}

void polygon(){
	
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
			
		//line
		case 'b':
			exit(0);
			break;
		
		// rectangle
		case 'c':
			glBegin(GL_POLYGON);
				glVertex2f(-0.7,-0.5);
				glVertex2f(-0.7,0.5);
				glVertex2f(0.5,0.5);
				glVertex2f(0.5,-0.5);
			glEnd();
			
			glFlush();
			break;
		
		//polygon
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


int main(int argc, char **argv){
	
	glutInit(&argc, argv);
	glutCreateWindow("simple");
	glutDisplayFunc(display);
	
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

	//MAIN MENU w/ submenus
	glutCreateMenu(menu);
	glutAddSubMenu("Clear", clearSubMenu);
	glutAddSubMenu("Shape", shapeSubMenu);
	glutAddSubMenu("Colour", colourSubMenu);
	glutAddSubMenu("Transparency", transSubMenu);
	glutAddMenuEntry("Quit", 'q');
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop();
}
