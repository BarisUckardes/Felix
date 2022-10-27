//
// Created by Baris on 10/27/2022.
//

#include "DX11Pipeline.h"
#include <d3d11.h>
#include <d3d11_1.h>
#include <Graphics/API/Directx11/Device/DX11Device.h>
#include <Graphics/API/Directx11/Pipeline/DX11PipelineUtils.h>
#include <Graphics/Pipeline/InputElementUtils.h>
#include <Graphics/API/Directx11/Device/DX11DeviceObjects.h>

namespace Felix
{
    Felix::DX11Pipeline::DX11Pipeline(const Felix::PipelineCreateDesc &desc, Felix::DX11Device *pDevice) : Pipeline(desc)
    {
        ID3D11Device* pDX11Device = pDevice->GetDXDevice();

        /*
         * Create input layout
         */
        const std::vector<InputElementDesc> inputElementDescs = desc.InputLayout.GetElements();

        std::vector<D3D11_INPUT_ELEMENT_DESC> inputElements;
        unsigned int offset = 0;
        for(unsigned char i = 0;i<inputElementDescs.size();i++)
        {
            const InputElementDesc& elementDesc = inputElementDescs[i];

            D3D11_INPUT_ELEMENT_DESC inputElementDesc {elementDesc.Name.c_str(),0,DX11PipelineUtils::GetInputElementDataFormat(elementDesc.DataType),0,offset,D3D11_INPUT_PER_VERTEX_DATA,0};

            inputElements.push_back(inputElementDesc);

            offset+=InputElementUtils::GetElementSize(elementDesc.DataType);
        }

        bool bVertexShaderFound = false;
        for(unsigned char i = 0;i<desc.ShadingPass.Shaders.size();i++)
        {
            const Shader* pShader = desc.ShadingPass.Shaders[i];

            if(pShader->GetShaderType() == ShaderType::Vertex)
            {
                const DX11Shader* pDX11Shader = (const DX11Shader*)pShader;
                ID3DBlob* pBlob = pDX11Shader->GetBlob();

                ASSERT(SUCCEEDED(pDX11Device->CreateInputLayout(inputElements.data(),
                                                                inputElements.size(),
                                                                pBlob->GetBufferPointer(),
                                                                pBlob->GetBufferSize(),
                                                                &_inputLayout)),
                       "DX11Pipeline","Failed to create input layout");

                bVertexShaderFound= true;
                break;
            }
        }
        ASSERT(bVertexShaderFound,"DX11Pipeline","Failed to find a suitable vertex shader for the input layout");

        /*
         * Create rasterizer state
         */
        D3D11_RASTERIZER_DESC rasterizerDesc = {};
        rasterizerDesc.DepthClipEnable = desc.RasterizerDesc.bEnableDepthClip;
        rasterizerDesc.FrontCounterClockwise = desc.RasterizerDesc.FrontFace == FrontFaceMode::CounterClockWise;
        rasterizerDesc.ScissorEnable = desc.RasterizerDesc.bEnableScissorTest;
        rasterizerDesc.FillMode = DX11PipelineUtils::GetFillMode(desc.RasterizerDesc.ShadingMode);
        rasterizerDesc.CullMode = DX11PipelineUtils::GetCullMode(desc.RasterizerDesc.CulledFace);
        rasterizerDesc.DepthBias = 0;
        rasterizerDesc.DepthBiasClamp = 0;
        rasterizerDesc.AntialiasedLineEnable =false;
        rasterizerDesc.MultisampleEnable = false;
        rasterizerDesc.SlopeScaledDepthBias = 0;

        ASSERT(SUCCEEDED(pDX11Device->CreateRasterizerState(&rasterizerDesc,&_rasterizerState)),"DX11Pipeline","Failed to create rasterizer state");

        /*
         * Create depth stencil state
         */
        D3D11_DEPTH_STENCIL_DESC depthStencilDesc = {};
        depthStencilDesc.DepthEnable = desc.DepthStencilDesc.bEnableDepthTest;
        depthStencilDesc.StencilEnable = desc.DepthStencilDesc.bEnableStencilTest;
        depthStencilDesc.DepthFunc = DX11PipelineUtils::GetComparision(desc.DepthStencilDesc.TestFunction);
        depthStencilDesc.DepthWriteMask = desc.DepthStencilDesc.bEnableDeptWrite == true ? D3D11_DEPTH_WRITE_MASK_ALL : D3D11_DEPTH_WRITE_MASK_ZERO;
        depthStencilDesc.StencilReadMask = 0;
        depthStencilDesc.StencilWriteMask = 0;
        depthStencilDesc.FrontFace = DX11PipelineUtils::GetStencilFaceDesc(desc.DepthStencilDesc.StencilFrontFace);
        depthStencilDesc.BackFace = DX11PipelineUtils::GetStencilFaceDesc(desc.DepthStencilDesc.StencilBackFace);

        ASSERT(SUCCEEDED(pDX11Device->CreateDepthStencilState(&depthStencilDesc,&_depthStencilState)),"DX11Pipeline","Failed to create depth stencil state");

        /*
         * Create blending state
         */
        D3D11_BLEND_DESC blendDesc = {};
        blendDesc.AlphaToCoverageEnable = false;
        blendDesc.IndependentBlendEnable = desc.BlendingDesc.bEnable;

        for(unsigned char i = 0;i<8;i++)
        {
            D3D11_RENDER_TARGET_BLEND_DESC rtBlendDesc = {};
            rtBlendDesc.BlendEnable = desc.BlendingDesc.bEnable;
            rtBlendDesc.RenderTargetWriteMask = desc.BlendingDesc.bEnable ? 1.0f : 0.0f;
            rtBlendDesc.BlendOp = DX11PipelineUtils::GetBlendingOperation(desc.BlendingDesc.ColorFunction);
            rtBlendDesc.SrcBlend = DX11PipelineUtils::GetColorBlendingFactor(desc.BlendingDesc.SourceColorFactor);
            rtBlendDesc.DestBlend = DX11PipelineUtils::GetColorBlendingFactor(desc.BlendingDesc.DestinationColorFactor);
            rtBlendDesc.BlendOpAlpha = DX11PipelineUtils::GetBlendingOperation(desc.BlendingDesc.AlphaFunction);
            rtBlendDesc.SrcBlendAlpha = DX11PipelineUtils::GetAlphaBlendingFactor(desc.BlendingDesc.SourceAlphaFactor);
            rtBlendDesc.DestBlendAlpha = DX11PipelineUtils::GetAlphaBlendingFactor(desc.BlendingDesc.DestinationAlphaFactor);

            blendDesc.RenderTarget[i] = rtBlendDesc;
        }

        ASSERT(SUCCEEDED(pDX11Device->CreateBlendState(&blendDesc,&_blendState)),"DX11Pipeline","Failed to create blending");

        /*
         * Create primitive topology
         */
        _topology = DX11PipelineUtils::GetPrimitives(desc.RasterizerDesc.Topology);
    }

    Felix::DX11Pipeline::~DX11Pipeline()
    {

    }

}