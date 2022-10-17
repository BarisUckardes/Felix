#pragma once
#include <Graphics/Pipeline/VertexElementDesc.h>

namespace Felix
{
	class EXPORT VertexElementUtils
	{
	public:
		VertexElementUtils() = delete;
		~VertexElementUtils() = delete;

		FORCEINLINE static unsigned int GetElementSize(const VertexElementDataType type);
	};
}