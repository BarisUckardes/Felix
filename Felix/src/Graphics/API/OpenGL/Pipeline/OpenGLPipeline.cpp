#include "OpenGLPipeline.h"
#include <Graphics/API/OpenGL/Device/OpenGLDeviceObjects.h>
#include <Graphics/API/OpenGL/Pipeline/OpenGLPipelineUtils.h>
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

		/*
		* Create pipeline state variables for OpenGL
		*/
		_primitives = OpenGLPipelineUtils::GetPrimitiveTopology(desc.RasterizerDesc.Topology);
		_frontFace = OpenGLPipelineUtils::GetFrontFace(desc.RasterizerDesc.FrontFace);
		_cullFace = OpenGLPipelineUtils::GetCullFace(desc.RasterizerDesc.CulledFace);
		_depthFunction = OpenGLPipelineUtils::GetDepthFunction(desc.DepthStencilDesc.TestFunction);
		_shadingMode = OpenGLPipelineUtils::GetShadingMode(desc.RasterizerDesc.ShadingMode);

		StencilGLFaceDesc stencilFrontFace = {};
		stencilFrontFace.StencilReferenceValue = desc.DepthStencilDesc.StencilFrontFace.StencilReferenceValue;
		stencilFrontFace.StencilWriteMask = desc.DepthStencilDesc.StencilFrontFace.StencilWriteMask;
		stencilFrontFace.StencilReadMask = desc.DepthStencilDesc.StencilFrontFace.StencilReadMask;
		stencilFrontFace.PassOperation = OpenGLPipelineUtils::GetStencilOperation(desc.DepthStencilDesc.StencilFrontFace.PassOperation);
		stencilFrontFace.FailOperation = OpenGLPipelineUtils::GetStencilOperation(desc.DepthStencilDesc.StencilFrontFace.FailOperation);
		stencilFrontFace.DepthFailOperation = OpenGLPipelineUtils::GetStencilOperation(desc.DepthStencilDesc.StencilFrontFace.DepthFailOperation);
		stencilFrontFace.Function = OpenGLPipelineUtils::GetStencilFunction(desc.DepthStencilDesc.StencilFrontFace.Function);

		StencilGLFaceDesc stencilBackFace = {};
		stencilBackFace.StencilReferenceValue = desc.DepthStencilDesc.StencilBackFace.StencilReferenceValue;
		stencilBackFace.StencilWriteMask = desc.DepthStencilDesc.StencilBackFace.StencilWriteMask;
		stencilBackFace.StencilReadMask = desc.DepthStencilDesc.StencilFrontFace.StencilReadMask;
		stencilBackFace.PassOperation = OpenGLPipelineUtils::GetStencilOperation(desc.DepthStencilDesc.StencilBackFace.PassOperation);
		stencilBackFace.FailOperation = OpenGLPipelineUtils::GetStencilOperation(desc.DepthStencilDesc.StencilBackFace.FailOperation);
		stencilBackFace.DepthFailOperation = OpenGLPipelineUtils::GetStencilOperation(desc.DepthStencilDesc.StencilBackFace.DepthFailOperation);
		stencilBackFace.Function = OpenGLPipelineUtils::GetStencilFunction(desc.DepthStencilDesc.StencilBackFace.Function);

		_stencilFrontFace = stencilFrontFace;
		_stencilBackFace = stencilBackFace;

		_colorBlendingFunction = OpenGLPipelineUtils::GetBlendingFunction(desc.BlendingDesc.ColorFunction);
		_alphaBlendingFunction = OpenGLPipelineUtils::GetBlendingFunction(desc.BlendingDesc.AlphaFunction);
		_sourceColorFactor = OpenGLPipelineUtils::GetBlendingColorFactor(desc.BlendingDesc.SourceColorFactor);
		_destinationColorFactor = OpenGLPipelineUtils::GetBlendingColorFactor(desc.BlendingDesc.DestinationColorFactor);
		_sourceAlphaFactor = OpenGLPipelineUtils::GetBlendingAlphaFactor(desc.BlendingDesc.SourceColorFactor);
		_destinationAlphaFactor = OpenGLPipelineUtils::GetBlendingAlphaFactor(desc.BlendingDesc.DestinationAlphaFactor);
	}
	OpenGLPipeline::~OpenGLPipeline()
	{
		if (_programHandle != 0)
			glDeleteProgram(_programHandle);
	}
}