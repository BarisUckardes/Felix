#include "OpenGLBuffer.h"
#include <GLAD/glad.h>
#include <Graphics/API/OpenGL/Buffer/OpenGLBufferUtils.h>
namespace Felix
{
	OpenGLBuffer::OpenGLBuffer(const GraphicsBufferCreateDesc& desc) : GraphicsBuffer(desc)
	{
		glCreateBuffers(1, &_handle);
		glNamedBufferData(_handle, desc.Size, desc.pInitialData, OpenGLBufferUtils::GetBufferUsage(desc.Usage));

	}
	OpenGLBuffer::~OpenGLBuffer()
	{
		if(_handle != 0)
			glDeleteBuffers(1, &_handle);

		_handle = 0;
	}
}