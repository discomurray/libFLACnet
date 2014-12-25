#pragma once

#include <FLAC\stream_encoder.h>

namespace FLAC
{
	public ref class DecoderErrorStats
	{
		unsigned long long absoluteSample;
		unsigned int frameNumber;
		unsigned int channel;
		unsigned int sample;
		int expected;
		int got;

		DecoderErrorStats();

	public:
		property unsigned long long AbsoluteSample
		{
			unsigned long long get();
		}

		property unsigned int FrameNumber
		{
			unsigned int get();
		}

		property unsigned int Channel
		{
			unsigned int get();
		}

		property unsigned int Sample
		{
			unsigned int get();
		}

		property int Expected
		{
			int get();
		}

		property int Got
		{
			int get();
		}

	internal:
		static DecoderErrorStats^ FromEncoder(FLAC__StreamEncoder* encoder);
	};
}
