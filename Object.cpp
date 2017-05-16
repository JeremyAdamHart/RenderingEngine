#include "Object.h"
#include "glmSupport.h"

using namespace glm;

quat Object::getOrientationQuat() {return orientation;}

vec3 Object::getPos() {return position;}

mat4 Object::getOrientationMat4() { return toMat4(orientation); }

mat4 Object::getTransform() { return translateMatrix(getPos())*getOrientationMat4(); }