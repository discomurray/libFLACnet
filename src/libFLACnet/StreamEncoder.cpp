#include "stdafx.h"
#include "StreamEncoder.h"

#include <vector>

#include <msclr\marshal.h>
#include <FLAC\assert.h>

#include "EncoderStreamException.h"

using namespace System;
using namespace System::IO;
using namespace System::Runtime::InteropServices;

using namespace FLAC;

using namespace msclr::interop;

StreamEncoder::StreamEncoder(Stream^ stream)
	: encoder(FLAC__stream_encoder_new()),
	  stream(stream)
{
}

StreamEncoder::~StreamEncoder()
{
	this->metadataHandle.Free();
	this->seekHandle.Free();
	this->tellHandle.Free();
	this->writeHandle.Free();

	if (this->encoder != nullptr)
	{
		FLAC__stream_encoder_finish(this->encoder);
		FLAC__stream_encoder_delete(this->encoder);
	}
}

unsigned int StreamEncoder::BitsPerSample::get()
{
	FLAC__ASSERT(this->IsValid);
	return FLAC__stream_encoder_get_bits_per_sample(this->encoder);
}

void StreamEncoder::BitsPerSample::set(unsigned int value)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_bits_per_sample(this->encoder, value) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

unsigned int StreamEncoder::BlockSize::get()
{
	FLAC__ASSERT(this->IsValid);
	return FLAC__stream_encoder_get_blocksize(this->encoder);
}

void StreamEncoder::BlockSize::set(unsigned int value)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_blocksize(this->encoder, value) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

unsigned int StreamEncoder::Channels::get()
{
	FLAC__ASSERT(this->IsValid);
	return FLAC__stream_encoder_get_channels(this->encoder);
}

void StreamEncoder::Channels::set(unsigned int value)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_channels(this->encoder, value) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

bool StreamEncoder::EscapeCoding::get()
{
	FLAC__ASSERT(this->IsValid);
	return FLAC__stream_encoder_get_do_escape_coding(this->encoder) != 0;
}

void StreamEncoder::EscapeCoding::set(bool value)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_do_escape_coding(this->encoder, value) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

bool StreamEncoder::ExhaustiveModelSearch::get()
{
	FLAC__ASSERT(this->IsValid);
	return FLAC__stream_encoder_get_do_exhaustive_model_search(this->encoder) != 0;
}

void StreamEncoder::ExhaustiveModelSearch::set(bool value)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_do_exhaustive_model_search(this->encoder, value) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

bool StreamEncoder::IsValid::get()
{
	return this->encoder != nullptr;
}


bool StreamEncoder::LooseMidSideStereo::get()
{
	FLAC__ASSERT(this->IsValid);
	return FLAC__stream_encoder_get_loose_mid_side_stereo(this->encoder) != 0;
}

void StreamEncoder::LooseMidSideStereo::set(bool value)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_loose_mid_side_stereo(this->encoder, value) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

unsigned int StreamEncoder::MaxLpcOrder::get()
{
	FLAC__ASSERT(this->IsValid);
	return FLAC__stream_encoder_get_max_lpc_order(this->encoder);
}

void StreamEncoder::MaxLpcOrder::set(unsigned int value)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_max_lpc_order(this->encoder, value) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

bool StreamEncoder::MidSideStereo::get()
{
	FLAC__ASSERT(this->IsValid);
	return FLAC__stream_encoder_get_do_mid_side_stereo(this->encoder) != 0;
}

void StreamEncoder::MidSideStereo::set(bool value)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_do_mid_side_stereo(this->encoder, value) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

unsigned int StreamEncoder::ResidualPartitionOrderMinimum::get()
{
	FLAC__ASSERT(this->IsValid);
	return FLAC__stream_encoder_get_min_residual_partition_order(this->encoder);
}

void StreamEncoder::ResidualPartitionOrderMinimum::set(unsigned int value)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_min_residual_partition_order(this->encoder, value) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

unsigned int StreamEncoder::ResidualPartitionOrderMaximum::get()
{
	FLAC__ASSERT(this->IsValid);
	return FLAC__stream_encoder_get_max_residual_partition_order(this->encoder);
}

void StreamEncoder::ResidualPartitionOrderMaximum::set(unsigned int value)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_max_residual_partition_order(this->encoder, value) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

