#pragma once

#include "Material.h"
#include "GLGeometry.h"
#include <glm/glm.hpp>
#include "Object.h"

class Drawable : public virtual Object{
	Material *material;
	GLGeometryContainer *geometry;

public:

	Drawable(const glm::mat4 &model_matrix = glm::mat4(), Material *material = nullptr, GLGeometryContainer *geometry = nullptr);

	Material *getMaterial(){ return material; }
	void setMaterial(Material* newMaterial) { material = newMaterial; }
	GLGeometryContainer *getGeometryContainer(){ return geometry; }
	void setGeometryContainer(GLGeometryContainer* newGeometry) { geometry = newGeometry; }
};