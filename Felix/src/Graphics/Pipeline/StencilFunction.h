#pragma once
#include <Core/Core.h>

namespace Felix
{
	/// <summary>
	/// Supported stencil functions
	/// </summary>
	enum class EXPORT StencilFunction
	{
		Never,
		Less,
		Equal,
		LessEqual,
		Greater,
		NotEqual,
		GreaterEqual,
		Always0
	};
}