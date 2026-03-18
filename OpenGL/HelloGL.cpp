#include "helloGL.h"

HelloGL::HelloGL(int argc, char* argv[])
{
	camera = new Camera();
	camera->eye.x = 0; camera->eye.y = 0; camera->eye.z = 1;
	camera->center.x = 0; camera->center.y = 0; camera->center.x = 0;
	camera->up.x = 0; camera->up.y = 1; camera->up.z = 0;



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

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, 800, 800);

	gluPerspective(45, 1, 0, 1000);

	glMatrixMode(GL_MODELVIEW);

	glutKeyboardFunc(GLUTCallbacks::Keyboard);

	glutMainLoop();
}
HelloGL::~HelloGL()
{
	delete camera;
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
	glLoadIdentity(); 
	//rotation += 0.5f;
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, 
		camera->center.x, camera->center.y, camera->center.z,
		camera->up.x, camera->up.y, camera->up.z);

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
	glTranslatef(x, y, 0);


	glRotatef(rotation, 0, 0, 0.5);
	glColor3f(0, 1, 0);
	glutWireTeapot(1);
	glPopMatrix();
}
void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'w')
	{
		camera->eye.z -= 0.1f;
		camera->center.z -= 0.1f;
	}
	else if (key == 's')
	{
		camera->eye.z += 0.1f;
		camera->center.z += 0.1f;
	}
	else if (key == 'a')
	{
		camera->eye.x -= 0.1f;
		camera->center.x -= 0.1f;
	}
	else if (key == 'd')
	{
		camera->eye.x += 0.1f;
		camera->center.x += 0.1f;
	}
	else if (key == 'z')
	{
		camera->center.x -= 0.1f;
		camera->center.z += 0.1f;
	}
	else if (key == 'c')
	{
		camera->center.x += 0.1f;
		camera->center.z -= 0.1f;
	}
}