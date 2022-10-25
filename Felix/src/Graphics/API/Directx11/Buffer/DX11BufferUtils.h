//
// Created by Baris on 10/26/2022.
//

#ifndef STBI_DX11BUFFERUTILS_H
#define STBI_DX11BUFFERUTILS_H

#include <Graphics/Buffer/GraphicsBufferType.h>
#include <Graphics/Buffer/GraphicsBufferUsage.h>
#include <d3d11.h>
#include <dxgi.h>

namespace Felix
{

    class EXPORT DX11BufferUtils {
    public:
        DX11BufferUtils() = delete;
        ~DX11BufferUtils() = delete;

        FORCEINLINE static D3D11_USAGE GetBufferUsage(const GraphicsBufferUsage usage) noexcept;
        FORCEINLINE static D3D11_BIND_FLAG GetBufferBindingPoint(const GraphicsBufferType type) noexcept;
        FORCEINLINE static unsigned int GetBufferCpuWriteFlags(const GraphicsBufferUsage usage) noexcept;

    };

}

#endif //STBI_DX11BUFFERUTILS_H
