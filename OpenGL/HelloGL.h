#pragma once
#include "GL/freeglut.h"
#include "GLUTCallbacks.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include <windows.h>
#define REFRESHRATE 16

struct Vector3
{
	float x, y, z;
};

struct Camera
{
	Vector3 eye, center, up;
};

struct Color
{
	GLfloat r, g, b;
};

struct Vertex
{
	GLfloat x, y, z;
};

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
	void DrawCube();
	void DrawCubeArray();
	void DrawIndexedCube();
	void DrawIndexedCubeAlt();
	void Keyboard(unsigned char key, int x, int y);

private:
	Camera* camera;

	static Vertex vertices[];
	static Color colors[];

	static Vertex indexedVertices[];
	static Color indexedColours[];
	static GLushort indices[];

	float rotation;
};