unsigned int StreamEncoder::QlpCoeffPrecision::get()
{
	FLAC__ASSERT(this->IsValid);
	return FLAC__stream_encoder_get_qlp_coeff_precision(this->encoder);
}

void StreamEncoder::QlpCoeffPrecision::set(unsigned int value)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_qlp_coeff_precision(this->encoder, value) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

bool StreamEncoder::QlpCoeffPrecisionSearch::get()
{
	FLAC__ASSERT(this->IsValid);
	return FLAC__stream_encoder_get_do_qlp_coeff_prec_search(this->encoder) != 0;
}

void StreamEncoder::QlpCoeffPrecisionSearch::set(bool value)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_do_qlp_coeff_prec_search(this->encoder, value) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

unsigned int StreamEncoder::SampleRate::get()
{
	FLAC__ASSERT(this->IsValid);
	return FLAC__stream_encoder_get_sample_rate(this->encoder);
}

void StreamEncoder::SampleRate::set(unsigned int value)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_sample_rate(this->encoder, value) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

bool StreamEncoder::StreamableSubset::get()
{
	FLAC__ASSERT(this->IsValid);
	return FLAC__stream_encoder_get_streamable_subset(this->encoder) != 0;
}

void StreamEncoder::StreamableSubset::set(bool value)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_streamable_subset(this->encoder, value) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

unsigned long long StreamEncoder::TotalSamplesEstimate::get()
{
	FLAC__ASSERT(this->IsValid);
	return FLAC__stream_encoder_get_total_samples_estimate(this->encoder) != 0;
}

void StreamEncoder::TotalSamplesEstimate::set(unsigned long long value)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_total_samples_estimate(this->encoder, value) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

bool StreamEncoder::Verify::get()
{
	FLAC__ASSERT(this->IsValid);
	return FLAC__stream_encoder_get_verify(this->encoder) != 0;
}

void StreamEncoder::Verify::set(bool value)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_verify(this->encoder, value) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

void StreamEncoder::Finish()
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_finish(this->encoder) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

DecoderErrorStats^ StreamEncoder::GetDecoderErrorStats()
{
	return DecoderErrorStats::FromEncoder(this->encoder);
}

EncoderStreamState^ StreamEncoder::GetState()
{
	FLAC__ASSERT(this->IsValid);
	return gcnew EncoderStreamState(FLAC__stream_encoder_get_state(this->encoder));
}

DecoderStreamState^ StreamEncoder::GetVerifyStreamState()
{
	FLAC__ASSERT(this->IsValid);
	return gcnew DecoderStreamState(FLAC__stream_encoder_get_verify_decoder_state(this->encoder));
}

void StreamEncoder::Initialize()
{
	FLAC__ASSERT(this->IsValid);

	auto writeDelegate = gcnew EncoderStreamWriteCallback(this, &StreamEncoder::WriteCallback);
	this->writeHandle = GCHandle::Alloc(writeDelegate);
	IntPtr writeFp = Marshal::GetFunctionPointerForDelegate(writeDelegate);
	auto writeCallback = static_cast<FLAC__StreamEncoderWriteCallback>(writeFp.ToPointer());

	auto seekDelegate = gcnew EncoderStreamSeekCallback(this, &StreamEncoder::SeekCallback);
	this->seekHandle = GCHandle::Alloc(seekDelegate);
	IntPtr seekFp = Marshal::GetFunctionPointerForDelegate(seekDelegate);
	FLAC__StreamEncoderSeekCallback seekCallback = static_cast<FLAC__StreamEncoderSeekCallback>(seekFp.ToPointer());

	auto tellDelegate = gcnew EncoderStreamTellCallback(this, &StreamEncoder::TellCallback);
	this->tellHandle = GCHandle::Alloc(tellDelegate);
	IntPtr tellFp = Marshal::GetFunctionPointerForDelegate(tellDelegate);
	FLAC__StreamEncoderTellCallback tellCallback = static_cast<FLAC__StreamEncoderTellCallback>(tellFp.ToPointer());

	auto metadataDelegate = gcnew EncoderStreamMetadataCallback(this, &StreamEncoder::MetadataCallback);
	this->metadataHandle = GCHandle::Alloc(metadataDelegate);
	IntPtr metadataFp = Marshal::GetFunctionPointerForDelegate(metadataDelegate);
	FLAC__StreamEncoderMetadataCallback metadataCallback = static_cast<FLAC__StreamEncoderMetadataCallback>(metadataFp.ToPointer());

	FLAC__StreamEncoderInitStatus status = FLAC__stream_encoder_init_stream(this->encoder, writeCallback, seekCallback, tellCallback, metadataCallback, nullptr);

	if (status != FLAC__StreamEncoderInitStatus::FLAC__STREAM_ENCODER_INIT_STATUS_OK)
	{
		throw gcnew EncoderStreamException();
	}
}

