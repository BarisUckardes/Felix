#pragma once
#include <Graphics/Buffer/GraphicsBufferType.h>
#include <Graphics/Buffer/GraphicsBufferUsage.h>

namespace Felix
{
	/// <summary>
	/// Required information to create a graphics buffer
	/// </summary>
	struct EXPORT GraphicsBufferCreateDesc
	{
		GraphicsBufferType Type;
		GraphicsBufferUsage Usage;
		const unsigned char* pInitialData;
		unsigned long Size;
		unsigned int SubItemSize;
		unsigned int SubItemCount;
	};
}