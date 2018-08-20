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

/*
std::string vertexCode;
std::string fragmentCode;
std::ifstream vShaderFile;
std::ifstream fShaderFile;
// Ловим исключения от файлов
vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
try {
// Открыть файл
vShaderFile.open(vertexPath);
fShaderFile.open(fragmentPath);
std::stringstream vShaderStream, fShaderStream;
// Чтение из файла
vShaderStream << vShaderFile.rdbuf();
fShaderStream << fShaderFile.rdbuf();
// Закрываем файлы
vShaderFile.close();
fShaderFile.close();
// Запись строк из потока
vertexCode = vShaderStream.str();
fragmentCode = fShaderStream.str();
} catch (std::ifstream::failure	e) {
std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
}
const char* vShaderCode = vertexCode.c_str();
const char* fShaderCode = fragmentCode.c_str();
// Compiling shaders
GLuint vertex, fragment;
// VS
vertex = glCreateShader(GL_VERTEX_SHADER);
glShaderSource(vertex, 1, &vShaderCode, NULL);
glCompileShader(vertex);
checkCompileErrors(vertex, "VERTEX");
// FS
fragment = glCreateShader(GL_FRAGMENT_SHADER);
glShaderSource(fragment, 1, &fShaderCode, NULL);
glCompileShader(fragment);
checkCompileErrors(fragment, "FRAGMENT");
// PROGRAMM

ID = glCreateProgram();
glAttachShader(ID, vertex);
glAttachShader(ID, fragment);
glLinkProgram(ID);
checkCompileErrors(ID, "PROGRAM");
// Delete VS AND FS
glDeleteShader(vertex);
glDeleteShader(fragment);
*/