void StreamEncoder::InitializeOgg()
{
	FLAC__ASSERT(this->IsValid);

	auto writeDelegate = gcnew EncoderStreamWriteCallback(this, &StreamEncoder::WriteCallback);
	this->writeHandle = GCHandle::Alloc(writeDelegate);
	IntPtr writeFp = Marshal::GetFunctionPointerForDelegate(writeDelegate);
	auto writeCallback = static_cast<FLAC__StreamEncoderWriteCallback>(writeFp.ToPointer());

	auto seekDelegate = gcnew EncoderStreamSeekCallback(this, &StreamEncoder::SeekCallback);
	this->seekHandle = GCHandle::Alloc(seekDelegate);
	IntPtr seekFp = Marshal::GetFunctionPointerForDelegate(seekDelegate);
	FLAC__StreamEncoderSeekCallback seekCallback = static_cast<FLAC__StreamEncoderSeekCallback>(seekFp.ToPointer());

	auto tellDelegate = gcnew EncoderStreamTellCallback(this, &StreamEncoder::TellCallback);
	this->tellHandle = GCHandle::Alloc(tellDelegate);
	IntPtr tellFp = Marshal::GetFunctionPointerForDelegate(tellDelegate);
	FLAC__StreamEncoderTellCallback tellCallback = static_cast<FLAC__StreamEncoderTellCallback>(tellFp.ToPointer());

	auto metadataDelegate = gcnew EncoderStreamMetadataCallback(this, &StreamEncoder::MetadataCallback);
	this->metadataHandle = GCHandle::Alloc(metadataDelegate);
	IntPtr metadataFp = Marshal::GetFunctionPointerForDelegate(metadataDelegate);
	FLAC__StreamEncoderMetadataCallback metadataCallback = static_cast<FLAC__StreamEncoderMetadataCallback>(metadataFp.ToPointer());

	auto readDelegate = gcnew EncoderStreamReadCallback(this, &StreamEncoder::ReadCallback);
	this->readHandle = GCHandle::Alloc(readDelegate);
	IntPtr readFp = Marshal::GetFunctionPointerForDelegate(readDelegate);
	auto readCallback = static_cast<FLAC__StreamEncoderReadCallback>(readFp.ToPointer());

	FLAC__StreamEncoderInitStatus status = FLAC__stream_encoder_init_ogg_stream(this->encoder, readCallback, writeCallback, seekCallback, tellCallback, metadataCallback, nullptr);

	if (status != FLAC__StreamEncoderInitStatus::FLAC__STREAM_ENCODER_INIT_STATUS_OK)
	{
		throw gcnew EncoderStreamException();
	}
}

void StreamEncoder::MetadataCallback(const FLAC__StreamEncoder* encoder, const FLAC__StreamMetadata* metadata, void* client_data)
{
}

void StreamEncoder::Process(array<array<int>^>^ samples, unsigned int sampleCount)
{
	FLAC__ASSERT(this->IsValid);

	int channelCount = samples->Length;

	FLAC__int32** channels = new FLAC__int32*[channelCount];
	for (int c = 0; c < channelCount; c++)
	{
		channels[c] = new FLAC__int32[sampleCount];

		for (unsigned int s = 0; s < sampleCount; s++)
		{
			channels[c][s] = samples[c][s];
		}
	}

	try
	{
		if (FLAC__stream_encoder_process(this->encoder, channels, sampleCount) == 0)
		{
			throw gcnew EncoderStreamException();
		}
	}
	finally
	{
		for (int c = 0; c < channelCount; c++)
		{
			delete[] channels[c];
		}

		delete[] channels;
	}
}

