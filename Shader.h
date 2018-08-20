#pragma once
#ifndef SHADER_H
#define SHADER_H

#include <GL\glew.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "utils.h"

class Shader {
public:
	Shader(const char* vertexPath, const char* fragmentPath);
	~Shader();

	GLuint ID;

	const char* vertexPath;
	const char* fragmentPath;
	void enable();
	void disable();

	// Специальные функции
	// Bool function
	void setBool(const std::string &name, bool value) const {
		glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
	}
	// Int function
	void setInt(const std::string &name, int value) const {
		glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
	}
	// Float function
	void setFloat(const std::string &name, float value) const {
		glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
	}
	// Vec2 function
	void setVec2(const std::string &name, float value) const {
		glUniform2f(glGetUniformLocation(ID, name.c_str()), value, 0);
	}
	// Vec3 function
	void setVec3(const std::string &name, float x, float y, float z) const {
		glUniform3f(glGetUniformLocation(ID, name.c_str()), x, y, z);
	}
#ifdef _GLM
	void setVec3(const std::string &name, const glm::vec3 &value) const
	{
		glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
	}
	// Mat4 function
	void setMat4(const std::string &name, const glm::mat4 &mat) const
	{
		glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
	}
#endif
	GLuint load();
private:
	
	void checkCompileErrors(GLuint shader, std::string type);
};
#endif