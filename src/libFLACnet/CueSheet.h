#pragma once

#include <cstdint>

#include "StreamMetadata.h"
#include "Track.h"

namespace FLAC
{
    public ref class CueSheet : StreamMetadata
    {
        array<wchar_t>^ mediaCatalogNumber;

    public:
        CueSheet();

        property unsigned int Length;

        property array<wchar_t>^ MediaCatalogNumber { array<wchar_t>^ get(); }

        property uint64_t LeadIn;

        property bool IsCd;

        property array<Track^>^ Tracks;
    };
}
