#include "stdafx.h"
#include "DecoderStreamState.h"

using namespace FLAC;

DecoderStreamState::DecoderStreamState(FLAC__StreamDecoderState state)
	: state(state)
{
}
