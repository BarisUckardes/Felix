#include <iostream>
#include <Window/Window.h>
#include <Graphics/Device/GraphicsDevice.h>
#include <Graphics/Device/GraphicsDeviceObjects.h>
#include <Graphics/Texture/TextureLoader.h>
#include <Graphics/Texture/TextureLoadResult.h>

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


	uniform sampler2D fTexture;

	in vec2 fUv;
	out vec4 ColorOut;
	void main()
	{
		ColorOut = texture2D(fTexture,fUv);
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

	/*
	* Create buffers
	*/
	std::vector<Vertex> vertexes = { {1,-1,1,0},{-1,-1,0,0},{0,1,0.5,1} };
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
	* Create textures
	*/
	Felix::TextureLoadResult textureLoadResult = {};
	Felix::TextureLoader::LoadTextureFromDisk("D:/Resources/Textures/MudSurfaceTile.jpg", textureLoadResult);

	Felix::TextureCreateDesc textureDesc = {};
	textureDesc.Width = textureLoadResult.Width;
	textureDesc.Height = textureLoadResult.Height;
	textureDesc.Depth = textureLoadResult.Depth;
	textureDesc.Format = textureLoadResult.Format;
	textureDesc.Usage = Felix::TextureUsage::Immutable;
	textureDesc.Type = Felix::TextureType::Texture2D;
	textureDesc.bGenerateMipmaps = false;
	textureDesc.pInitialData = textureLoadResult.pData;
	Felix::Texture* pTexture = pDevice->CreateTexture(textureDesc);

	/*
	* Create samplers
	*/
	Felix::TextureSamplerCreateDesc textureSamplerDesc = {};
	textureSamplerDesc.WrappingR = Felix::TextureSamplerWrapMode::Repeat;
	textureSamplerDesc.WrappingS = Felix::TextureSamplerWrapMode::Repeat;
	textureSamplerDesc.WrappingT = Felix::TextureSamplerWrapMode::Repeat;
	textureSamplerDesc.MinFilter = Felix::TextureSamplerMinFilter::Nearest;
	textureSamplerDesc.MagFilter = Felix::TextureSamplerMagFilter::Nearest;
	textureSamplerDesc.MaxAnisotropy = 1;
	Felix::TextureSampler* pTextureSampler = pDevice->CreateTextureSampler(textureSamplerDesc);

	/*
	* Create resource
	*/
	Felix::GraphicsResourceCreateDesc textureResourceDesc = {};
	textureResourceDesc.Type = Felix::GraphicsResourceType::Texture;
	textureResourceDesc.pDeviceObject = pTexture;
	Felix::GraphicsResourceCreateDesc textureSamplerResourceDesc = {};
	textureSamplerResourceDesc.Type = Felix::GraphicsResourceType::TextureSampler;
	textureSamplerResourceDesc.pDeviceObject = pTextureSampler;

	Felix::GraphicsResource* pTextureResource = pDevice->CreateResource(textureResourceDesc);
	Felix::GraphicsResource* pSamplerResource = pDevice->CreateResource(textureSamplerResourceDesc);

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
	resourceStateDesc.SlotDescriptions.push_back({ "fTexture",Felix::GraphicsResourceType::Texture,Felix::ShaderType::Fragment });
	resourceStateDesc.SlotDescriptions.push_back({ "fTexture",Felix::GraphicsResourceType::TextureSampler,Felix::ShaderType::Fragment });

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

		pCmdBuffer->CommitResource(0, pTextureResource);
		pCmdBuffer->CommitResource(1, pSamplerResource);

		pCmdBuffer->DrawIndexed(6);
		pCmdBuffer->Unlock();

		pDevice->Swapbuffers();
	}

	return 0;
}
