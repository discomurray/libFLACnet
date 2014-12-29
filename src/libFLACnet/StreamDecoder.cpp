#include "stdafx.h"
#include "StreamDecoder.h"

#include <FLAC\assert.h>

#include "DecoderStreamException.h"

using namespace System;
using namespace System::Runtime::InteropServices;

using namespace FLAC;

StreamDecoder::StreamDecoder()
	: decoder(FLAC__stream_decoder_new())
{
}

StreamDecoder::~StreamDecoder()
{
	this->readHandle.Free();
	this->seekHandle.Free();
	this->tellHandle.Free();
	this->lengthHandle.Free();
	this->eofHandle.Free();
	this->writeHandle.Free();
	this->metadataHandle.Free();
	this->errorHandle.Free();

	if (this->decoder != nullptr)
	{
		FLAC__stream_decoder_finish(this->decoder);
		FLAC__stream_decoder_delete(this->decoder);
	}
}

unsigned int StreamDecoder::BitsPerSample::get()
{
	FLAC__ASSERT(this->IsValid);

	return FLAC__stream_decoder_get_bits_per_sample(this->decoder);
}

unsigned int StreamDecoder::BlockSize::get()
{
	FLAC__ASSERT(this->IsValid);

	return FLAC__stream_decoder_get_blocksize(this->decoder);
}

ChannelAssignment StreamDecoder::ChannelAssignment::get()
{
	FLAC__ASSERT(this->IsValid);

	return static_cast<FLAC::ChannelAssignment>(FLAC__stream_decoder_get_channel_assignment(this->decoder));
}

unsigned int StreamDecoder::Channels::get()
{
	FLAC__ASSERT(this->IsValid);

	return FLAC__stream_decoder_get_channels(this->decoder);
}

bool StreamDecoder::IsValid::get()
{
	return this->decoder != nullptr;
}

bool StreamDecoder::Md5Checking::get()
{
	FLAC__ASSERT(this->IsValid);

	return FLAC__stream_decoder_get_md5_checking(this->decoder) != 0;
}

void StreamDecoder::Md5Checking::set(bool value)
{
	FLAC__ASSERT(this->IsValid);

	if (FLAC__stream_decoder_set_md5_checking(this->decoder, value) == 0)
	{
		throw gcnew DecoderStreamException();
	}
}

unsigned int StreamDecoder::SampleRate::get()
{
	FLAC__ASSERT(this->IsValid);

	return FLAC__stream_decoder_get_sample_rate(this->decoder);
}

unsigned long long StreamDecoder::TotalSamples::get()
{
	FLAC__ASSERT(this->IsValid);

	return FLAC__stream_decoder_get_total_samples(this->decoder);
}

FLAC__bool StreamDecoder::Eof(const FLAC__StreamDecoder* decoder, void* client_data)
{
	return 0;
}
void StreamDecoder::Error(const FLAC__StreamDecoder* decoder, FLAC__StreamDecoderErrorStatus status, void* client_data)
{

}

unsigned long long StreamDecoder::GetDecodePosition()
{
	FLAC__ASSERT(this->IsValid);

	FLAC__uint64 position;
	if (FLAC__stream_decoder_get_decode_position(this->decoder, &position) == 0)
	{
		throw gcnew DecoderStreamException();
	}

	return position;
}

DecoderStreamState^ StreamDecoder::GetState()
{
	FLAC__ASSERT(this->IsValid);

	return gcnew DecoderStreamState(FLAC__stream_decoder_get_state(this->decoder));
}

