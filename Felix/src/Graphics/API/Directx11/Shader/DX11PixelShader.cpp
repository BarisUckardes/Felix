#ifdef FELIX_OS_WINDOWS
//
// Created by Baris on 10/27/2022.
//

#include "DX11PixelShader.h"
#include <Graphics/API/Directx11/Device/DX11Device.h>

namespace Felix
{
    DX11PixelShader::DX11PixelShader(const ShaderCreateDesc& desc, DX11Device* pDevice) : DX11Shader(desc, pDevice)
    {
        ID3D11Device* pDX11Device = pDevice->GetDXDevice();
        ID3DBlob* pBlob = GetBlob();

        ASSERT(SUCCEEDED( pDX11Device->CreatePixelShader(pBlob->GetBufferPointer(),pBlob->GetBufferSize(),nullptr,&_shader)),"DX11PixelShader","Shader creation failed!");
    }
}
#endif