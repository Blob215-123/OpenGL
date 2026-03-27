#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "Structure.h"
#include <iostream>
#include <fstream>

class Cube
{
private:
	static Vertex* indexedVertices;
	static Color* indexedColours;
	static GLushort* indices;

	static int numVertices, numColors, numIndices;

	Vector3 _position;
	GLfloat _rotation;

public:
	Cube(float x, float y, float z);
	~Cube();
	static bool Load(char* path);

	void Draw();
	void Update();
};

