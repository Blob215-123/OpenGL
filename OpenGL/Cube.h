#pragma once
#include "SceneObject.h"
#include <iostream>
#include <fstream>

class Cube : public SceneObject
{
private:

	Vector3 _position;
	GLfloat _rotation;
public:
	Cube(Mesh* mesh, Texture2D* texture,float x, float y, float z);


	~Cube();
	static bool Load(char* path);

	void Draw();
	void Update();
};

