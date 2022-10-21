#include "OpenGLTextureSamplerUtils.h"
#include <GLAD/glad.h>

namespace Felix
{
	unsigned int OpenGLTextureSamplerUtils::GetWrapMode(const TextureSamplerWrapMode mode)
	{
		switch (mode)
		{
		case Felix::TextureSamplerWrapMode::ClampToEdge:
			return GL_CLAMP_TO_EDGE;
		case Felix::TextureSamplerWrapMode::MirroredRepeat:
			return GL_MIRRORED_REPEAT;
		case Felix::TextureSamplerWrapMode::Repeat:
			return GL_REPEAT;
		default:
			ASSERT(false, "OpenGLTextureSamplerResourceUtils", "Invalid TextureSamplerWrapMode!");
			break;
		}
	}
	unsigned int OpenGLTextureSamplerUtils::GetMinFilter(const TextureSamplerMinFilter filter)
	{
		switch (filter)
		{
		case Felix::TextureSamplerMinFilter::Nearest:
			return GL_NEAREST;
		case Felix::TextureSamplerMinFilter::Linear:
			return GL_LINEAR;
		case Felix::TextureSamplerMinFilter::NearestMipmapNearest:
			return GL_NEAREST_MIPMAP_NEAREST;
		case Felix::TextureSamplerMinFilter::LinearMipmapNearest:
			return GL_LINEAR_MIPMAP_NEAREST;
		case Felix::TextureSamplerMinFilter::NearestMipmapLinear:
			return GL_NEAREST_MIPMAP_LINEAR;
		case Felix::TextureSamplerMinFilter::LinearMipmapLinear:
			return GL_LINEAR_MIPMAP_LINEAR;
		default:
			ASSERT(false, "OpenGLTextureSamplerResourceUtils", "Invalid TextureSamplerMinFilter!");
			break;
		}
	}
	unsigned int OpenGLTextureSamplerUtils::GetMagFilter(TextureSamplerMagFilter filter)
	{
		switch (filter)
		{
		case Felix::TextureSamplerMagFilter::Nearest:
			return GL_NEAREST;
		case Felix::TextureSamplerMagFilter::Linear:
			return GL_LINEAR;
		default:
			ASSERT(false, "OpenGLTextureSamplerResourceUtils", "Invalid TextureSamplerMagFilter!");
			break;
		}
	}
}