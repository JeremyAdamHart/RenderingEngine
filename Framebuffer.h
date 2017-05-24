#pragma once

#include "glSupport.h"
#include "Texture.h"
#include <map>

class Framebuffer {
	map<GLenum, Texture> tex;
public:
	GLuint id;
	Framebuffer(GLuint id, Texture tex, GLenum attachment);

	GLuint getID() const;
	const Texture &getTexture(GLenum attachment) const;
	void addTexture(Texture newTex, GLenum attachment);
};