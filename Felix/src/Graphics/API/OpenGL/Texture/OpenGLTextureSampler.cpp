#include "OpenGLTextureSampler.h"
#include <Graphics/API/OpenGL/Texture/OpenGLTextureSamplerUtils.h>
#include <GLAD/glad.h>

namespace Felix
{
	OpenGLTextureSampler::OpenGLTextureSampler(const TextureSamplerCreateDesc& desc) : TextureSampler(desc)
	{
		glGenSamplers(1, &_handle);

		glSamplerParameteri(_handle, GL_TEXTURE_WRAP_S, OpenGLTextureSamplerUtils::GetWrapMode(desc.WrappingS));
		glSamplerParameteri(_handle, GL_TEXTURE_WRAP_T, OpenGLTextureSamplerUtils::GetWrapMode(desc.WrappingT));
		glSamplerParameteri(_handle, GL_TEXTURE_WRAP_R, OpenGLTextureSamplerUtils::GetWrapMode(desc.WrappingR));

		glSamplerParameteri(_handle, GL_TEXTURE_MAG_FILTER, OpenGLTextureSamplerUtils::GetMinFilter(desc.MinFilter));
		glSamplerParameteri(_handle, GL_TEXTURE_MIN_FILTER, OpenGLTextureSamplerUtils::GetMagFilter(desc.MagFilter));
		glSamplerParameteri(_handle, GL_TEXTURE_MAX_ANISOTROPY, desc.MaxAnisotropy);
	}
	OpenGLTextureSampler::~OpenGLTextureSampler()
	{
		if (_handle != 0)
			glDeleteSamplers(1, &_handle);
	}
}