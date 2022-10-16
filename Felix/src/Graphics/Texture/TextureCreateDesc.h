#pragma once
#include <Graphics/Texture/TextureType.h>
#include <Graphics/Texture/TextureFormat.h>
#include <Graphics/Texture/TextureUsage.h>

namespace Felix
{
	/// <summary>
	/// Required information to create a texture
	/// </summary>
	struct EXPORT TextureCreateDesc
	{
		TextureType Type;
		TextureUsage Usage;
		TextureFormat Format;
		unsigned int Width;
		unsigned int Height;
		unsigned int Depth;
		const unsigned char* pInitialData;
		bool bGenerateMipmaps;
	};
}