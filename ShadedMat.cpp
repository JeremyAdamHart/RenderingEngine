#include "ShadedMat.h"

int const SHADED_MAT = __COUNTER__;

const int ShadedMat::id = Material::getNextID();

ShadedMat::ShadedMat(float ka, float kd, float ks, float alpha) :
	ka(ka), kd(kd), ks(ks), alpha(alpha) 
{}

int ShadedMat::getType() const {
//	static int typeID = ++id_counter;
//	return typeID;
	return id;
}

void ShadedMat::loadUniforms(GLint *locations) const {
//	glUniform1i(locations[TEXTURE_LOCATION], tex.getTexUnit());
	glUniform1f(locations[KA_LOCATION], ka);
	glUniform1f(locations[KD_LOCATION], kd);
	glUniform1f(locations[KS_LOCATION], ks);
	glUniform1f(locations[ALPHA_LOCATION], alpha);
}