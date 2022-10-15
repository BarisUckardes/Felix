#pragma once
#include <Core/Core.h>

namespace Felix
{
	/// <summary>
	/// Supported buffer types
	/// </summary>
	enum class EXPORT GraphicsBufferType
	{
		VertexBuffer,
		IndexBuffer,
		ConstantBuffer
	};
}