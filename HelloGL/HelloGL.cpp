#include "HelloGL.h"
#include "Cube.h"
#include "MeshLoader.h"
#include "Pyramid.h"

HelloGL::HelloGL(int argc, char* argv[]) // constructor
{
	InitGL(argc, argv);
	InitObjects();
	InitLighting();
	
	glutMainLoop();
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // this will clear the scene
	for (int i = 0; i < 100; i++)
	{
		objects[i]->Draw();
	}
	for (int i = 0; i < 100; i++)
	{
		_pyramid[i]->Draw();
	}

	Vector3 v = { -1.8f, -2.0f, -1.0f };
	Color c = { 0.0f, 1.0f, 0.0f };

	DrawString("OpenGL FOGGS Project\n Use NumPad 9 to change background color\n Use 'wasdqe' to move the camera", &v, &c);

	glFlush(); // flushes the scene drawn to the graphics card
	glutSwapBuffers();
}

void HelloGL::Update()
{
	glLoadIdentity();
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.x, camera->up.y, camera->up.z);
	glutPostRedisplay();
	glLightfv(GL_LIGHT0, GL_AMBIENT, &(_lightData->ambient.x));
	glLightfv(GL_LIGHT0, GL_POSITION, &(_lightPosition->x));
	glEnable(GL_DIFFUSE);
	glEnable(GL_SPECULAR);
	
	for (int i = 0; i < 100; i++)
	{
		objects[i]->Update();
	}
	for (int i = 0; i < 100; i++)
	{
		_pyramid[i]->Update();
	}
}

void HelloGL::Keyboard(unsigned char key, int x, int y)
{

	// move the camera
	if (key == 'd')
		camera->eye.x += 0.1f;
	else if (key == 'a')
		camera->eye.x -= 0.1f;
	else if (key == 'w')
		camera->eye.y += 0.1f;
	else if (key == 's')
		camera->eye.y -= 0.1f;
	else if (key == 'e')
		camera->eye.z += 0.1f;
	else if (key == 'q')
		camera->eye.z -= 0.1f;

	// change background colour
	GLfloat colors[][3] = { { 0.1f, 0.0f, 0.1f }, { 0.1f, 0.1f, 0.1f } };
	static int back;

	if (key == '9')
	{
		back ^= 1; // bitwise xor assignment

		glClearColor(colors[back][0], colors[back][1], colors[back][2], 1.0f);
		glutPostRedisplay();
	}
}

HelloGL::~HelloGL(void) // destructor?
{
	delete camera;
}

void HelloGL::InitObjects()
{
	camera = new Camera();
	camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 2.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f, camera->up.y = 1.0f; camera->up.z = 0.0f;

	Mesh* cubeMesh = MeshLoader::Load((char*)"cube.txt");
	Texture2D* cubetexture = new Texture2D();
	cubetexture->Load((char*)"stars.raw", 512, 512);
	for (int i = 0; i < 100; i++)
	{
		objects[i] = new Cube(cubeMesh, cubetexture, ((rand() % 400) / 10.0f) - 20.0f,
			((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}	

	Mesh* pyramidMesh = MeshLoader::Load((char*)"pyramid.txt");
	//Texture2D* pyramidtexture = new Texture2D();
	//pyramidtexture->Load((char*)"Penguins.raw", 512, 512);
	for (int i = 0; i < 100; i++)
	{
		_pyramid[i] = new Pyramid(pyramidMesh,((rand() % 400) / 10.0f) - 20.0f,
			((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}
	
}

void HelloGL::InitGL(int argc, char* argv[])
{
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH); // double buffering is now enabled
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// set the viewport to be the entire window
	glViewport(0, 0, 800, 800);

	// set the correct perspective
	gluPerspective(90, 1, 1000, 0);

	glMatrixMode(GL_MODELVIEW);

	glEnable(GL_TEXTURE_2D); // without this there will just be white boxes
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE); // enable culling
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glCullFace(GL_BACK); // specify to cull back faces
}

void HelloGL::InitLighting()
{
	_lightPosition = new Vector4();
	_lightPosition->x = 0.0;
	_lightPosition->y = 0.0;
	_lightPosition->z = 1.0;
	_lightPosition->w = 0.0;

	_lightData = new Lighting();
	_lightData->ambient.x = 0.2;
	_lightData->ambient.y = 0.2;
	_lightData->ambient.z = 0.2;
	_lightData->ambient.w = 1.0;
	_lightData->diffuse.x = 0.8;
	_lightData->diffuse.y = 0.8;
	_lightData->diffuse.z = 0.8;
	_lightData->diffuse.w = 1.8;
	_lightData->specular.x = 0.2;
	_lightData->specular.y = 0.2;
	_lightData->specular.z = 0.2;
	_lightData->specular.w = 1.0;
}

void HelloGL::InitMenu()
{
	
	glutAddMenuEntry("Teapot0", 0);
	glutAddMenuEntry("None", -1);
	glutAttachMenu(GLUT_LEFT_BUTTON);
}

int HelloGL::glutCreateMenu(void (*func)(int value))
{
	return 0;
}

void HelloGL::DrawString(const char* text, Vector3* position, Color* color)
{
	glPushMatrix();
	glTranslatef(position->x, position->y, position->z);
	glRasterPos2f(0.0f, 0.0f); // raster position 
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char*)text);
	glPopMatrix();
}