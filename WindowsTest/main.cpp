#include <iostream>
#include <Window/Window.h>
#include <Graphics/Device/GraphicsDevice.h>
#include <Graphics/Device/GraphicsDeviceObjects.h>

using namespace std;

const std::string vShader = R"(
	#version 450 core
	layout(location = 0) in vec2 aPosition;

	void main()
	{
		gl_Position = vec4(aPosition,0,1.0f);
	}
)";
const std::string fShader = R"(
	#version 450 core

	out vec4 ColorOut;
	void main()
	{
		ColorOut = vec4(0,1,0,0);
	}
)";

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
	* Create shaders
	*/
	Felix::ShaderCreateDesc vertexShaderDesc = {};
	vertexShaderDesc.Type = Felix::ShaderType::Vertex;
	vertexShaderDesc.Source = vShader;
	vertexShaderDesc.EntryPoint = "main";

	Felix::ShaderCreateDesc fragmentShaderDesc = {};
	fragmentShaderDesc.Type = Felix::ShaderType::Fragment;
	fragmentShaderDesc.Source = fShader;
	fragmentShaderDesc.EntryPoint = "main";

	Felix::Shader* pVertexShader = pDevice->CreateShader(vertexShaderDesc);
	Felix::Shader* pFragmentShader = pDevice->CreateShader(fragmentShaderDesc);

	struct Vertex
	{
		float X;
		float Y;
	};

	/*
	* Create buffers
	*/
	std::vector<Vertex> vertexes = { {1,-1},{-1,-1},{0,1} };

	std::vector<unsigned int> indexes = { 0,1,2,0,2,1 };

	Felix::GraphicsBufferCreateDesc vertexBufferDesc = {};
	vertexBufferDesc.Type = Felix::GraphicsBufferType::VertexBuffer;
	vertexBufferDesc.Usage = Felix::GraphicsBufferUsage::Immutable;
	vertexBufferDesc.SubItemCount = vertexes.size();
	vertexBufferDesc.SubItemSize = sizeof(Vertex);
	vertexBufferDesc.pInitialData = (const unsigned char*)vertexes.data();

	Felix::GraphicsBufferCreateDesc indexBufferDesc = {};
	indexBufferDesc.Type = Felix::GraphicsBufferType::IndexBuffer;
	indexBufferDesc.Usage = Felix::GraphicsBufferUsage::Immutable;
	indexBufferDesc.SubItemCount = indexes.size();
	indexBufferDesc.SubItemSize = sizeof(unsigned int);
	indexBufferDesc.pInitialData = (const unsigned char*)indexes.data();

	Felix::GraphicsBuffer* pVertexBuffer = pDevice->CreateBuffer(vertexBufferDesc);
	Felix::GraphicsBuffer* pIndexBuffer = pDevice->CreateBuffer(indexBufferDesc);

	/*
	* Create pipeline
	*/
	Felix::PipelineCreateDesc pipelineDesc = {};

	Felix::ShadingPassDesc shadingPassDesc = {};
	shadingPassDesc.Shaders = { pVertexShader,pFragmentShader };
	pipelineDesc.ShadingPass = shadingPassDesc;

	std::vector<Felix::InputElementDesc> inputElements;
	inputElements.push_back(Felix::InputElementDesc({"Vertex",Felix::InputElementDataType::Float2,false}));
	Felix::InputLayoutDesc inputLayoutDesc(inputElements);
	pipelineDesc.InputLayoutDesc = inputLayoutDesc;

	Felix::RasterizerStateDesc rasterizerStateDesc = {};
	rasterizerStateDesc.bEnableDepthClip = false;
	rasterizerStateDesc.bEnableScissorTest = false;
	rasterizerStateDesc.CulledFace = Felix::CullMode::Back;
	rasterizerStateDesc.FrontFace = Felix::FrontFaceMode::CounterClockWise;
	rasterizerStateDesc.ShadingMode = Felix::PolygonShadingMode::Solid;
	rasterizerStateDesc.Topology = Felix::PrimitiveTopology::TriangleList;
	pipelineDesc.RasterizerDesc = rasterizerStateDesc;

	Felix::DepthStencilStateDesc depthStencilStateDesc = {};
	depthStencilStateDesc.bEnableDepthTest = false;
	depthStencilStateDesc.bEnableDeptWrite = false;
	depthStencilStateDesc.bEnableStencilTest = false;
	depthStencilStateDesc.TestFunction = Felix::DepthTestFunction::GreatEqual;
	pipelineDesc.DepthStencilDesc = depthStencilStateDesc;

	Felix::Pipeline* pPipeline = pDevice->CreatePipeline(pipelineDesc);

	/*
	* Create framebuffer
	*/
	Felix::Framebuffer* pSwapchainFramebuffer = pDevice->GetSwapchainFramebuffer();

	/*
	* Create viewports
	*/
	Felix::ViewportDesc viewport = {};
	viewport.PositionX = 0;
	viewport.PositionY = 0;
	viewport.Width = 1024;
	viewport.Height = 1024;
	viewport.MinDepth = 0.0f;
	viewport.MaxDepth = 1.0f;

	/*
	* Loop
	*/
	pWindow->Show();
	while (pWindow->IsActive())
	{
		pWindow->PollInputEvents();

		pCmdBuffer->Lock();
		pCmdBuffer->BindPipeline(pPipeline);
		pCmdBuffer->BindFramebuffer(pSwapchainFramebuffer);
		pCmdBuffer->SetViewport(viewport);
		pCmdBuffer->ClearColor(1, 0, 0, 1);
		pCmdBuffer->SetVertexBuffer(pVertexBuffer);
		pCmdBuffer->SetIndexBuffer(pIndexBuffer);
		
		pCmdBuffer->DrawIndexed(6);
		pCmdBuffer->Unlock();

		pDevice->Swapbuffers();
	}

	return 0;
}
