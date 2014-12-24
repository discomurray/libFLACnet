#pragma once

#include <FLAC\stream_decoder.h>

namespace FLAC
{
	public ref class DecoderStreamState
	{
		FLAC__StreamDecoderState state;

	internal:
		DecoderStreamState(FLAC__StreamDecoderState state);
	};
}
