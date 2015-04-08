#pragma once

#include <cstdint>

namespace FLAC
{
    public ref class TrackIndex
    {
    public:
        TrackIndex();

        property uint64_t Offset;

        property unsigned char Number;
    };
}
