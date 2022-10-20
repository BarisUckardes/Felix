#pragma once
#include <Core/Core.h>

namespace Felix
{
	/// <summary>
	/// Supported blending factors
	/// </summary>
	enum class EXPORT BlendingFactor
	{
		Zero,
		One,
		Source,
		OneMinusSource,
		Destination,
		OneMinusDestination,
		Constant,
		OneMinusConstant
	};
}