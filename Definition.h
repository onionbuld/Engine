#pragma once

#define _GLFW
#define _GLM

#include <GL\glew.h>

#ifdef _GLFW
#include <GLFW\glfw3.h>
#endif

#include <iostream>
#ifdef _GLM
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#endif