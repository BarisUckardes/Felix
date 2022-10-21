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
	void OpenGLCommandBuffer::CommitResourceCore(const unsigned int slotIndex, GraphicsResource* pResource)
	{
		const OpenGLPipeline* pPipeline = (const OpenGLPipeline*)GetBoundPipeline();
		const OpenGLPipeline::PipelineResource resource = pPipeline->GetGLResources()[slotIndex];
		const ResourceSlotDesc slotDesc = pPipeline->GetResourceStateDesc().SlotDescriptions[slotIndex];

		switch (pResource->GetResourceType())
		{
			case Felix::GraphicsResourceType::Texture:
			{
				const OpenGLTextureResource * pTexture = (const OpenGLTextureResource*)pResource;
				const unsigned int currentTextureSlot = GL_TEXTURE0 + GetBoundTextureCount();

				glActiveTexture(currentTextureSlot);
				glBindTexture(GL_TEXTURE_2D, pTexture->GetGLHandle());
				glUniform1i(resource.UniformIndex, GetBoundTextureCount());

				break;
			}
			case Felix::GraphicsResourceType::TextureSampler:
			{
				const OpenGLTextureSamplerResource* pSampler = (const OpenGLTextureSamplerResource*)pResource;

				GLuint texture_unit = GetBoundTextureCount();
				glBindSampler(texture_unit, pSampler->GetGLHandle());

				break;
			}
			case Felix::GraphicsResourceType::ConstantBuffer:
			{
				const OpenGLBuffer* pConstantBuffer = (const OpenGLBuffer*)pResource->GetResource();

				glBindBufferBase(GL_UNIFORM_BUFFER, resource.UniformBlockBindingPoint, pConstantBuffer->GetGLHandle());
				break;
			}
			default:
				break;
		}
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

		const OpenGLPipeline::StencilGLFaceDesc& stencilFrontDesc = pGLPipeline->GetGLStencilFrontDesc();
		const OpenGLPipeline::StencilGLFaceDesc& stencilBackDesc = pGLPipeline->GetGLStencilBackDesc();

		glStencilMaskSeparate(GL_FRONT, stencilFrontDesc.StencilWriteMask);
		glStencilFuncSeparate(GL_FRONT,stencilFrontDesc.Function,stencilFrontDesc.StencilReferenceValue,stencilFrontDesc.StencilReadMask);
		glStencilOpSeparate(GL_FRONT, stencilFrontDesc.FailOperation, stencilFrontDesc.DepthFailOperation, stencilFrontDesc.PassOperation);

		glStencilMaskSeparate(GL_BACK, stencilBackDesc.StencilWriteMask);
		glStencilFuncSeparate(GL_BACK, stencilBackDesc.Function, stencilBackDesc.StencilReferenceValue, stencilBackDesc.StencilReadMask);
		glStencilOpSeparate(GL_BACK, stencilBackDesc.FailOperation, stencilBackDesc.DepthFailOperation, stencilBackDesc.PassOperation);

		/*
		* Set blending state
		*/
		const BlendingStateDesc& blendingState = pPipeline->GetBlendingDesc();

		if (blendingState.bEnable)
			glEnable(GL_BLEND);
		else
			glDisable(GL_BLEND);

		glBlendEquationSeparate(pGLPipeline->GetColorBlendingFunction(),pGLPipeline->GetAlphaBlendingFunction());
		glBlendFuncSeparate(pGLPipeline->GetSourceColorFactor(),pGLPipeline->GetDestinationColorFactor(),pGLPipeline->GetSourceAlphaFactor(),pGLPipeline->GetDestinationAlphaFactor());
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