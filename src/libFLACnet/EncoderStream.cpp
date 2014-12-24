#include "stdafx.h"
#include "EncoderStream.h"

#include <FLAC\assert.h>

#include "EncoderStreamException.h"

using namespace FLAC;

EncoderStream::EncoderStream()
	: encoder(FLAC__stream_encoder_new())
{
}

EncoderStream::~EncoderStream()
{
	if (this->encoder != nullptr)
	{
		FLAC__stream_encoder_finish(this->encoder);
		FLAC__stream_encoder_delete(this->encoder);
	}
}

bool EncoderStream::IsValid::get()
{
	return this->encoder != nullptr;
}

void EncoderStream::SetOggSerialNumber(long serialNumber)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_ogg_serial_number(this->encoder, serialNumber) != 0)
	{
		throw gcnew EncoderStreamException();
	}
}
