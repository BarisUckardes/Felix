#include "GraphicsDevice.h"
#include <Graphics/Device/StandaloneGraphicsDeviceCreateDesc.h>
#include <Graphics/Device/WindowGraphicsDeviceCreateDesc.h>
#include <Graphics/API/OpenGL/Device/OpenGLDevice.h>
#include <Graphics/Device/GraphicsDeviceObjects.h>

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
    GraphicsDevice::GraphicsDevice(Window* pOwnerWindow)
    {
        _standalone = false;
        _ownerWindow = pOwnerWindow;
    }
    GraphicsDevice::GraphicsDevice()
    {
        _standalone = true;
        _ownerWindow = nullptr;
    }
    void GraphicsDevice::RegisterDeviceObject(GraphicsDeviceObject* pDeviceObject)
    {
        _objects.push_back(pDeviceObject);
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
                pDevice = new OpenGLDevice(pOwnerWindow);
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
        * Bind device to the window
        */

        return pDevice;
    }
}