#pragma once
#include <Core/Core.h>

namespace Felix
{
	/// <summary>
	/// Supported texture formats
	/// </summary>
	enum class TextureFormat
	{
		None = 0,
		RGB8,
		RGBA8,
		RGBA32F,
		Depth24Stencil8
	};
}