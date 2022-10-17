#include "CommandBuffer.h"

namespace Felix
{
	CommandBuffer::CommandBuffer(const CommandBufferCreateDesc& desc)
	{
		ClearCachedState();
	}
	void CommandBuffer::Lock()
	{
		LockCore();

		_locked = true;
	}
	void CommandBuffer::Unlock()
	{
		ClearCachedState();
		UnlockCore();

		_locked = false;
	}
	void CommandBuffer::BindPipeline(Pipeline* pPipeline)
	{
		CheckLock();

		_boundPipeline = pPipeline;

		BindPipelineCore(pPipeline);
	}
	void CommandBuffer::BindFramebuffer(Framebuffer* pFramebuffer)
	{
		CheckLock();
		CheckBoundPipeline();

		_boundFramebuffer = pFramebuffer;

		BindFramebufferCore(pFramebuffer);
	}
	void CommandBuffer::ClearColor(const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a)
	{
		CheckLock();
		CheckBoundFramebuffer();

		ClearColorCore(r, g, b, a);
	}
	void CommandBuffer::ClearDepth(const unsigned char depth)
	{
		CheckLock();
		CheckBoundFramebuffer();

		ClearDepthCore(depth);
	}
	void CommandBuffer::ClearStencil(const int stencil)
	{
		CheckLock();
		CheckBoundFramebuffer();

		ClearStencilCore(stencil);
	}

	void CommandBuffer::ClearCachedState()
	{
		_boundFramebuffer = nullptr;
		_boundPipeline = nullptr;
		_boundScissors = {};
		_boundViewport = {};
		_boundTextureCount = 0;
		_boundConstantBufferCount = 0;
	}

	void CommandBuffer::CheckLock()
	{
		ASSERT(_locked, "CommandBuffer", "You cannot submit commands before locking the command buffer");
	}
	void CommandBuffer::CheckBoundPipeline()
	{
		ASSERT(_boundPipeline != nullptr, "CommandBuffer", "You must bind a pipeline before submitting pipeline related commands");
	}
	void CommandBuffer::CheckBoundFramebuffer()
	{
		ASSERT(_boundFramebuffer != nullptr, "CommandBuffer", "You must bind a framebuffer before submitting pipeline related commands");
	}
}