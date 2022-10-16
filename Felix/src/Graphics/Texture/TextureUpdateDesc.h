#pragma once
#include <Core/Core.h>

namespace Felix
{
	/// <summary>
	/// Required information to update a texture
	/// </summary>
	struct EXPORT TextureUpdateDesc
	{
		const unsigned char* pData;
	};
}