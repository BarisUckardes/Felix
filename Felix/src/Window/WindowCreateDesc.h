#pragma once
#include <string>

namespace Felix
{
	/// <summary>
	/// Required information to create window 
	/// </summary>
	struct WindowCreateDesc
	{
		std::string Title;
		unsigned short Width;
		unsigned short Height;
		unsigned short PositionX;
		unsigned short PositionY;
	};
}