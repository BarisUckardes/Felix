#include "OpenGLTextureUtils.h"
#include <GLAD/glad.h>

namespace Felix
{
	unsigned int OpenGLTextureUtils::GetTextureFormat(const TextureFormat format)
	{
		switch (format)
		{
			case Felix::TextureFormat::None:
				return GL_NONE;
			case Felix::TextureFormat::RGB8:
				return GL_RGB;
			case Felix::TextureFormat::RGBA8:
				return GL_RGBA8;
			default:
				ASSERT(false, "OpenGLTextureUtils", "Invalid TextureFormat!");
				break;
		}
	}
	unsigned int OpenGLTextureUtils::GetTextureInternalFormat( TextureFormat format)
	{
		switch (format)
		{
			case Felix::TextureFormat::None:
				return GL_NONE;
			case Felix::TextureFormat::RGB8:
				return GL_RGB8;
			case Felix::TextureFormat::RGBA8:
				return GL_RGBA8;
			default:
				ASSERT(false,"OpenGLTextureUtils","Invalid TextureFormat!");
				break;
		}
	}
	unsigned int OpenGLTextureUtils::GetTextureType(const TextureType type)
	{
		switch (type)
		{
			case Felix::TextureType::Texture1D:
				return GL_TEXTURE_1D;
			case Felix::TextureType::Texture2D:
				return GL_TEXTURE_2D;
			case Felix::TextureType::Texture3D:
				return GL_TEXTURE_3D;
			case Felix::TextureType::CubeTexture:
				return GL_TEXTURE_CUBE_MAP;
			default:
				ASSERT(false, "OpenGLTextureUtils", "Invalid TextureType!");
				break;
		}
	}
	unsigned int OpenGLTextureUtils::GetTextureUsage(const TextureUsage usage)
	{
		switch (usage)
		{
			case Felix::TextureUsage::Immutable:
				return GL_STATIC_DRAW;
			case Felix::TextureUsage::Sampled:
				return GL_STATIC_DRAW;
			case Felix::TextureUsage::RenderTarget:
				return GL_STATIC_DRAW;
			case Felix::TextureUsage::DepthStencilTarget:
				return GL_STATIC_DRAW;
			default:
				ASSERT(false, "OpenGLTextureUtils", "Invalid TextureUsage!");
				break;
		}
	}
	unsigned int OpenGLTextureUtils::GetDataType(const TextureFormat format)
	{
		switch (format)
		{
			case Felix::TextureFormat::None:
				return GL_NONE;
			case Felix::TextureFormat::RGB8:
				return GL_UNSIGNED_BYTE;
			case Felix::TextureFormat::RGBA8:
				return GL_UNSIGNED_BYTE;
			default:
				ASSERT(false, "OpenGLTextureUtils", "Invalid TextureFormat!");
				break;
		}
	}
}