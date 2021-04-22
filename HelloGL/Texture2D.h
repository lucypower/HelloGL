#pragma once
#include <Windows.h> // required for OpenGL on Windows
#include <gl/GL.h> // openGL
#include <gl/GLU.h> // openGL utilities
#include "GL\freeglut.h" // freeglut library
#include "GLUTCallbacks.h"
#include "Structures.h"

class Texture2D
{
private:

	GLuint _ID; // Texture ID
	int _width, _height;

public:

	Texture2D();
	~Texture2D();

	bool Load(char* path, int width, int height);

	GLuint GetID() const { return _ID; }
	int GetWidth() const { return _width; }
	int GetHeight() const { return _height; }
};

