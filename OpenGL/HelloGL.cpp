#include "helloGL.h"

HelloGL::HelloGL(int argc, char* argv[])
{
	rotation = 0.0f;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);



	glutCreateWindow("Simple OpenGL Program");
	//glutDisplayFunc(Display);

	GLUTCallbacks::Init(this);
	glutDisplayFunc(GLUTCallbacks::Display);

	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);

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
	DrawTriangle(-0.5, 0.5);
	DrawTriangle(0.5, -0.5);
	//Must be last
	glFlush();
	glutSwapBuffers();
}
void HelloGL::Update()
{
	//rotation += 0.5f;

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
void HelloGL::DrawTriangle(float x, float y)
{
	glPushMatrix();
	glTranslatef(x, y, 0.0f);


	glRotatef(rotation, 0, 0, 0.5);

	glBegin(GL_POLYGON);
	glColor3f(0, 1, 0);
	glVertex2f(0.25, 0.25);
	glColor3f( 1, 0, 0);
	glVertex2f(-0.25, 0.25);

	glColor3f(0, 0, 1);
	glVertex2f(-0.25, -0.25);
	glVertex2f(0.25, -0.25);

	glEnd();
	glPopMatrix();
}
void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'd')
	{
		rotation -= 0.5f;
	}
	else if (key == 'a')
	{
		rotation += 0.5f;
	}
}