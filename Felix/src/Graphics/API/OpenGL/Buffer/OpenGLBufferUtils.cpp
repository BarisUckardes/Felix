#include "OpenGLBufferUtils.h"
#include <GLAD/glad.h>

namespace Felix
{
	unsigned int OpenGLBufferUtils::GetBufferType(const GraphicsBufferType type)
	{
		switch (type)
		{
			case Felix::GraphicsBufferType::VertexBuffer:
				return GL_ARRAY_BUFFER;
			case Felix::GraphicsBufferType::IndexBuffer:
				return GL_ELEMENT_ARRAY_BUFFER;
			case Felix::GraphicsBufferType::ConstantBuffer:
				return GL_UNIFORM_BUFFER;
			default:
				ASSERT(false, "OpenGLBufferUtils", "Invalid GraphicsBufferType!");
				break;
		}
	}
	unsigned int OpenGLBufferUtils::GetBufferUsage(const GraphicsBufferUsage usage)
	{
		switch (usage)
		{
			case Felix::GraphicsBufferUsage::Immutable:
				return GL_STATIC_DRAW;
			case Felix::GraphicsBufferUsage::Dynamic:
				return GL_DYNAMIC_DRAW;
			default:
				ASSERT(false, "OpenGLBufferUtils", "Invalid GraphicsBufferUsage!");
				break;
		}
	}
}