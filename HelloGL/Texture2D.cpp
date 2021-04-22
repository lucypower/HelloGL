#include "Texture2D.h"
#include <fstream>
#include <iostream>

Texture2D::Texture2D()
{

}

Texture2D::~Texture2D()
{
	glDeleteTextures(1, &_ID);
}

bool Texture2D::Load(char* path, int width, int height)
{
	char* tempTextureData; 
	int fileSize; 
	std::ifstream inFile;

	_width = width; 
	_height = height;

	inFile.open(path, std::ios::binary);

	if (!inFile.good())
	{
		std::cerr << "Can't open texture file " << path << std::endl;
		return false;
	}

	inFile.seekg(0, std::ios::end); // seek to end of file
	fileSize = (int)inFile.tellg(); // get current position in file - the end, gives us total file size
	tempTextureData = new char[fileSize]; // create a new array to store data
	inFile.seekg(0, std::ios::beg); // seek back to beginning of file
	inFile.read(tempTextureData, fileSize); // read in all the data in one go
	inFile.close(); // close the file

	std::cout << path << " loaded." << std::endl;

	glGenTextures(1, &_ID); // get next texture
	glBindTexture(GL_TEXTURE_2D, _ID); // bind the texture to the ID
	glTexImage2D(GL_TEXTURE_2D, 0, 2, width, height, 
		0, GL_RGB, GL_UNSIGNED_BYTE, tempTextureData); // specify details of our texture image
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // minification filter
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // magnification filter

	delete[] tempTextureData; // clear up the data
	return true;
}
