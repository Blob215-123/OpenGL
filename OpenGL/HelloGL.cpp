#include "HelloGL.h"
#include "Cube.h"
#include "MeshLoader.h"
#include "Pyramid.h"

HelloGL::HelloGL(int argc, char* argv[])
{
	InitGL(argc, argv);
	InitObjects();
	InitLighting();
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
	for (int i = 0; i < 1000; i++)
	{
		objects[i]->Draw();
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
	glLightfv(GL_LIGHT0, GL_AMBIENT, &(_lightData->Ambient.x));
	glLightfv(GL_LIGHT0, GL_POSITION, &(_lightPosition->x));

	for (int i = 0; i < 1000; i++)
	{
		objects[i]->Update();
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
void HelloGL::InitLighting()
{
	_lightPosition = new Vector4();
	_lightPosition->x = 0.0;
	_lightPosition->y = 0.0;
	_lightPosition->z = 1.0;
	_lightPosition->w = 0.0;

	_lightData = new Lighting();
	_lightData->Ambient.x = 0.2;
	_lightData->Ambient.y = 0.2;
	_lightData->Ambient.z = 0.2;
	_lightData->Ambient.w = 1.0;
	_lightData->Diffuse.x = 0.8;
	_lightData->Diffuse.y = 0.8;
	_lightData->Diffuse.z = 0.8;
	_lightData->Diffuse.w = 1.0;
	_lightData->Specular.x = 0.2;
	_lightData->Specular.y = 0.2;
	_lightData->Specular.z = 0.2;
	_lightData->Specular.w = 1.0;
}
void HelloGL::InitObjects()
{
		rotation = 0.0f;
		Mesh* cubeMesh = MeshLoader::LoadTextured((char*)"cube.txt");
		//Mesh* pyramidMesh = MeshLoader::Load((char*)"pyramid.txt");
		Texture2D* texture = new Texture2D();
		texture->Load((char*)"Penguins.raw", 512, 512);

	for (int i = 0; i < 1000; i++)
	{
		objects[i] = new Cube(cubeMesh, texture ,((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}
	//for (int i = 500; i < 1000; i++)
	//{
	//	objects[i] = new Pyramid(pyramidMesh, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	//}

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


	glEnable(GL_TEXTURE_2D);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

}