#pragma once

#include "Material.h"
#include "GLGeometry.h"
#include <glm/glm.hpp>
#include "Object.h"
#include <map>

class Drawable : public virtual Object{
protected:
	std::map<int, Material*> material;
	GLGeometryContainer *geometry;

public:
	Drawable(glm::vec3 position, glm::quat &orientation, Material *material, GLGeometryContainer *geometry);

	bool loadUniforms(int type, GLint *uniformLocations) const;

	Material *getMaterial(int type);
	void addMaterial(Material* newMaterial);
	bool removeMaterial(int type);
	GLGeometryContainer *getGeometryPtr(){ return geometry; }
	void setGeometryContainer(GLGeometryContainer* newGeometry) { geometry = newGeometry; }
	const GLGeometryContainer &getGeometry() const { return *geometry; }
};