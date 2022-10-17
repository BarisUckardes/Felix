#include "VertexLayoutDesc.h"
#include <Graphics/Pipeline/VertexElementUtils.h>

namespace Felix
{
	void VertexLayoutDesc::CalculateStride()
	{
		unsigned int stride = 0;
		for (unsigned char i = 0; i < _elements.size(); i++)
		{
			const VertexElementDesc& desc = _elements[i];
			stride += VertexElementUtils::GetElementSize(desc.DataType);
		}

		_stride = stride;
	}
}