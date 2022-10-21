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

		/*
		* Update texture data
		*/
		switch (type)
		{
			case Felix::TextureType::Texture1D:
			{
				glTextureStorage1D(_handle, 1, internalFormat, desc.Width);
				glTextureSubImage1D(_handle, 0, 0, desc.Width, format, dataType, desc.pInitialData);
				break;
			}
			case Felix::TextureType::Texture2D:
			{
				glTextureStorage2D(_handle, 1, internalFormat, desc.Width,desc.Height);
				glTextureSubImage2D(_handle, 0, 0, 0, desc.Width, desc.Height,format, dataType, desc.pInitialData);
				break;
			}
			case Felix::TextureType::Texture3D:
			{
				glTextureStorage3D(_handle, 1, internalFormat, desc.Width,desc.Height,desc.Depth);
				glTextureSubImage3D(_handle, 0, 0,0,0, desc.Width,desc.Height,desc.Depth, format, dataType, desc.pInitialData);
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

		if(desc.bGenerateMipmaps)
			glGenerateTextureMipmap(_handle);
	}
	OpenGLTexture::~OpenGLTexture()
	{
		if (_handle != 0)
			glDeleteTextures(1, &_handle);
	}
}