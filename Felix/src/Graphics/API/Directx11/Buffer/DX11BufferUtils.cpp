//
// Created by Baris on 10/26/2022.
//

#include "DX11BufferUtils.h"

namespace Felix
{
    D3D11_USAGE Felix::DX11BufferUtils::GetBufferUsage(const Felix::GraphicsBufferUsage usage) noexcept
    {
        switch (usage)
        {
            case GraphicsBufferUsage::Dynamic:
                return D3D11_USAGE_DYNAMIC;
            case GraphicsBufferUsage::Immutable:
                return D3D11_USAGE_IMMUTABLE;
            default:
                ASSERT(false,"DX11BufferUtils","Invalid GraphicsBufferUsage!");
                break;
        }
    }

    D3D11_BIND_FLAG Felix::DX11BufferUtils::GetBufferBindingPoint(const Felix::GraphicsBufferType type) noexcept
    {
        switch (type)
        {
            case GraphicsBufferType::VertexBuffer:
                return D3D11_BIND_VERTEX_BUFFER;
            case GraphicsBufferType::IndexBuffer:
                return D3D11_BIND_INDEX_BUFFER;
            case GraphicsBufferType::ConstantBuffer:
                return D3D11_BIND_CONSTANT_BUFFER;
            default:
                ASSERT(false,"DX11BufferUtils","Invalid GraphicsBufferType!");
                break;
        }
    }

    unsigned int Felix::DX11BufferUtils::GetBufferCpuWriteFlags(const Felix::GraphicsBufferUsage usage) noexcept
    {
        switch (usage)
        {
            case GraphicsBufferUsage::Dynamic:
                return D3D11_CPU_ACCESS_WRITE;
            case GraphicsBufferUsage::Immutable:
                return D3D11_CPU_ACCESS_WRITE;
            default:
                ASSERT(false,"DX11BufferUtils","Invalid GraphicsBufferUsage!");
                break;
        }
    }

}