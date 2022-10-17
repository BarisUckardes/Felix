#pragma once
#include <Core/Core.h>

namespace Felix
{
	/// <summary>
	/// Supported vertex element data types
	/// </summary>
	enum class EXPORT InputElementDataType
	{
		Boolean = 0,
		Integer,
		Integer2,
		Integer3,
		Integer4,
		UnsignedInteger,
		UnsignedInteger2,
		UnsignedInteger3,
		UnsignedInteger4,
		Float,
		Float2,
		Float3,
		Float4,
		Matrix3x3,
		Matrix4x4
	};
}