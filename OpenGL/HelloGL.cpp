#include "HelloGL.h"
#include "Cube.h"
#include "MeshLoader.h"
#include "Pyramid.h"
#include <cmath>

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

	for (int i = 0; i < 1000; i++)
	{
		objects[i]->Draw();
	}
	//Must be last
	Vector3 v = { -1.4f, 0.7f, -1.0f };
	Color c = { 0.0f, 1.0f , 0.0f };
	DrawString("OPENGL PRJECT", &v, &c);
	glFlush();
	glutSwapBuffers();
}
void HelloGL::DrawString(const char* text, Vector3* position, Color* color)
{

	glPushMatrix();

	glTranslatef(position->x, position->y, position->z);
	glRasterPos2f(0.0f, 0.0f);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char*)text);

	glPopMatrix();


}
void HelloGL::Update()
{
	glLoadIdentity(); 
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, 
		camera->center.x, camera->center.y, camera->center.z,
		camera->up.x, camera->up.y, camera->up.z);
	glLightfv(GL_LIGHT0, GL_AMBIENT, &(_lightData->Ambient.x));
	glLightfv(GL_LIGHT0, GL_POSITION, &(_lightPosition->x));

	for (int i = 0; i < 1000; i++)
	{
		objects[i]->Update();
	}
	glutPostRedisplay();
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
	else if (key == 'q')
	{
		camera->eye.y -= 0.1f;
		camera->center.y -= 0.1f;
	}
	else if (key == 'e')
	{
		camera->eye.y += 0.1f;
		camera->center.y += 0.1f;
	}
	else if (key == 'z')
	{
		std::cerr << camera->center.x << std::endl;
		angle -= 0.1f;
		std::cerr << "Camera rotation: " << angle << std::endl;
		camera->center.x = camera->eye.x + (1 * cos(angle));
		camera->center.z = camera->eye.z + (1 * sin(angle));
		std::cerr << camera->center.x << std::endl;
	}
	else if (key == 'c')
	{
		std::cerr << camera->center.x << std::endl;
		angle += 0.1f;
		std::cerr << "Camera rotation: " << angle << std::endl;
		camera->center.x = camera->eye.x + (1 * cos(angle));
		camera->center.z = camera->eye.z + (1 * sin(angle));
		std::cerr << camera->center.x << std::endl;
	}
	else if (key == 'r')
	{
		angle = 0.0f;
		camera->eye.x = 0; camera->eye.y = 0; camera->eye.z = 1;
		camera->center.x = 0; camera->center.y = 0; camera->center.x = 0;
		camera->up.x = 0; camera->up.y = 1; camera->up.z = 0;
	}
}
void HelloGL::InitLighting()
{
	_lightPosition = new Vector4();
	_lightPosition->x = 0.0f;
	_lightPosition->y = 0.0f;
	_lightPosition->z = 1.0f;
	_lightPosition->w = 0.0f;

	_lightData = new Lighting();
	_lightData->Ambient.x = 0.2f;
	_lightData->Ambient.y = 0.2f;
	_lightData->Ambient.z = 0.2f;
	_lightData->Ambient.w = 1.0f;
	_lightData->Diffuse.x = 0.8f;
	_lightData->Diffuse.y = 0.8f;
	_lightData->Diffuse.z = 0.8f;
	_lightData->Diffuse.w = 1.0f;
	_lightData->Specular.x = 0.2f;
	_lightData->Specular.y = 0.2f;
	_lightData->Specular.z = 0.2f;
	_lightData->Specular.w = 1.0f;
}
void HelloGL::InitObjects()
{
		rotation = 0.0f;
		angle = 0.0f;
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