#pragma once
#include <Core/Core.h>

namespace Felix
{
	/// <summary>
	/// Required information to specify a viewport state
	/// </summary>
	struct EXPORT ViewportDesc
	{
		unsigned int PositionX;
		unsigned int PositionY;
		unsigned int Width;
		unsigned int Height;
		float MinDepth;
		float MaxDepth;
	};
}