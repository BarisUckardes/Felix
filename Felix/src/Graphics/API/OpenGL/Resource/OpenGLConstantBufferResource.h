#pragma once
#include <Graphics/Resource/GraphicsResource.h>

namespace Felix
{
	/// <summary>
	/// OpenGL implementation of the constant buffer resource
	/// </summary>
	class EXPORT OpenGLConstantBufferResource : public GraphicsResource
	{
	public:
		OpenGLConstantBufferResource(const unsigned int handle, const GraphicsResourceCreateDesc& desc);
		virtual ~OpenGLConstantBufferResource();

		FORCEINLINE unsigned int GetGLHandle() const noexcept { return _handle; }
	private:
		const unsigned int _handle;
	};
}