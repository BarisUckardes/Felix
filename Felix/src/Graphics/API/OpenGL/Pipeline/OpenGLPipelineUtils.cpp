#include "OpenGLPipelineUtils.h"
#include <GLAD/glad.h>

namespace Felix
{
	unsigned int OpenGLPipelineUtils::GetFrontFace(const FrontFaceMode frontFace)
	{
		switch (frontFace)
		{
			case FrontFaceMode::CounterClockWise:
				return GL_CCW;
			case FrontFaceMode::ClockWise:
				return GL_CW;
			default:
				ASSERT(false, "OpenGLPipelineUtils", "Invalid FrontFaceMode!");
				break;
		}
	}
	unsigned int OpenGLPipelineUtils::GetCullFace(const CullMode mode)
	{
		switch (mode)
		{
		case CullMode::None0:
			return GL_NONE;
		case CullMode::Front:
			return GL_FRONT;
		case CullMode::Back:
			return GL_BACK;
		case CullMode::FrontAndBack:
			return GL_FRONT_AND_BACK;
		default:
			ASSERT(false, "OpenGLPipelineUtils", "Invalid CullMode!");
			break;
		}
	}
	unsigned int OpenGLPipelineUtils::GetDepthFunction(const DepthTestFunction function)
	{
		switch (function)
		{
		case DepthTestFunction::Always0:
			return GL_ALWAYS;
		case DepthTestFunction::Never:
			return GL_NEVER;
		case DepthTestFunction::Less:
			return GL_LESS;
		case DepthTestFunction::Equal:
			return GL_EQUAL;
		case DepthTestFunction::LessEqual:
			return GL_LEQUAL;
		case DepthTestFunction::Greater:
			return GL_GREATER;
		case DepthTestFunction::NotEqual:
			return GL_NOTEQUAL;
		case DepthTestFunction::GreatEqual:
			return GL_GEQUAL;
		default:
			ASSERT(false, "OpenGLPipelineUtils", "Invalid DepthTestFunction!");
			break;
		}
	}
	unsigned int OpenGLPipelineUtils::GetPrimitiveTopology(const PrimitiveTopology topology)
	{
		switch (topology)
		{
		case PrimitiveTopology::TriangleList:
			return GL_TRIANGLES;
		case PrimitiveTopology::Patches:
			return GL_PATCHES;
		default:
			ASSERT(false, "OpenGLPipelineUtils", "Invalid PrimitiveTopology!");
			break;
		}
	}
	unsigned int OpenGLPipelineUtils::GetShadingMode(const PolygonShadingMode mode)
	{
		switch (mode)
		{
		case PolygonShadingMode::Wireframe:
			return GL_LINES;
		case PolygonShadingMode::Points:
			return GL_POINTS;
		case PolygonShadingMode::Solid:
			return GL_FILL;
		default:
			ASSERT(false, "OpenGLPipelineUtils", "Invalid PolygonShadingMode!");
			break;
		}
	}
	unsigned int OpenGLPipelineUtils::GetInputElementComponentCount(const InputElementDataType type)
	{
		switch (type)
		{
		case InputElementDataType::Boolean:
			return 1;
		case InputElementDataType::Integer:
			return 1;
		case InputElementDataType::Integer2:
			return 2;
		case InputElementDataType::Integer3:
			return 3;
		case InputElementDataType::Integer4:
			return 4;
		case InputElementDataType::UnsignedInteger:
			return 1;
		case InputElementDataType::UnsignedInteger2:
			return 2;
		case InputElementDataType::UnsignedInteger3:
			return 3;
		case InputElementDataType::UnsignedInteger4:
			return 4;
		case InputElementDataType::Float:
			return 1;
		case InputElementDataType::Float2:
			return 2;
		case InputElementDataType::Float3:
			return 3;
		case InputElementDataType::Float4:
			return 4;
		case InputElementDataType::Matrix3x3:
			return 9;
		case InputElementDataType::Matrix4x4:
			return 16;
		default:
			ASSERT(false, "OpenGLPipelineUtils", "Invalid InputElementDataType");
			break;
		}
	}
	unsigned int OpenGLPipelineUtils::GetInputElementDataType(const InputElementDataType type)
	{

		switch (type)
		{
			case InputElementDataType::Boolean:
				return GL_BOOL;
			case InputElementDataType::Integer:
			case InputElementDataType::Integer2:
			case InputElementDataType::Integer3:
			case InputElementDataType::Integer4:
				return GL_INT;
			case InputElementDataType::UnsignedInteger:
				return GL_UNSIGNED_INT;
			case InputElementDataType::UnsignedInteger2:
			case InputElementDataType::UnsignedInteger3:
			case InputElementDataType::UnsignedInteger4:
				return GL_UNSIGNED_INT;;
			case InputElementDataType::Float:
			case InputElementDataType::Float2:
			case InputElementDataType::Float3:
			case InputElementDataType::Float4:
			case InputElementDataType::Matrix3x3:
			case InputElementDataType::Matrix4x4:
				return GL_FLOAT;
			default:
				ASSERT(false, "OpenGLPipelineUtils", "Invalid InputElementDataType");
				break;
		}

	}
	unsigned int OpenGLPipelineUtils::GetStencilOperation(const StencilOperation operation)
	{
		switch (operation)
		{
		case Felix::StencilOperation::Keep:
			return GL_KEEP;
		case Felix::StencilOperation::Zero:
			return GL_ZERO;
		case Felix::StencilOperation::Replace:
			return GL_REPLACE;
		case Felix::StencilOperation::Increment:
			return GL_INCR;
		case Felix::StencilOperation::IncrementWrap:
			return GL_INCR_WRAP;
		case Felix::StencilOperation::Decrement:
			return GL_DECR;
		case Felix::StencilOperation::DecrementWrap:
			return GL_DECR_WRAP;
		case Felix::StencilOperation::Invert:
			return GL_INVERT;
		default:
			ASSERT(false, "OpenGLPipelineUtils", "Invalid StencilOperation");
			break;
		}
	}
	unsigned int OpenGLPipelineUtils::GetStencilFunction(const StencilFunction function)
	{
		switch (function)
		{
			case Felix::StencilFunction::Never:
				return GL_NEVER;
			case Felix::StencilFunction::Less:
				return GL_LESS;
			case Felix::StencilFunction::Equal:
				return GL_EQUAL;
			case Felix::StencilFunction::LessEqual:
				return GL_LEQUAL;
			case Felix::StencilFunction::Greater:
				return GL_GREATER;
			case Felix::StencilFunction::NotEqual:
				return GL_NOTEQUAL;
			case Felix::StencilFunction::GreaterEqual:
				return GL_GEQUAL;
			case Felix::StencilFunction::Always0:
				return GL_ALWAYS;
			default:
				ASSERT(false, "OpenGLPipelineUtils", "Invalid StencilFunction");
				break;
		}
	}
	unsigned int OpenGLPipelineUtils::GetBlendingFunction(const BlendingFunction function)
	{
		switch (function)
		{
			case Felix::BlendingFunction::Add:
				return GL_FUNC_ADD;
			case Felix::BlendingFunction::Subtract:
				return GL_FUNC_SUBTRACT;
			case Felix::BlendingFunction::ReverseSubtract:
				return GL_FUNC_REVERSE_SUBTRACT;
			case Felix::BlendingFunction::Min:
				return GL_MIN;
			case Felix::BlendingFunction::Max:
				return GL_MAX;
			default:
				ASSERT(false, "OpenGLPipelineUtils", "Invalid BlendingFunction!");
				break;
		}
	}
	unsigned int OpenGLPipelineUtils::GetBlendingColorFactor(const BlendingFactor factor)
	{
		switch (factor)
		{
			case Felix::BlendingFactor::Zero:
				return GL_ZERO;
			case Felix::BlendingFactor::One:
				return GL_ONE;
			case Felix::BlendingFactor::Source:
				return GL_SRC_COLOR;
			case Felix::BlendingFactor::OneMinusSource:
				return GL_ONE_MINUS_SRC_COLOR;
			case Felix::BlendingFactor::Destination:
				return GL_DST_COLOR;
			case Felix::BlendingFactor::OneMinusDestination:
				return GL_ONE_MINUS_DST_COLOR;
			case Felix::BlendingFactor::Constant:
				return GL_CONSTANT_COLOR;
			case Felix::BlendingFactor::OneMinusConstant:
				return GL_ONE_MINUS_CONSTANT_COLOR;
			default:
				ASSERT(false, "OpenGLPipelineUtils", "Invalid BlendingFactor!");
				break;
		}
	}
	unsigned int OpenGLPipelineUtils::GetBlendingAlphaFactor(const BlendingFactor factor)
	{
		switch (factor)
		{
		case Felix::BlendingFactor::Zero:
			return GL_ZERO;
		case Felix::BlendingFactor::One:
			return GL_ONE;
		case Felix::BlendingFactor::Source:
			return GL_SRC_ALPHA;
		case Felix::BlendingFactor::OneMinusSource:
			return GL_ONE_MINUS_SRC_ALPHA;
		case Felix::BlendingFactor::Destination:
			return GL_DST_ALPHA;
		case Felix::BlendingFactor::OneMinusDestination:
			return GL_ONE_MINUS_DST_ALPHA;
		case Felix::BlendingFactor::Constant:
			return GL_CONSTANT_ALPHA;
		case Felix::BlendingFactor::OneMinusConstant:
			return GL_ONE_MINUS_CONSTANT_ALPHA;
		default:
			ASSERT(false, "OpenGLPipelineUtils", "Invalid BlendingFactor!");
			break;
		}
	}
}