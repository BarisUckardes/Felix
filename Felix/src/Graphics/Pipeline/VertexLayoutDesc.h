#pragma once
#include <Graphics/Pipeline/VertexElementDesc.h>
#include <vector>

namespace Felix
{
	class EXPORT VertexLayoutDesc
	{
	public:
		VertexLayoutDesc(const std::vector<VertexElementDesc>& elements) : _elements(elements)
		{
			CalculateStride();
		}

		FORCEINLINE std::vector<VertexElementDesc> GetElements() const noexcept { return _elements; }
		FORCEINLINE unsigned int GetStride() const noexcept { return _stride; }

	private:
		void CalculateStride();
	private:
		std::vector<VertexElementDesc> _elements;
		unsigned int _stride;
	};
}