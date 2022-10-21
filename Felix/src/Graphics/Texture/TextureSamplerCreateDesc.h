#pragma once
#include <Graphics/Texture/TextureSamplerMagFilter.h>
#include <Graphics/Texture/TextureSamplerMinFilter.h>
#include <Graphics/Texture/TextureSamplerWrapMode.h>

namespace Felix
{
	/// <summary>
	/// Required information to create a texture sampler
	/// </summary>
	struct EXPORT TextureSamplerCreateDesc
	{
		TextureSamplerMinFilter MinFilter;
		TextureSamplerMagFilter MagFilter;
		TextureSamplerWrapMode WrappingS;
		TextureSamplerWrapMode WrappingT;
		TextureSamplerWrapMode WrappingR;
		unsigned int MaxAnisotropy;
	};
}