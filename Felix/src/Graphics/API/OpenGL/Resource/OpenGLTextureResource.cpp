#include "OpenGLTextureResource.h"

namespace Felix
{
	OpenGLTextureResource::OpenGLTextureResource(const unsigned int handle, const GraphicsResourceCreateDesc& desc) : GraphicsResource(desc),_handle(handle)
	{

	}
	OpenGLTextureResource::~OpenGLTextureResource()
	{
	}
}