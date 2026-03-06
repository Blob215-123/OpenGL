#include "helloGL.h"

HelloGL::HelloGL(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutCreateWindow("Simple OpenGL Program");
	//glutDisplayFunc(Display);

	GLUTCallbacks::Init(this);
	glutDisplayFunc(GLUTCallbacks::Display);

	glutMainLoop();
}

void HelloGL::Display()
{
	//Must be first
	glClear(GL_COLOR_BUFFER_BIT);

	/*DrawPolygon(-0.5, 0.5);
	//DrawPolygon(0.5, -0.5);*/
	DrawTriangle();
	//Must be last
	glFlush();
}

void HelloGL::DrawPolygon()
{
	//Draw polygon
	glBegin(GL_POLYGON);
	glVertex2f(-0.75, 0.5);
	glVertex2f(0.75, 0.5);
	glVertex2f(0.75, -0.5);
	glVertex2f(-0.75, -0.5);
	glEnd();

}
void HelloGL::DrawPolygon(float x, float y)
{
	glBegin(GL_POLYGON);
	glVertex2f(x + -0.15, y + 0.15);
	glVertex2f(x + 0.15, y + 0.15);
	glVertex2f(x + 0.15, y + -0.15);
	glVertex2f(x + -0.15, y + -0.15);
	glEnd();
}  
void HelloGL::DrawTriangle()
{
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(0.25, 0);
	glVertex2f(0.5, -0.25);
	glVertex2f(0.5, -0.5);
	glVertex2f(0.25, -0.75);
	glVertex2f(0, -0.75);
	glVertex2f(-0.25, -0.5);
	glVertex2f(-0.25, -0.25);

	glEnd();
}