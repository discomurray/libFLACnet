#pragma once

#include <FLAC\stream_decoder.h>

#include "DecoderStreamState.h"
#include "MetadataId.h"
#include "MetadataType.h"

namespace FLAC
{
	public ref class Decoder
	{
		FLAC__StreamDecoder* decoder;

	public:
		Decoder();
		~Decoder();

		property bool IsValid
		{
			bool get();
		}

		property bool Md5Checking
		{
			bool get();
			void set(bool value);
		}

		DecoderStreamState^ GetState();

		void SetMetadataIgnore(MetadataType type);

		void SetMetadataIgnoreAll();

		void SetMetadataIgnoreApplication(MetadataId^ id);

		void SetMetadataRespond(MetadataType type);

		void SetMetadataRespondAll();

		void SetMetadataRespondApplication(MetadataId^ id);

		void SetOggSerialNumber(long serialNumber);
	};
}
