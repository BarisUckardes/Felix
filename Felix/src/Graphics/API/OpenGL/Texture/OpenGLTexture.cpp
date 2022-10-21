#include "OpenGLTexture.h"
#include <Graphics/API/OpenGL/Texture/OpenGLTextureUtils.h>
#include <GLAD/glad.h>

namespace Felix
{
	OpenGLTexture::OpenGLTexture(const TextureCreateDesc& desc) : Texture(desc)
	{
		/*
		* Create texture
		*/
		glCreateTextures(OpenGLTextureUtils::GetTextureType(desc.Type), 1, &_handle);

		const TextureType type = desc.Type;
		const unsigned int internalFormat = OpenGLTextureUtils::GetTextureInternalFormat(desc.Format);
		const unsigned int format = OpenGLTextureUtils::GetTextureFormat(desc.Format);
		const unsigned int dataType = OpenGLTextureUtils::GetDataType(desc.Format);
		const unsigned int mipmaps = 1;

		/*
		* Update texture data
		*/
		switch (type)
		{
			case Felix::TextureType::Texture1D:
			{
				glTextureStorage1D(_handle, mipmaps, internalFormat, desc.Width);
				break;
			}
			case Felix::TextureType::Texture2D:
			{
				glTextureStorage2D(_handle, mipmaps, internalFormat, desc.Width,desc.Height);
				glTextureSubImage2D(_handle, 0, 0, 0, desc.Width, desc.Height,format, dataType, desc.pInitialData);
				break;
			}
			case Felix::TextureType::Texture3D:
			{
				glTextureStorage3D(_handle, mipmaps, internalFormat, desc.Width,desc.Height,desc.Depth);
				break;
			}
			case Felix::TextureType::CubeTexture:
			{
				ASSERT(false, "OpenGLTexture", "Cube textures are not supported yet!");
				break;
			}
			default:
				break;
		}

		/*
		* Generate texture parameters
		*/
		/*glTextureParameteri(_handle, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTextureParameteri(_handle, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTextureParameteri(_handle, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(_handle, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTextureParameteri(_handle, GL_TEXTURE_MAX_LEVEL, 0);
		glTextureParameteri(_handle, GL_TEXTURE_MAX_LEVEL, mipmaps - 1);

		if(desc.bGenerateMipmaps)
			glGenerateTextureMipmap(_handle);*/
	}
	OpenGLTexture::~OpenGLTexture()
	{
		if (_handle != 0)
			glDeleteTextures(1, &_handle);
	}
}