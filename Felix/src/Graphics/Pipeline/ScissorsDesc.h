#pragma once
#include <Core/Core.h>

namespace Felix
{
	/// <summary>
	/// Required information to specify a scissors state
	/// </summary>
	struct EXPORT ScissorsDesc
	{
		unsigned int PositionX;
		unsigned int PositionY;
		unsigned int Width;
		unsigned int Height;
	};
}