#include "stdafx.h"
#include "EncoderStream.h"

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
