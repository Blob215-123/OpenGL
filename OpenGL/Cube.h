#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "Structure.h"

class Cube
{
private:
	static Vertex indexedVertices[];
	static Color indexedColours[];
	static GLushort indices[];

	Vector3 _position;
	GLfloat _rotation;

public:
	Cube(float x, float y, float z);
	~Cube();

	void Draw();
	void Update();
};

