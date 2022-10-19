#pragma once
#include <Graphics/Buffer/GraphicsBuffer.h>

namespace Felix
{
	class EXPORT OpenGLBuffer : public GraphicsBuffer
	{
	public:
		OpenGLBuffer(const GraphicsBufferCreateDesc& desc);
		virtual ~OpenGLBuffer();

		FORCEINLINE unsigned int GetGLHandle() const noexcept { return _handle; }
	private:
		unsigned int _handle;
	};
}