void StreamDecoder::Initialize()
{
	FLAC__ASSERT(this->IsValid);

	auto readDelegate = gcnew StreamDecoderRead(this, &StreamDecoder::Read);
	this->readHandle = GCHandle::Alloc(readDelegate);
	IntPtr readFp = Marshal::GetFunctionPointerForDelegate(readDelegate);
	auto readCallback = static_cast<FLAC__StreamDecoderReadCallback>(readFp.ToPointer());

	auto seekDelegate = gcnew StreamDecoderSeek(this, &StreamDecoder::Seek);
	this->seekHandle = GCHandle::Alloc(seekDelegate);
	IntPtr seekFp = Marshal::GetFunctionPointerForDelegate(seekDelegate);
	auto seekCallback = static_cast<FLAC__StreamDecoderSeekCallback>(seekFp.ToPointer());

	auto tellDelegate = gcnew StreamDecoderTell(this, &StreamDecoder::Tell);
	this->tellHandle = GCHandle::Alloc(tellDelegate);
	IntPtr tellFp = Marshal::GetFunctionPointerForDelegate(tellDelegate);
	auto tellCallback = static_cast<FLAC__StreamDecoderTellCallback>(tellFp.ToPointer());

	auto lengthDelegate = gcnew StreamDecoderLength(this, &StreamDecoder::Length);
	this->lengthHandle = GCHandle::Alloc(lengthDelegate);
	IntPtr lengthFp = Marshal::GetFunctionPointerForDelegate(lengthDelegate);
	auto lengthCallback = static_cast<FLAC__StreamDecoderLengthCallback>(lengthFp.ToPointer());

	auto eofDelegate = gcnew StreamDecoderEof(this, &StreamDecoder::Eof);
	this->eofHandle = GCHandle::Alloc(eofDelegate);
	IntPtr eofFp = Marshal::GetFunctionPointerForDelegate(eofDelegate);
	auto eofCallback = static_cast<FLAC__StreamDecoderEofCallback>(eofFp.ToPointer());

	auto writeDelegate = gcnew StreamDecoderWrite(this, &StreamDecoder::Write);
	this->writeHandle = GCHandle::Alloc(writeDelegate);
	IntPtr writeFp = Marshal::GetFunctionPointerForDelegate(writeDelegate);
	auto writeCallback = static_cast<FLAC__StreamDecoderWriteCallback>(writeFp.ToPointer());

	auto metadataDelegate = gcnew StreamDecoderMetadata(this, &StreamDecoder::Metadata);
	this->metadataHandle = GCHandle::Alloc(metadataDelegate);
	IntPtr metadataFp = Marshal::GetFunctionPointerForDelegate(metadataDelegate);
	auto metadataCallback = static_cast<FLAC__StreamDecoderMetadataCallback>(metadataFp.ToPointer());

	auto errorDelegate = gcnew StreamDecoderError(this, &StreamDecoder::Error);
	this->errorHandle = GCHandle::Alloc(errorDelegate);
	IntPtr errorFp = Marshal::GetFunctionPointerForDelegate(errorDelegate);
	auto errorCallback = static_cast<FLAC__StreamDecoderErrorCallback>(errorFp.ToPointer());

	FLAC__StreamDecoderInitStatus status = FLAC__stream_decoder_init_stream(
		this->decoder,
		readCallback,
		seekCallback,
		tellCallback,
		lengthCallback,
		eofCallback,
		writeCallback,
		metadataCallback,
		errorCallback,
		nullptr);

	if (status != FLAC__StreamDecoderInitStatus::FLAC__STREAM_DECODER_INIT_STATUS_OK)
	{
		throw gcnew DecoderStreamException();
	}
}

