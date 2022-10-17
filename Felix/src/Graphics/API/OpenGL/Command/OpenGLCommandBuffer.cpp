#include "OpenGLCommandBuffer.h"
#include <Graphics/API/OpenGL/Device/OpenGLDeviceObjects.h>
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
	void OpenGLCommandBuffer::SetViewportCore(const ViewportDesc& desc)
	{
		glViewport(desc.PositionX, desc.PositionY, desc.Width, desc.Height);
		glDepthRange(desc.MinDepth, desc.MaxDepth);
	}
	void OpenGLCommandBuffer::SetScissorsCore(const ScissorsDesc& desc)
	{
		glScissor(desc.PositionX, desc.PositionY, desc.Width, desc.Height);
	}
	void OpenGLCommandBuffer::SetVertexBufferCore(GraphicsBuffer* pBuffer)
	{
		const OpenGLBuffer* pGLBuffer = (const OpenGLBuffer*)pBuffer;

		glBindBuffer(GL_ARRAY_BUFFER, pGLBuffer->GetGLHandle());
	}
	void OpenGLCommandBuffer::SetIndexBufferCore(GraphicsBuffer* pBuffer)
	{
		const OpenGLBuffer* pGLBuffer = (const OpenGLBuffer*)pBuffer;

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, pGLBuffer->GetGLHandle());
	}
	void OpenGLCommandBuffer::DrawIndexedCore(const unsigned int indexCount)
	{

	}
	void OpenGLCommandBuffer::BindPipelineCore(Pipeline* pPipeline)
	{

	}
	void OpenGLCommandBuffer::BindFramebufferCore(Framebuffer* pFramebuffer)
	{
		unsigned int handle = 0;
		if (!pFramebuffer->IsSwapchain())
		{
			const OpenGLFramebuffer* pGLFramebuffer = (const OpenGLFramebuffer*)pFramebuffer;
			handle = pGLFramebuffer->GetGLHandle();
		}

		glBindFramebuffer(GL_FRAMEBUFFER, handle);

	}
	void OpenGLCommandBuffer::LockCore()
	{

	}
	void OpenGLCommandBuffer::UnlockCore()
	{

	}

}