#include "OpenGLTextureSampler.h"
#include <Graphics/API/OpenGL/Texture/OpenGLTextureSamplerUtils.h>
#include <GLAD/glad.h>

namespace Felix
{
	OpenGLTextureSampler::OpenGLTextureSampler(const TextureSamplerCreateDesc& desc) : TextureSampler(desc)
	{
		glGenSamplers(1, &_handle);

		glSamplerParameteri(_handle, GL_TEXTURE_WRAP_S, OpenGLTextureSamplerUtils::GetWrapMode(desc.WrappingU));
		glSamplerParameteri(_handle, GL_TEXTURE_WRAP_T, OpenGLTextureSamplerUtils::GetWrapMode(desc.WrappingV));
		glSamplerParameteri(_handle, GL_TEXTURE_WRAP_R, OpenGLTextureSamplerUtils::GetWrapMode(desc.WrappingW));

		glSamplerParameteri(_handle, GL_TEXTURE_MAG_FILTER, OpenGLTextureSamplerUtils::GetMinFilter(desc.Filter,desc.bMipmaps));
		glSamplerParameteri(_handle, GL_TEXTURE_MIN_FILTER, OpenGLTextureSamplerUtils::GetMagFilter(desc.Filter,desc.bMipmaps));
		glSamplerParameteri(_handle, GL_TEXTURE_MAX_ANISOTROPY, desc.MaxAnisotropy);
        glSamplerParameteri(_handle, GL_TEXTURE_MIN_LOD,desc.MinLod);
        glSamplerParameteri(_handle,GL_TEXTURE_MAX_LOD,desc.MaxLod);
        glSamplerParameteri(_handle,GL_TEXTURE_LOD_BIAS,desc.LodBias);
	}
	OpenGLTextureSampler::~OpenGLTextureSampler()
	{
		if (_handle != 0)
			glDeleteSamplers(1, &_handle);
	}
}