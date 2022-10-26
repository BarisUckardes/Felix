//
// Created by Baris on 10/26/2022.
//

#ifndef STBI_DX11VERTEXSHADER_H
#define STBI_DX11VERTEXSHADER_H

#include <Graphics/API/Directx11/Shader/DX11Shader.h>

namespace Felix
{
    class EXPORT DX11VertexShader final : public DX11Shader {
    public:
        DX11VertexShader(const ShaderCreateDesc& desc,DX11Device* pDevice);
        virtual ~DX11VertexShader() override {}

        FORCEINLINE ID3D11VertexShader* GetVertexShader() const noexcept { return _shader.Get();}
    private:
        DXPTR<ID3D11VertexShader> _shader;
    };

}

#endif //STBI_DX11VERTEXSHADER_H
