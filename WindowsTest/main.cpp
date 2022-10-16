#include <iostream>
#include <Window/Window.h>
#include <Graphics/Device/GraphicsDevice.h>
#include <Graphics/Command/CommandBuffer.h>
using namespace std;

int main()
{
	/*
	* Create window
	*/
	Felix::WindowCreateDesc createDesc = {};
	createDesc.Title = "Felix windows test";
	createDesc.Width = 1024;
	createDesc.Height = 1024;
	createDesc.PositionX = 100;
	createDesc.PositionY = 100;

	Felix::Window* pWindow = Felix::Window::Create(createDesc);

	/*
	* Create graphics device
	*/
	Felix::WindowGraphicsDeviceCreateDesc deviceDesc = {};
	Felix::SwapchainFramebufferCreateDesc swapchainDesc = {};

	Felix::GraphicsDevice* pDevice = Felix::GraphicsDevice::CreateWindowDevice(deviceDesc,swapchainDesc,pWindow);

	/*
	* Create command buffer
	*/
	Felix::CommandBufferCreateDesc cmdBufferDesc = {};
	Felix::CommandBuffer* pCmdBuffer = pDevice->CreateCommandBuffer(cmdBufferDesc);

	/*
	* Loop
	*/
	pWindow->Show();
	while (pWindow->IsActive())
	{
		pWindow->PollInputEvents();

		pCmdBuffer->Lock();

		pCmdBuffer->ClearColor(1, 0, 0, 1);

		pCmdBuffer->Unlock();

		pDevice->Swapbuffers();
	}

	return 0;
}
