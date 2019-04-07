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

	GameValues defaultValues{ 1, 7, Difficulty::Medium, 10000, 1000, 10 };
}