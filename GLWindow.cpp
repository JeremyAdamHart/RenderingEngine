#include "GLWindow.h"

#include <iostream>

using namespace glm;
using namespace std;

#include "Drawable.h"
#include "SimpleGeometry.h"
#include "SimpleShader.h"
#include "ColorMat.h"
#include "TrackballCamera.h"
#include <glm/gtc/matrix_transform.hpp>

WindowManager::WindowManager() :
window_width(800), window_height(800)
{
	glfwInit();
	window = createWindow(window_width, window_height, 
		"You really should rename this");
	initGlad();

	glfwSwapInterval(1);

	glClearColor(1.f, 1.f, 1.f, 1.f);

	glViewport(0, 0, window_width, window_height);
}

WindowManager::WindowManager(int width, int height, std::string name, glm::vec4 color) :
	window_width(width), window_height(height) 
{
	glfwInit();
	window = createWindow(window_width, window_height, name);
	initGlad();

	glClearColor(color.r, color.g, color.b, color.a);

	glViewport(0, 0, window_width, window_height);
}

//Temporary testing
void WindowManager::mainLoop() {

	vec3 points [6] = {
		//First triangle
		vec3(-0.5f, 0.5f, 0.f),
		vec3(0.5f, 0.5f, 0.f),
		vec3(0.5f, -0.5f, 0.f),
		//Second triangle
		vec3(0.5f, -0.5f, 0.f),
		vec3(-0.5f, -0.5f, 0.f),
		vec3(-0.5f, 0.5f, 0.f)
	};

	Drawable square(
		new ColorMat(vec3(0.f, 0.f, 1.f)),
		new SimpleGeometry(points, 6, GL_TRIANGLES));

	TrackballCamera cam(
		vec3(0, 0, -1), vec3(0, 0, 1),
		glm::perspective(90.f, 1.f, 0.1f, 3.f));

	SimpleShader shader;

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		shader.draw(cam, square);

		glfwSwapBuffers(window);
		glfwWaitEvents();
	}

	delete square.getMaterial(COLOR_MAT);
	delete square.getGeometryPtr();

	glfwTerminate();
}

void initGlad() {
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "GLAD initialization failed" << std::endl;
	}
}

GLFWwindow *createWindow(int width, int height, std::string name)
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	GLFWwindow *window = glfwCreateWindow(
		width, height, name.c_str(), nullptr, nullptr);
	
	if (window == NULL) {
		glfwTerminate();
		return nullptr;
	}
	else {
		glfwMakeContextCurrent(window);
		return window;
	}
}

