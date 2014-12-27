#include "stdafx.h"
#include "EncoderStream.h"

#include <msclr\marshal.h>
#include <FLAC\assert.h>

#include "EncoderStreamException.h"

using namespace System;
using namespace System::Runtime::InteropServices;

using namespace FLAC;

using namespace msclr::interop;

EncoderStream::EncoderStream()
	: encoder(FLAC__stream_encoder_new())
{
}

EncoderStream::~EncoderStream()
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

unsigned int EncoderStream::BitsPerSample::get()
{
	FLAC__ASSERT(this->IsValid);
	return FLAC__stream_encoder_get_bits_per_sample(this->encoder);
}

void EncoderStream::BitsPerSample::set(unsigned int value)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_bits_per_sample(this->encoder, value) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

unsigned int EncoderStream::BlockSize::get()
{
	FLAC__ASSERT(this->IsValid);
	return FLAC__stream_encoder_get_blocksize(this->encoder);
}

void EncoderStream::BlockSize::set(unsigned int value)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_blocksize(this->encoder, value) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

unsigned int EncoderStream::Channels::get()
{
	FLAC__ASSERT(this->IsValid);
	return FLAC__stream_encoder_get_channels(this->encoder);
}

void EncoderStream::Channels::set(unsigned int value)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_channels(this->encoder, value) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

bool EncoderStream::EscapeCoding::get()
{
	FLAC__ASSERT(this->IsValid);
	return FLAC__stream_encoder_get_do_escape_coding(this->encoder) != 0;
}

void EncoderStream::EscapeCoding::set(bool value)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_do_escape_coding(this->encoder, value) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

bool EncoderStream::ExhaustiveModelSearch::get()
{
	FLAC__ASSERT(this->IsValid);
	return FLAC__stream_encoder_get_do_exhaustive_model_search(this->encoder) != 0;
}

void EncoderStream::ExhaustiveModelSearch::set(bool value)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_do_exhaustive_model_search(this->encoder, value) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

bool EncoderStream::IsValid::get()
{
	return this->encoder != nullptr;
}


bool EncoderStream::LooseMidSideStereo::get()
{
	FLAC__ASSERT(this->IsValid);
	return FLAC__stream_encoder_get_loose_mid_side_stereo(this->encoder) != 0;
}

void EncoderStream::LooseMidSideStereo::set(bool value)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_loose_mid_side_stereo(this->encoder, value) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

unsigned int EncoderStream::MaxLpcOrder::get()
{
	FLAC__ASSERT(this->IsValid);
	return FLAC__stream_encoder_get_max_lpc_order(this->encoder);
}

void EncoderStream::MaxLpcOrder::set(unsigned int value)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_max_lpc_order(this->encoder, value) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

bool EncoderStream::MidSideStereo::get()
{
	FLAC__ASSERT(this->IsValid);
	return FLAC__stream_encoder_get_do_mid_side_stereo(this->encoder) != 0;
}

void EncoderStream::MidSideStereo::set(bool value)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_do_mid_side_stereo(this->encoder, value) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

unsigned int EncoderStream::ResidualPartitionOrderMinimum::get()
{
	FLAC__ASSERT(this->IsValid);
	return FLAC__stream_encoder_get_min_residual_partition_order(this->encoder);
}

void EncoderStream::ResidualPartitionOrderMinimum::set(unsigned int value)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_min_residual_partition_order(this->encoder, value) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

unsigned int EncoderStream::ResidualPartitionOrderMaximum::get()
{
	FLAC__ASSERT(this->IsValid);
	return FLAC__stream_encoder_get_max_residual_partition_order(this->encoder);
}

void EncoderStream::ResidualPartitionOrderMaximum::set(unsigned int value)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_max_residual_partition_order(this->encoder, value) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

unsigned int EncoderStream::QlpCoeffPrecision::get()
{
	FLAC__ASSERT(this->IsValid);
	return FLAC__stream_encoder_get_qlp_coeff_precision(this->encoder);
}

void EncoderStream::QlpCoeffPrecision::set(unsigned int value)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_qlp_coeff_precision(this->encoder, value) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

bool EncoderStream::QlpCoeffPrecisionSearch::get()
{
	FLAC__ASSERT(this->IsValid);
	return FLAC__stream_encoder_get_do_qlp_coeff_prec_search(this->encoder) != 0;
}

void EncoderStream::QlpCoeffPrecisionSearch::set(bool value)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_do_qlp_coeff_prec_search(this->encoder, value) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

unsigned int EncoderStream::SampleRate::get()
{
	FLAC__ASSERT(this->IsValid);
	return FLAC__stream_encoder_get_sample_rate(this->encoder);
}

void EncoderStream::SampleRate::set(unsigned int value)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_sample_rate(this->encoder, value) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

bool EncoderStream::StreamableSubset::get()
{
	FLAC__ASSERT(this->IsValid);
	return FLAC__stream_encoder_get_streamable_subset(this->encoder) != 0;
}

void EncoderStream::StreamableSubset::set(bool value)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_streamable_subset(this->encoder, value) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

