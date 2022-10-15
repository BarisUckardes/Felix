#include "OpenGLCommandBuffer.h"
#include <GLAD/glad.h>

namespace Felix
{
	OpenGLCommandBuffer::OpenGLCommandBuffer(const CommandBufferCreateDesc& desc) : CommandBuffer(desc)
	{

	}
	void OpenGLCommandBuffer::ClearColorCore(const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a)
	{
		glClearColor(r, g, b, a);
		glClear(GL_COLOR_BUFFER_BIT);
	}
	void OpenGLCommandBuffer::LockCore()
	{
	}
	void OpenGLCommandBuffer::UnlockCore()
	{
	}
}