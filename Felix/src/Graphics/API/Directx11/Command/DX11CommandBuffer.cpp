//
// Created by Baris on 10/26/2022.
//

#include "DX11CommandBuffer.h"


namespace Felix
{
    DX11CommandBuffer::DX11CommandBuffer(const Felix::CommandBufferCreateDesc &desc) : CommandBuffer(desc)
    {

    }

    DX11CommandBuffer::~DX11CommandBuffer()
    {

    }

    void DX11CommandBuffer::LockCore()
    {

    }

    void DX11CommandBuffer::UnlockCore()
    {

    }

    void DX11CommandBuffer::BindPipelineCore(Pipeline *pPipeline)
    {

    }

    void DX11CommandBuffer::BindFramebufferCore(Framebuffer *pFramebuffer)
    {

    }

    void DX11CommandBuffer::SetViewportCore(const ViewportDesc &desc)
    {

    }

    void DX11CommandBuffer::SetScissorsCore(const ScissorsDesc &desc)
    {

    }

    void DX11CommandBuffer::ClearColorCore(const unsigned char r, const unsigned char g, const unsigned char b,
                                           const unsigned char a)
                                           {

    }

    void DX11CommandBuffer::ClearDepthCore(const unsigned char depth)
    {

    }

    void DX11CommandBuffer::ClearStencilCore(const int stencil)
    {

    }

    void DX11CommandBuffer::SetVertexBufferCore(GraphicsBuffer *pBuffer)
    {

    }

    void DX11CommandBuffer::SetIndexBufferCore(GraphicsBuffer *pBuffer)
    {

    }

    void DX11CommandBuffer::CommitResourceCore(const unsigned int slotIndex, GraphicsResource *pResource)
    {

    }

    void DX11CommandBuffer::DrawIndexedCore(const unsigned int indexCount)
    {

    }

    void DX11CommandBuffer::ClearCachedStateCore()
    {

    }


}