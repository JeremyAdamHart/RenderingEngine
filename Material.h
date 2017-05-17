#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

//All derived subclasses are singletons
class Material{
protected:
	Material(){}
public:
	virtual int getType();
};