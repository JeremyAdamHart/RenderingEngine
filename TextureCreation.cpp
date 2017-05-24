#include "TextureCreation.h"
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

using namespace std;

Texture createTexture2D(string filename, TextureManager *manager) {
	int width, height, comp;
	unsigned char *image = stbi_load(filename.c_str(), 
		&width, &height, &comp, 0);
	
	if ((image == nullptr) || (comp > 4)) {
		cout << "Texture invalid" << endl;
		return Texture();
	}

	const GLenum formats[4] = { GL_RED, GL_RG, GL_RGB, GL_RGBA };

	TexInfo info(GL_TEXTURE_2D, { width, height }, 0, 
		formats[comp-1], formats[comp-1], GL_UNSIGNED_BYTE);
		
	Texture tex = createTexture2D(info, manager, image);
	stbi_image_free(image);
	
	return tex;
}

Texture createTexture2D(TexInfo info, unsigned char *data) {
	return createTexture2D(info, nullptr, data);
}

Texture createTexture2D(TexInfo info, TextureManager *manager, 
	unsigned char *data) {
	GLuint texID;
	glGenTextures(1, &texID);
	glActiveTexture(GL_TEXTURE0);	//Bind to avoid disturbing active units
	glBindTexture(GL_TEXTURE_2D, texID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glTexImage2D(GL_TEXTURE_2D, info.level, info.format, info.dimensions[0],
		info.dimensions[1], 0, info.internalFormat, GL_UNSIGNED_BYTE, data);

	return Texture(texID, info, manager);
}