#pragma once

#include "IUnit.h"

namespace fleet {
	class ITroop : public IUnit {
	public:
		ITroop(const std::string& unitType, unsigned short rank) : IUnit{ unitType, rank } {}
		virtual ~ITroop() = default;

		virtual void attack() = 0;
	protected:
		unsigned attack;
		unsigned accuracy;
		unsigned maxTroop;
		unsigned troopCount;
	};
}