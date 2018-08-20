#pragma once
#include <iostream>
#include <GL\glew.h>
#include <GLFW\glfw3.h>

class Window {
	public:
		Window(const char* name, int wigth, int height);
		~Window();

		bool closed();
		void mainLoop();
		GLFWwindow* goWindow();
	private:
		const char* name;
		int width;
		int height;
		GLFWwindow* window;
	
		bool init();
public:
		void update();
		void clear();
private:
		void render();

		friend void resize_callback(GLFWwindow* window, int width, int height);
	};