#include "stdafx.h"
#include "Decoder.h"

#include <FLAC\assert.h>

#include "DecoderStreamException.h"

using namespace FLAC;

Decoder::Decoder()
	: decoder(FLAC__stream_decoder_new())
{
}

Decoder::~Decoder()
{
	if (this->decoder != nullptr)
	{
		FLAC__stream_decoder_finish(this->decoder);
		FLAC__stream_decoder_delete(this->decoder);
	}
}

unsigned int Decoder::BitsPerSample::get()
{
	FLAC__ASSERT(this->IsValid);

	return FLAC__stream_decoder_get_bits_per_sample(this->decoder);
}

ChannelAssignment Decoder::ChannelAssignment::get()
{
	FLAC__ASSERT(this->IsValid);

	return static_cast<FLAC::ChannelAssignment>(FLAC__stream_decoder_get_channel_assignment(this->decoder));
}

unsigned int Decoder::Channels::get()
{
	FLAC__ASSERT(this->IsValid);

	return FLAC__stream_decoder_get_channels(this->decoder);
}

bool Decoder::IsValid::get()
{
	return this->decoder != nullptr;
}

bool Decoder::Md5Checking::get()
{
	FLAC__ASSERT(this->IsValid);

	return FLAC__stream_decoder_get_md5_checking(this->decoder) != 0;
}

void Decoder::Md5Checking::set(bool value)
{
	FLAC__ASSERT(this->IsValid);

	if (FLAC__stream_decoder_set_md5_checking(this->decoder, value) == 0)
	{
		throw gcnew DecoderStreamException();
	}
}

unsigned long long Decoder::TotalSamples::get()
{
	FLAC__ASSERT(this->IsValid);

	return FLAC__stream_decoder_get_total_samples(this->decoder);
}

DecoderStreamState^ Decoder::GetState()
{
	FLAC__ASSERT(this->IsValid);

	return gcnew DecoderStreamState(FLAC__stream_decoder_get_state(this->decoder));
}

void Decoder::SetMetadataIgnore(MetadataType type)
{
	FLAC__ASSERT(this->IsValid);

	if (FLAC__stream_decoder_set_metadata_ignore(this->decoder, static_cast<FLAC__MetadataType>(type)) == 0)
	{
		throw gcnew DecoderStreamException();
	}
}

void Decoder::SetMetadataIgnoreAll()
{
	FLAC__ASSERT(this->IsValid);

	if (FLAC__stream_decoder_set_metadata_ignore_all(this->decoder) == 0)
	{
		throw gcnew DecoderStreamException();
	}
}

void Decoder::SetMetadataIgnoreApplication(MetadataId^ id)
{
	FLAC__ASSERT(this->IsValid);

	FLAC__byte flacId[4] = { id->byte1, id->byte2, id->byte3, id->byte4 };

	if (FLAC__stream_decoder_set_metadata_ignore_application(this->decoder, flacId) == 0)
	{
		throw gcnew DecoderStreamException();
	}
}

void Decoder::SetMetadataRespond(MetadataType type)
{
	FLAC__ASSERT(this->IsValid);

	if (FLAC__stream_decoder_set_metadata_respond(this->decoder, static_cast<FLAC__MetadataType>(type)) == 0)
	{
		throw gcnew DecoderStreamException();
	}
}

void Decoder::SetMetadataRespondAll()
{
	FLAC__ASSERT(this->IsValid);

	if (FLAC__stream_decoder_set_metadata_respond_all(this->decoder) == 0)
	{
		throw gcnew DecoderStreamException();
	}
}

void Decoder::SetMetadataRespondApplication(MetadataId^ id)
{
	FLAC__ASSERT(this->IsValid);

	FLAC__byte flacId[4] = { id->byte1, id->byte2, id->byte3, id->byte4 };

	if (FLAC__stream_decoder_set_metadata_respond_application(this->decoder, flacId) == 0)
	{
		throw gcnew DecoderStreamException();
	}
}

void Decoder::SetOggSerialNumber(long serialNumber)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_decoder_set_ogg_serial_number(this->decoder, serialNumber) == 0)
	{
		throw gcnew DecoderStreamException();
	}
}
