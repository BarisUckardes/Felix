#pragma once
#include <Core/Core.h>

namespace Felix
{
	/// <summary>
	/// Required information to update a graphics buffer
	/// </summary>
	struct EXPORT GraphicsBufferUpdateDesc
	{
		unsigned long Offset;
		unsigned long Size;
		const unsigned char* pData;
	};
}