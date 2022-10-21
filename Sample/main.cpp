#include <iostream>
#include <Window/Window.h>
#include <Graphics/Device/GraphicsDevice.h>
#include <Graphics/Device/GraphicsDeviceObjects.h>

using namespace std;

const std::string vShader = R"(
	#version 450 core
	layout(location = 0) in vec2 aPosition;
	layout(location = 1) in vec2 aUv;

	out vec2 fUv;
	void main()
	{
		gl_Position = vec4(aPosition,0,1.0f);
		fUv = aUv;
	}
)";
const std::string fShader = R"(
	#version 450 core


	layout(std140) uniform MyConstantBuffer
    {
		vec3 MyColor;
    };

	layout(std140) uniform MyConstantBuffer2
    {
		vec3 MyColor2;
    };

	in vec2 fUv;
	out vec4 ColorOut;
	void main()
	{
		ColorOut = vec4(fUv,0,0);
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
	deviceDesc.PreferredAPI = Felix::GraphicsAPI::OpenGL;
	deviceDesc.SwapchainBufferCount = 3;
	deviceDesc.SwapchainBufferFormat = Felix::TextureFormat::RGBA8;
	deviceDesc.SwapchainDepthStencilBufferFormat = Felix::TextureFormat::None;

	Felix::GraphicsDevice* pDevice = Felix::GraphicsDevice::CreateWindowDevice(deviceDesc,pWindow);

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
		float U;
		float V;
	};
	struct ConstantBufferData
	{
		float R;
		float G;
		float B;
	};

	/*
	* Create buffers
	*/
	std::vector<Vertex> vertexes = { {1,-1,1,0},{-1,-1,0,0},{0,1,0.5,1} };
	std::vector<unsigned int> indexes = { 0,1,2,0,2,1 };
	ConstantBufferData constantBufferData = { 0,1,0.0 };
	ConstantBufferData constantBufferData2 = { 0,0,1 };

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

	Felix::GraphicsBufferCreateDesc constantBufferDesc = {};
	constantBufferDesc.Type = Felix::GraphicsBufferType::ConstantBuffer;
	constantBufferDesc.Usage = Felix::GraphicsBufferUsage::Dynamic;
	constantBufferDesc.SubItemCount = 1;
	constantBufferDesc.SubItemSize = sizeof(ConstantBufferData); // must multiples of 16 bytes for std140
	constantBufferDesc.pInitialData = (const unsigned char*)&constantBufferData;

	Felix::GraphicsBufferCreateDesc constantBufferDesc2 = {};
	constantBufferDesc2.Type = Felix::GraphicsBufferType::ConstantBuffer;
	constantBufferDesc2.Usage = Felix::GraphicsBufferUsage::Dynamic;
	constantBufferDesc2.SubItemCount = 1;
	constantBufferDesc2.SubItemSize = sizeof(ConstantBufferData); // must multiples of 16 bytes for std140
	constantBufferDesc2.pInitialData = (const unsigned char*)&constantBufferData2;

	Felix::GraphicsBuffer* pVertexBuffer = pDevice->CreateBuffer(vertexBufferDesc);
	Felix::GraphicsBuffer* pIndexBuffer = pDevice->CreateBuffer(indexBufferDesc);
	Felix::GraphicsBuffer* pConstantBuffer = pDevice->CreateBuffer(constantBufferDesc);
	Felix::GraphicsBuffer* pConstantBuffer2 = pDevice->CreateBuffer(constantBufferDesc2);

	/*
	* Create resource
	*/
	Felix::GraphicsResourceCreateDesc constantBufferResourcDesc = {};
	constantBufferResourcDesc.Type = Felix::GraphicsResourceType::ConstantBuffer;
	constantBufferResourcDesc.pDeviceObject = pConstantBuffer;
	Felix::GraphicsResourceCreateDesc constantBufferResourcDesc2 = {};
	constantBufferResourcDesc2.Type = Felix::GraphicsResourceType::ConstantBuffer;
	constantBufferResourcDesc2.pDeviceObject = pConstantBuffer2;

	Felix::GraphicsResource* pConstantBufferResource = pDevice->CreateResource(constantBufferResourcDesc);
	Felix::GraphicsResource* pConstantBufferResource2 = pDevice->CreateResource(constantBufferResourcDesc2);

	/*
	* Create pipeline
	*/
	Felix::PipelineCreateDesc pipelineDesc = {};

	Felix::ShadingPassDesc shadingPassDesc = {};
	shadingPassDesc.Shaders = { pVertexShader,pFragmentShader };
	pipelineDesc.ShadingPass = shadingPassDesc;

	std::vector<Felix::InputElementDesc> inputElements;
	inputElements.push_back(Felix::InputElementDesc({"Vertex",Felix::InputElementDataType::Float2,false}));
	inputElements.push_back(Felix::InputElementDesc({ "UV",Felix::InputElementDataType::Float2,false }));
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

	Felix::StencilFaceDesc stencilFrontDesc = {};
	stencilFrontDesc.StencilReferenceValue = 1;
	stencilFrontDesc.StencilReadMask = 0;
	stencilFrontDesc.StencilWriteMask = 1;
	stencilFrontDesc.Function = Felix::StencilFunction::Always;
	stencilFrontDesc.DepthFailOperation = Felix::StencilOperation::Keep;
	stencilFrontDesc.FailOperation = Felix::StencilOperation::Keep;
	stencilFrontDesc.PassOperation = Felix::StencilOperation::Keep;
	depthStencilStateDesc.StencilFrontFace = stencilFrontDesc;

	Felix::StencilFaceDesc stencilBackFace = {};
	stencilBackFace.StencilReferenceValue = 1;
	stencilBackFace.StencilReadMask = 0;
	stencilBackFace.StencilWriteMask = 1;
	stencilBackFace.Function = Felix::StencilFunction::Always;
	stencilBackFace.DepthFailOperation = Felix::StencilOperation::Keep;
	stencilBackFace.FailOperation = Felix::StencilOperation::Keep;
	stencilBackFace.PassOperation = Felix::StencilOperation::Keep;
	depthStencilStateDesc.StencilBackFace = stencilBackFace;

	pipelineDesc.DepthStencilDesc = depthStencilStateDesc;

	Felix::BlendingStateDesc blendingStateDesc = {};
	blendingStateDesc.bEnable = false;
	blendingStateDesc.AlphaFunction = Felix::BlendingFunction::Add;
	blendingStateDesc.SourceAlphaFactor = Felix::BlendingFactor::One;
	blendingStateDesc.DestinationAlphaFactor = Felix::BlendingFactor::One;
	blendingStateDesc.ColorFunction = Felix::BlendingFunction::Add;
	blendingStateDesc.SourceColorFactor = Felix::BlendingFactor::One;
	blendingStateDesc.DestinationColorFactor = Felix::BlendingFactor::One;

	pipelineDesc.BlendingDesc = blendingStateDesc;
	
	Felix::ResourceStateDesc resourceStateDesc = {};
	resourceStateDesc.SlotDescriptions.push_back({"MyConstantBuffer",Felix::GraphicsResourceType::ConstantBuffer,Felix::ShaderType::Fragment});
	resourceStateDesc.SlotDescriptions.push_back({ "MyConstantBuffer2",Felix::GraphicsResourceType::ConstantBuffer,Felix::ShaderType::Fragment });
	pipelineDesc.ResourceStateDesc = resourceStateDesc;

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

		pCmdBuffer->CommitResource(0, pConstantBufferResource);
		pCmdBuffer->CommitResource(1, pConstantBufferResource2);

		pCmdBuffer->DrawIndexed(6);
		pCmdBuffer->Unlock();

		pDevice->Swapbuffers();
	}

	return 0;
}
