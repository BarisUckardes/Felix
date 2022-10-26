//
// Created by Baris on 10/26/2022.
//

#ifndef STBI_DX11COMMANDBUFFER_H
#define STBI_DX11COMMANDBUFFER_H

#include <Graphics/Command/CommandBuffer.h>

namespace Felix
{
    class EXPORT DX11CommandBuffer : public CommandBuffer {
    public:
        DX11CommandBuffer(const CommandBufferCreateDesc& desc);
        virtual ~DX11CommandBuffer() override;

    protected:
        void LockCore() override;

        void UnlockCore() override;

        void BindPipelineCore(Pipeline *pPipeline) override;

        void BindFramebufferCore(Framebuffer *pFramebuffer) override;

        void SetViewportCore(const ViewportDesc &desc) override;

        void SetScissorsCore(const ScissorsDesc &desc) override;

        void ClearColorCore(const unsigned char r, const unsigned char g, const unsigned char b,
                            const unsigned char a) override;

        void ClearDepthCore(const unsigned char depth) override;

        void ClearStencilCore(const int stencil) override;

        void SetVertexBufferCore(GraphicsBuffer *pBuffer) override;

        void SetIndexBufferCore(GraphicsBuffer *pBuffer) override;

        void CommitResourceCore(const unsigned int slotIndex, GraphicsResource *pResource) override;

        void DrawIndexedCore(const unsigned int indexCount) override;

        void ClearCachedStateCore() override;

    protected:

    private:
    };

}

#endif //STBI_DX11COMMANDBUFFER_H
