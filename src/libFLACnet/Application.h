#pragma once

#include "StreamMetadata.h"

namespace FLAC
{
    public ref class Application : StreamMetadata
    {
    public:
        Application();

        property array<unsigned char>^ Id;

        property array<unsigned char>^ Data;
    };
}
