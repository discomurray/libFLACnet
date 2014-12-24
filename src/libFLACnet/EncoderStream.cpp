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

bool EncoderStream::StreamableSubset::get()
{
	FLAC__ASSERT(this->IsValid);
	return FLAC__stream_encoder_get_streamable_subset(this->encoder) != 0;
}

void EncoderStream::StreamableSubset::set(bool value)
{
	FLAC__ASSERT(is_valid());
	if (FLAC__stream_encoder_set_streamable_subset(this->encoder, value) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

bool EncoderStream::Verify::get()
{
	FLAC__ASSERT(this->IsValid);
	return FLAC__stream_encoder_get_verify(this->encoder);
}

void EncoderStream::Verify::set(bool value)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_verify(this->encoder, value) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

void EncoderStream::SetOggSerialNumber(long serialNumber)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_ogg_serial_number(this->encoder, serialNumber) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}
