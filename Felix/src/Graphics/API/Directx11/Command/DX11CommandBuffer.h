//
// Created by Baris on 10/26/2022.
//

#ifndef STBI_DX11COMMANDBUFFER_H
#define STBI_DX11COMMANDBUFFER_H

#include <Graphics/Command/CommandBuffer.h>
#include <Graphics/Shader/ShaderType.h>
#include <d3d11.h>

namespace Felix
{
    class DX11Texture;
    class DX11TextureSampler;
    class DX11Buffer;
    class DX11Resource;


    class EXPORT DX11CommandBuffer : public CommandBuffer {
    public:
        DX11CommandBuffer(const CommandBufferCreateDesc& desc,ID3D11Device* pDevice,ID3D11DeviceContext* pContext);
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
        void _CommitResourceAsTexture(const unsigned int slotIndex,const ShaderType targetStage,const DX11Resource* pResource);
        void _CommitResourceAsSampler(const unsigned int slotIndex,const ShaderType targetStage,const DX11TextureSampler* pSampler);
        void _CommitResourceAsConstantBuffer(const unsigned int slotIndex,const ShaderType targetStage,const DX11Buffer* pBuffer);
        void DrawIndexedCore(const unsigned int indexCount) override;

        void ClearCachedStateCore() override;

    protected:

    private:
        ID3D11Device* _dx11Device;
        ID3D11DeviceContext* _dx11Context;
        D3D11_VIEWPORT _currentViewport;
    };

}

#endif //STBI_DX11COMMANDBUFFER_H
