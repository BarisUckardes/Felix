#pragma once
#include <Graphics/Pipeline/InputElementDesc.h>
#include <vector>

namespace Felix
{
	class EXPORT InputLayoutDesc
	{
	public:
		InputLayoutDesc(const std::vector<InputElementDesc>& elements) : _elements(elements)
		{
			CalculateStride();
		}
		InputLayoutDesc() : _stride(0) {}

		FORCEINLINE std::vector<InputElementDesc> GetElements() const noexcept { return _elements; }
		FORCEINLINE unsigned int GetStride() const noexcept { return _stride; }

	private:
		void CalculateStride();
	private:
		std::vector<InputElementDesc> _elements;
		unsigned int _stride;
	};
}