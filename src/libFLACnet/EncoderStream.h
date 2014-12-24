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

		property unsigned int Channels { unsigned int get(); void set(unsigned int); }
		property bool IsValid { bool get(); }
		property bool StreamableSubset { bool get(); void set(bool value); }
		property bool Verify { bool get(); void set(bool value); }

		void SetOggSerialNumber(long serialNumber);
	};
}
