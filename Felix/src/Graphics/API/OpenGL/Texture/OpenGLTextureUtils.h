#pragma once
#include <Graphics/Texture/TextureFormat.h>
#include <Graphics/Texture/TextureType.h>
#include <Graphics/Texture/TextureUsage.h>

namespace Felix
{
	class EXPORT OpenGLTextureUtils
	{
	public:
		OpenGLTextureUtils() = delete;
		~OpenGLTextureUtils() = delete;

		FORCEINLINE static unsigned int GetTextureFormat(const TextureFormat format);
		FORCEINLINE static unsigned int GetTextureInternalFormat(const TextureFormat format);
		FORCEINLINE static unsigned int GetTextureType(const TextureType type);
		FORCEINLINE static unsigned int GetTextureUsage(const TextureUsage usage);
		FORCEINLINE static unsigned int GetDataType(const TextureFormat format);
	};
}