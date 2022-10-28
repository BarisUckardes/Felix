//
// Created by Baris on 10/25/2022.
//

#ifndef STBI_DX11CORE_H
#define STBI_DX11CORE_H

#include <d3d11.h>
#include <wrl/client.h>

using namespace Microsoft::WRL;
template<typename T>
using DXPTR = ComPtr<T>;

namespace Felix
{
    class DX11Device;
}

#endif //STBI_DX11CORE_H
