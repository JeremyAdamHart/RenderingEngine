#include "TextureMat.h"

int const TEXTURE_MAT = __COUNTER__;

TextureMat::TextureMat(Texture tex) :tex(tex) {}

int TextureMat::getType() const { return TEXTURE_MAT; }

void TextureMat::loadUniforms(GLint *locations) const {
	glUniform1i(locations[TEXTURE_LOCATION], tex.getTexUnit());
}