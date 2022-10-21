#include "OpenGLConstantBufferResource.h"
#include <GLAD/glad.h>

namespace Felix
{
	OpenGLConstantBufferResource::OpenGLConstantBufferResource(const unsigned int handle, const GraphicsResourceCreateDesc& desc) : GraphicsResource(desc),_handle(handle) 
	{
	}
	OpenGLConstantBufferResource::~OpenGLConstantBufferResource()
	{
	}
}