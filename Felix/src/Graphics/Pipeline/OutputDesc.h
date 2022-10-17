#pragma once
#include <Graphics/Texture/TextureFormat.h>
#include <vector>

namespace Felix
{
	/// <summary>
	/// Represents the output description of the pipeline
	/// </summary>
	struct EXPORT OutputDesc
	{
		unsigned int Width;
		unsigned int Height;
		std::vector<TextureFormat> Formats;
	};
}