#include "DX12CommandBuffer.h"
#include <Graphics/API/Directx12/Device/DX12Device.h>
#include <Graphics/API/Directx12/Device/DX12DeviceObjects.h>

namespace Felix
{
	DX12CommandBuffer::DX12CommandBuffer(const CommandBufferCreateDesc& desc, DX12Device* pDevice) : CommandBuffer(desc)
	{
		ASSERT(SUCCEEDED(pDevice->GetDXDevice()->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, pDevice->GetDXCmdAllocator(), nullptr, IID_PPV_ARGS(&_cmdList))), "DX12CommandBuffer", "Failed to create a command list");

		ASSERT(SUCCEEDED(_cmdList->Close()), "DX12CommandBuffer", "Failed to first close the command list");

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
		/*
		* Validate if a framebuffer still attached and barrier
		*/
		Framebuffer* pFramebuffer = GetBoundFramebuffer();
		if (pFramebuffer != nullptr)
		{
			if (pFramebuffer->IsSwapchain())
			{
				D3D12_RESOURCE_BARRIER barrier = {};
				barrier.Transition.pResource = ((const DX12SwapchainFramebuffer*)pFramebuffer)->GetDXCurrentRtv();
				barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_RENDER_TARGET;
				barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_PRESENT;
				barrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
				barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
				barrier.Flags = D3D12_RESOURCE_BARRIER_FLAG_NONE;
				_cmdList->ResourceBarrier(1, &barrier);
			}
		}

		ASSERT(SUCCEEDED(_cmdList->Close()), "DX12CommandBuffer", "Failed to close the command list");
	}
	void DX12CommandBuffer::BindPipelineCore(Pipeline* pPipeline)
	{

	}

	void DX12CommandBuffer::BindFramebufferCore(Framebuffer* pFramebuffer)
	{
		/*
		* Validate if a framebuffer still attached
		*/
		Framebuffer* pCurrentFramebuffer = GetBoundFramebuffer();
		if (pCurrentFramebuffer != nullptr)
		{
			if (pCurrentFramebuffer->IsSwapchain())
			{
				D3D12_RESOURCE_BARRIER barrier = {};
				barrier.Transition.pResource = ((const DX12SwapchainFramebuffer*)pCurrentFramebuffer)->GetDXCurrentRtv();
				barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_RENDER_TARGET;
				barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_PRESENT;
				barrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
				barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
				barrier.Flags = D3D12_RESOURCE_BARRIER_FLAG_NONE;
				_cmdList->ResourceBarrier(1, &barrier);
			}
		}

		/*
		* Validate if swapchain
		*/
		if (pFramebuffer->IsSwapchain())
		{
			const DX12SwapchainFramebuffer* pDXFramebuffer = (const DX12SwapchainFramebuffer*)pFramebuffer;

			/*
			* Create render target barrier
			*/
			D3D12_RESOURCE_BARRIER barrier = {};

			barrier.Transition.pResource = pDXFramebuffer->GetDXCurrentRtv();
			barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_PRESENT;
			barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_RENDER_TARGET;
			barrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
			barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
			barrier.Flags = D3D12_RESOURCE_BARRIER_FLAG_NONE;

			_cmdList->ResourceBarrier(1, &barrier);

			/*
			* Set render target
			*/
			D3D12_CPU_DESCRIPTOR_HANDLE rtvHandle = pDXFramebuffer->GetDXCurrentRtvDescriptor();
			_cmdList->OMSetRenderTargets(1, &rtvHandle, false, nullptr);
		}
		else
		{

		}
	}
	void DX12CommandBuffer::SetViewportCore(const ViewportDesc& desc)
	{

	}
	void DX12CommandBuffer::SetScissorsCore(const ScissorsDesc& desc)
	{

	}
	void DX12CommandBuffer::ClearColorCore(const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a)
	{
		const float clearColor[] = { r,g,b,a };

		Framebuffer* pFramebuffer = GetBoundFramebuffer();

		D3D12_CPU_DESCRIPTOR_HANDLE rtvHandle = {};
		if (pFramebuffer->IsSwapchain())
		{
			const DX12SwapchainFramebuffer* pDXFramebuffer = (const DX12SwapchainFramebuffer*)pFramebuffer;
			rtvHandle = pDXFramebuffer->GetDXCurrentRtvDescriptor();
		}
		else
		{

		}

		_cmdList->ClearRenderTargetView(rtvHandle, clearColor, 0, nullptr);
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