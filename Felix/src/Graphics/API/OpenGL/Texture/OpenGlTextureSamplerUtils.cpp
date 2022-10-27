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

    unsigned int OpenGLTextureSamplerUtils::GetMinFilter(const TextureSamplerFilter filter,const bool bMipmap)
    {
        if(bMipmap)
        {
            switch (filter)
            {
                case TextureSamplerFilter::Anisotropic:
                    return 0;
                case TextureSamplerFilter::MinPointMagPointMipPoint:
                    return GL_NEAREST_MIPMAP_NEAREST;
                case TextureSamplerFilter::MinPointMagPointMipLinear:
                    return GL_NEAREST_MIPMAP_LINEAR;
                case TextureSamplerFilter::MinPointMagLinearMipPoint:
                    return GL_NEAREST_MIPMAP_NEAREST;
                case TextureSamplerFilter::MinPointMagLinearMipLinear:
                    return GL_NEAREST_MIPMAP_LINEAR;
                case TextureSamplerFilter::MinLinearMagPointMipPoint:
                    return GL_LINEAR_MIPMAP_NEAREST;
                case TextureSamplerFilter::MinLinearMagPointMipLinear:
                    return GL_LINEAR_MIPMAP_LINEAR;
                case TextureSamplerFilter::MinLinearMagLinearMipPoint:
                    return GL_LINEAR_MIPMAP_NEAREST;
                case TextureSamplerFilter::MinLinearMagLinearMipLinear:
                    return GL_LINEAR_MIPMAP_LINEAR;
                default:
                    ASSERT(false,"OpenGLTextureSamplerUtils","Invalid TextureSamplerFilter!");
            }
        }
        else
        {
            switch (filter)
            {
                case TextureSamplerFilter::Anisotropic:
                    return GL_LINEAR;
                case TextureSamplerFilter::MinPointMagPointMipPoint:
                    return GL_NEAREST;
                case TextureSamplerFilter::MinPointMagPointMipLinear:
                    return GL_NEAREST;
                case TextureSamplerFilter::MinPointMagLinearMipPoint:
                    return GL_NEAREST;
                case TextureSamplerFilter::MinPointMagLinearMipLinear:
                    return GL_NEAREST;
                case TextureSamplerFilter::MinLinearMagPointMipPoint:
                    return GL_LINEAR;
                case TextureSamplerFilter::MinLinearMagPointMipLinear:
                    return GL_LINEAR;
                case TextureSamplerFilter::MinLinearMagLinearMipPoint:
                    return GL_LINEAR;
                case TextureSamplerFilter::MinLinearMagLinearMipLinear:
                    return GL_LINEAR;
                default:
                    ASSERT(false,"OpenGLTextureSamplerUtils","Invalid TextureSamplerFilter!");
            }
        }
    }

    unsigned int OpenGLTextureSamplerUtils::GetMagFilter(const TextureSamplerFilter filter,const bool bMipmap)
    {
        switch (filter)
        {
            case TextureSamplerFilter::Anisotropic:
                return 0;
            case TextureSamplerFilter::MinPointMagPointMipPoint:
                return GL_NEAREST;
            case TextureSamplerFilter::MinPointMagPointMipLinear:
                return GL_NEAREST;
            case TextureSamplerFilter::MinPointMagLinearMipPoint:
                return GL_LINEAR;
            case TextureSamplerFilter::MinPointMagLinearMipLinear:
                return GL_LINEAR;
            case TextureSamplerFilter::MinLinearMagPointMipPoint:
                return GL_NEAREST;
            case TextureSamplerFilter::MinLinearMagPointMipLinear:
                return GL_NEAREST;
            case TextureSamplerFilter::MinLinearMagLinearMipPoint:
                return GL_LINEAR;
            case TextureSamplerFilter::MinLinearMagLinearMipLinear:
                return GL_LINEAR;
            default:
                ASSERT(false,"OpenGLTextureSamplerUtils","Invalid TextureSamplerFilter!");
        }
    }

}