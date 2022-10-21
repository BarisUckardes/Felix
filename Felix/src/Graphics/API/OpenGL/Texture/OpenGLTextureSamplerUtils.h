#pragma once
#include <Graphics/Texture/TextureSamplerCreateDesc.h>

namespace Felix
{
	class EXPORT OpenGLTextureSamplerUtils
	{
	public:
		FORCEINLINE static unsigned int GetWrapMode(const TextureSamplerWrapMode mode);
		FORCEINLINE static unsigned int GetMinFilter(const TextureSamplerMinFilter filter);
		FORCEINLINE static unsigned int GetMagFilter(const TextureSamplerMagFilter filter);
	};
}