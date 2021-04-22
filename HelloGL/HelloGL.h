#pragma once
#include <Windows.h> // required for OpenGL on Windows
#include <gl/GL.h> // openGL
#include <gl/GLU.h> // openGL utilities
#include "GL\freeglut.h" // freeglut library
#include "GLUTCallbacks.h"
#include "Structures.h"
#include "Cube.h"
#include "Sphere.h"

#define REFRESHRATE 16 // 16 = 16ms = roughly 60fps


class HelloGL
{
public:
	HelloGL(int argc, char* argv[]); // constructor definition

	~HelloGL(void); // destructor definition

	void Display();
	void Update();
	void Keyboard(unsigned char key, int x, int y);
	
	int glutCreateMenu(void (*func)(int value));
	void InitMenu();
	void InitObjects();
	void InitLighting();
	void InitGL(int argc, char* argv[]);
	void DrawString(const char* text, Vector3* position, Color* color);

private:
	
	Camera* camera;
	
	int NUM_TEAPOTS = 3;
	int theTeapots;

	SceneObject* _pyramid[100];
	SceneObject* objects[100];
	//Sphere _sphere;

	Vector4* _lightPosition;
	Lighting* _lightData;
};


