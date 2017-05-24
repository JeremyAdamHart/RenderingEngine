#pragma once

#include "Texture.h"
#include <string>

Texture createTexture2D(std::string filename, TextureManager *manager=nullptr);

Texture createTexture2D(TexInfo info, unsigned char *data=nullptr);
Texture createTexture2D(TexInfo info, TextureManager *manager, 
	unsigned char *data);