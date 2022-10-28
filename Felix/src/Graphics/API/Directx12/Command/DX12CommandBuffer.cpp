#include "DX12CommandBuffer.h"
#include <Graphics/API/Directx12/Device/DX12Device.h>

namespace Felix
{
	DX12CommandBuffer::DX12CommandBuffer(const CommandBufferCreateDesc& desc, DX12Device* pDevice) : CommandBuffer(desc)
	{
		ASSERT(SUCCEEDED(pDevice->GetDXDevice()->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, pDevice->GetDXCmdAllocator(), nullptr, IID_PPV_ARGS(&_cmdList))), "DX12CommandBuffer", "Failed to create a command list");

		ASSERT(SUCCEEDED(_cmdList->Close()), "DX12CommandBuffer", "Failed to close the command list");

		_ownerAllocator = pDevice->GetDXCmdAllocator();
	}
	DX12CommandBuffer::~DX12CommandBuffer()
	{

	}
	void DX12CommandBuffer::LockCore()
	{
		ASSERT(SUCCEEDED(_cmdList->Reset(_ownerAllocator, nullptr)), "DX12CommandBuffer", "Failed to reset the command list");
	}
	void DX12CommandBuffer::UnlockCore()
	{
		ASSERT(SUCCEEDED(_cmdList->Close()), "DX12CommandBuffer", "Failed to close the command list");
	}
	void DX12CommandBuffer::BindPipelineCore(Pipeline* pPipeline)
	{
	}

	void DX12CommandBuffer::BindFramebufferCore(Framebuffer* pFramebuffer)
	{

	}
	void DX12CommandBuffer::SetViewportCore(const ViewportDesc& desc)
	{

	}
	void DX12CommandBuffer::SetScissorsCore(const ScissorsDesc& desc)
	{

	}
	void DX12CommandBuffer::ClearColorCore(const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a)
	{

	}
	void DX12CommandBuffer::ClearDepthCore(const unsigned char depth)
	{

	}
	void DX12CommandBuffer::ClearStencilCore(const int stencil)
	{

	}
	void DX12CommandBuffer::SetVertexBufferCore(GraphicsBuffer* pBuffer)
	{

	}
	void DX12CommandBuffer::SetIndexBufferCore(GraphicsBuffer* pBuffer)
	{

	}
	void DX12CommandBuffer::CommitResourceCore(const unsigned int slotIndex, GraphicsResource* pResource)
	{

	}
	void DX12CommandBuffer::DrawIndexedCore(const unsigned int indexCount)
	{

	}
	void DX12CommandBuffer::ClearCachedStateCore()
	{

	}
}