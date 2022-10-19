#pragma once
#include <Core/Core.h>

namespace Felix
{
	/// <summary>
	/// Supported depth test functions
	/// </summary>
	enum class EXPORT DepthTestFunction
	{
		Always,
		Never,
		Less,
		Equal,
		LessEqual,
		Greater,
		NotEqual,
		GreatEqual
	};
}