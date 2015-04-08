#pragma once

#include <FLAC\format.h>

namespace FLAC
{
    public enum class MetadataType
    {
        StreamInfo = FLAC__MetadataType::FLAC__METADATA_TYPE_STREAMINFO,
        Padding = FLAC__MetadataType::FLAC__METADATA_TYPE_PADDING,
        Application = FLAC__MetadataType::FLAC__METADATA_TYPE_APPLICATION,
        SeekTable = FLAC__MetadataType::FLAC__METADATA_TYPE_SEEKTABLE,
        VorbisComment = FLAC__MetadataType::FLAC__METADATA_TYPE_VORBIS_COMMENT,
        CueSheet = FLAC__MetadataType::FLAC__METADATA_TYPE_CUESHEET,
        Picture = FLAC__MetadataType::FLAC__METADATA_TYPE_PICTURE,
        Undefined = FLAC__MetadataType::FLAC__METADATA_TYPE_UNDEFINED,
        MaxUndefined = FLAC__MetadataType::FLAC__MAX_METADATA_TYPE,
    };
}
