#include "stdafx.h"
#include "SeekPoint.h"

#include <cstdint>

#include <FLAC\format.h>

using namespace FLAC;

SeekPoint::SeekPoint()
{
}

uint64_t SeekPoint::Placeholder::get()
{
    return FLAC__STREAM_METADATA_SEEKPOINT_PLACEHOLDER;
}
