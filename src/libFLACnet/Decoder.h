#pragma once

#include <FLAC\stream_decoder.h>

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

		void SetMetadataIgnore(MetadataType type);

		void SetMetadataRespond(MetadataType type);

		void SetMetadataRespondAll();

		void SetMetadataRespondApplication(MetadataId^ id);

		void SetOggSerialNumber(long serialNumber);
	};
}
