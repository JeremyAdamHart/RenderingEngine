#include "TextureMat.h"

int const TEXTURE_MAT = __COUNTER__;

const int TextureMat::id = ++Material::id_counter;

TextureMat::TextureMat(Texture tex) :tex(tex) {}

int TextureMat::getType() const {
//	static int typeID = ++id_counter;
//	return typeID;
	return id;
}

void TextureMat::loadUniforms(GLint *locations) const {
	glUniform1i(locations[TEXTURE_LOCATION], tex.getTexUnit());
}