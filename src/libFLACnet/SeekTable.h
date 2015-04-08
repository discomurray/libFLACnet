#pragma once

#include "StreamMetadata.h"
#include "SeekPoint.h"

namespace FLAC
{
    public ref class SeekTable : StreamMetadata
    {
    public:
        SeekTable();

        property array<SeekPoint^>^ Points;
    };
}

