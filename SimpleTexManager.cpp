#include "SimpleTexManager.h"
#include <iostream>
#include <limits>

SimpleTexManager::SimpleTexManager():counter(0) {
	int maxTexUnits = 0;
	glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &maxTexUnits);
	cout << "Max available texture units = " << maxTexUnits << endl;

	texUnits.resize(maxTexUnits - 1, -1);
}

void SimpleTexManager::removeTexture(int handle) {
	textures.erase(handle);
	for (int i = 0; i < texUnits.size(); i++) {
		if (texUnits[i] == handle)
			texUnits[i] = -1;
	}
}

int SimpleTexManager::addTexture(Texture tex) {
	textures[++counter] = tex;
	return counter;
}

//Change -> Use a most recent method
GLenum SimpleTexManager::requestTexUnit(int handle) {
	int texUnit = -1;

	for (int i = 0; i < texUnits.size(); i++) {
		if (texUnits[i] == -1) {
			texUnits[i] = handle;
			texUnit = i + 1;
		}
	}

	int minSize = 10000000000;
	for (int i = 0; i < texUnits.size(); i++) {
		int newSize = sizeOfTexture(textures[texUnits[i]]);
		if (newSize < minSize)
			texUnit = i+1; 
	}

	texUnits[texUnit] = handle;

	return GL_TEXTURE0 + texUnit;
}

int sizeOfTexture(const Texture &tex) {
	int size = 1;
	if (tex.getWidth() > 0) size *= tex.getWidth();
	if (tex.getHeight() > 0) size *= tex.getHeight();
	if (tex.getDepth() > 0) size *= tex.getDepth();

	return size;
}