#pragma once
#include <Graphics/Buffer/GraphicsBufferType.h>
#include <Graphics/Buffer/GraphicsBufferUsage.h>

namespace Felix
{
	class EXPORT OpenGLBufferUtils
	{
	public:
		OpenGLBufferUtils() = delete;
		~OpenGLBufferUtils() = delete;

		FORCEINLINE static unsigned int GetBufferType(const GraphicsBufferType type);
		FORCEINLINE static unsigned int GetBufferUsage(const GraphicsBufferUsage usage);
	};
}