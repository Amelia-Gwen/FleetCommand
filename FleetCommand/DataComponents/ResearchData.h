#pragma once

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
		unsigned short oilProduction{ 0 };
		unsigned short cashProduction{ 0 };
		unsigned short researchProduction{ 0 };
		unsigned short airDefense{ 0 };
		unsigned short groundDefense{ 0 };
	};

	struct ResearchMaximums {
		unsigned short shpiyardMax{ 5 };
		unsigned short shipTypeMax{ 6 };
		unsigned short durabilityMax{ 4 };
		unsigned short firepowerMax{ 4 };
		unsigned short hullMax{ 5 };
		unsigned short engineMax{ 4 };
		unsigned short weaponMax{ 6 };
		unsigned short fuelEfficiencyMax{ 5 };
		unsigned short productionMax{ 4 };
		unsigned short DefenseMax{ 5 };
	};
}