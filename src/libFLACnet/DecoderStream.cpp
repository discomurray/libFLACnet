#include "stdafx.h"
#include "DecoderStream.h"

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
