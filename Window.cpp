#include "window.h"

	Window::Window(const char* name, int width, int height) {
		this->name = name;
		this->width = width;
		this->height = height;
		if (!init())
			glfwTerminate();
	}

	Window::~Window() {
		glfwTerminate();
	}

	bool Window::init() {
		if (!glfwInit()) {
			std::cout << "GLFW IS NOT!" << std::endl;
			glfwTerminate();
			return false;
		}
		else {
			std::cout << "GLFW IS GOOD!" << std::endl;
		}
		window = glfwCreateWindow(width, height, name, NULL, NULL);
		
		if (window == NULL) {
			std::cerr << "Error: Create Window IS NOT OFF!" << std::endl;
			glfwTerminate();
			return -1;
		}
		glfwMakeContextCurrent(window);
		glfwSetWindowSizeCallback(window, resize_callback);
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		
		if (!glewInit() == GLEW_OK) {
			std::cout << "GLEW IS NOT!" << std::endl;
			glfwTerminate();
			return false;
		}
		else {
			std::cout << "GLEW IS GOOD!" << std::endl;
		}
		return true;
	}

	bool Window::closed() {
		return (glfwWindowShouldClose(window) == 1);
	}

	void Window::mainLoop() {
		clear();
		render();
		update();
	}

	void Window::update() {
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	
	void Window::clear() {
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::render() {
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		
		glBegin(GL_QUADS);
		glVertex2d(0.5f, 0.5f);
		glVertex2d(0.5f, -0.5f);
		glVertex2d(-0.5f, -0.5f);
		glVertex2d(-0.5f, 0.5f);
		glEnd();
		
	
	}

	 void resize_callback(GLFWwindow* window, int width, int height) {
		glViewport(0, 0, width, height);
	}

	 GLFWwindow* Window::goWindow() {
		 return window;
	 }