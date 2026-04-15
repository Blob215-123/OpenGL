#pragma once
#include "GL/freeglut.h"
#include "GLUTCallbacks.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include <Windows.h>
#include "Structure.h"
#include "Cube.h";

#define REFRESHRATE 16

class HelloGL
{
public:
	HelloGL(int argc, char* argv[]);
	~HelloGL(void);

	void Display();

	//void DrawPolygon();
	//void DrawPolygon(float x, float y);
	//void DrawTriangle(float x, float y);
	void Update();
	//void DrawCube();
	//void DrawCubeArray();
	//void DrawIndexedCube();
	//void DrawIndexedCubeAlt();
	void Keyboard(unsigned char key, int x, int y);
	void InitObjects();
	void InitGL(int argc, char* argv[]);

private:
	Cube *_cubes[200];

	Camera* camera;

	//static Vertex vertices[];
	//static Color colors[];

	//static Vertex indexedVertices[];
	//static Color indexedColours[];
	//static GLushort indices[];

	float rotation;
};