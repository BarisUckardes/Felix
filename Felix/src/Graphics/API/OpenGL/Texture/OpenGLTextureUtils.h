#pragma once
#include <Graphics/Texture/TextureFormat.h>
#include <Graphics/Texture/TextureType.h>
#include <Graphics/Texture/TextureUsage.h>
#include <Graphics/Texture/TextureWrapMode.h>
#include <Graphics/Texture/TextureMinFilter.h>
#include <Graphics/Texture/TextureMagFilter.h>

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
		FORCEINLINE static unsigned int GetWrapMode(const TextureWrapMode mode);
		FORCEINLINE static unsigned int GetMinFilter(const TextureMinFilter filter);
		FORCEINLINE static unsigned int GetMagFilter(const TextureMagFilter filter);
	};
}