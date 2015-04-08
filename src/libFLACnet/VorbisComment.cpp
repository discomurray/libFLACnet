#include "stdafx.h"
#include "VorbisComment.h"

#include "MetadataType.h"

using namespace FLAC;

VorbisComment::VorbisComment()
{
    this->Type = MetadataType::VorbisComment;
}
