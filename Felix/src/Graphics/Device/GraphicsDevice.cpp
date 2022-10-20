#include "GraphicsDevice.h"
#include <Graphics/Device/StandaloneGraphicsDeviceCreateDesc.h>
#include <Graphics/Device/WindowGraphicsDeviceCreateDesc.h>
#include <Graphics/API/OpenGL/Device/OpenGLDevice.h>
#include <Graphics/Device/GraphicsDeviceObjects.h>
#include <Window/WindowDeviceAdapter.h>
#include <Window/Window.h>

namespace Felix
{
    GraphicsDevice* GraphicsDevice::CreateStandalone(const StandaloneGraphicsDeviceCreateDesc& desc, const GraphicsDeviceCapabilities& requiredCapabilities)
    {
        /*
        * Get requrested api
        */
        GraphicsAPI requestedAPI = desc.PreferredDevice;

        GraphicsDevice* pDevice = nullptr;
        switch (requestedAPI)
        {
            case Felix::GraphicsAPI::OpenGL:
            case Felix::GraphicsAPI::OpenGLES:
                ASSERT(false,"Graphics device","OpenGL or OpenGL-ES not allowed to create a standalone graphics device!");
                break;
            case Felix::GraphicsAPI::Directx11:
                ASSERT(false, "GraphicsDevice", "This api type is not supported at the moment");
                break;
            case Felix::GraphicsAPI::Directx12:
                ASSERT(false,"GraphicsDevice","This api type is not supported at the moment");
                break;
            case Felix::GraphicsAPI::Vulkan:
                ASSERT(false,"GraphicsDevice","This api type is not supported at the moment");
                break;
            case Felix::GraphicsAPI::Metal:
                ASSERT(false,"GraphicsDevice","This api type is not supported at the moment");
                break;
            case Felix::GraphicsAPI::GNM:
                ASSERT(false,"GraphicsDevice","This api type is not supported at the moment");
                break;
            case Felix::GraphicsAPI::GNMX:
                ASSERT(false,"GraphicsDevice","This api type is not supported at the moment");
                break;
            default:
                break;
        }

        return pDevice;
    }
    GraphicsDevice* GraphicsDevice::CreateWindowDevice(const WindowGraphicsDeviceCreateDesc& desc,Window* pOwnerWindow, const GraphicsDeviceCapabilities& requiredCapabilities)
    {
        /*
        * Get requested api
        */
        GraphicsAPI requestedAPI = desc.PreferredAPI;

        GraphicsDevice* pDevice = nullptr;
        switch (requestedAPI)
        {
            case Felix::GraphicsAPI::OpenGL:
            {
                pDevice = new OpenGLDevice(desc,pOwnerWindow);
                break;
            }
            case Felix::GraphicsAPI::OpenGLES:
                break;
            case Felix::GraphicsAPI::Directx11:
                break;
            case Felix::GraphicsAPI::Directx12:
                break;
            case Felix::GraphicsAPI::Vulkan:
                break;
            case Felix::GraphicsAPI::Metal:
                break;
            case Felix::GraphicsAPI::GNM:
                break;
            case Felix::GraphicsAPI::GNMX:
                break;
            default:
                break;
        }

        /*
        * Create swapchain desc
        */
        SwapchainFramebufferCreateDesc swapchainFramebufferDesc = {};
        swapchainFramebufferDesc.Width = pOwnerWindow->GetWidth();
        swapchainFramebufferDesc.Height = pOwnerWindow->GetHeight();
        swapchainFramebufferDesc.Format = desc.SwapchainBufferFormat;
        swapchainFramebufferDesc.DepthStencilFormat = desc.SwapchainDepthStencilBufferFormat;
        swapchainFramebufferDesc.BufferCount = desc.SwapchainBufferCount;

        /*
        * Create swapchain framebuffer
        */
        pDevice->CreateSwapchainFramebuffer(swapchainFramebufferDesc);

        return pDevice;
    }

    void GraphicsDevice::Swapbuffers()
    {
        if (_standalone)
            return;

        SwapbuffersCore();
    }
    CommandBuffer* GraphicsDevice::CreateCommandBuffer(const CommandBufferCreateDesc& desc)
    {
        CommandBuffer* pObject = CreateCommandBufferCore(desc);

        RegisterDeviceObject(pObject);

        return pObject;

    }
    GraphicsBuffer* GraphicsDevice::CreateBuffer(const GraphicsBufferCreateDesc& desc)
    {
        GraphicsBuffer* pObject = CreateBufferCore(desc);

        RegisterDeviceObject(pObject);

        return pObject;
    }
    Shader* GraphicsDevice::CreateShader(const ShaderCreateDesc& desc)
    {
        Shader* pObject = CreateShaderCore(desc);

        RegisterDeviceObject(pObject);

        return pObject;
    }
    Texture* GraphicsDevice::CreateTexture(const TextureCreateDesc& desc)
    {
        Texture* pObject = CreateTextureCore(desc);

        RegisterDeviceObject(pObject);

        return pObject;
    }
    Framebuffer* GraphicsDevice::CreateFramebuffer(const FramebufferCreateDesc& desc)
    {
        Framebuffer* pObject = CreateFramebufferCore(desc);

        RegisterDeviceObject(pObject);

        return pObject;
    }
    GraphicsResource* GraphicsDevice::CreateResource(const GraphicsResourceCreateDesc& desc)
    {
        /*
        * Validate if resource is nullptr
        */
        ASSERT(desc.pDeviceObject != nullptr, "GraphicsDevice", "Targer resource object cannot be nullptr!");

        GraphicsResource* pObject = CreateResourceCore(desc);

        RegisterDeviceObject(pObject);

        return pObject;
    }
    Pipeline* GraphicsDevice::CreatePipeline(const PipelineCreateDesc& desc)
    {
        Pipeline* pObject = CreatePipelineCore(desc);

        RegisterDeviceObject(pObject);

        return pObject;
    }
    TextureSampler* GraphicsDevice::CreateTextureSampler(const TextureSamplerCreateDesc& desc)
    {
        TextureSampler* pObject = CreateTextureSamplerCore(desc);

        RegisterDeviceObject(pObject);

        return pObject;
    }
    void GraphicsDevice::UpdateBuffer(GraphicsBuffer* pBuffer, const GraphicsBufferUpdateDesc& desc)
    {
        UpdateBufferCore(pBuffer, desc);
    }
    void GraphicsDevice::UpdateTexture(Texture* pTexture, const TextureUpdateDesc& desc)
    {
        UpdateTextureCore(pTexture, desc);
    }
    GraphicsDevice::GraphicsDevice(Window* pOwnerWindow)
    {
        _standalone = false;
        _ownerWindow = pOwnerWindow;
    }

    GraphicsDevice::GraphicsDevice()
    {
        _standalone = true;
        _ownerWindow = nullptr;
        _swapchainFramebuffer = nullptr;
    }

    void GraphicsDevice::RegisterDeviceObject(GraphicsDeviceObject* pDeviceObject)
    {
        _objects.push_back(pDeviceObject);
    }
    void GraphicsDevice::CreateSwapchainFramebuffer(const SwapchainFramebufferCreateDesc& desc)
    {
        Framebuffer* pFramebuffer = CreateSwapchainFramebufferCore(desc);

        RegisterDeviceObject(pFramebuffer);

        _swapchainFramebuffer = pFramebuffer;
    }

  
}