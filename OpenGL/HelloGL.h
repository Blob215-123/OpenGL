#pragma once
#include "GL/freeglut.h"

#include <gl/GL.h>
#include <gl/GLU.h>
#include <Windows.h>
#include "GLUTCallbacks.h"
#include "Structure.h"
#include "Cube.h";

#define REFRESHRATE 16

class HelloGL
{
public:
	HelloGL(int argc, char* argv[]);
	~HelloGL(void);

	void Display();

	void Update();
	void Keyboard(unsigned char key, int x, int y);
	void InitObjects();
	void InitGL(int argc, char* argv[]);
	void InitLighting();

private:
	SceneObject* objects[1000];

	Camera* camera;

	float rotation;

	Vector4* _lightPosition;
	Lighting* _lightData;

};