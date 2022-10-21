#pragma once
#include <Graphics/Texture/TextureFormat.h>

namespace Felix
{
	class EXPORT TextureLoaderUtils
	{
	public:
		TextureLoaderUtils() = delete;
		~TextureLoaderUtils() = delete;

		FORCEINLINE static TextureFormat GetTextureFormat(const unsigned int channels);
	};
}