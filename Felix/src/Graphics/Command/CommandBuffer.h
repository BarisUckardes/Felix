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


		FORCEINLINE void Lock();
		FORCEINLINE void Unlock();

		FORCEINLINE void ClearColor(const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a);
		FORCEINLINE void ClearDepth(const unsigned char depth);
		FORCEINLINE void ClearStencil(const int stencil);

	protected:
		FORCEINLINE virtual void LockCore() = 0;
		FORCEINLINE virtual void UnlockCore() = 0;

		FORCEINLINE virtual void ClearColorCore(const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a) = 0;
		FORCEINLINE virtual void ClearDepthCore(const unsigned char depth) = 0;
		FORCEINLINE virtual void ClearStencilCore(const int stencil) = 0;

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
