#include "Definition.h"
#include "Shader.h"
#include "Window.h"
#include "Texture.h"

const int WIDTH = 800, HEIGHT = 600;

// ----------------------------------------------------------------------------
// vertices
// ----------------------------------------------------------------------------
float Vertices[] = {
	-0.5f, -0.5f, -0.5f,	0.0f, 0.0f, -1.0f,
	0.5f, -0.5f, -0.5f,		0.0f, 0.0f, -1.0f,
	0.5f, 0.5f, -0.5f,		0.0f, 0.0f, -1.0f,
	0.5f, 0.5f, -0.5f,		0.0f, 0.0f, -1.0f,
	-0.5f, 0.5f, -0.5f,		0.0f, 0.0f, -1.0f,
	-0.5f, -0.5f, -0.5f,	0.0f, 0.0f, -1.0f,
	
	-0.5f, -0.5f, 0.5f,		0.0f, 0.0f, 1.0f,
	0.5f, -0.5f, 0.5f,		0.0f, 0.0f, 1.0f,
	0.5f, 0.5f, 0.5f,		0.0f, 0.0f, 1.0f,
	0.5f, 0.5f, 0.5f,		0.0f, 0.0f, 1.0f,
	-0.5f, 0.5f, 0.5f,		0.0f, 0.0f, 1.0f,
	-0.5f, -0.5f, 0.5f,		0.0f, 0.0f, 1.0f,
	
	-0.5f, 0.5f, 0.5f,		-1.0f, 0.0f, 0.0f,
	-0.5f, 0.5f, -0.5f,		-1.0f, 0.0f, 0.0f,
	-0.5f, -0.5f, -0.5f,	-1.0f, 0.0f, 0.0f,
	-0.5f, -0.5f, -0.5f,	-1.0f, 0.0f, 0.0f,
	-0.5f, -0.5f, 0.5f,		-1.0f, 0.0f, 0.0f,
	-0.5f, 0.5f, 0.5f,		-1.0f, 0.0f, 0.0f,
	
	0.5f, 0.5f, 0.5f,		1.0f, 0.0f, 0.0f,
	0.5f, 0.5f, -0.5f,		1.0f, 0.0f, 0.0f,
	0.5f, -0.5f, -0.5f,		1.0f, 0.0f, 0.0f,
	0.5f, -0.5f, -0.5f,		1.0f, 0.0f, 0.0f,
	0.5f, -0.5f, 0.5f,		1.0f, 0.0f, 0.0f,
	0.5f, 0.5f, 0.5f,		1.0f, 0.0f, 0.0f,
	
	-0.5f, -0.5f, -0.5f,	0.0f, -1.0f, 0.0f,
	0.5f, -0.5f, -0.5f,		0.0f, -1.0f, 0.0f,
	0.5f, -0.5f, 0.5f,		0.0f, -1.0f, 0.0f,
	0.5f, -0.5f, 0.5f,		0.0f, -1.0f, 0.0f,
	-0.5f, -0.5f, 0.5f,		0.0f, -1.0f, 0.0f,
	-0.5f, -0.5f, -0.5f,	0.0f, -1.0f, 0.0f,
	
	-0.5f, 0.5f, -0.5f,		0.0f, 1.0f, 0.0f,
	0.5f, 0.5f, -0.5f,		0.0f, 1.0f, 0.0f,
	0.5f, 0.5f, 0.5f,		0.0f, 1.0f, 0.0f,
	0.5f, 0.5f, 0.5f,		0.0f, 1.0f, 0.0f,
	-0.5f, 0.5f, 0.5f,		0.0f, 1.0f, 0.0f,
	-0.5f, 0.5f, -0.5f,		0.0f, 1.0f, 0.0f
};
float cubeVertices[] = {
	// positions          // texture Coords
	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
	0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
	0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
	0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
	-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

	0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
	0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
	0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
};

glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
bool firstMouse = true;
float yaw = -90.0f;
float pitch = 0.0f;
float lastX = 800.0f / 2.0;
float lastY = 600.0 / 2.0;

float deltaTime = 0.0f;
float lastFrame = 0.0f;

void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void MoveCamera(GLFWwindow* window);

