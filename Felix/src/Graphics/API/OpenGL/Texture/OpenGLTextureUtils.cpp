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
				return GL_RGB8;
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
				return GL_RGB;
			case Felix::TextureFormat::RGBA8:
				return GL_RGBA;
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
	unsigned int OpenGLTextureUtils::GetWrapMode(const TextureWrapMode mode)
	{
		switch (mode)
		{
		case Felix::TextureWrapMode::ClampToEdge:
			return GL_CLAMP_TO_EDGE;
		case Felix::TextureWrapMode::MirroredRepeat:
			return GL_MIRRORED_REPEAT;
		case Felix::TextureWrapMode::Repeat:
			return GL_REPEAT;
		default:
			ASSERT(false, "OpenGLTextureSamplerResourceUtils", "Invalid TextureSamplerWrapMode!");
			break;
		}
	}
	unsigned int OpenGLTextureUtils::GetMinFilter(const TextureMinFilter filter)
	{
		switch (filter)
		{
		case Felix::TextureMinFilter::Nearest:
			return GL_NEAREST;
		case Felix::TextureMinFilter::Linear:
			return GL_LINEAR;
		case Felix::TextureMinFilter::NearestMipmapNearest:
			return GL_NEAREST_MIPMAP_NEAREST;
		case Felix::TextureMinFilter::LinearMipmapNearest:
			return GL_LINEAR_MIPMAP_NEAREST;
		case Felix::TextureMinFilter::NearestMipmapLinear:
			return GL_NEAREST_MIPMAP_LINEAR;
		case Felix::TextureMinFilter::LinearMipmapLinear:
			return GL_LINEAR_MIPMAP_LINEAR;
		default:
			ASSERT(false, "OpenGLTextureSamplerResourceUtils", "Invalid TextureSamplerMinFilter!");
			break;
		}
	}
	unsigned int OpenGLTextureUtils::GetMagFilter(TextureMagFilter filter)
	{
		switch (filter)
		{
		case Felix::TextureMagFilter::Nearest:
			return GL_NEAREST;
		case Felix::TextureMagFilter::Linear:
			return GL_LINEAR;
		default:
			ASSERT(false, "OpenGLTextureSamplerResourceUtils", "Invalid TextureSamplerMagFilter!");
			break;
		}
	}
}