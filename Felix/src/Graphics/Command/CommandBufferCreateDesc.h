#pragma once
#include <Core/Core.h>

namespace Felix
{
	/// <summary>
	/// Required information to create a command buffer
	/// </summary>
	struct EXPORT CommandBufferCreateDesc
	{
		bool AsyncSubmission;
	};
}