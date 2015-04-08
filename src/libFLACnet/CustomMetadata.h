#pragma once

#include "StreamMetadata.h"

namespace FLAC
{
    public ref class CustomMetadata : StreamMetadata
    {
    public:
        CustomMetadata();

        property unsigned int Length;

        property MetadataType Type;

        property array<unsigned char>^ Data;
    };
}

