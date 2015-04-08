#pragma once

#include <cstdint>
#include "PictureType.h"

namespace FLAC
{
    public ref class Picture
    {
    public:
        Picture();

        property PictureType Type;

        property System::String^ MimeType;

        property System::String^ Description;

        property uint32_t Width;

        property uint32_t Height;

        property uint32_t Depth;

        property uint32_t Colors;

        property array<unsigned char>^ Data;
    };
}
