#pragma once
#include <d3d12.h>
#include <wrl/client.h>

using namespace Microsoft::WRL;
template<typename T>
using DXPTR = ComPtr<T>;

namespace Felix
{
    class DX12Device;
}
