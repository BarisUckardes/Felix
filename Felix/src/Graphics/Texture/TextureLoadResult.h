#pragma once
#include <Graphics/Texture/TextureFormat.h>

namespace Felix
{
	/// <summary>
	/// Texture load result output
	/// </summary>
	struct EXPORT TextureLoadResult
	{
		unsigned int Width;
		unsigned int Height;
		unsigned int Depth;
		TextureFormat Format;
		const unsigned char* pData;
	};
}