#include "CommandBuffer.h"
#include <Graphics/Buffer/GraphicsBuffer.h>
#include <Graphics/Resource/GraphicsResource.h>
#include <Graphics/Pipeline/Pipeline.h>

namespace Felix
{
	CommandBuffer::CommandBuffer(const CommandBufferCreateDesc& desc)
	{
		_boundFramebuffer = nullptr;
		_boundPipeline = nullptr;
		_boundScissors = {};
		_boundViewport = {};
		_boundTextureCount = 0;
		_boundConstantBufferCount = 0;
	}
	void CommandBuffer::Lock()
	{
		LockCore();

		_locked = true;
	}
	void CommandBuffer::Unlock()
	{
		UnlockCore();
		ClearCachedState();
		
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
		//CheckBoundPipeline();

		BindFramebufferCore(pFramebuffer);

		_boundFramebuffer = pFramebuffer;
	}
	void CommandBuffer::SetViewport(const ViewportDesc& desc)
	{
		CheckLock();
		CheckBoundPipeline();
		CheckBoundFramebuffer();

		SetViewportCore(desc);

		_boundViewport = desc;
	}
	void CommandBuffer::SetScissors(const ScissorsDesc& desc)
	{
		CheckLock();
		CheckBoundPipeline();
		CheckBoundFramebuffer();

		SetScissorsCore(desc);

		_boundScissors = desc;
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

	void CommandBuffer::SetVertexBuffer(GraphicsBuffer* pBuffer)
	{
		ASSERT(pBuffer->GetBufferType() == GraphicsBufferType::VertexBuffer, "CommandBuffer", "The specified buffer is not VertexBuffer");

		SetVertexBufferCore(pBuffer);
	}
	void CommandBuffer::SetIndexBuffer(GraphicsBuffer* pBuffer)
	{
		ASSERT(pBuffer->GetBufferType() == GraphicsBufferType::IndexBuffer, "CommandBuffer", "The specified buffer is not IndexBuffer");

		SetIndexBufferCore(pBuffer);
	}
	void CommandBuffer::CommitResource(const unsigned int slotIndex, GraphicsResource* pResource)
	{
		CheckBoundPipeline();

		/*
		* Validate resource
		*/
		const ResourceStateDesc& resourceStateDesc = GetBoundPipeline()->GetResourceStateDesc();

		ASSERT(resourceStateDesc.SlotDescriptions[slotIndex].Type == pResource->GetResourceType(), "CommandBuffer", "Commited resource has no match in the given pipeline resource slots");

		CommitResourceCore(slotIndex, pResource);

		/*
		* Validate resources
		*/
		if (pResource->GetResourceType() == GraphicsResourceType::ConstantBuffer)
		{
			_boundConstantBufferCount++;
		}
	}
	void CommandBuffer::DrawIndexed(const unsigned int indexCount)
	{
		CheckLock();
		CheckBoundPipeline();
		CheckBoundFramebuffer();

		DrawIndexedCore(indexCount);
	}
	void CommandBuffer::ClearCachedState()
	{
		_boundFramebuffer = nullptr;
		_boundPipeline = nullptr;
		_boundScissors = {};
		_boundViewport = {};
		_boundTextureCount = 0;
		_boundConstantBufferCount = 0;

		ClearCachedStateCore();
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