unsigned long long EncoderStream::TotalSamplesEstimate::get()
{
	FLAC__ASSERT(this->IsValid);
	return FLAC__stream_encoder_get_total_samples_estimate(this->encoder) != 0;
}

void EncoderStream::TotalSamplesEstimate::set(unsigned long long value)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_total_samples_estimate(this->encoder, value) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

bool EncoderStream::Verify::get()
{
	FLAC__ASSERT(this->IsValid);
	return FLAC__stream_encoder_get_verify(this->encoder) != 0;
}

void EncoderStream::Verify::set(bool value)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_verify(this->encoder, value) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

DecoderErrorStats^ EncoderStream::GetDecoderErrorStats()
{
	return DecoderErrorStats::FromEncoder(this->encoder);
}

EncoderStreamState^ EncoderStream::GetState()
{
	FLAC__ASSERT(this->IsValid);
	return gcnew EncoderStreamState(FLAC__stream_encoder_get_state(this->encoder));
}

DecoderStreamState^ EncoderStream::GetVerifyStreamState()
{
	FLAC__ASSERT(this->IsValid);
	return gcnew DecoderStreamState(FLAC__stream_encoder_get_verify_decoder_state(this->encoder));
}

void EncoderStream::Initialize()
{
	FLAC__ASSERT(this->IsValid);

	auto writeDelegate = gcnew EncoderStreamWriteCallback(this, &EncoderStream::WriteCallback);
	this->writeHandle = GCHandle::Alloc(writeDelegate);
	IntPtr writeFp = Marshal::GetFunctionPointerForDelegate(writeDelegate);
	auto writeCallback = static_cast<FLAC__StreamEncoderWriteCallback>(writeFp.ToPointer());

	auto seekDelegate = gcnew EncoderStreamSeekCallback(this, &EncoderStream::SeekCallback);
	this->seekHandle = GCHandle::Alloc(seekDelegate);
	IntPtr seekFp = Marshal::GetFunctionPointerForDelegate(seekDelegate);
	FLAC__StreamEncoderSeekCallback seekCallback = static_cast<FLAC__StreamEncoderSeekCallback>(seekFp.ToPointer());

	auto tellDelegate = gcnew EncoderStreamTellCallback(this, &EncoderStream::TellCallback);
	this->tellHandle = GCHandle::Alloc(tellDelegate);
	IntPtr tellFp = Marshal::GetFunctionPointerForDelegate(tellDelegate);
	FLAC__StreamEncoderTellCallback tellCallback = static_cast<FLAC__StreamEncoderTellCallback>(tellFp.ToPointer());

	auto metadataDelegate = gcnew EncoderStreamMetadataCallback(this, &EncoderStream::MetadataCallback);
	this->metadataHandle = GCHandle::Alloc(metadataDelegate);
	IntPtr metadataFp = Marshal::GetFunctionPointerForDelegate(metadataDelegate);
	FLAC__StreamEncoderMetadataCallback metadataCallback = static_cast<FLAC__StreamEncoderMetadataCallback>(metadataFp.ToPointer());

	FLAC__StreamEncoderInitStatus status = FLAC__stream_encoder_init_stream(this->encoder, writeCallback, seekCallback, tellCallback, metadataCallback, nullptr);
}

void EncoderStream::MetadataCallback(const FLAC__StreamEncoder* encoder, const FLAC__StreamMetadata* metadata, void* client_data)
{
}

FLAC__StreamEncoderSeekStatus EncoderStream::SeekCallback(const FLAC__StreamEncoder* encoder, FLAC__uint64 absolute_byte_offset, void* client_data)
{
	return FLAC__StreamEncoderSeekStatus::FLAC__STREAM_ENCODER_SEEK_STATUS_OK;
}

void EncoderStream::SetApodization(String^ specification)
{
	FLAC__ASSERT(this->IsValid);

	marshal_context context;
	const char* nativeSpecification = context.marshal_as<const char*>(specification);

	if (FLAC__stream_encoder_set_apodization(this->encoder, nativeSpecification) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

void EncoderStream::SetOggSerialNumber(long serialNumber)
{
	FLAC__ASSERT(this->IsValid);
	if (FLAC__stream_encoder_set_ogg_serial_number(this->encoder, serialNumber) == 0)
	{
		throw gcnew EncoderStreamException();
	}
}

FLAC__StreamEncoderTellStatus EncoderStream::TellCallback(const FLAC__StreamEncoder* encoder, FLAC__uint64* absolute_byte_offset, void* client_data)
{
	return FLAC__StreamEncoderTellStatus::FLAC__STREAM_ENCODER_TELL_STATUS_OK;
}

FLAC__StreamEncoderWriteStatus EncoderStream::WriteCallback(const FLAC__StreamEncoder* encoder, const FLAC__byte buffer[], size_t bytes, unsigned samples, unsigned current_frame, void* client_data)
{
	return FLAC__StreamEncoderWriteStatus::FLAC__STREAM_ENCODER_WRITE_STATUS_OK;
}
