#include "Definition.h"
#include "Shader.cpp"
#include "Window.h"

const int WIDTH = 800, HEIGHT = 600;

int main()
{
	// ----------------------------------------------------------------------------
	// Init
	// ----------------------------------------------------------------------------
	Window window("Engine", 800, 640);
	// ----------------------------------------------------------------------------
	// vertices
	// ----------------------------------------------------------------------------
	float vertices[] = {
		// positions
		0.5f, 0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,

		0.5f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f
	};
	// ----------------------------------------------------------------------------
	// Shader
	// ----------------------------------------------------------------------------
	Shader shader("shader/vertex.vs", "shader/fragment.fs");
	shader.use();
	// ----------------------------------------------------------------------------
	// Init object buffer
	// ----------------------------------------------------------------------------
	GLuint VBO, VAO;
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindVertexArray(VAO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);
	// ----------------------------------------------------------------------------
	// MainLoop and Renderer
	// ----------------------------------------------------------------------------
	while (!window.closed())
	{
		window.mainLoop();
	}
	// ----------------------------------------------------------------------------
	system("PAUSE");
	return 0;
}