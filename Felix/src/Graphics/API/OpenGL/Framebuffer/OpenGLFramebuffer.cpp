#include "OpenGLFramebuffer.h"
#include <Graphics/API/OpenGL/Texture/OpenGLTexture.h>
#include <Graphics/API/OpenGL/Framebuffer/OpenGLFramebufferUtils.h>
#include <GLAD/glad.h>

namespace Felix
{
	OpenGLFramebuffer::OpenGLFramebuffer(const FramebufferCreateDesc& desc, const bool bSwapchain) : Framebuffer(desc,bSwapchain)
	{
		/*
		* Create framebuffer
		*/
		glCreateFramebuffers(1, &_handle);
		glBindFramebuffer(GL_FRAMEBUFFER, _handle);

		std::vector<unsigned int> drawBuffers;
		unsigned int attachmentSlot = GL_COLOR_ATTACHMENT0;
		for (unsigned char i = 0; i < desc.Attachments.size(); i++)
		{
			const OpenGLTexture* pAttachment = (const OpenGLTexture*)desc.Attachments[i];
			const unsigned int textureHandle = pAttachment->GetGLHandle();

			if (pAttachment->GetUsage() | TextureUsage::RenderTarget)
			{
				glFramebufferTexture2D(GL_FRAMEBUFFER, attachmentSlot, textureHandle, GL_TEXTURE_2D, 0);
				drawBuffers.push_back(attachmentSlot);
				attachmentSlot++;
			}
			else if (pAttachment->GetUsage() == TextureUsage::DepthStencilTarget)
			{
				glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, textureHandle, GL_TEXTURE_2D, 0);
			}
		}
		glDrawBuffers(drawBuffers.size(), drawBuffers.data());

		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}
	OpenGLFramebuffer::~OpenGLFramebuffer()
	{

	}
}