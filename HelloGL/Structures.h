#pragma once
#include <Windows.h> // required for OpenGL on Windows
#include <gl/GL.h> // openGL
#include <gl/GLU.h> // openGL utilities
#include "GL\freeglut.h" // freeglut library
#include "GLUTCallbacks.h"

struct Vector3
{
	float x;
	float y;
	float z;
};

struct Camera
{
	Vector3 eye;
	Vector3 center;
	Vector3 up;
};

struct Color
{
	GLfloat r, g, b;
};

struct Vertex
{
	GLfloat x, y, z;
};

struct TexCoord
{
	GLfloat u;
	GLfloat v;
};

struct Mesh
{
	Vertex* Vertices;
	Vector3* Normals;
	GLushort* Indices;
	TexCoord* TexCoords;
	int VertexCount, NormalCount, TexCoordCount, IndexCount;
};

struct Vector4
{
	float x, y, z, w;
};

struct Lighting
{
	Vector4 ambient, diffuse, specular;
};

struct Material
{
	Vector4 ambient, diffuse, specular;
	GLfloat shininess;
};
