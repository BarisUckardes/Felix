#include "CommandBuffer.h"

namespace Felix
{
	CommandBuffer::CommandBuffer(const CommandBufferCreateDesc& desc)
	{

	}
	void CommandBuffer::Lock()
	{
		LockCore();

		_locked = true;
	}
	void CommandBuffer::Unlock()
	{
		UnlockCore();

		_locked = false;
	}
	void CommandBuffer::ClearColor(const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a)
	{
		if (!_locked)
			return;

		ClearColorCore(r, g, b, a);
	}
}