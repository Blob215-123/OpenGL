#include "Cube.h"

Cube::Cube(Mesh* mesh, Texture2D* texture, float x, float y, float z) : SceneObject(mesh, texture)
{
	_position.x = x;
	_position.y = y;
	_position.z = z;

	_rotation = 0.0f;
}

Cube::~Cube()
{

}

//bool Cube::Load(char* path)
//{
//	std::ifstream inFile;
//	inFile.open(path);
//
//	if (!inFile.good())
//	{
//		std::cerr << "Can't open text file " << path << std::endl;
//		return false;
//	}
//
//	inFile >> numVertices;
//	indexedVertices = new Vertex[numVertices];
//
//	for (int i = 0; i < numVertices; i++)
//	{
//		inFile >> indexedVertices[i].x;
//		inFile >> indexedVertices[i].y;
//		inFile >> indexedVertices[i].z;
//	}
//
//	inFile >> numColors;
//	indexedColours = new Color[numColors];
//	
//	for (int i = 0; i < numColors; i++)
//	{
//		inFile >> indexedColours[i].r;
//		inFile >> indexedColours[i].g;
//		inFile >> indexedColours[i].b;
//	}
//
//	inFile >> numIndices;
//	indices = new GLushort[numIndices];
//
//	for (int i = 0; i < numIndices; i++)
//	{
//		inFile >> indices[i];
//	}
//
//	inFile.close();
//
//	return true;
//}

void Cube::Draw()
{
	if (_mesh->Vertices != nullptr && _mesh->Colors != nullptr)
	{

		glBindTexture(GL_TEXTURE_2D, _texture->GetID());
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);

		glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
		glColorPointer(3, GL_FLOAT, 0, _mesh->Colors);
		glTexCoordPointer(2, GL_FLOAT, 0, _mesh->TexCoords);

		glPushMatrix();

		glTranslatef(_position.x, _position.y, _position.z);

		glRotatef(_rotation, 1.0f, 0.0f, 0.0f);

		glDrawElements(GL_TRIANGLES, _mesh->IndexCount, GL_UNSIGNED_SHORT, _mesh->Indices);

		glPopMatrix();

		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}
}

void Cube::Update()
{

}