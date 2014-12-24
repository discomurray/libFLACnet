#include "stdafx.h"
#include "DecoderStream.h"

#include <FLAC\assert.h>

#include "DecoderStreamException.h"

using namespace FLAC;

DecoderStream::DecoderStream()
	: decoder(FLAC__stream_decoder_new())
{
}

DecoderStream::~DecoderStream()
{
	if (this->decoder != nullptr)
	{
		FLAC__stream_decoder_finish(this->decoder);
		FLAC__stream_decoder_delete(this->decoder);
	}
}

bool DecoderStream::IsValid::get()
{
	return this->decoder != nullptr;
}

void DecoderStream::SetOggSerialNumber(long serialNumber)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_decoder_set_ogg_serial_number(this->decoder, serialNumber) != 0)
	{
		throw gcnew DecoderStreamException();
	}
}
