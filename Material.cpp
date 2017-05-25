#include "Material.h"
#include <glad/glad.h>

int Material::id_counter = 0;

int Material::getType() const { return 0; }
void Material::loadUniforms(GLint *locations) const { }
