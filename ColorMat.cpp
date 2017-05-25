#include "ColorMat.h"

int const COLOR_MAT = __COUNTER__;

const int ColorMat::id = ++Material::id_counter;

ColorMat::ColorMat(glm::vec3 color) :color(color) {}

int ColorMat::getType() const {
//	static int typeID = ++id_counter;
//	return typeID;
	return id;
}

void ColorMat::loadUniforms(GLint *locations) const {
	glUniform3f(locations[COLOR_LOCATION], color.x, color.y, color.z);
}