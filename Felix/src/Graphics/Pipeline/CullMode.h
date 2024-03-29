#pragma once
#include <Core/Core.h>

namespace Felix
{
	/// <summary>
	/// Supported cullings modes
	/// </summary>
	enum class EXPORT CullMode
	{
		None0 = 0,
		Front,
		Back,
		FrontAndBack
	};
}