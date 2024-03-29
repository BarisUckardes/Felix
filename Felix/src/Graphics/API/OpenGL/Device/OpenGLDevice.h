#pragma once
#include <Graphics/Device/GraphicsDevice.h>

#ifdef FELIX_OS_WINDOWS
#include <Windows.h>
#elif FELIX_OS_LINUX
#endif

namespace Felix
{
    class EXPORT OpenGLDevice : public GraphicsDevice
    {
    public:
        OpenGLDevice(const WindowGraphicsDeviceCreateDesc& desc ,Window* pOwnerWindow);
        virtual ~OpenGLDevice() override;

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

        virtual void WaitForFinishCore() override final;
        virtual void SubmitCommandsCore(CommandBuffer* pCmdBuffer) override final;
    private:

#ifdef FELIX_OS_WINDOWS
        HGLRC _context;
		HDC _windowDeviceContext;
#elif  FELIX_OS_LINUX
#endif
    };
}