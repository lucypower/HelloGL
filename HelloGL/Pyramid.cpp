#include "Pyramid.h"
#include <iostream>
#include <fstream>


Pyramid::Pyramid(Mesh* mesh, float x, float y, float z) : SceneObject(mesh, nullptr)
{
	_position.x = x;
	_position.y = y;
	_position.z = z;
}

Pyramid::~Pyramid()
{

}

void Pyramid::Draw()
{
	if (_mesh->Vertices != nullptr && _mesh->Normals != nullptr && _mesh->Indices != nullptr)
	{
		//glBindTexture(GL_TEXTURE, _texture->GetID());
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
		glNormalPointer(GL_FLOAT, 0, _mesh->Normals);
		glTexCoordPointer(2, GL_FLOAT, 0, _mesh->TexCoords);

		MaterialSetUp();
		glMaterialfv(GL_FRONT, GL_AMBIENT, &(_material->ambient.x));
		glMaterialf(GL_FRONT, GL_SHININESS, _material->shininess);

		glPushMatrix();
		glTranslatef(_position.x, _position.y, _position.z);
		glRotatef(_pyramidRotation, 1.0f, 1.0f, 0.0f);
		glDrawElements(GL_TRIANGLES, _mesh->IndexCount, GL_UNSIGNED_SHORT, _mesh->Indices);
		glPopMatrix();

		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
	}
}

void Pyramid::Update()
{
	_pyramidRotation -= ((rand() % 20) / 3);

}

void Pyramid::MaterialSetUp()
{
	_material = new Material();
	_material->ambient.x = -3.0; _material->ambient.y = -1.05;
	_material->ambient.z = -1.05; _material->ambient.w = -2.0;
	_material->diffuse.x = 0.8; _material->diffuse.y = 0.0;
	_material->diffuse.z = 0.05; _material->diffuse.w = 0.05;
	_material->specular.x = 1.0; _material->specular.y = 1.0;
	_material->specular.z = 1.0; _material->specular.w = 1.0;
	_material->shininess = 10.0;
}
