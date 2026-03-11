#include "helloGL.h"

HelloGL::HelloGL(int argc, char* argv[])
{
	rotation = 0.0f;
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glutInit(&argc, argv);
	glutCreateWindow("Simple OpenGL Program");
	//glutDisplayFunc(Display);

	GLUTCallbacks::Init(this);
	glutDisplayFunc(GLUTCallbacks::Display);

	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);

	glutMainLoop();
}
HelloGL::~HelloGL()
{

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
void HelloGL::Update()
{
	rotation += 0.5f;

	if (rotation >= 360.0f)
		rotation = 0.0f;
	glutPostRedisplay();
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
	glPushMatrix();
	glRotatef(rotation, 0.5, 0.5 , 1);

	glBegin(GL_POLYGON);
	glColor3f(0, 1, 0);
	glVertex3f(1, 1, 1) ;
	glVertex3f(0, 1, 1);
	glVertex3f(0, 1, 0);
	glVertex3f(1, 1, 0);
	glColor3f(0, 0, 1);
	glVertex3f(1, 0, 0);
	glVertex3f(0,0,0);
	glVertex3f(0, 0, 1);
	glVertex3f(1, 0, 1);
	glVertex3f(1, 0, 0);

	glEnd();
	glPopMatrix();
}