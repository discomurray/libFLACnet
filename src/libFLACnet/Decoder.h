#pragma once

#include <FLAC\stream_decoder.h>

#include "ChannelAssignment.h"
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

		property unsigned int BitsPerSample
		{
			unsigned int get();
		}

		property unsigned int BlockSize
		{
			unsigned int get();
		}

		property ChannelAssignment ChannelAssignment
		{
			FLAC::ChannelAssignment get();
		}

		property unsigned int Channels
		{
			unsigned int get();
		}

		property bool IsValid
		{
			bool get();
		}

		property bool Md5Checking
		{
			bool get();
			void set(bool value);
		}

		property unsigned int SampleRate
		{
			unsigned int get();
		}

		property unsigned long long TotalSamples
		{
			unsigned long long get();
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
