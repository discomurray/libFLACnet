#include "stdafx.h"
#include "StreamInfo.h"

#include <FLAC\format.h>

using namespace FLAC;

StreamInfo::StreamInfo()
{
    this->Type = MetadataType::StreamInfo;
    this->Md5Sum = gcnew array<unsigned char>(16);
}
