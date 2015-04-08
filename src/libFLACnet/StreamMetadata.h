#pragma once

#include "MetadataType.h"

namespace FLAC
{
    public ref class StreamMetadata
    {
    public:
        StreamMetadata();

        property bool IsLast;

        property MetadataType Type;
    };
}