void StreamEncoder::ProcessInterleaved(array<int>^ samples, unsigned int sampleCount)
{
	FLAC__ASSERT(this->IsValid);

	std::vector<FLAC__int32> buffer(samples->Length);
	for (int i = 0; i < samples->Length; i++)
	{
		buffer[i] = samples[i];
	}

	if (FLAC__stream_encoder_process_interleaved(this->encoder, buffer.data(), sampleCount) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

FLAC__StreamEncoderReadStatus StreamEncoder::ReadCallback(const FLAC__StreamEncoder* encoder, FLAC__byte buffer[], size_t* bytes, void* client_data)
{
	array<unsigned char>^ managedBuffer = gcnew array<unsigned char>(*bytes);

	try
	{
		int read = this->stream->Read(managedBuffer, 0, *bytes);
		if (read == 0)
		{
			return FLAC__StreamEncoderReadStatus::FLAC__STREAM_ENCODER_READ_STATUS_END_OF_STREAM;
		}

		*bytes = read;
		for (int i = 0; i < read; i++)
		{
			buffer[i] = managedBuffer[i];
		}

		return FLAC__StreamEncoderReadStatus::FLAC__STREAM_ENCODER_READ_STATUS_CONTINUE;
	}
	catch (Exception^)
	{
		return FLAC__StreamEncoderReadStatus::FLAC__STREAM_ENCODER_READ_STATUS_ABORT;
	}
}

FLAC__StreamEncoderSeekStatus StreamEncoder::SeekCallback(const FLAC__StreamEncoder* encoder, FLAC__uint64 absolute_byte_offset, void* client_data)
{
	if (!this->stream->CanSeek)
	{
		return FLAC__STREAM_ENCODER_SEEK_STATUS_UNSUPPORTED;
	}

	try
	{
		this->stream->Seek(absolute_byte_offset, SeekOrigin::Begin);
		return FLAC__StreamEncoderSeekStatus::FLAC__STREAM_ENCODER_SEEK_STATUS_OK;
	}
	catch (Exception^)
	{
		return FLAC__StreamEncoderSeekStatus::FLAC__STREAM_ENCODER_SEEK_STATUS_ERROR;
	}
}

void StreamEncoder::SetCompressionLevel(unsigned int level)
{
	FLAC__ASSERT(this->IsValid);

	if (FLAC__stream_encoder_set_compression_level(this->encoder, level) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

void StreamEncoder::SetApodization(String^ specification)
{
	FLAC__ASSERT(this->IsValid);

	marshal_context context;
	const char* nativeSpecification = context.marshal_as<const char*>(specification);

	if (FLAC__stream_encoder_set_apodization(this->encoder, nativeSpecification) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

void StreamEncoder::SetOggSerialNumber(long serialNumber)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_ogg_serial_number(this->encoder, serialNumber) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

FLAC__StreamEncoderTellStatus StreamEncoder::TellCallback(const FLAC__StreamEncoder* encoder, FLAC__uint64* absolute_byte_offset, void* client_data)
{
	try
	{
		*absolute_byte_offset = this->stream->Position;

		return FLAC__StreamEncoderTellStatus::FLAC__STREAM_ENCODER_TELL_STATUS_OK;
	}
	catch (Exception^)
	{
		return FLAC__StreamEncoderTellStatus::FLAC__STREAM_ENCODER_TELL_STATUS_ERROR;
	}
}

FLAC__StreamEncoderWriteStatus StreamEncoder::WriteCallback(const FLAC__StreamEncoder* encoder, const FLAC__byte buffer[], size_t bytes, unsigned samples, unsigned current_frame, void* client_data)
{
	array<unsigned char>^ managedBuffer = gcnew array<unsigned char>(bytes);
	for (unsigned int i = 0; i < bytes; i++)
	{
		managedBuffer[i] = buffer[i];
	}

	try
	{
		this->stream->Write(managedBuffer, 0, bytes);
	}
	catch (Exception^)
	{
		return FLAC__StreamEncoderWriteStatus::FLAC__STREAM_ENCODER_WRITE_STATUS_FATAL_ERROR;
	}

	return FLAC__StreamEncoderWriteStatus::FLAC__STREAM_ENCODER_WRITE_STATUS_OK;
}