void StreamDecoder::InitializeOgg()
{
	FLAC__ASSERT(this->IsValid);

	auto readDelegate = gcnew StreamDecoderRead(this, &StreamDecoder::Read);
	this->readHandle = GCHandle::Alloc(readDelegate);
	IntPtr readFp = Marshal::GetFunctionPointerForDelegate(readDelegate);
	auto readCallback = static_cast<FLAC__StreamDecoderReadCallback>(readFp.ToPointer());

	auto seekDelegate = gcnew StreamDecoderSeek(this, &StreamDecoder::Seek);
	this->seekHandle = GCHandle::Alloc(seekDelegate);
	IntPtr seekFp = Marshal::GetFunctionPointerForDelegate(seekDelegate);
	auto seekCallback = static_cast<FLAC__StreamDecoderSeekCallback>(seekFp.ToPointer());

	auto tellDelegate = gcnew StreamDecoderTell(this, &StreamDecoder::Tell);
	this->tellHandle = GCHandle::Alloc(tellDelegate);
	IntPtr tellFp = Marshal::GetFunctionPointerForDelegate(tellDelegate);
	auto tellCallback = static_cast<FLAC__StreamDecoderTellCallback>(tellFp.ToPointer());

	auto lengthDelegate = gcnew StreamDecoderLength(this, &StreamDecoder::Length);
	this->lengthHandle = GCHandle::Alloc(lengthDelegate);
	IntPtr lengthFp = Marshal::GetFunctionPointerForDelegate(lengthDelegate);
	auto lengthCallback = static_cast<FLAC__StreamDecoderLengthCallback>(lengthFp.ToPointer());

	auto eofDelegate = gcnew StreamDecoderEof(this, &StreamDecoder::Eof);
	this->eofHandle = GCHandle::Alloc(eofDelegate);
	IntPtr eofFp = Marshal::GetFunctionPointerForDelegate(eofDelegate);
	auto eofCallback = static_cast<FLAC__StreamDecoderEofCallback>(eofFp.ToPointer());

	auto writeDelegate = gcnew StreamDecoderWrite(this, &StreamDecoder::Write);
	this->writeHandle = GCHandle::Alloc(writeDelegate);
	IntPtr writeFp = Marshal::GetFunctionPointerForDelegate(writeDelegate);
	auto writeCallback = static_cast<FLAC__StreamDecoderWriteCallback>(writeFp.ToPointer());

	auto metadataDelegate = gcnew StreamDecoderMetadata(this, &StreamDecoder::Metadata);
	this->metadataHandle = GCHandle::Alloc(metadataDelegate);
	IntPtr metadataFp = Marshal::GetFunctionPointerForDelegate(metadataDelegate);
	auto metadataCallback = static_cast<FLAC__StreamDecoderMetadataCallback>(metadataFp.ToPointer());

	auto errorDelegate = gcnew StreamDecoderError(this, &StreamDecoder::Error);
	this->errorHandle = GCHandle::Alloc(errorDelegate);
	IntPtr errorFp = Marshal::GetFunctionPointerForDelegate(errorDelegate);
	auto errorCallback = static_cast<FLAC__StreamDecoderErrorCallback>(errorFp.ToPointer());

	FLAC__StreamDecoderInitStatus status = FLAC__stream_decoder_init_ogg_stream(
		this->decoder,
		readCallback,
		seekCallback,
		tellCallback,
		lengthCallback,
		eofCallback,
		writeCallback,
		metadataCallback,
		errorCallback,
		nullptr);

	if (status != FLAC__StreamDecoderInitStatus::FLAC__STREAM_DECODER_INIT_STATUS_OK)
	{
		throw gcnew DecoderStreamException();
	}
}

FLAC__StreamDecoderLengthStatus StreamDecoder::Length(const FLAC__StreamDecoder* decoder, FLAC__uint64* stream_length, void* client_data)
{
	return FLAC__StreamDecoderLengthStatus::FLAC__STREAM_DECODER_LENGTH_STATUS_OK;
}

void StreamDecoder::Finish()
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_decoder_finish(this->decoder) == 0)
	{
		throw gcnew DecoderStreamException();
	}
}

void StreamDecoder::Flush()
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_decoder_flush(this->decoder) == 0)
	{
		throw gcnew DecoderStreamException();
	}
}

void StreamDecoder::Metadata(const FLAC__StreamDecoder* decoder, const FLAC__StreamMetadata* metadata, void* client_data)
{
}

void StreamDecoder::ProcessSingle()
{
	FLAC__ASSERT(this->IsValid);

	if (FLAC__stream_decoder_process_single(this->decoder) == 0)
	{
		throw gcnew DecoderStreamException();
	}
}

void StreamDecoder::ProcessUntilEndOfMetadata()
{
	FLAC__ASSERT(this->IsValid);

	if (FLAC__stream_decoder_process_until_end_of_metadata(this->decoder) == 0)
	{
		throw gcnew DecoderStreamException();
	}
}

