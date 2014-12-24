#include "stdafx.h"
#include "EncoderStreamState.h"

using namespace FLAC;

EncoderStreamState::EncoderStreamState(FLAC__StreamEncoderState state)
	: state(state)
{
}
