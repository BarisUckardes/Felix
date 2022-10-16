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

		virtual GraphicsBufferType GetBufferType() const noexcept override { return GraphicsBufferType::VertexBuffer; }
	private:
		unsigned int _handle;
	};
}