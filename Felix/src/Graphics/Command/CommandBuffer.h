#pragma once
#include <Core/Core.h>
#include <Graphics/Device/GraphicsDeviceObject.h>
#include <Graphics/Command/CommandBufferCreateDesc.h>
#include <Graphics/Pipeline/ViewportDesc.h>
#include <Graphics/Pipeline/ScissorsDesc.h>

namespace Felix
{
	class Pipeline;
	class Framebuffer;
	class GraphicsBuffer;
	class GraphicsResource;

	/// <summary>
	/// A graphics device object which records the rendering commands and playbacks the list
	/// </summary>
	class EXPORT CommandBuffer : public GraphicsDeviceObject
	{
	public:
		CommandBuffer(const CommandBufferCreateDesc& desc);
		virtual ~CommandBuffer() {}

		FORCEINLINE bool IsAsyncSubmissionSupported() const noexcept { return _asyncSubmission; }
		FORCEINLINE bool IsLocked() const noexcept { return _locked; }
		FORCEINLINE Pipeline* GetBoundPipeline() const noexcept { return _boundPipeline; }
		FORCEINLINE Framebuffer* GetBoundFramebuffer() const noexcept { return _boundFramebuffer; }
		FORCEINLINE ViewportDesc GetBoundViewport() const noexcept { return _boundViewport; }
		FORCEINLINE ScissorsDesc GetScissors() const noexcept { return _boundScissors; }
		FORCEINLINE unsigned int GetBoundTextureCount() const noexcept { return _boundTextureCount; }
		FORCEINLINE unsigned int GetBoundContantBufferCount() const noexcept { return _boundConstantBufferCount; }

		FORCEINLINE void Lock();
		FORCEINLINE void Unlock();

		FORCEINLINE void BindPipeline(Pipeline* pPipeline);
		FORCEINLINE void BindFramebuffer(Framebuffer* pFramebuffer);

		FORCEINLINE void SetViewport(const ViewportDesc& desc);
		FORCEINLINE void SetScissors(const ScissorsDesc& desc);

		FORCEINLINE void ClearColor(const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a);
		FORCEINLINE void ClearDepth(const unsigned char depth);
		FORCEINLINE void ClearStencil(const int stencil);

		FORCEINLINE void SetVertexBuffer(GraphicsBuffer* pBuffer);
		FORCEINLINE void SetIndexBuffer(GraphicsBuffer* pBuffer);

		FORCEINLINE void CommitResource(const unsigned int slotIndex, GraphicsResource* pResource);

		FORCEINLINE void DrawIndexed(const unsigned int indexCount);

	protected:
		FORCEINLINE virtual void LockCore() = 0;
		FORCEINLINE virtual void UnlockCore() = 0;

		FORCEINLINE virtual void BindPipelineCore(Pipeline* pPipeline) = 0;
		FORCEINLINE virtual void BindFramebufferCore(Framebuffer* pFramebuffer) = 0;

		FORCEINLINE virtual void SetViewportCore(const ViewportDesc& desc) = 0;
		FORCEINLINE virtual void SetScissorsCore(const ScissorsDesc& desc) = 0;

		FORCEINLINE virtual void ClearColorCore(const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a) = 0;
		FORCEINLINE virtual void ClearDepthCore(const unsigned char depth) = 0;
		FORCEINLINE virtual void ClearStencilCore(const int stencil) = 0;

		FORCEINLINE virtual void SetVertexBufferCore(GraphicsBuffer* pBuffer) = 0;
		FORCEINLINE virtual void SetIndexBufferCore(GraphicsBuffer* pBuffer) = 0;

		FORCEINLINE virtual void CommitResourceCore(const unsigned int slotIndex, GraphicsResource* pResource) = 0;

		FORCEINLINE virtual void DrawIndexedCore(const unsigned int indexCount) = 0;

		FORCEINLINE virtual void ClearCachedStateCore() = 0;
	private:
		FORCEINLINE void CheckBoundPipeline();
		FORCEINLINE void CheckBoundFramebuffer();
		FORCEINLINE void CheckLock();

		void ClearCachedState();
	private:
		Pipeline* _boundPipeline;
		Framebuffer* _boundFramebuffer;
		ViewportDesc _boundViewport;
		ScissorsDesc _boundScissors;
		unsigned int _boundTextureCount;
		unsigned int _boundConstantBufferCount;
		bool _asyncSubmission;
		bool _locked;
	};
}
