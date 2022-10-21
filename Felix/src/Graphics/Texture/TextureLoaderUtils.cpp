#include "TextureLoaderUtils.h"

namespace Felix
{
	TextureFormat TextureLoaderUtils::GetTextureFormat(const unsigned int channels)
	{
		return channels == 4 ? TextureFormat::RGBA8 : TextureFormat::RGB8;
	}
}