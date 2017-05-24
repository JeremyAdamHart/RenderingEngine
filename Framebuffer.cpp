#include "Framebuffer.h"

const Texture NO_TEXTURE;

Framebuffer::Framebuffer(GLuint id, Texture tex, GLenum attachment) :
id(id)
{
	addTexture(tex, attachment);
}

void Framebuffer::addTexture(Texture newTex, GLenum attachment) {
	tex[attachment] = newTex;

	glBindFramebuffer(GL_FRAMEBUFFER, id);
	glFramebufferTexture(GL_FRAMEBUFFER,
		attachment,
		newTex.getID(),
		newTex.getLevel());
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}
const Texture &Framebuffer::getTexture(GLenum attachment) const { 
	try {
		return tex.at(attachment);
	}
	catch (out_of_range) {
		return NO_TEXTURE;
	}
}

GLuint Framebuffer::getID() const { return id; }