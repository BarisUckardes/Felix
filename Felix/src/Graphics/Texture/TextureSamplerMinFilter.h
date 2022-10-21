#pragma once
#include <Core/Core.h>

namespace Felix
{
	/// <summary>
	/// Supported minification filtering
	/// </summary>
	enum class EXPORT TextureSamplerMinFilter
	{
		Nearest,
		Linear,
		NearestMipmapNearest,
		LinearMipmapNearest,
		NearestMipmapLinear,
		LinearMipmapLinear
	};
}