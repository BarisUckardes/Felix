#pragma once
#include <Core/Core.h>

namespace Felix
{
	/// <summary>
	/// Supported stencil result operations
	/// </summary>
	enum class EXPORT StencilOperation
	{
		Never,
		Less,
		Equal,
		LessEqual,
		Greater,
		NotEqual,
		GreaterEqual,
		Always
	};
}