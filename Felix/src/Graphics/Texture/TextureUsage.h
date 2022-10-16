#pragma once
#include <Core/Core.h>

namespace Felix
{
	/// <summary>
	/// Supported texture usages
	/// </summary>
	enum class EXPORT TextureUsage
	{
		Immutable = 1 << 1,
		Sampled = 1 << 2,
		RenderTarget = 1 << 3,
		DepthStencilTarget = 1 << 4
	};

	FORCEINLINE static bool operator|(const TextureUsage a, const TextureUsage b)
	{
		return ((unsigned int)a | (unsigned int)b);
	}

	FORCEINLINE static TextureUsage operator&(const TextureUsage a, const TextureUsage b)
	{
		return (TextureUsage)((unsigned int)a | (unsigned int)b);
	}
}