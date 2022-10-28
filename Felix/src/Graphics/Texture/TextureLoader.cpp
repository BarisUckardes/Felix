#include "TextureLoader.h"
#include <Graphics/Texture/TextureLoadResult.h>
#include <Graphics/Texture/TextureLoaderUtils.h>
#include <stb_image.h>

namespace Felix
{
	bool TextureLoader::LoadTextureFromDisk(const std::string& path, TextureLoadResult& resultOut)
	{
		int width = 0;
		int height = 0;
		int channels = 0;

		unsigned char* pData = stbi_load(path.c_str(), &width, &height, &channels,4);

		resultOut.Width = width;
		resultOut.Height = height;
		resultOut.Depth = 0;
		resultOut.Format = TextureLoaderUtils::GetTextureFormat(channels);
		resultOut.pData = pData;

		return pData != nullptr;
	}
}