#pragma once
#include <Graphics/Pipeline/Pipeline.h>
#include <Graphics/API/Directx12/Core/DX12Core.h>
#include <d3d12.h>

namespace Felix
{
	class EXPORT DX12Pipeline : public Pipeline
	{
	public:
		DX12Pipeline(const PipelineCreateDesc& desc, DX12Device* pDevice);
		virtual ~DX12Pipeline() override;

	private:
		DXPTR<ID3D12RootSignature> _rootSignature;
	};
}