#pragma once
#include "Structure.h"

class SceneObject
{
protected:
	Mesh* _mesh;

public:
	SceneObject(Mesh* mesh);
	~SceneObject();

	virtual void Update();
	virtual void Draw();
};

