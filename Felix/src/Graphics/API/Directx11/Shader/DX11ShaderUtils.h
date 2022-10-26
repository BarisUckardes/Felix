//
// Created by Baris on 10/27/2022.
//

#ifndef FELIX_DX11SHADERUTILS_H
#define FELIX_DX11SHADERUTILS_H

#include <d3d11.h>
#include <Graphics/Shader/ShaderCreateDesc.h>

namespace Felix
{
    class EXPORT DX11ShaderUtils {
    public:
        FORCEINLINE static std::string GetTargetShaderString(const ShaderCreateDesc& desc);
    };
}


#endif //FELIX_DX11SHADERUTILS_H
