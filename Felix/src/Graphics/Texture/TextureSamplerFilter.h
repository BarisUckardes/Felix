//
// Created by Baris on 10/28/2022.
//

#ifndef FELIX_TEXTURESAMPLERFILTER_H
#define FELIX_TEXTURESAMPLERFILTER_H

#include <Core/Core.h>

namespace Felix
{
    enum class EXPORT TextureSamplerFilter
    {
        Anisotropic,
        MinPointMagPointMipPoint,
        MinPointMagPointMipLinear,
        MinPointMagLinearMipPoint,
        MinPointMagLinearMipLinear,
        MinLinearMagPointMipPoint,
        MinLinearMagPointMipLinear,
        MinLinearMagLinearMipPoint,
        MinLinearMagLinearMipLinear
    };
}
#endif //FELIX_TEXTURESAMPLERFILTER_H
