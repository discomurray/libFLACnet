#pragma once

#include "StreamMetadata.h"

namespace FLAC
{
    public ref class Padding : public StreamMetadata
    {
    public:
        Padding();

        property unsigned int Length;
    };
}

