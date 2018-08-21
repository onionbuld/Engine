#include "Shader.h"

Shader::Shader(const char* vertexPath, const char* fragmentPath)
	: fragmentPath(fragmentPath), vertexPath(vertexPath) {
		ID = load();
	}

Shader::~Shader() {
	glDeleteProgram(ID);
}

GLuint Shader::load() {
	// Получаем исходные коды вершиного и фрагментного шейдеров
	GLuint program = glCreateProgram();
	GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

	std::string vertexSrcString = read_file(vertexPath);
	std::string fragmentSrcString = read_file(fragmentPath);

	const char* vertexSource = vertexSrcString.c_str();
	const char* fragmentSource = fragmentSrcString.c_str();

	glShaderSource(vertex, 1, &vertexSource, NULL);
	glCompileShader(vertex);
	checkCompileErrors(vertex, "VERTEX");

	glShaderSource(fragment, 1, &fragmentSource, NULL);
	glCompileShader(fragment);
	checkCompileErrors(fragment, "FRAGMENT");

	glAttachShader(program, vertex);
	glAttachShader(program, fragment);

	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vertex);
	glDeleteShader(fragment);

	return program;
}
// Активация шейдера

void Shader::enable() {
	glUseProgram(ID);
}

void Shader::disable() {
	glUseProgram(0);
}

// Обработка ошибок
void Shader::checkCompileErrors(GLuint shader, std::string type) {
	int success;
	char infoLog[1024];
	if (type != "PROGRAM") {
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "ERROR::SHADER_COMPILATION_ERROR of type:" << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
		}
	}
	else {
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
		}
	}
}