#pragma once

#include "Difficulty.h"

namespace fleet {
	struct GameValues {
		int players;
		int computers;
		Difficulty difficulty;
		int oil;
		int cash;
		int research;
	};
}