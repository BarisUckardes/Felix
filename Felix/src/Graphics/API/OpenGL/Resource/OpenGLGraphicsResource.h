#pragma once
#include <Graphics/Resource/GraphicsResource.h>

namespace Felix
{
	class EXPORT OpenGLGraphicsResource : public GraphicsResource
	{
	public:
		OpenGLGraphicsResource(const GraphicsResourceCreateDesc& desc) : GraphicsResource(desc) {}
		virtual ~OpenGLGraphicsResource() override {}
	};
}