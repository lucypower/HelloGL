#include "Sphere.h"

Sphere::Sphere(float x, float y, float z)
{
	_position.x = x;
	_position.y = y;
	_position.z = z;
}

Sphere::~Sphere()
{

}

void Sphere::Draw()
{
	glPushMatrix();
	MaterialSetUp();
	glMaterialfv(GL_FRONT, GL_AMBIENT, &(_material->ambient.x));
	glMaterialf(GL_FRONT, GL_SHININESS, _material->shininess);
	glTranslatef(0, 0, -20);
	glRotatef(_rotation, 1.0f, 1.0f, 1.0f);
	glutSolidSphere(10, 10, 10);
	glPopMatrix();
} 

void Sphere::Update()
{
	_rotation += 0.5f;
}

void Sphere::MaterialSetUp()
{

}