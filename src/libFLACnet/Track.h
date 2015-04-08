#pragma once

#include <cstdint>

#include "TrackIndex.h"

namespace FLAC
{
    public ref class Track
    {
    public:
        Track();

        property uint64_t Offset;

        property unsigned char Number;

        property System::String^ ISRC;

        property unsigned Type;

        property unsigned PreEmphasis;

        property array<TrackIndex^>^ Indices;

    };
}
