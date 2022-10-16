#pragma once
#include <Graphics/Shader/ShaderType.h>

namespace Felix
{
	class EXPORT OpenGLShaderUtils
	{
	public:
		OpenGLShaderUtils() = delete;
		~OpenGLShaderUtils() = delete;

		FORCEINLINE static unsigned int GetShaderType(const ShaderType type);
	};
}