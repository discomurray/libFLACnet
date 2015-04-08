#include "stdafx.h"
#include "Ogg.h"

#include <FLAC\export.h>

using namespace FLAC;

Ogg::Ogg()
{
}

bool Ogg::IsSupported::get()
{
    return static_cast<bool>(FLAC_API_SUPPORTS_OGG_FLAC);
}
