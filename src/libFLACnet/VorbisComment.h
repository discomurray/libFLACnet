#pragma once

#include "StreamMetadata.h"

namespace FLAC
{
    public ref class VorbisComment : StreamMetadata
    {
    public:
        VorbisComment();

        property System::String^ Vendor;

        property array<System::String^>^ Comments;
    };
}

