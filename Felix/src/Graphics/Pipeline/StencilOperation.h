#pragma once
#include <Core/Core.h>

namespace Felix
{
	/// <summary>
	/// Supported stencil result operations
	/// </summary>
	enum class EXPORT StencilOperation
	{
		Keep,
		Zero,
		Replace,
		Increment,
		IncrementWrap,
		Decrement,
		DecrementWrap,
		Invert
	};
}