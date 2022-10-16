#pragma once
#include <Graphics/Shader/Shader.h>

namespace Felix
{
	class EXPORT OpenGLShader : public Shader
	{
	public:
		OpenGLShader(const ShaderCreateDesc& desc);
		virtual ~OpenGLShader();

		FORCEINLINE unsigned int GetGLHandle() const noexcept { return _handle; }
	private:
		unsigned int _handle;
	};
}