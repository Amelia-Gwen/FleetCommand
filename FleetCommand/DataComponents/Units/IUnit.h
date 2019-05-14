#pragma once

#include <vector>

namespace fleet {

	class IUnit {
	public:
		IUnit(unsigned short rank) : rank{ rank } {}
		virtual ~IUnit() = default;

		virtual void move() = 0;
		virtual void fire() = 0;
	protected:
		unsigned short rank;
		unsigned hitPoints;
		unsigned short movePoints;
		unsigned short attackPoints;
		unsigned attack;
		unsigned defense;
		unsigned speed;
		unsigned accuracy;
		unsigned evade;

		bool canBeFlagship;
		bool isFlagship;
	};
}