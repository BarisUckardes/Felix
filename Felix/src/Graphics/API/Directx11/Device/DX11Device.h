//
// Created by Baris on 10/25/2022.
//

#ifndef STBI_DX11DEVICE_H
#define STBI_DX11DEVICE_H

#include <Graphics/Device/GraphicsDevice.h>
#include <Graphics/Device/StandaloneGraphicsDeviceCreateDesc.h>
#include <Graphics/API/Directx11/Core/DX11Core.h>
#include <dxgi1_4.h>
#include <dxgi.h>

namespace Felix
{
    class EXPORT DX11Device : public GraphicsDevice {
    public:
        DX11Device(const WindowGraphicsDeviceCreateDesc& desc,Window* pOwnerWindow);
        DX11Device(const StandaloneGraphicsDeviceCreateDesc& desc);
        virtual ~DX11Device() override;

        FORCEINLINE ID3D11Device* GetDXDevice() const noexcept { return _device.Get();}
        FORCEINLINE ID3D11DeviceContext* GetDXContenxt() const noexcept { return _context.Get();}
        FORCEINLINE IDXGIFactory4* GetDXFactory() const noexcept { return _factory.Get();}

    protected:

    private:
        void _CreateDX11Device();

    protected:
        virtual void SwapbuffersCore() override;

        virtual CommandBuffer* CreateCommandBufferCore(const CommandBufferCreateDesc& desc) override;
        virtual GraphicsBuffer* CreateBufferCore(const GraphicsBufferCreateDesc& desc) override;
        virtual Shader* CreateShaderCore(const ShaderCreateDesc& desc) override;
        virtual Texture* CreateTextureCore(const TextureCreateDesc& desc) override;
        virtual Framebuffer* CreateFramebufferCore(const FramebufferCreateDesc& desc) override;
        virtual Framebuffer* CreateSwapchainFramebufferCore(const SwapchainFramebufferCreateDesc& desc) override;
        virtual GraphicsResource* CreateResourceCore(const GraphicsResourceCreateDesc& desc) override;
        virtual Pipeline* CreatePipelineCore(const PipelineCreateDesc& desc) override;
        virtual TextureSampler* CreateTextureSamplerCore(const TextureSamplerCreateDesc& desc) override;

        virtual void UpdateBufferCore(GraphicsBuffer* pBuffer, const GraphicsBufferUpdateDesc& desc) override;
        virtual void UpdateTextureCore(Texture* pTexture, const TextureUpdateDesc& desc) override;

    private:
        DXPTR<ID3D11Device> _device;
        DXPTR<ID3D11DeviceContext> _context;
        DXPTR<IDXGIFactory4> _factory;
        DXPTR<IDXGIAdapter1> _adapter;
    };

}

#endif //STBI_DX11DEVICE_H
