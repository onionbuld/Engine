#pragma once
#ifndef TEXTURE_H
#define TEXTURE_H
#include <GL\glew.h>

class Texture {
public:
	Texture(const char* TSource);
	~Texture();

	GLuint texture;
	const char* TSource;
	int width;
	int height;
	int nrChannels;
	unsigned char *data;
};
#endif