#include "Framebuffer.h"
#include <Graphics/Texture/Texture.h>

namespace Felix
{
	Framebuffer::Framebuffer(const FramebufferCreateDesc& desc,const bool bSwapchain)
	{
		_attachments = desc.Attachments;
		_width = desc.Width;
		_height = desc.Height;
		_swapchain = bSwapchain;

        /*
         * Validate if swapchain
         */
        if(bSwapchain)
        {
            _depthStencil = false;
            return;
        }

		/*
		* Search for depth stencil texture
		*/
		for (unsigned char i = 0; i < desc.Attachments.size(); i++)
		{
			Texture* pAttachment = desc.Attachments[i];

			if (pAttachment->GetUsageFlags() & TextureUsage::DepthStencilTarget)
			{
				_depthStencilTexture = pAttachment;
				_depthStencil = true;
				return;
			}
		}

		_depthStencil = false;

	}
}