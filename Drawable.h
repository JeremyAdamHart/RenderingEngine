#pragma once

#include "Material.h"
#include "GLGeometry.h"
#include <glm/glm.hpp>
#include "Object.h"

class Drawable : public virtual Object{
	Material *material;
	GLGeometryContainer *geometry;

public:

	Drawable(glm::vec3 position, glm::quat &orientation, Material *material, GLGeometryContainer *geometry);

	Material *getMaterial(){ return material; }
	void setMaterial(Material* newMaterial) { material = newMaterial; }
	GLGeometryContainer *getGeometryContainer(){ return geometry; }
	void setGeometryContainer(GLGeometryContainer* newGeometry) { geometry = newGeometry; }
};