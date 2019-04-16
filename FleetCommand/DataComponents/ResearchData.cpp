#include "ResearchData.h"

#include <limits>

namespace fleet {
	const std::vector<unsigned> ResearchCosts::playerShipyard ={ 10, 25, 60, 150, 400, std::numeric_limits<unsigned>::max() };
	const std::vector<unsigned> ResearchCosts::shipType ={ 15, 35, 80, 175, 400, 900, std::numeric_limits<unsigned>::max() };
	const std::vector<unsigned> ResearchCosts::durability ={ 8, 20, 45, 100, std::numeric_limits<unsigned>::max() };
	const std::vector<unsigned> ResearchCosts::firepower ={ 8, 20, 45, 100, std::numeric_limits<unsigned>::max() };
	const std::vector<unsigned> ResearchCosts::hull ={ 8, 18, 40, 85, 180, std::numeric_limits<unsigned>::max() };
	const std::vector<unsigned> ResearchCosts::engine ={ 8, 20, 45, 100, std::numeric_limits<unsigned>::max() };
	const std::vector<unsigned> ResearchCosts::weapons ={ 5, 12, 30, 75, 200, 500, std::numeric_limits<unsigned>::max() };
	const std::vector<unsigned> ResearchCosts::fuelEfficiency ={ 7, 15, 35, 85, 180, std::numeric_limits<unsigned>::max() };
	const std::vector<unsigned> ResearchCosts::playerProduction ={ 10, 25, 60, 140, std::numeric_limits<unsigned>::max() };
	const std::vector<unsigned> ResearchCosts::cityShipyard ={ 100, 220, 450, 1000, 2300, std::numeric_limits<unsigned>::max() };
	const std::vector<unsigned> ResearchCosts::defense ={ 75, 175, 375, 800, 1750, std::numeric_limits<unsigned>::max() };
	const std::vector<unsigned> ResearchCosts::cityProduction ={ 50, 150, 350, 750, std::numeric_limits<unsigned>::max() };
}