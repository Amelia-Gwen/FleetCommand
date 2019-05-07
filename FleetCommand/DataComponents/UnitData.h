#pragma once

namespace fleet {
	struct UnitBaseCosts {
		// Basic ship classes
		static const unsigned patrol{ 900 };
		static const unsigned corvette{ 1100 };
		static const unsigned frigate{ 1400 };
		static const unsigned submarine{ 1600 };
		static const unsigned destroyer{ 1800 };
		static const unsigned cruiser{ 2200 };
		static const unsigned carrier{ 2800 };

		// Specialty ships
		static const unsigned tanker{ 200 };
		static const unsigned transport{ 300 };
		static const unsigned cargo{ 400 };
		static const unsigned missile{ 4400 };

		// Troops
		static const unsigned marines{ 20 };
	};
}