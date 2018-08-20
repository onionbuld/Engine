#include "Definition.h"
#include "Shader.h"
#include "Window.h"

const int WIDTH = 800, HEIGHT = 600;

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
GLuint VBO, VAO;

int main()
{
	// ----------------------------------------------------------------------------
	// Init
	// ----------------------------------------------------------------------------
	Window window("Engine", 800, 640);
	
	// ----------------------------------------------------------------------------
	// Shader
	// ----------------------------------------------------------------------------
	Shader shader("shader/vertex.vs", "shader/fragment.fs");
	shader.enable();
	// ----------------------------------------------------------------------------
	// Init object buffer
	// ----------------------------------------------------------------------------
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
		window.clear();
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glBindVertexArray(0);
		window.update();
	}
	// ----------------------------------------------------------------------------
	system("PAUSE");
	return 0;
}