#include "OpenGLShaderUtils.h"
#include <GLAD/glad.h>

namespace Felix
{
	unsigned int OpenGLShaderUtils::GetShaderType(const ShaderType type)
	{
		switch (type)
		{
			case Felix::ShaderType::Vertex:
				return GL_VERTEX_SHADER;
			case Felix::ShaderType::Fragment:
				return GL_FRAGMENT_SHADER;
			case Felix::ShaderType::Geometry:
				return GL_GEOMETRY_SHADER;
			case Felix::ShaderType::TesellationEval:
				return GL_TESS_EVALUATION_SHADER;
			case Felix::ShaderType::TesellationControl:
				return GL_TESS_CONTROL_SHADER;
			case Felix::ShaderType::Compute:
				return GL_COMPUTE_SHADER;
			default:
				ASSERT(false, "OpenGLShaderUtils", "Invalid ShaderType!");
				break;
		}
	}
}