#pragma once
#include "Structure.h"
#include "Texture2D.h"

class SceneObject
{
protected:
	Mesh* _mesh;
	Texture2D* _texture;

public:
	SceneObject(Mesh* mesh, Texture2D* texture);
	~SceneObject();

	virtual void Update();
	virtual void Draw();
};

