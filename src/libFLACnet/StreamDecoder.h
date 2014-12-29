#pragma once

#include <FLAC\stream_decoder.h>

#include "ChannelAssignment.h"
#include "DecoderStreamState.h"
#include "MetadataId.h"
#include "MetadataType.h"

namespace FLAC
{
	[System::Runtime::InteropServices::UnmanagedFunctionPointer(System::Runtime::InteropServices::CallingConvention::Cdecl)]
	public delegate FLAC__StreamDecoderReadStatus StreamDecoderRead(const FLAC__StreamDecoder* decoder, FLAC__byte buffer[], size_t* bytes, void* client_data);

	[System::Runtime::InteropServices::UnmanagedFunctionPointer(System::Runtime::InteropServices::CallingConvention::Cdecl)]
	public delegate FLAC__StreamDecoderSeekStatus StreamDecoderSeek(const FLAC__StreamDecoder* decoder, FLAC__uint64 absolute_byte_offset, void* client_data);

	[System::Runtime::InteropServices::UnmanagedFunctionPointer(System::Runtime::InteropServices::CallingConvention::Cdecl)]
	public delegate FLAC__StreamDecoderTellStatus StreamDecoderTell(const FLAC__StreamDecoder* decoder, FLAC__uint64* absolute_byte_offset, void* client_data);

	[System::Runtime::InteropServices::UnmanagedFunctionPointer(System::Runtime::InteropServices::CallingConvention::Cdecl)]
	public delegate FLAC__StreamDecoderLengthStatus StreamDecoderLength(const FLAC__StreamDecoder* decoder, FLAC__uint64* stream_length, void* client_data);

	[System::Runtime::InteropServices::UnmanagedFunctionPointer(System::Runtime::InteropServices::CallingConvention::Cdecl)]
	public delegate FLAC__bool StreamDecoderEof(const FLAC__StreamDecoder* decoder, void* client_data);

	[System::Runtime::InteropServices::UnmanagedFunctionPointer(System::Runtime::InteropServices::CallingConvention::Cdecl)]
	public delegate FLAC__StreamDecoderWriteStatus StreamDecoderWrite(const FLAC__StreamDecoder* decoder, const FLAC__Frame* frame, const FLAC__int32* const buffer[], void* client_data);

	[System::Runtime::InteropServices::UnmanagedFunctionPointer(System::Runtime::InteropServices::CallingConvention::Cdecl)]
	public delegate void StreamDecoderMetadata(const FLAC__StreamDecoder* decoder, const FLAC__StreamMetadata* metadata, void* client_data);

	[System::Runtime::InteropServices::UnmanagedFunctionPointer(System::Runtime::InteropServices::CallingConvention::Cdecl)]
	public delegate void StreamDecoderError(const FLAC__StreamDecoder* decoder, FLAC__StreamDecoderErrorStatus status, void* client_data);

	public ref class StreamDecoder
	{
		FLAC__StreamDecoder* decoder;

		System::Runtime::InteropServices::GCHandle readHandle;

		System::Runtime::InteropServices::GCHandle seekHandle;

		System::Runtime::InteropServices::GCHandle tellHandle;

		System::Runtime::InteropServices::GCHandle lengthHandle;

		System::Runtime::InteropServices::GCHandle eofHandle;

		System::Runtime::InteropServices::GCHandle writeHandle;

		System::Runtime::InteropServices::GCHandle metadataHandle;

		System::Runtime::InteropServices::GCHandle errorHandle;

	public:
		StreamDecoder();

		~StreamDecoder();

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

		unsigned long long GetDecodePosition();

		DecoderStreamState^ GetState();

		void Initialize();

		void InitializeOgg();

		void Finish();

		void Flush();

		void ProcessSingle();

		void ProcessUntilEndOfMetadata();

		void ProcessUntilEndOfStream();

		void Reset();

		void SetMetadataIgnore(MetadataType type);

		void SetMetadataIgnoreAll();

		void SetMetadataIgnoreApplication(MetadataId^ id);

		void SetMetadataRespond(MetadataType type);

		void SetMetadataRespondAll();

		void SetMetadataRespondApplication(MetadataId^ id);

		void SetOggSerialNumber(long serialNumber);

	private:
		FLAC__StreamDecoderReadStatus Read(const FLAC__StreamDecoder* decoder, FLAC__byte buffer[], size_t* bytes, void* client_data);
		FLAC__StreamDecoderSeekStatus Seek(const FLAC__StreamDecoder* decoder, FLAC__uint64 absolute_byte_offset, void* client_data);
		FLAC__StreamDecoderTellStatus Tell(const FLAC__StreamDecoder* decoder, FLAC__uint64* absolute_byte_offset, void* client_data);
		FLAC__StreamDecoderLengthStatus Length(const FLAC__StreamDecoder* decoder, FLAC__uint64* stream_length, void* client_data);
		FLAC__bool Eof(const FLAC__StreamDecoder* decoder, void* client_data);
		FLAC__StreamDecoderWriteStatus Write(const FLAC__StreamDecoder* decoder, const FLAC__Frame* frame, const FLAC__int32* const buffer[], void* client_data);
		void Metadata(const FLAC__StreamDecoder* decoder, const FLAC__StreamMetadata* metadata, void* client_data);
		void Error(const FLAC__StreamDecoder* decoder, FLAC__StreamDecoderErrorStatus status, void* client_data);
	};
}
