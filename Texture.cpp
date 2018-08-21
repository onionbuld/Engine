#include "Texture.h"
#include "iostream"
#define STB_IMAGE_IMPLEMENTATION
#include "stb-master\stb_image.h"

Texture::Texture(const char* TSource) {

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	data = stbi_load(TSource, &width, &height, &nrChannels, 0);
	if (data)
	{
		std::cout << "| " << TSource << " | -- " << " Texture.cpp is ok;" << std::endl;
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture " << TSource << std::endl;
	}
	stbi_image_free(data);
}

Texture::~Texture() {

}