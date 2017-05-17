#pragma once

#include "Shader.h"
#include "Drawable.h"
#include "Camera.h"
#include "Scene.h"

class SimpleShader : public Shader {
protected:

public:
	SimpleShader(map<GLenum, string> defines = {});
	
	virtual bool createProgram(map<GLenum, string> defines = {});

	void draw(const Camera &cam, const Drawable &obj);
	void draw(const Camera &cam, const Scene &scene);
};