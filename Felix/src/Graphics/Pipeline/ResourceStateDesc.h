#pragma once
#include <Graphics/Pipeline/ResourceSlotDesc.h>
#include <vector>

namespace Felix
{
	/// <summary>
	/// Required information to describe the pipeline resource state
	/// </summary>
	struct EXPORT ResourceStateDesc
	{
		std::vector<ResourceSlotDesc> SlotDescriptions;
	};
}