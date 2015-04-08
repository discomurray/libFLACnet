#include "stdafx.h"
#include "SeekTable.h"

#include <FLAC\format.h>

using namespace FLAC;

SeekTable::SeekTable()
{
    this->Type = MetadataType::SeekTable;
    this->Points = gcnew array<SeekPoint^>(0);
}
