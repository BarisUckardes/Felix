#pragma once
#include <Graphics/Shader/ShaderCreateDesc.h>
#include <Graphics/Device/GraphicsDeviceObject.h>

namespace Felix
{
	/// <summary>
	/// Graphics device programming unit authored by the GraphicsDevice
	/// </summary>
	class EXPORT Shader : public GraphicsDeviceObject
	{
	public:
		FORCEINLINE ShaderType GetShaderType() const noexcept { return _type; }
		FORCEINLINE std::string GetSource() const noexcept { return _source; }
		FORCEINLINE std::string GetEntryPoint() const noexcept { return _entryPoint; }

		FORCEINLINE GraphicsDeviceObjectType GetDeviceObjectType() const noexcept final { return GraphicsDeviceObjectType::Shader; }
	protected:
		Shader(const ShaderCreateDesc& desc) : _type(desc.Type),_source(desc.Source),_entryPoint(desc.EntryPoint) {}
		virtual ~Shader() {}
	private:
		const ShaderType _type;
		const std::string _source;
		const std::string _entryPoint;
	};
}