#pragma once

#include <FLAC\stream_encoder.h>

namespace FLAC
{
	public ref class EncoderStream
	{
		FLAC__StreamEncoder* encoder;

	public:
		EncoderStream();
		~EncoderStream();
	};
}
