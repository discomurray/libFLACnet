#include "stdafx.h"
#include "DecoderErrorStats.h"

using namespace FLAC;

DecoderErrorStats::DecoderErrorStats()
{
}

unsigned long long DecoderErrorStats::AbsoluteSample::get()
{
	return this->absoluteSample;
}

unsigned int DecoderErrorStats::FrameNumber::get()
{
	return this->frameNumber;
}

unsigned int DecoderErrorStats::Channel::get()
{
	return this->channel;
}

unsigned int DecoderErrorStats::Sample::get()
{
	return this->sample;
}

int DecoderErrorStats::Expected::get()
{
	return this->expected;
}

int DecoderErrorStats::Got::get()
{
	return this->got;
}

DecoderErrorStats^ DecoderErrorStats::FromEncoder(FLAC__StreamEncoder* encoder)
{
	unsigned long long absoluteSample;
	unsigned int frameNumber;
	unsigned int channel;
	unsigned int sample;
	int expected;
	int got;

	FLAC__stream_encoder_get_verify_decoder_error_stats(encoder, &absoluteSample, &frameNumber, &channel, &sample, &expected, &got);

	DecoderErrorStats^ stats = gcnew DecoderErrorStats();
	stats->absoluteSample = absoluteSample;
	stats->frameNumber = frameNumber;
	stats->channel = channel;
	stats->sample = sample;
	stats->expected = expected;
	stats->got = got;

	return stats;
}