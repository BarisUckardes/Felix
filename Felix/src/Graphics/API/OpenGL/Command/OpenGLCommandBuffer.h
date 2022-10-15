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

		FORCEINLINE GraphicsDeviceObjectType GetDeviceObjectType() const noexcept { return GraphicsDeviceObjectType::CommandBuffer; }

	protected:
		virtual void LockCore() override final;
		virtual void UnlockCore() override final;

		virtual void ClearColorCore(const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a) override final;
		virtual void ClearDepthCore(const unsigned char depth) override final;
		virtual void ClearStencilCore(const int stencil) override;

	};
}