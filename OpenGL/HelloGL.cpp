#include "helloGL.h"
#include "Cube.h"


HelloGL::HelloGL(int argc, char* argv[])
{
	InitObjects();
	InitGL(argc, argv);
	glutMainLoop();
}
HelloGL::~HelloGL()
{
	delete camera;
	camera = nullptr;
}



void HelloGL::Display()
{
	//Must be first
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/*DrawPolygon(-0.5, 0.5);
	//DrawPolygon(0.5, -0.5);*/
	/*DrawTriangle(-0.5, 0.5);
	DrawTriangle(0.5, -0.5);*/
	/*DrawCube();*/
	/*DrawCubeArray();*/
	for (int i = 0; i < 200; i++)
	{
		_cubes[i]->Draw();
	}
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

	for (int i = 0; i < 200; i++)
	{
		_cubes[i]->Update();
	}
	if (rotation >= 360.0f)
		rotation = 0.0f;
	glutPostRedisplay();
}

//void HelloGL::DrawPolygon()
//{
//	//Draw polygon
//	glBegin(GL_POLYGON);
//	glVertex2f(-0.75, 0.5);
//	glVertex2f(0.75, 0.5);
//	glVertex2f(0.75, -0.5);
//	glVertex2f(-0.75, -0.5);
//	glEnd();
//
//}
//void HelloGL::DrawPolygon(float x, float y)
//{
//	glBegin(GL_POLYGON);
//	glVertex2f(x + -0.15, y + 0.15);
//	glVertex2f(x + 0.15, y + 0.15);
//	glVertex2f(x + 0.15, y + -0.15);
//	glVertex2f(x + -0.15, y + -0.15);
//	glEnd();
//}  
//void HelloGL::DrawTriangle(float x, float y)
//{
//	glPushMatrix();
//	glTranslatef(x, y, 0);
//
//
//	glRotatef(rotation, 0, 0, 0.5);
//	glColor3f(0, 1, 0);
//	glutWireTeapot(1);
//	glPopMatrix();
//}
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
//void HelloGL::DrawCube()
//{
//	glBegin(GL_TRIANGLES);
//
//	// face v0-v1-v2
//
//	glColor3f(1, 1, 1);
//	glVertex3f(1, 1, 1);
//	glColor3f(1, 1, 0);
//	glVertex3f(-1, 1, 1);
//	glColor3f(1, 0, 0);
//	glVertex3f(-1, -1, 1);
//
//	// face v2-v3-v0
//
//	glColor3f(1, 0, 0);
//	glVertex3f(-1, -1, 1);
//	glColor3f(1, 0, 1);
//	glVertex3f(1, -1, 1);
//	glColor3f(1, 1, 1);
//	glVertex3f(1, 1, 1);
//
//	// face v0-v3-v4
//
//	glColor3f(1, 1, 1);
//	glVertex3f(1, 1, 1);
//	glColor3f(1, 0, 1);
//	glVertex3f(1, -1, 1);
//	glColor3f(0, 0, 1);
//	glVertex3f(1, -1, -1);
//
//	// face v4-v5-v0
//
//	glColor3f(0, 0, 1);
//	glVertex3f(1, -1, -1);
//	glColor3f(0, 1, 1);
//	glVertex3f(1, 1, -1);
//	glColor3f(1, 1, 1);
//	glVertex3f(1, 1, 1);
//
//	// face v0-v5-v6
//
//	glColor3f(1, 1, 1);
//	glVertex3f(1, 1, 1);
//	glColor3f(0, 1, 1);
//	glVertex3f(1, 1, -1);
//	glColor3f(0, 1, 0);
//	glVertex3f(-1, 1, -1);
//
//	// face v6-v1-v0
//
//	glColor3f(0, 1, 0);
//	glVertex3f(-1, 1, -1);
//	glColor3f(1, 1, 0);
//	glVertex3f(-1, 1, 1);
//	glColor3f(1, 1, 1);
//	glVertex3f(1, 1, 1);
//
//
//	// face v1-v6-v7
//
//	glColor3f(1, 1, 0);
//	glVertex3f(-1, 1, 1);
//	glColor3f(0, 1, 0);
//	glVertex3f(-1, 1, -1);
//	glColor3f(0, 0, 0);
//	glVertex3f(-1, -1, -1);
//
//	// face v7-v2-v1
//
//	glColor3f(0, 0, 0);
//	glVertex3f(-1, -1, -1);
//	glColor3f(1, 0, 0);
//	glVertex3f(-1, -1, 1);
//	glColor3f(1, 1, 0);
//	glVertex3f(-1, 1, 1);
//
//	// face v7-v4-v3
//
//	glColor3f(0, 0, 0);
//	glVertex3f(-1, -1, -1);
//	glColor3f(0, 0, 1);
//	glVertex3f(1, -1, -1);
//	glColor3f(1, 0, 1);
//	glVertex3f(1, -1, 1);
//
//	// face v3-v2-v7
//
//	glColor3f(1, 0, 1);
//	glVertex3f(1, -1, 1);
//	glColor3f(1, 0, 0);
//	glVertex3f(-1, -1, 1);
//	glColor3f(0, 0, 0);
//	glVertex3f(-1, -1, -1);
//
//	// face v4-v7-v6
//
//	glColor3f(0, 0, 1);
//	glVertex3f(1, -1, -1);
//	glColor3f(0, 0, 0);
//	glVertex3f(-1, -1, -1);
//	glColor3f(0, 1, 0);
//	glVertex3f(-1, 1, -1);
//
//	// face v6-v5-v4
//
//	glColor3f(0, 1, 0);
//	glVertex3f(-1, 1, -1);
//	glColor3f(0, 1, 1);
//	glVertex3f(1, 1, -1);
//	glColor3f(0, 0, 1);
//	glVertex3f(1, -1, -1);
//
//	glEnd();
//}
//void HelloGL::DrawCubeArray()
//{
//	glPushMatrix();
//
//	glBegin(GL_TRIANGLES);
//	for (int i = 0; i < 36; i++)
//	{
//		glColor3fv(&colors[i].r);
//		glVertex3fv(&vertices[i].x);
//	}
//	glEnd();
//
//	glPopMatrix();
//}
//void HelloGL::DrawIndexedCube()
//{
//	//glPushMatrix();
//
//	//glBegin(GL_TRIANGLES);
//	//for (int i = 0; i < 36; i++)
//	//{
//	//	glColor3fv(&indexedColours[indices[i]].r);
//	//	glVertex3fv(&indexedVertices[indices[i]].x);
//	//}
//	//glEnd();
//	//glPopMatrix();
//}
//void HelloGL::DrawIndexedCubeAlt()
//{
//	//glEnableClientState(GL_VERTEX_ARRAY);
//	//glEnableClientState(GL_COLOR_ARRAY);
//
//	//glVertexPointer(3, GL_FLOAT, 0, indexedVertices);
//	//glColorPointer(3, GL_FLOAT, 0, indexedColours);
//
//	//glPushMatrix();
//	//	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, indices);
//
//	//glPopMatrix();
//
//	//glDisableClientState(GL_COLOR_ARRAY);
//	//glDisableClientState(GL_VERTEX_ARRAY);
//}
void HelloGL::InitObjects()
{
		rotation = 0.0f;

	Cube::Load((char*)"cube.txt");
	for (int i = 0; i < 200; i++)
	{
		_cubes[i] = new Cube(mesh,((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f,
			-(rand() % 1000) / 10.0f);
	}

	camera = new Camera();
	camera->eye.x = 0; camera->eye.y = 0; camera->eye.z = 1;
	camera->center.x = 0; camera->center.y = 0; camera->center.x = 0;
	camera->up.x = 0; camera->up.y = 1; camera->up.z = 0;
}
void HelloGL::InitGL(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GL_DEPTH_BUFFER_BIT);


	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);



	glutCreateWindow("Simple OpenGL Program");
	//glutDisplayFunc(Display);

	GLUTCallbacks::Init(this);
	glutDisplayFunc(GLUTCallbacks::Display);

	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Update, REFRESHRATE);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, 800, 800);

	gluPerspective(45, 1, 1, 1000);

	glMatrixMode(GL_MODELVIEW);

	glutKeyboardFunc(GLUTCallbacks::Keyboard);



	glEnable(GL_CULL_FACE);

	glCullFace(GL_BACK);

	glEnable(GL_DEPTH_TEST);
}