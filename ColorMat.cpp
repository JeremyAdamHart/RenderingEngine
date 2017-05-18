#include "ColorMat.h"

int const COLOR_MAT = __COUNTER__;

ColorMat::ColorMat(glm::vec3 color) :color(color) {}

int ColorMat::getType() const { return COLOR_MAT; }

void ColorMat::loadUniforms(GLint *locations) const {
	glUniform3f(locations[COLOR_LOCATION], color.x, color.y, color.z);
}