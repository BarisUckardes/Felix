#pragma once
#include <Graphics/Resource/GraphicsResource.h>

namespace Felix
{
	class EXPORT OpenGLTextureResource : public GraphicsResource
	{
	public:
		OpenGLTextureResource(const unsigned int handle, const GraphicsResourceCreateDesc& desc);
		virtual ~OpenGLTextureResource();

		FORCEINLINE unsigned int GetGLHandle() const noexcept { return _handle; }
	private:
		const unsigned int _handle;
	};
}