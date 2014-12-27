#pragma once

#include <FLAC\stream_encoder.h>

#include "DecoderErrorStats.h"
#include "DecoderStreamState.h"
#include "EncoderStreamState.h"

namespace FLAC
{
	[System::Runtime::InteropServices::UnmanagedFunctionPointer(System::Runtime::InteropServices::CallingConvention::Cdecl)]
	private delegate FLAC__StreamEncoderWriteStatus EncoderStreamWriteCallback(const FLAC__StreamEncoder* encoder, const FLAC__byte buffer[], size_t bytes, unsigned samples, unsigned current_frame, void* client_data);

	[System::Runtime::InteropServices::UnmanagedFunctionPointer(System::Runtime::InteropServices::CallingConvention::Cdecl)]
	private delegate FLAC__StreamEncoderSeekStatus EncoderStreamSeekCallback(const FLAC__StreamEncoder* encoder, FLAC__uint64 absolute_byte_offset, void* client_data);

	[System::Runtime::InteropServices::UnmanagedFunctionPointer(System::Runtime::InteropServices::CallingConvention::Cdecl)]
	private delegate FLAC__StreamEncoderTellStatus EncoderStreamTellCallback(const FLAC__StreamEncoder* encoder, FLAC__uint64* absolute_byte_offset, void* client_data);

	[System::Runtime::InteropServices::UnmanagedFunctionPointer(System::Runtime::InteropServices::CallingConvention::Cdecl)]
	private delegate void EncoderStreamMetadataCallback(const FLAC__StreamEncoder* encoder, const FLAC__StreamMetadata* metadata, void* client_data);

	public ref class EncoderStream
	{
		FLAC__StreamEncoder* encoder;

		System::Runtime::InteropServices::GCHandle metadataHandle;

		System::Runtime::InteropServices::GCHandle seekHandle;

		System::Runtime::InteropServices::GCHandle tellHandle;

		System::Runtime::InteropServices::GCHandle writeHandle;

	public:
		EncoderStream();

		~EncoderStream();

		property unsigned int BitsPerSample
		{
			unsigned int get();
			void set(unsigned int value);
		}

		property unsigned int BlockSize
		{
			unsigned int get();
			void set(unsigned int value);
		}

		property unsigned int Channels
		{
			unsigned int get();
			void set(unsigned int value);
		}

		property bool EscapeCoding
		{
			bool get();
			void set(bool value);
		}

		property bool ExhaustiveModelSearch
		{
			bool get();
			void set(bool value);
		}

		property bool IsValid
		{
			bool get();
		}

		property bool LooseMidSideStereo
		{
			bool get();
			void set(bool value);
		}

		property unsigned int MaxLpcOrder
		{
			unsigned int get();
			void set(unsigned int value);
		}

		property bool MidSideStereo
		{
			bool get();
			void set(bool value);
		}

		property unsigned int QlpCoeffPrecision
		{
			unsigned int get();
			void set(unsigned int value);
		}

		property bool QlpCoeffPrecisionSearch
		{
			bool get();
			void set(bool value);
		}

		property unsigned int ResidualPartitionOrderMinimum
		{
			unsigned int get();
			void set(unsigned int value);
		}

		property unsigned int ResidualPartitionOrderMaximum
		{
			unsigned int get();
			void set(unsigned int value);
		}

		property unsigned int SampleRate
		{
			unsigned int get();
			void set(unsigned int);
		}

		property bool StreamableSubset
		{
			bool get();
			void set(bool value);
		}

		property unsigned long long TotalSamplesEstimate
		{
			unsigned long long get();
			void set(unsigned long long value);
		}

		property bool Verify
		{
			bool get();
			void set(bool value);
		}

		void Finish();

		DecoderErrorStats^ GetDecoderErrorStats();

		EncoderStreamState^ GetState();

		DecoderStreamState^ GetVerifyStreamState();

		void Initialize();

		void Process(array<array<int>^>^ samples, unsigned int sampleCount);

		void ProcessInterleaved(array<int>^ samples, unsigned int sampleCount);

		void SetApodization(System::String^ specification);

		void SetOggSerialNumber(long serialNumber);

	private:
		void MetadataCallback(const FLAC__StreamEncoder* encoder, const FLAC__StreamMetadata* metadata, void* client_data);

		FLAC__StreamEncoderSeekStatus SeekCallback(const FLAC__StreamEncoder* encoder, FLAC__uint64 absolute_byte_offset, void* client_data);

		FLAC__StreamEncoderTellStatus TellCallback(const FLAC__StreamEncoder* encoder, FLAC__uint64* absolute_byte_offset, void* client_data);
				
		FLAC__StreamEncoderWriteStatus WriteCallback(const FLAC__StreamEncoder* encoder, const FLAC__byte buffer[], size_t bytes, unsigned samples, unsigned current_frame, void* client_data);
	};
}
