//
// Created by Baris on 10/26/2022.
//

#ifndef STBI_DX11SHADER_H
#define STBI_DX11SHADER_H

#include <Graphics/Shader/Shader.h>
#include <Graphics/API/Directx11/Core/DX11Core.h>
namespace Felix
{
    class EXPORT DX11Shader : public Shader {

    public:
        DX11Shader(const ShaderCreateDesc& desc,DX11Device* pDevice);
        virtual ~DX11Shader() override;


    private:

    };

}

#endif //STBI_DX11SHADER_H
