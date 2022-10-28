//
// Created by Baris on 10/26/2022.
//

#include "DX11Buffer.h"
#include <Graphics/API/Directx11/Device/DX11Device.h>
#include <Graphics/API/Directx11/Buffer/DX11BufferUtils.h>

namespace Felix
{
    DX11Buffer::DX11Buffer(const Felix::GraphicsBufferCreateDesc& desc,DX11Device* pDevice) : GraphicsBuffer(desc)
    {
        /*
         * Create buffer desc
         */
        const unsigned int bufferSize = desc.SubItemSize*desc.SubItemCount;
        D3D11_BUFFER_DESC bufferDesc = {};
        bufferDesc.Usage = DX11BufferUtils::GetBufferUsage(desc.Usage);
        bufferDesc.ByteWidth = bufferSize + (16-(bufferSize)%16);
        bufferDesc.StructureByteStride = desc.SubItemSize;
        bufferDesc.BindFlags = DX11BufferUtils::GetBufferBindingPoint(desc.Type);
        bufferDesc.CPUAccessFlags = DX11BufferUtils::GetBufferCpuWriteFlags(desc.Usage);
        bufferDesc.MiscFlags = 0;

        D3D11_SUBRESOURCE_DATA subresourceData = {};
        subresourceData.pSysMem = desc.pInitialData;
        subresourceData.SysMemPitch = desc.SubItemSize;

        if(desc.pInitialData != nullptr)
        {
            ASSERT(SUCCEEDED( pDevice->GetDXDevice()->CreateBuffer(&bufferDesc,&subresourceData,&_buffer)),"DX11Buffer","Failed to create buffer");
        }
        else
        {
            ASSERT(SUCCEEDED( pDevice->GetDXDevice()->CreateBuffer(&bufferDesc,nullptr,&_buffer)),"DX11Buffer","Failed to create buffer");
        }
    }
    DX11Buffer::~DX11Buffer()
    {

    }
}
