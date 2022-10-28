#pragma once
#include <Graphics/Command/CommandBuffer.h>
#include <Graphics/API/Directx12/Core/DX12Core.h>

namespace Felix
{
	class EXPORT DX12CommandBuffer : public CommandBuffer
	{
	public:
		DX12CommandBuffer(const CommandBufferCreateDesc& desc, DX12Device* pDevice);
		virtual ~DX12CommandBuffer() override;

		FORCEINLINE ID3D12CommandList* GetDXCmdList() const noexcept { return _cmdList.Get(); }
	protected:
		virtual void LockCore() override;
		virtual void UnlockCore() override;
		virtual void BindPipelineCore(Pipeline* pPipeline) override;
		virtual void BindFramebufferCore(Framebuffer* pFramebuffer) override;
		virtual void SetViewportCore(const ViewportDesc& desc) override;
		virtual void SetScissorsCore(const ScissorsDesc& desc) override;
		virtual void ClearColorCore(const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a) override;
		virtual void ClearDepthCore(const unsigned char depth) override;
		virtual void ClearStencilCore(const int stencil) override;
		virtual void SetVertexBufferCore(GraphicsBuffer* pBuffer) override;
		virtual void SetIndexBufferCore(GraphicsBuffer* pBuffer) override;
		virtual void CommitResourceCore(const unsigned int slotIndex, GraphicsResource* pResource) override;
		virtual void DrawIndexedCore(const unsigned int indexCount) override;
		virtual void ClearCachedStateCore() override;
	private:
		DXPTR<ID3D12GraphicsCommandList> _cmdList;
		ID3D12CommandAllocator* _ownerAllocator;

	};
}