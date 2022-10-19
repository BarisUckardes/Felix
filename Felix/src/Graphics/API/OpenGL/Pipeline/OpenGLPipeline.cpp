#include "OpenGLPipeline.h"
#include <Graphics/API/OpenGL/Device/OpenGLDeviceObjects.h>

#include <GLAD/glad.h>

namespace Felix
{
#define FELIX_OPENGL_MAX_ERROR_LENGTH 4096

	OpenGLPipeline::OpenGLPipeline(const PipelineCreateDesc& desc) : Pipeline(desc)
	{
		/*
		* Create program
		*/
		_programHandle = glCreateProgram();
		for (unsigned char i = 0; i < desc.ShadingPass.Shaders.size(); i++)
		{
			const OpenGLShader* pShader = (const OpenGLShader*)desc.ShadingPass.Shaders[i];
			const unsigned int shaderHandle = pShader->GetGLHandle();

			glAttachShader(_programHandle, shaderHandle);
		}

		glLinkProgram(_programHandle);

		{
			GLint state = 0;
			glGetProgramiv(_programHandle, GL_LINK_STATUS, (int*)&state);
			if (state == GL_FALSE)
			{
				int maxLength = FELIX_OPENGL_MAX_ERROR_LENGTH;
				glGetProgramiv(_programHandle, GL_INFO_LOG_LENGTH, &maxLength);

				char* pErrorLog = new char[maxLength];
				glGetProgramInfoLog(_programHandle, maxLength, &maxLength, pErrorLog);

				LOG("OpenGLPipeline", "Program cannot be linked with these logs: %s", pErrorLog);
				delete[] pErrorLog;
			}
		}
	}
	OpenGLPipeline::~OpenGLPipeline()
	{
		if (_programHandle != 0)
			glDeleteProgram(_programHandle);
	}
}