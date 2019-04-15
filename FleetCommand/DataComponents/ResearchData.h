#pragma once

#include <vector>

namespace fleet {
	struct PlayerResearch {
		unsigned short shipyard{ 0 };
		unsigned short shipType{ 0 };
		unsigned short durability{ 0 };
		unsigned short firepower{ 0 };
		unsigned short hull{ 0 };
		unsigned short engine{ 0 };
		unsigned short weapons{ 0 };
		unsigned short fuelEfficiency{ 0 };
		unsigned short oilProduction{ 0 };
		unsigned short cashProduction{ 0 };
		unsigned short researchProduction{ 0 };
	};

	struct CityResearch {
		unsigned short shipyard{ 0 };
		unsigned short airDefense{ 0 };
		unsigned short groundDefense{ 0 };
		unsigned short oilProduction{ 0 };
		unsigned short cashProduction{ 0 };
		unsigned short researchProduction{ 0 };
	};

	struct ResearchMaximums {
		static const unsigned short shpiyardMax{ 5 };
		static const unsigned short shipTypeMax{ 6 };
		static const unsigned short durabilityMax{ 4 };
		static const unsigned short firepowerMax{ 4 };
		static const unsigned short hullMax{ 5 };
		static const unsigned short engineMax{ 4 };
		static const unsigned short weaponMax{ 6 };
		static const unsigned short fuelEfficiencyMax{ 5 };
		static const unsigned short productionMax{ 4 };
		static const unsigned short defenseMax{ 5 };
	};

	struct ResearchCosts {
		static const std::vector<unsigned> playerShipyard;
		static const std::vector<unsigned> shipType;
		static const std::vector<unsigned> durability;
		static const std::vector<unsigned> firepower;
		static const std::vector<unsigned> hull;
		static const std::vector<unsigned> engine;
		static const std::vector<unsigned> weapons;
		static const std::vector<unsigned> fuelEfficiency;
		static const std::vector<unsigned> playerProduction;
		static const std::vector<unsigned> cityShipyard;
		static const std::vector<unsigned> defense;
		static const std::vector<unsigned> cityProduction;

	};
}