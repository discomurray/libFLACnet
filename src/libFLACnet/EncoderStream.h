#pragma once

#include <FLAC\stream_encoder.h>

#include "DecoderErrorStats.h"
#include "DecoderStreamState.h"
#include "EncoderStreamState.h"

namespace FLAC
{
	public ref class EncoderStream
	{
		FLAC__StreamEncoder* encoder;

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

		DecoderErrorStats^ GetDecoderErrorStats();

		EncoderStreamState^ GetState();

		DecoderStreamState^ GetVerifyStreamState();

		void SetApodization(System::String^ specification);

		void SetOggSerialNumber(long serialNumber);
	};
}
