#include "OpenGLTextureSampler.h"
#include <GLAD/glad.h>

namespace Felix
{
	OpenGLTextureSampler::OpenGLTextureSampler(const TextureSamplerCreateDesc& desc) : TextureSampler(desc)
	{
		glCreateSamplers(1, &_handle);

		glSamplerParameteri(_handle, GL_TEXTURE_WRAP_S, 0);
		glSamplerParameteri(_handle, GL_TEXTURE_WRAP_T, 0);
		glSamplerParameteri(_handle, GL_TEXTURE_WRAP_R, 0);

		glSamplerParameteri(_handle, GL_TEXTURE_MAG_FILTER, 0);
		glSamplerParameteri(_handle, GL_TEXTURE_MIN_FILTER, 0);
		glSamplerParameteri(_handle, GL_TEXTURE_MAX_ANISOTROPY, desc.MaxAnisotropy);
	}
	OpenGLTextureSampler::~OpenGLTextureSampler()
	{
		if (_handle != 0)
			glDeleteSamplers(1, &_handle);
	}
}