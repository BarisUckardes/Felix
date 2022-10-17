#include "InputLayoutDesc.h"
#include <Graphics/Pipeline/InputElementUtils.h>

namespace Felix
{
	void InputLayoutDesc::CalculateStride()
	{
		unsigned int stride = 0;
		for (unsigned char i = 0; i < _elements.size(); i++)
		{
			const InputElementDesc& desc = _elements[i];
			stride += InputElementUtils::GetElementSize(desc.DataType);
		}

		_stride = stride;
	}
}