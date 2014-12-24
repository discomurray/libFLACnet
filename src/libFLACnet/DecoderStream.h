#pragma once

#include <FLAC\stream_decoder.h>

namespace FLAC
{
	public ref class DecoderStream
	{
		FLAC__StreamDecoder* decoder;

	public:
		DecoderStream();
		~DecoderStream();
	};
}
