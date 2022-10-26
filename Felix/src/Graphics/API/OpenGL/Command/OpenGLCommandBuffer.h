#pragma once
#include <Graphics/Command/CommandBuffer.h>

namespace Felix
{
	/// <summary>
	/// OpenGL implementation of the CommandBuffer
	/// </summary>
	class EXPORT OpenGLCommandBuffer : public CommandBuffer
	{
	public:
		OpenGLCommandBuffer(const CommandBufferCreateDesc& desc);
		virtual ~OpenGLCommandBuffer() {}
	protected:
		virtual void LockCore() override final;
		virtual void UnlockCore() override final;

		virtual void BindPipelineCore(Pipeline* pPipeline) override;
		virtual void BindFramebufferCore(Framebuffer* pFramebuffer) override;

		virtual void SetViewportCore(const ViewportDesc& desc) override;
		virtual void SetScissorsCore(const ScissorsDesc& desc) override;

		virtual void SetVertexBufferCore(GraphicsBuffer* pBuffer) override;
		virtual void SetIndexBufferCore(GraphicsBuffer* pBuffer) override;

		virtual void ClearColorCore(const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a) override final;
		virtual void ClearDepthCore(const unsigned char depth) override final;
		virtual void ClearStencilCore(const int stencil) override;

		virtual void CommitResourceCore(const unsigned int slotIndex, GraphicsResource* pResource) override;

		virtual void DrawIndexedCore(const unsigned int indexCount) override;

		virtual void ClearCachedStateCore() override;
	private:
		unsigned int _currentVertexArray;
		unsigned int _currentPrimitives;

		


	};
}