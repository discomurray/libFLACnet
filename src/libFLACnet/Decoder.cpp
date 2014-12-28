#include "stdafx.h"
#include "Decoder.h"

#include <FLAC\assert.h>

#include "DecoderStreamException.h"

using namespace FLAC;

Decoder::Decoder()
	: decoder(FLAC__stream_decoder_new())
{
}

Decoder::~Decoder()
{
	if (this->decoder != nullptr)
	{
		FLAC__stream_decoder_finish(this->decoder);
		FLAC__stream_decoder_delete(this->decoder);
	}
}

bool Decoder::IsValid::get()
{
	return this->decoder != nullptr;
}

bool Decoder::Md5Checking::get()
{
	FLAC__ASSERT(this->IsValid);

	return FLAC__stream_decoder_get_md5_checking(this->decoder) != 0;
}

void Decoder::Md5Checking::set(bool value)
{
	FLAC__ASSERT(this->IsValid);

	if (FLAC__stream_decoder_set_md5_checking(this->decoder, value) == 0)
	{
		throw gcnew DecoderStreamException();
	}
}

void Decoder::SetOggSerialNumber(long serialNumber)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_decoder_set_ogg_serial_number(this->decoder, serialNumber) == 0)
	{
		throw gcnew DecoderStreamException();
	}
}
