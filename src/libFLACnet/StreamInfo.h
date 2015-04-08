#pragma once

#include <stdint.h>

#include "StreamMetadata.h"

namespace FLAC
{
    public ref class StreamInfo : public StreamMetadata
    {
    public:
        StreamInfo();

        property unsigned int MinBlockSize;

        property unsigned int MaxBlockSize;

        property unsigned int MinFrameSize;

        property unsigned int MaxFrameSize;

        property unsigned int SampleRate;

        property unsigned int Channels;

        property unsigned int BitsPerSample;

        property uint64_t TotalSamples;

        property array<unsigned char>^ Md5Sum;
    };
}
