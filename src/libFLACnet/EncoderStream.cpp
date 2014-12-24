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

unsigned int EncoderStream::BitsPerSample::get()
{
	FLAC__ASSERT(this->IsValid);
	return FLAC__stream_encoder_get_bits_per_sample(this->encoder);
}

void EncoderStream::BitsPerSample::set(unsigned int value)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_bits_per_sample(this->encoder, value) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

unsigned int EncoderStream::BlockSize::get()
{
	FLAC__ASSERT(this->IsValid);
	return FLAC__stream_encoder_get_blocksize(this->encoder);
}

void EncoderStream::BlockSize::set(unsigned int value)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_blocksize(this->encoder, value) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}
unsigned int EncoderStream::Channels::get()
{
	FLAC__ASSERT(this->IsValid);
	return FLAC__stream_encoder_get_channels(this->encoder);
}

void EncoderStream::Channels::set(unsigned int value)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_channels(this->encoder, value) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

bool EncoderStream::IsValid::get()
{
	return this->encoder != nullptr;
}

bool EncoderStream::MidSideStereo::get()
{
	FLAC__ASSERT(this->IsValid);
	return FLAC__stream_encoder_get_do_mid_side_stereo(this->encoder) != 0;
}

void EncoderStream::MidSideStereo::set(bool value)
{
	FLAC__ASSERT(is_valid());
	if (FLAC__stream_encoder_set_do_mid_side_stereo(this->encoder, value) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}


unsigned int EncoderStream::SampleRate::get()
{
	FLAC__ASSERT(this->IsValid);
	return FLAC__stream_encoder_get_sample_rate(this->encoder);
}

void EncoderStream::SampleRate::set(unsigned int value)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_sample_rate(this->encoder, value) == 0)
	{
		throw gcnew EncoderStreamException();
	}
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
	return FLAC__stream_encoder_get_verify(this->encoder) != 0;
}

void EncoderStream::Verify::set(bool value)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_verify(this->encoder, value) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

void EncoderStream::SetApodization(const char* specification)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_apodization(this->encoder, specification) == 0)
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
