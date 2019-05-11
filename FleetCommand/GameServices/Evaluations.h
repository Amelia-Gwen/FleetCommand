#pragma once

namespace fleet {
	bool inline canAfford(unsigned cost, unsigned resource) { return !(resource < cost); }
}
