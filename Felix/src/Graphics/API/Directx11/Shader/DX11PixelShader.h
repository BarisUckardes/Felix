//
// Created by Baris on 10/27/2022.
//

#ifndef STBI_DX11PIXELSHADER_H
#define STBI_DX11PIXELSHADER_H

#include <Graphics/API/Directx11/Shader/DX11Shader.h>

namespace Felix
{
    class EXPORT DX11PixelShader final : public DX11Shader {
    public:
        DX11PixelShader(const ShaderCreateDesc &desc, DX11Device *pDevice);
        virtual ~DX11PixelShader() override {}

        FORCEINLINE ID3D11PixelShader* GetPixelShader() const noexcept { return _shader.Get();}

    private:
        DXPTR<ID3D11PixelShader> _shader;
    };

}

#endif //STBI_DX11PIXELSHADER_H
