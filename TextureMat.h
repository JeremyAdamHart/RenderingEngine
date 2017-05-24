#pragma once

#include "Material.h"
#include "Texture.h"

extern const int TEXTURE_MAT;

class TextureMat : public Material {
public:
	enum {
		TEXTURE_LOCATION = 0,
		COUNT
	};

	Texture tex;

	TextureMat(Texture tex);

	virtual int getType() const;
	virtual void loadUniforms(GLint *locations) const;	//Must have already called useProgram
};