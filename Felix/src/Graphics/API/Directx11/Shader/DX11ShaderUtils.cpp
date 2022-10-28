#ifdef FELIX_OS_WINDOWS
//
// Created by Baris on 10/27/2022.
//

#include "DX11ShaderUtils.h"

std::string Felix::DX11ShaderUtils::GetTargetShaderString(const Felix::ShaderCreateDesc &desc)
{
    std::string text;

    switch (desc.Type)
    {
        case ShaderType::Vertex:
            text = "vs_";
            break;
        case ShaderType::Fragment:
            text = "ps_";
            break;
        case ShaderType::Geometry:
            break;
        case ShaderType::TesellationEval:
            break;
        case ShaderType::TesellationControl:
            break;
        case ShaderType::Compute:
            break;
        default:
            break;
    }

    text+= "4_0"; //TODO: must enable a way to make the user decide

    return text;
}

#endif