void StreamDecoder::ProcessUntilEndOfStream()
{
	FLAC__ASSERT(this->IsValid);

	if (FLAC__stream_decoder_process_until_end_of_stream(this->decoder) == 0)
	{
		throw gcnew DecoderStreamException();
	}
}

FLAC__StreamDecoderReadStatus StreamDecoder::Read(const FLAC__StreamDecoder* decoder, FLAC__byte buffer[], size_t* bytes, void* client_data)
{
	return FLAC__StreamDecoderReadStatus::FLAC__STREAM_DECODER_READ_STATUS_CONTINUE;
}

void StreamDecoder::Reset()
{
	FLAC__ASSERT(this->IsValid);

	if (FLAC__stream_decoder_reset(this->decoder) == 0)
	{
		throw gcnew DecoderStreamException();
	}
}

FLAC__StreamDecoderSeekStatus StreamDecoder::Seek(const FLAC__StreamDecoder* decoder, FLAC__uint64 absolute_byte_offset, void* client_data)
{
	return FLAC__StreamDecoderSeekStatus::FLAC__STREAM_DECODER_SEEK_STATUS_OK;
}

void StreamDecoder::SetMetadataIgnore(MetadataType type)
{
	FLAC__ASSERT(this->IsValid);

	if (FLAC__stream_decoder_set_metadata_ignore(this->decoder, static_cast<FLAC__MetadataType>(type)) == 0)
	{
		throw gcnew DecoderStreamException();
	}
}

void StreamDecoder::SetMetadataIgnoreAll()
{
	FLAC__ASSERT(this->IsValid);

	if (FLAC__stream_decoder_set_metadata_ignore_all(this->decoder) == 0)
	{
		throw gcnew DecoderStreamException();
	}
}

void StreamDecoder::SetMetadataIgnoreApplication(MetadataId^ id)
{
	FLAC__ASSERT(this->IsValid);

	FLAC__byte flacId[4] = { id->byte1, id->byte2, id->byte3, id->byte4 };

	if (FLAC__stream_decoder_set_metadata_ignore_application(this->decoder, flacId) == 0)
	{
		throw gcnew DecoderStreamException();
	}
}

void StreamDecoder::SetMetadataRespond(MetadataType type)
{
	FLAC__ASSERT(this->IsValid);

	if (FLAC__stream_decoder_set_metadata_respond(this->decoder, static_cast<FLAC__MetadataType>(type)) == 0)
	{
		throw gcnew DecoderStreamException();
	}
}

void StreamDecoder::SetMetadataRespondAll()
{
	FLAC__ASSERT(this->IsValid);

	if (FLAC__stream_decoder_set_metadata_respond_all(this->decoder) == 0)
	{
		throw gcnew DecoderStreamException();
	}
}

void StreamDecoder::SetMetadataRespondApplication(MetadataId^ id)
{
	FLAC__ASSERT(this->IsValid);

	FLAC__byte flacId[4] = { id->byte1, id->byte2, id->byte3, id->byte4 };

	if (FLAC__stream_decoder_set_metadata_respond_application(this->decoder, flacId) == 0)
	{
		throw gcnew DecoderStreamException();
	}
}

void StreamDecoder::SetOggSerialNumber(long serialNumber)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_decoder_set_ogg_serial_number(this->decoder, serialNumber) == 0)
	{
		throw gcnew DecoderStreamException();
	}
}

FLAC__StreamDecoderTellStatus StreamDecoder::Tell(const FLAC__StreamDecoder* decoder, FLAC__uint64* absolute_byte_offset, void* client_data)
{
	return FLAC__StreamDecoderTellStatus::FLAC__STREAM_DECODER_TELL_STATUS_OK;
}

FLAC__StreamDecoderWriteStatus StreamDecoder::Write(const FLAC__StreamDecoder* decoder, const FLAC__Frame* frame, const FLAC__int32* const buffer[], void* client_data)
{
	return FLAC__StreamDecoderWriteStatus::FLAC__STREAM_DECODER_WRITE_STATUS_CONTINUE;
}