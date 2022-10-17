#include "VertexElementUtils.h"

namespace Felix
{
	unsigned int VertexElementUtils::GetElementSize(const VertexElementDataType type)
	{
		switch (type)
		{
			case VertexElementDataType::Boolean:
				return 1;
			case VertexElementDataType::Integer:
				return 4;
			case VertexElementDataType::Integer2:
				return 8;
			case VertexElementDataType::Integer3:
				return 12;
			case VertexElementDataType::Integer4:
				return 16;
			case VertexElementDataType::UnsignedInteger:
				return 4;
			case VertexElementDataType::UnsignedInteger2:
				return 8;
			case VertexElementDataType::UnsignedInteger3:
				return 12;
			case VertexElementDataType::UnsignedInteger4:
				return 16;
			case VertexElementDataType::Float:
				return 4;
			case VertexElementDataType::Float2:
				return 8;
			case VertexElementDataType::Float3:
				return 12;
			case VertexElementDataType::Float4:
				return 16;
			case VertexElementDataType::Matrix3x3:
				return 36;
			case VertexElementDataType::Matrix4x4:
				return 64;
			default:
				ASSERT(false, "VertexElementUtils", "Invalid VertexElementDataType, cannot get a size out of it");
				break;
		}
	}
}