#pragma once

#include <cstdint>

namespace FLAC
{
    public ref class SeekPoint
    {
    public:
        SeekPoint();

        property uint64_t SampleNumber;

        property uint64_t StreamOffset;

        property unsigned int FrameSamples;

        static property uint64_t Placeholder { uint64_t get(); }
    };
}
