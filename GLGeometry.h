#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

//Namespace for vertex attributes
struct ATTRIB_LOCATION {
	enum{
		POSITION=0,
		NORMAL,
		TEX_COORD,
		COLOR,
			};
};

class GLGeometryContainer{
protected:
	GLGeometryContainer(){}

public:
	virtual void bindGeometry(){}
	virtual int startIndex() { return 0; }
	virtual int numElements() { return 0; }
	virtual GLenum getMode() { return 0; }
	virtual GLint getVaoID() { return -1; }		//Don't use to bind VAO, only for comparison

	virtual bool usingDrawElements() { return false; }
};