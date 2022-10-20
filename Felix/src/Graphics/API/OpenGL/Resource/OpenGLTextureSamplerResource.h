#pragma once
#include <Graphics/Resource/GraphicsResource.h>

namespace Felix
{
	/// <summary>
	/// Represents OpenGL implementation of a commitable texture sampler resource
	/// </summary>
	class EXPORT OpenGLTextureSamplerResource : public GraphicsResource
	{
	public:
		OpenGLTextureSamplerResource(const unsigned int handle,const GraphicsResourceCreateDesc& desc) : GraphicsResource(desc),_handle(handle) {}
		virtual ~OpenGLTextureSamplerResource() {}

		FORCEINLINE unsigned int GetGLHandle() const noexcept { return _handle; }
	private:
		const unsigned int _handle;
	};
}