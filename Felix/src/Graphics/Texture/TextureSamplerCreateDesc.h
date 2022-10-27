#pragma once
#include <Graphics/Texture/TextureSamplerFilter.h>
#include <Graphics/Texture/TextureSamplerWrapMode.h>

namespace Felix
{
	/// <summary>
	/// Required information to create a texture sampler
	/// </summary>
	struct EXPORT TextureSamplerCreateDesc
	{
        TextureSamplerFilter Filter;
		TextureSamplerWrapMode WrappingU;
		TextureSamplerWrapMode WrappingV;
		TextureSamplerWrapMode WrappingW;
        bool bMipmaps;
		unsigned int MaxAnisotropy;
	};
}