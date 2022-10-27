#pragma once
#include <Graphics/Texture/TextureSamplerCreateDesc.h>

namespace Felix
{
	class EXPORT OpenGLTextureSamplerUtils
	{
	public:
		FORCEINLINE static unsigned int GetWrapMode(const TextureSamplerWrapMode mode);
		FORCEINLINE static unsigned int GetMinFilter(const TextureSamplerFilter filter,const bool bMipmap);
		FORCEINLINE static unsigned int GetMagFilter(const TextureSamplerFilter filter,const bool bMipmap);
	};
}