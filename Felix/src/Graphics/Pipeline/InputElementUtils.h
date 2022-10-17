#pragma once
#include <Graphics/Pipeline/InputElementDesc.h>

namespace Felix
{
	class EXPORT InputElementUtils
	{
	public:
		InputElementUtils() = delete;
		~InputElementUtils() = delete;

		FORCEINLINE static unsigned int GetElementSize(const InputElementDataType type);
	};
}