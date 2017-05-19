#include "Texture.h"

using namespace std;

TexInfo::TexInfo() : dimensions(), target(0), level(-1), 
	internalFormat(-1), border(-1), format(0), type(0)
{}

TexInfo::TexInfo(GLenum target, std::vector<int> dimensions, GLint level,
	GLint border, GLenum format, GLenum type) :target(target), dimensions(dimensions),
	level(level), border(border), format(format), type(type) {}

Texture::Texture() :texID(-1), manager(nullptr), handle(-1){}

Texture::Texture(GLuint texID, TexInfo info, TextureManager *manager) :
	texID(texID), info(info), manager(manager)
{
	handle = manager->addTexture(*this);
}

void Texture::deleteTexture() {
	if(texID > 0)
		glDeleteTextures(1, (GLuint*)&texID);
	if(manager != nullptr)
		manager->removeTexture(handle);
	texID = -1;
	handle = -1;
}

void Texture::newTexture(GLuint newTexID, TexInfo newInfo) {
	deleteTexture();
	texID = newTexID;
	info = newInfo;
	handle = manager->addTexture(*this);
}

GLenum Texture::getTexUnit() {
	return manager->requestTexUnit(handle);
}

size_t Texture::numDimensions() const { return info.dimensions.size(); }
int Texture::getWidth() const {
	if (info.dimensions.size() > 0)
		return info.dimensions[0];
	else
		return -1;
}

int Texture::getHeight() const {
	if (info.dimensions.size() > 1)
		return info.dimensions[1];
	else
		return -1;
}

int Texture::getDepth() const {
	if (info.dimensions.size() > 2)
		return info.dimensions[2];
	else
		return -1;
}

GLenum Texture::getTarget() const { return info.target; }
GLint Texture::getLevel() const { return info.level; }
GLint Texture::getBorder() const { return info.border; }
GLenum Texture::getFormat() const { return info.format; }
GLenum Texture::getType() const { return info.type; }

