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

		property unsigned int BitsPerSample { unsigned int get(); void set(unsigned int); }
		property unsigned int BlockSize { unsigned int get(); void set(unsigned int); }
		property unsigned int Channels { unsigned int get(); void set(unsigned int); }
		property bool IsValid { bool get(); }
		property bool MidSideStereo { bool get(); void set(bool value); }
		property unsigned int SampleRate { unsigned int get(); void set(unsigned int); }
		property bool StreamableSubset { bool get(); void set(bool value); }
		property bool Verify { bool get(); void set(bool value); }

		void SetApodization(System::String^ specification);
		void SetOggSerialNumber(long serialNumber);
	};
}
