#pragma once
#include "GL/freeglut.h"

#include <gl/GL.h>
#include <gl/GLU.h>
#include <Windows.h>

class Texture2D
{
private:
	GLuint _ID;
	int _width, _height;
public:
	Texture2D();
	~Texture2D();

	bool Load(char* path, int width, int height);

	GLuint GetID() const { return _ID; }
	int GetWidth() const { return _width; }
	int GetHeight() const { return _height; }
};

