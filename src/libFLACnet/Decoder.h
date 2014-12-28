#pragma once

#include <FLAC\stream_decoder.h>

namespace FLAC
{
	public ref class Decoder
	{
		FLAC__StreamDecoder* decoder;

	public:
		Decoder();
		~Decoder();

		property bool IsValid { bool get(); }

		void SetOggSerialNumber(long serialNumber);
	};
}
