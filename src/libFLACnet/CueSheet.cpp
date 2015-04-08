#include "stdafx.h"
#include "CueSheet.h"

using namespace FLAC;

CueSheet::CueSheet()
{
    this->mediaCatalogNumber = gcnew array<wchar_t>(129);
}

array<wchar_t>^ CueSheet::MediaCatalogNumber::get()
{
    return this->mediaCatalogNumber;
}
