#pragma once
#include "SceneObject.h"
#include <iostream>
#include <fstream>

class Pyramid : public SceneObject
{
private:

	Vector3 _position;
	GLfloat _rotation;
public:
	Pyramid(Mesh* mesh, float x, float y, float z);


	~Pyramid();
	static bool Load(char* path);

	void Draw();
	void Update();
};

