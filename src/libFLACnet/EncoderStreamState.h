#pragma once

#include <FLAC\stream_encoder.h>

namespace FLAC
{
	public ref class EncoderStreamState
	{
		FLAC__StreamEncoderState state;

	internal:
		EncoderStreamState(FLAC__StreamEncoderState state);
	};
}
