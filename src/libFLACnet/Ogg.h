#pragma once

namespace FLAC
{
    public ref class Ogg
    {
    private:
        Ogg();

    public:
        static property bool IsSupported { bool get(); }
    };
}

