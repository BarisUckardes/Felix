#ifdef FELIX_OS_WINDOWS
//
// Created by Baris on 10/26/2022.
//

#include "DX11Shader.h"
#include <d3dcompiler.h>
#include <Graphics/API/Directx11/Shader/DX11ShaderUtils.h>

namespace Felix
{
    DX11Shader::DX11Shader(const Felix::ShaderCreateDesc &desc, Felix::DX11Device *pDevice): Shader(desc)
    {
        /*
         * Compile shader
         */
        ID3DBlob* pErrorBlob = nullptr;
        D3DCompile(desc.Source.c_str(),
                   desc.Source.size(),
                   nullptr,nullptr,nullptr,
                   desc.EntryPoint.c_str(),
                   DX11ShaderUtils::GetTargetShaderString(desc).c_str(),
                   D3DCOMPILE_ENABLE_STRICTNESS,
                   0,
                   &_shaderBlob,
                   &pErrorBlob
        );


        ASSERT(pErrorBlob == nullptr,"DX11Shader","Shader compilation failed with logs: %s",pErrorBlob->GetBufferPointer());
    }

}
#endif