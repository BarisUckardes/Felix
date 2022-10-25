//
// Created by Baris on 10/26/2022.
//

#ifndef STBI_DX11BUFFER_H
#define STBI_DX11BUFFER_H

#include <Graphics/API/Directx11/Core/DX11Core.h>
#include <Graphics/Buffer/GraphicsBuffer.h>
#include <d3d11.h>

namespace Felix
{
    class DX11Device;

    class EXPORT DX11Buffer : public GraphicsBuffer {
    public:
        DX11Buffer(const GraphicsBufferCreateDesc& desc,DX11Device* pDevice);
        virtual ~DX11Buffer() override final;

        FORCEINLINE ID3D11Buffer* GetDX11Buffer() const noexcept { return _buffer.Get();}
    private:
        DXPTR<ID3D11Buffer> _buffer;
    };
}


#endif //STBI_DX11BUFFER_H
