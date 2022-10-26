//
// Created by Baris on 10/26/2022.
//

#include "DX11VertexShader.h"
#include <Graphics/API/Directx11/Device/DX11Device.h>

namespace Felix
{
    DX11VertexShader::DX11VertexShader(const Felix::ShaderCreateDesc &desc, Felix::DX11Device *pDevice) : DX11Shader(desc,pDevice)
    {
        /*
         * Create vertex shader
         */
        ID3D11Device* pDX11Device = pDevice->GetDXDevice();
        ID3DBlob* pBlob = GetBlob();

        ASSERT(SUCCEEDED(pDX11Device->CreateVertexShader(pBlob->GetBufferPointer(),pBlob->GetBufferSize(),nullptr,&_shader)),"DX11VertexShader","Failed to create vertex shader");
    }

}