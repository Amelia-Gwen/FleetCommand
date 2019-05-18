#pragma once

namespace fleet {
	struct UnitBaseCosts {
		// Basic ship classes
		static const unsigned patrol{ 900 };
		static const unsigned corvette{ 1500 };
		static const unsigned submarine{ 1900 };
		static const unsigned destroyer{ 1400 };
		static const unsigned cruiser{ 1800 };
		static const unsigned battleship{ 2200 };
		static const unsigned carrier{ 2800 };
		static const unsigned dreadnought{ 4400 };

		// Specialty ships
		static const unsigned tanker{ 200 };
		static const unsigned transport{ 300 };
		static const unsigned cargo{ 400 };
		static const unsigned missile{ 4400 };

		// Troops
		static const unsigned marines{ 20 };

		// Aircraft
		static const unsigned fighter{ 120 };
		static const unsigned bomber{ 500 };
	};
}