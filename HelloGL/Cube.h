#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <string>
#include "GL\freeglut.h"
#include "Structures.h"
#include "SceneObject.h"

class Cube : public SceneObject
{
private:

	GLfloat _rotation;
	Vector3 _position;
	Material* _material;

public:

	Cube(Mesh* mesh, Texture2D* texture, float x, float y, float z);
	~Cube();

	void Draw();
	void Update();
	void MaterialSetUp();

	//static bool Load(char* path);
};

