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
	void OpenGLCommandBuffer::ClearDepthCore(const unsigned char depth)
	{
		glClearDepth(depth);
		glClear(GL_DEPTH_BUFFER_BIT);
	}
	void OpenGLCommandBuffer::ClearStencilCore(const int stencil)
	{
		glClearStencil(stencil);
		glClear(GL_STENCIL_BUFFER_BIT);
	}
	void OpenGLCommandBuffer::BindPipelineCore(Pipeline* pPipeline)
	{

	}
	void OpenGLCommandBuffer::BindFramebufferCore(Framebuffer* pFramebuffer)
	{

	}
	void OpenGLCommandBuffer::LockCore()
	{

	}
	void OpenGLCommandBuffer::UnlockCore()
	{

	}

}