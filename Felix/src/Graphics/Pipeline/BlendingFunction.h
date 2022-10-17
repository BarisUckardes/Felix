#pragma once
#include <Core/Core.h>

namespace Felix
{
	/// <summary>
	/// Supported blending functions
	/// </summary>
	enum class EXPORT BlendingFunction
	{
		Add,
		Subtract,
		ReverseSubtract,
		Min,
		Max
	};
}