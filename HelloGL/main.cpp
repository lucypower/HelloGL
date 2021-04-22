#include "HelloGL.h"

// "game idea" - choose one of the planets eg Jupiter and show moons
// and have the camera movement rotate them and show the different
// orbits

int main(int argc, char* argv[])
{
	HelloGL* game = new HelloGL(argc, argv); // creates an instance of our game

	return 0; // assumes a successful exit if our game exits
}