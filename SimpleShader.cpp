#include "SimpleShader.h"

vector<pair<GLenum, string>> shaders{
	{GL_VERTEX_SHADER, "shaders/simple.vert"},
	{GL_FRAGMENT_SHADER, "shaders/simple.frag"}
};

SimpleShader::SimpleShader(map<GLenum, string> defines) {
	createProgram(defines);
}

bool SimpleShader::createProgram(map<GLenum, string> defines) {
	programID = createGLProgram(shaders, defines);
	return programID != 0;
}