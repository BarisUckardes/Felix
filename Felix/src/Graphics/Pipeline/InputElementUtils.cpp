#include "InputElementUtils.h"

namespace Felix
{
	unsigned int InputElementUtils::GetElementSize(const InputElementDataType type)
	{
		switch (type)
		{
			case InputElementDataType::Boolean:
				return 1;
			case InputElementDataType::Integer:
				return 4;
			case InputElementDataType::Integer2:
				return 8;
			case InputElementDataType::Integer3:
				return 12;
			case InputElementDataType::Integer4:
				return 16;
			case InputElementDataType::UnsignedInteger:
				return 4;
			case InputElementDataType::UnsignedInteger2:
				return 8;
			case InputElementDataType::UnsignedInteger3:
				return 12;
			case InputElementDataType::UnsignedInteger4:
				return 16;
			case InputElementDataType::Float:
				return 4;
			case InputElementDataType::Float2:
				return 8;
			case InputElementDataType::Float3:
				return 12;
			case InputElementDataType::Float4:
				return 16;
			case InputElementDataType::Matrix3x3:
				return 36;
			case InputElementDataType::Matrix4x4:
				return 64;
			default:
				ASSERT(false, "VertexElementUtils", "Invalid VertexElementDataType, cannot get a size out of it");
				break;
		}
	}
}