glm::vec3 lightPos(1.2f, 1.0f, 2.0f);
glm::vec3 LightColor(1.0f, 1.0f, 1.0f);

int main()
{
	// ----------------------------------------------------------------------------
	// Init
	// ----------------------------------------------------------------------------
	Window window("Engine", 800, 640);

	glfwSetCursorPosCallback(window.goWindow(), mouse_callback);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	// ----------------------------------------------------------------------------
	// Shader
	// ----------------------------------------------------------------------------
	//Shader shader("shader/vertex.vs", "shader/fragment.fs");	// v. 1.0
	//shader.enable();											// v. 1.0
	Shader shader_light("shader/vertex_light.vs", "shader/fragment_light.fs");
	Shader shader_lamp("shader/lamp.vs", "shader/lamp.fs");

	//shader_light.enable();
	//shader_lamp.enable();
	// ----------------------------------------------------------------------------
	// Init object buffer
	// ----------------------------------------------------------------------------
	// cube VAO
	GLuint cubeVAO, cubeVBO;
	glGenVertexArrays(1, &cubeVAO);
	glGenBuffers(1, &cubeVBO);
	glBindVertexArray(cubeVAO);
	glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), &Vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glBindVertexArray(0);
	
	GLuint cube_light_VAO;
	glGenVertexArrays(1, &cube_light_VAO);
	glBindVertexArray(cube_light_VAO);
	glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), &Vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);
	
	// ----------------------------------------------------------------------------
	// Transform and Camera
	// ----------------------------------------------------------------------------
#ifdef _GLM

	glm::mat4 projection = glm::perspective(glm::radians(55.0f), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
	//shader.setMat4("projection", projection);					// v. 1.0
	//shader.setMat4("model", model);							// v. 1.0

#endif
	// ----------------------------------------------------------------------------
	// MainLoop and Renderer
	// ----------------------------------------------------------------------------
	while (!window.closed())
	{
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		glm::mat4 view;
		view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
		window.clear();
		// 1
		shader_light.enable();
		// Light 
		shader_light.setVec3("light.position", lightPos);
		shader_light.setVec3("light.ambient", 0.6f, 0.6f, 0.6f);
		shader_light.setVec3("light.diffuse", 0.8f, 0.8f, 0.8f);
		shader_light.setVec3("light.specular", 1.0f, 1.0f, 1.0f);
		// bronze				
		shader_light.setVec3("material.ambient", 0.2125f, 0.1275f, 0.054f);
		shader_light.setVec3("material.diffuse", 0.714f, 0.4284f, 0.18144f);
		shader_light.setVec3("material.specular", 0.393548f, 0.271906f, 0.166721f);
		shader_light.setFloat("material.shininess", 32.0f);

		shader_light.setVec3("viewPos", cameraPos.x, cameraPos.y, cameraPos.z);
		
		shader_light.setMat4("view", view);
		shader_light.setMat4("projection", projection);
		glBindVertexArray(cubeVAO);
		glm::mat4 model;
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
		shader_light.setMat4("model", model);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		glBindVertexArray(0);
		// 2
		shader_lamp.enable();
		shader_lamp.setMat4("view", view);
		shader_lamp.setMat4("projection", projection);
		model = glm::mat4();
		model = glm::translate(model, lightPos);
		model = glm::scale(model, glm::vec3(0.2f));
		shader_lamp.setMat4("model", model);
		glBindVertexArray(cube_light_VAO);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		glBindVertexArray(0);

		window.update();

		MoveCamera(window.goWindow());
	}
	// ----------------------------------------------------------------------------
	glDeleteVertexArrays(1, &cubeVAO);
	glDeleteVertexArrays(1, &cube_light_VAO);
	glDeleteBuffers(1, &cubeVBO);
	system("PAUSE");
	return 0;
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	float sensitivity = 0.1f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	yaw += xoffset;
	pitch += yoffset;

	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	glm::vec3 front;
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	cameraFront = glm::normalize(front);
}

void MoveCamera(GLFWwindow* window) {
	float cameraSpeed = 5.0f * deltaTime;
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		cameraPos += cameraSpeed * cameraFront;
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		cameraPos -= cameraSpeed * cameraFront;
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
}