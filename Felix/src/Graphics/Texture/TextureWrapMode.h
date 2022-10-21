#pragma once
#include <Core/Core.h>

namespace Felix
{
	/// <summary>
	/// Supported texture sampler uv wrapping modes
	/// </summary>
	enum class EXPORT TextureWrapMode
	{
		ClampToEdge,
		MirroredRepeat,
		Repeat
	};
}