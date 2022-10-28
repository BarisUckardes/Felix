#pragma once
#include <Core/Core.h>

namespace Felix
{
	/// <summary>
	/// Supported texture usages
	/// </summary>
	enum class EXPORT TextureUsage : unsigned int
	{
		Sampled = 1 << 0,
		RenderTarget = 1 << 1,
		DepthStencilTarget = 1 << 2
	};

	FORCEINLINE static TextureUsage operator | (const TextureUsage a, const TextureUsage b)
	{
		return (TextureUsage)((unsigned int)a | (unsigned int)b);
	}

	FORCEINLINE static bool operator&(const TextureUsage a, const TextureUsage b)
	{
		return ((unsigned int)a & (unsigned int)b);
	}
}