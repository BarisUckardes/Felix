#pragma once
#include <Core/Core.h>
#include <string>

namespace Felix
{
	struct TextureLoadResult;

	class EXPORT TextureLoader
	{
	public:
		TextureLoader() = delete;
		~TextureLoader() = delete;

		FORCEINLINE static bool LoadTextureFromDisk(const std::string& path, TextureLoadResult& resultOut);
	};
}