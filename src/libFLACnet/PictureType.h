#pragma once

#include <FLAC\format.h>

namespace FLAC
{
    public enum class PictureType
    {
        Other = FLAC__StreamMetadata_Picture_Type::FLAC__STREAM_METADATA_PICTURE_TYPE_OTHER,
        FileIconStandard = FLAC__StreamMetadata_Picture_Type::FLAC__STREAM_METADATA_PICTURE_TYPE_FILE_ICON_STANDARD,
        FileIcon = FLAC__StreamMetadata_Picture_Type::FLAC__STREAM_METADATA_PICTURE_TYPE_FILE_ICON,
        FrontCover = FLAC__StreamMetadata_Picture_Type::FLAC__STREAM_METADATA_PICTURE_TYPE_FRONT_COVER,
        BackCover = FLAC__StreamMetadata_Picture_Type::FLAC__STREAM_METADATA_PICTURE_TYPE_BACK_COVER,
        LeafletPage = FLAC__StreamMetadata_Picture_Type::FLAC__STREAM_METADATA_PICTURE_TYPE_LEAFLET_PAGE,
        Media = FLAC__StreamMetadata_Picture_Type::FLAC__STREAM_METADATA_PICTURE_TYPE_MEDIA,
        LeadArtist = FLAC__StreamMetadata_Picture_Type::FLAC__STREAM_METADATA_PICTURE_TYPE_LEAD_ARTIST,
        Artist = FLAC__StreamMetadata_Picture_Type::FLAC__STREAM_METADATA_PICTURE_TYPE_ARTIST,
        Conductor = FLAC__StreamMetadata_Picture_Type::FLAC__STREAM_METADATA_PICTURE_TYPE_CONDUCTOR,
        Band = FLAC__StreamMetadata_Picture_Type::FLAC__STREAM_METADATA_PICTURE_TYPE_BAND,
        Composer = FLAC__StreamMetadata_Picture_Type::FLAC__STREAM_METADATA_PICTURE_TYPE_COMPOSER,
        Lyricist = FLAC__StreamMetadata_Picture_Type::FLAC__STREAM_METADATA_PICTURE_TYPE_LYRICIST,
        RecordingLocation = FLAC__StreamMetadata_Picture_Type::FLAC__STREAM_METADATA_PICTURE_TYPE_RECORDING_LOCATION,
        DuringRecording = FLAC__StreamMetadata_Picture_Type::FLAC__STREAM_METADATA_PICTURE_TYPE_DURING_RECORDING,
        DuringPerformance = FLAC__StreamMetadata_Picture_Type::FLAC__STREAM_METADATA_PICTURE_TYPE_DURING_PERFORMANCE,
        VideoScreenCapture = FLAC__StreamMetadata_Picture_Type::FLAC__STREAM_METADATA_PICTURE_TYPE_VIDEO_SCREEN_CAPTURE,
        Fish = FLAC__StreamMetadata_Picture_Type::FLAC__STREAM_METADATA_PICTURE_TYPE_FISH,
        Illustration = FLAC__StreamMetadata_Picture_Type::FLAC__STREAM_METADATA_PICTURE_TYPE_ILLUSTRATION,
        BandLogo = FLAC__StreamMetadata_Picture_Type::FLAC__STREAM_METADATA_PICTURE_TYPE_BAND_LOGOTYPE,
        PublisherLogo = FLAC__StreamMetadata_Picture_Type::FLAC__STREAM_METADATA_PICTURE_TYPE_PUBLISHER_LOGOTYPE,
        Undefined = FLAC__StreamMetadata_Picture_Type::FLAC__STREAM_METADATA_PICTURE_TYPE_UNDEFINED
    };
}