#pragma once
#include <Core/Core.h>
#include <Graphics/Device/GraphicsDeviceObject.h>
#include <Graphics/Command/CommandBufferCreateDesc.h>

namespace Felix
{
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


	protected:
		FORCEINLINE virtual void LockCore() = 0;
		FORCEINLINE virtual void UnlockCore() = 0;

		FORCEINLINE virtual void ClearColorCore(const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a) = 0;
	private:
		bool _asyncSubmission;
		bool _locked;
	};
}
