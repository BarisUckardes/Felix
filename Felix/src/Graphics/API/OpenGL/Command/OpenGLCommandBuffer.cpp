#include "OpenGLCommandBuffer.h"
#include <Graphics/API/OpenGL/Device/OpenGLDeviceObjects.h>
#include <Graphics/API/OpenGL/Pipeline/OpenGLPipelineUtils.h>
#include <Graphics/Pipeline/InputElementUtils.h>
#include <GLAD/glad.h>

namespace Felix
{
	OpenGLCommandBuffer::OpenGLCommandBuffer(const CommandBufferCreateDesc& desc) : CommandBuffer(desc)
	{
		_currentPrimitives = GL_NONE;
	}
	void OpenGLCommandBuffer::ClearColorCore(const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a)
	{
		glClearColor(r, g, b, a);
		glClear(GL_COLOR_BUFFER_BIT);
	}
	void OpenGLCommandBuffer::ClearDepthCore(const unsigned char depth)
	{
		glClearDepth(depth);
		glClear(GL_DEPTH_BUFFER_BIT);
	}
	void OpenGLCommandBuffer::ClearStencilCore(const int stencil)
	{
		glClearStencil(stencil);
		glClear(GL_STENCIL_BUFFER_BIT);
	}
	void OpenGLCommandBuffer::SetViewportCore(const ViewportDesc& desc)
	{
		glViewport(desc.PositionX, desc.PositionY, desc.Width, desc.Height);
		glDepthRange(desc.MinDepth, desc.MaxDepth);
	}
	void OpenGLCommandBuffer::SetScissorsCore(const ScissorsDesc& desc)
	{
		glScissor(desc.PositionX, desc.PositionY, desc.Width, desc.Height);
	}
	void OpenGLCommandBuffer::SetVertexBufferCore(GraphicsBuffer* pBuffer)
	{
		const OpenGLBuffer* pGLBuffer = (const OpenGLBuffer*)pBuffer;

		/*
		* Revalidate vertex buffer
		*/
		const unsigned int vertexBufferHandle = pGLBuffer->GetGLHandle();
		if (_currentVertexArray != 0)
			glDeleteVertexArrays(1, &_currentVertexArray);

		/*
		* Create new vertex array object
		*/
		glGenVertexArrays(1, &_currentVertexArray);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBufferHandle);
		const InputLayoutDesc inputLayout = GetBoundPipeline()->GetInputLayoutDesc();
		const std::vector<InputElementDesc> inputElements = inputLayout.GetElements();

		glBindVertexArray(_currentVertexArray);
		unsigned int offset = 0;
		for (unsigned int i = 0; i < inputElements.size(); i++)
		{
			const InputElementDesc& elementDesc = inputElements[i];

			glEnableVertexAttribArray(i);

			glVertexAttribPointer(i,
				OpenGLPipelineUtils::GetInputElementComponentCount(elementDesc.DataType),
				OpenGLPipelineUtils::GetInputElementDataType(elementDesc.DataType),
				elementDesc.bNormalize,
				inputLayout.GetStride(),
				(const void*)(offset)
			);

			offset += InputElementUtils::GetElementSize(elementDesc.DataType);
		}
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		glBindVertexArray(_currentVertexArray);
	}
	void OpenGLCommandBuffer::SetIndexBufferCore(GraphicsBuffer* pBuffer)
	{
		const OpenGLBuffer* pGLBuffer = (const OpenGLBuffer*)pBuffer;

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, pGLBuffer->GetGLHandle());
	}
	void OpenGLCommandBuffer::DrawIndexedCore(const unsigned int indexCount)
	{
		glDrawElements(_currentPrimitives, indexCount, GL_UNSIGNED_INT, nullptr);
	}
	void OpenGLCommandBuffer::ClearCachedStateCore()
	{
		_currentPrimitives = 0;
	}
	void OpenGLCommandBuffer::BindPipelineCore(Pipeline* pPipeline)
	{
		const OpenGLPipeline* pGLPipeline = (const OpenGLPipeline*)pPipeline;

		/*
		* Set program
		*/
		glUseProgram(pGLPipeline->GetGLProgramHandle());

		/*
		* Set rasterizer state
		*/
		const RasterizerStateDesc& rasterizerState = pPipeline->GetRasterizerDesc();

		if(rasterizerState.bEnableScissorTest)
			glEnable(GL_SCISSOR_TEST);
		else
			glDisable(GL_SCISSOR_TEST);

		if (rasterizerState.bEnableDepthClip)
			glEnable(GL_DEPTH_CLAMP);
		else
			glDisable(GL_DEPTH_CLAMP);

		glFrontFace(pGLPipeline->GetGLFrontFace());

		if (rasterizerState.CulledFace == CullMode::None)
			glDisable(GL_CULL_FACE);
		else
			glEnable(GL_CULL_FACE);

		glCullFace(pGLPipeline->GetGLCullFace());

		glPolygonMode(GL_FRONT_AND_BACK, pGLPipeline->GetGLShadingMode());

		/*
		* Set depth&stencil state
		*/
		const DepthStencilStateDesc& depthStencilState = pPipeline->GetDepthStencilDesc();

		if (depthStencilState.bEnableDepthTest)
			glEnable(GL_DEPTH_TEST);
		else
			glDisable(GL_DEPTH_TEST);

		glDepthFunc(pGLPipeline->GetGLDepthFunction());

		glDepthMask(depthStencilState.bEnableDeptWrite);

		if (depthStencilState.bEnableStencilTest)
			glEnable(GL_STENCIL_TEST);
		else
			glDisable(GL_STENCIL_TEST);

		_currentPrimitives = pGLPipeline->GetGLPrimitives();

	}
	void OpenGLCommandBuffer::BindFramebufferCore(Framebuffer* pFramebuffer)
	{
		unsigned int handle = 0;
		if (!pFramebuffer->IsSwapchain())
		{
			const OpenGLFramebuffer* pGLFramebuffer = (const OpenGLFramebuffer*)pFramebuffer;
			handle = pGLFramebuffer->GetGLHandle();
		}

		glBindFramebuffer(GL_FRAMEBUFFER, handle);

	}
	void OpenGLCommandBuffer::LockCore()
	{

	}
	void OpenGLCommandBuffer::UnlockCore()
	{

	}

}