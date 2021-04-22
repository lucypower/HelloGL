#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "Structures.h"
#include "SceneObject.h"

class Sphere
{
private:

	GLfloat _rotation;

	Vector3 _position;

	Material* _material;

public:

	Sphere(float x, float y, float z);
	~Sphere();

	void Draw();
	void Update();
	void MaterialSetUp();
};

