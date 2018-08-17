#include "Definition.h"
#include "Shader.cpp"

const int WIDTH = 800, HEIGHT = 600;

int main()
{
	// ----------------------------------------------------------------------------
	// Init
	// ----------------------------------------------------------------------------
	if (glfwInit()) {
		std::cout << "GLFW IS OK!" << std::endl;
	}
	else {
		std::cout << "GLFW IS NOT OK!" << std::endl;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "ENGINE", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(window);

	if (glewInit() == GLEW_OK) {
		std::cout << "GLEW IS OK!" << std::endl;
	}
	else {
		std::cout << "GLEW IS NOT OK!" << std::endl;
	}
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
	while (!glfwWindowShouldClose(window))
	{
		// Clear
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// Render
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glBindVertexArray(0);
		// Swap Buffer
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	// ----------------------------------------------------------------------------
	system("PAUSE");
	return 0;
}