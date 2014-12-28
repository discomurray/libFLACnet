#pragma once

#include <FLAC\format.h>

namespace FLAC
{
	public enum class ChannelAssignment
	{
		Independent = FLAC__ChannelAssignment::FLAC__CHANNEL_ASSIGNMENT_INDEPENDENT,

		Left = FLAC__ChannelAssignment::FLAC__CHANNEL_ASSIGNMENT_LEFT_SIDE,

		Right = FLAC__ChannelAssignment::FLAC__CHANNEL_ASSIGNMENT_RIGHT_SIDE,

		Mid = FLAC__ChannelAssignment::FLAC__CHANNEL_ASSIGNMENT_MID_SIDE,
	};
}
