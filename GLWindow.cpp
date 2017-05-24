#include "GLWindow.h"

#include <iostream>

using namespace glm;
using namespace std;

#include "Drawable.h"
#include "SimpleGeometry.h"
#include "SimpleShader.h"
#include "ColorMat.h"
#include "TrackballCamera.h"
#include "SimpleTexManager.h"
#include "simpleTexShader.h"
#include "TextureCreation.h"
#include "TextureMat.h"
#include "MeshInfoLoader.h"


#include <glm/gtc/matrix_transform.hpp>

TrackballCamera cam(
	vec3(0, 0, -1), vec3(0, 0, 1),
	glm::perspective(90.f, 1.f, 0.1f, 3.f));

void cursorPositionCallback(GLFWwindow *window, double xpos, double ypos) {
	static vec2 lastPos = vec2(0.f, 0.f);
	
	int vp[4];
	glGetIntegerv(GL_VIEWPORT, vp);
	vec2 mousePos = vec2(float(xpos) / float(vp[2]), 
		float(-ypos) / float(vp[3]))*2.f
		- vec2(1.f, 1.f);

	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
		vec2 diff = mousePos - lastPos;
		cam.trackballRight(-diff.x*3.14159f);
		cam.trackballUp(-diff.y*3.14159f);
	}

	lastPos = mousePos;
}

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

/*	//TEST TEXTURE MANAGER
	SimpleTexManager tm;

	Texture t1(0, TexInfo(), &tm);
	Texture t2(0, TexInfo(), &tm);
	Texture t3(0, TexInfo(), &tm);
	Texture t4(0, TexInfo(), &tm);

	int units[10];
	units[0] = t3.getTexUnit();
	units[1] = t2.getTexUnit();
	units[2] = t3.getTexUnit();
	units[3] = t1.getTexUnit();
	units[4] = t4.getTexUnit();
	units[5] = t3.getTexUnit();
	units[6] = t4.getTexUnit();
	units[7] = t1.getTexUnit();
	units[8] = t1.getTexUnit();
	units[9] = t2.getTexUnit();

	t3.deleteTexture();
	t2.deleteTexture();
	t1.deleteTexture();
	t4.deleteTexture();

	//END TEST */

	glfwSetCursorPosCallback(window, cursorPositionCallback);

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

	vec2 coords[6] = {
		//First triangle
		vec2(0, 1.f),
		vec2(1.f, 1.f),
		vec2(1.f, 0.f),
		//Second triangle
		vec2(1.f, 0.f),
		vec2(0.f, 0.f),
		vec2(0.f, 1.f)
	};

	SimpleTexManager tm;
	Texture dogTexture = createTexture2D("textures/dog.png", &tm);

	Drawable texSquare(
		new TextureMat(dogTexture),
		new SimpleTexGeometry(points, coords, 6, GL_TRIANGLES));

	Drawable square(
		new ColorMat(vec3(0.f, 0.f, 1.f)),
		new SimpleGeometry(points, 6, GL_TRIANGLES));



	SimpleTexShader texShader;
	SimpleShader shader;


	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//		shader.draw(cam, square);
		texShader.draw(cam, texSquare);

		glfwSwapBuffers(window);
		glfwWaitEvents();
	}

	delete square.getMaterial(COLOR_MAT);
	delete square.getGeometryPtr();
	dogTexture.deleteTexture();

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

