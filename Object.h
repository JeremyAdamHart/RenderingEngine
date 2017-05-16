#pragma once
#include <glm/gtx/quaternion.hpp>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

class Object {
protected:
	Object();
	Object(glm::vec3 position, glm::quat orientation);

	glm::quat orientation;
	glm::vec3 position;
public:
	glm::quat getOrientationQuat();
	glm::mat4 getOrientationMat4();
	glm::mat4 getTransform();
	glm::vec3 getPos();
};
