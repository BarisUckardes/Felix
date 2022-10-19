#include "OpenGLShader.h"
#include <Graphics/API/OpenGL/Shader/OpenGLShaderUtils.h>
#include <GLAD/glad.h>

namespace Felix
{
#define FELIX_OPENGL_MAX_ERROR_LENGTH 4096
	OpenGLShader::OpenGLShader(const ShaderCreateDesc& desc) : Shader(desc)
	{
		/*
		* Create shader
		*/
		_handle = glCreateShader(OpenGLShaderUtils::GetShaderType(desc.Type));

		/*
		* Set shader data
		*/
		const char* pData = desc.Source.data();
		glShaderSource(_handle, 1, &pData, NULL);

		/*
		* Compile shader
		*/
		glCompileShader(_handle);

		/*
		* Validate shader compilation
		*/
		GLint state = 0;
		glGetShaderiv(_handle, GL_COMPILE_STATUS, &state);
		if (state == GL_FALSE)
		{
			GLint maxLength = FELIX_OPENGL_MAX_ERROR_LENGTH;
			glGetShaderiv(_handle, GL_INFO_LOG_LENGTH, &maxLength);

			char* errorLog = new char[FELIX_OPENGL_MAX_ERROR_LENGTH];
			glGetShaderInfoLog(_handle, maxLength, &maxLength, errorLog);

			LOG("OpenGLShader", "Shader compile failed with logs: %s", errorLog);
			delete[] errorLog;
		}
	}
	OpenGLShader::~OpenGLShader()
	{
		if (_handle != 0)
			glDeleteShader(_handle);
	}

}