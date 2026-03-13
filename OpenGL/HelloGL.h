#pragma once
#include "GL/freeglut.h"
#include "GLUTCallbacks.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include <windows.h>
#define REFRESHRATE 16

class HelloGL
{
public:
	HelloGL(int argc, char* argv[]);
	~HelloGL(void);


	void Display();

	void DrawPolygon();
	void DrawPolygon(float x, float y);
	void DrawTriangle(float x, float y);
	void Update();

	void Keyboard(unsigned char key, int x, int y);

private:
	float rotation;
};

