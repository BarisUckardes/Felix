#include "DX12Pipeline.h"
#include <d3d12.h>
#include <Graphics/API/Directx12/Pipeline/DX12PipelineUtils.h>
#include <Graphics/API/Directx12/Device/DX12Device.h>


namespace Felix
{
    DX12Pipeline::DX12Pipeline(const PipelineCreateDesc& desc, DX12Device* pDevice) : Pipeline(desc)
    {
        /*
        * Create root signature
        */
        D3D12_ROOT_SIGNATURE_DESC rootSignatureDesc = {};
        rootSignatureDesc.Flags = D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT;
        rootSignatureDesc.NumParameters = 0; //TODO: implement
        rootSignatureDesc.NumStaticSamplers = 0; //TODO: implement

        std::vector<D3D12_ROOT_PARAMETER> rootParameters;
        std::vector<D3D12_STATIC_SAMPLER_DESC> samplerDescs;
        for (unsigned int i = 0; i < desc.Resources.SlotDescriptions.size(); i++)
        {
            const ResourceSlotDesc& slotDesc = desc.Resources.SlotDescriptions[i];

            GraphicsResourceType resourceType = slotDesc.Type;

            switch (resourceType)
            {
                case Felix::GraphicsResourceType::Texture:
                {
                    D3D12_ROOT_PARAMETER rootParameter = {};
                    rootParameter.ParameterType = D3D12_ROOT_PARAMETER_TYPE_SRV;
                    rootParameter.ShaderVisibility = DX12PipelineUtils::GetShaderVisibility(slotDesc.Stage);
                    rootParameter.Descriptor = {};
                    rootParameter.Constants = {};
                    rootParameter.DescriptorTable = {};

                    rootParameters.push_back(rootParameter);
                    break;
                }
                case Felix::GraphicsResourceType::TextureSampler:
                {
                    D3D12_STATIC_SAMPLER_DESC samplerDesc = {};
                    
                    samplerDescs.push_back(samplerDesc);
                    break;
                }
                case Felix::GraphicsResourceType::ConstantBuffer:
                {
                    D3D12_ROOT_PARAMETER rootParameter = {};
                    rootParameter.ParameterType = D3D12_ROOT_PARAMETER_TYPE_CBV;
                    rootParameter.ShaderVisibility = DX12PipelineUtils::GetShaderVisibility(slotDesc.Stage);
                    rootParameter.Descriptor = {};
                    rootParameter.Constants = {};
                    rootParameter.DescriptorTable = {};

                    rootParameters.push_back(rootParameter);
                    break;
                }
                default:
                    ASSERT(false, "DX12Pipeline", "Invalid resource type!");
                    break;
            }
        }
        rootSignatureDesc.pParameters = rootParameters.data();
        rootSignatureDesc.pStaticSamplers = samplerDescs.data();
        rootSignatureDesc.NumParameters = rootParameters.size();
        rootSignatureDesc.NumStaticSamplers = samplerDescs.size();

        ID3DBlob* pSignatureBlob;
        ID3DBlob* pErrorBlob;

        ASSERT(SUCCEEDED(D3D12SerializeRootSignature(&rootSignatureDesc, D3D_ROOT_SIGNATURE_VERSION_1, &pSignatureBlob, &pErrorBlob)),"DX12Pipeline","Failed to serialize the root signature with logs: %s",pErrorBlob->GetBufferPointer());

        ASSERT(SUCCEEDED(pDevice->GetDXDevice()->CreateRootSignature(0, pSignatureBlob->GetBufferPointer(), pSignatureBlob->GetBufferSize(), IID_PPV_ARGS(&_rootSignature))), "DX12Pipeline", "Failed to create the root signature");

        /*
        * Create input layour
        */
        unsigned char semanticCache[4];
        for (unsigned char i = 0; i < 4; i++)
            semanticCache[i] = 0;

        D3D12_INPUT_LAYOUT_DESC inputLayoutDesc = {};

        std::vector<InputElementDesc> inputElementDescs = desc.InputLayout.GetElements();
        unsigned int offset = 0;
        for (unsigned int i = 0; i < inputElementDescs.size(); i++)
        {
            const InputElementDesc& inputElementDesc = inputElementDescs[i];

            const std::string semanticText = DX12PipelineUtils::GetInputElementSemanticName(inputElementDesc.Semantic);

            char* pSemanticCache = new char[semanticText.size() + 1];
            semanticText.copy(pSemanticCache, semanticText.size(), 0);
            pSemanticCache[semanticText.size()] = '\0';

            D3D12_INPUT_ELEMENT_DESC inputElement;
        }
    }
    DX12Pipeline::~DX12Pipeline()
    {

    }
}