#pragma once

#include <string>
#include <vector>

namespace fleet {

	class IUnit {
	public:
		IUnit(const std::string& type, unsigned short rank) : unitType{ type }, rank { rank } {}
		virtual ~IUnit() = default;

		virtual void move();
		virtual void fire();
	protected:
		std::string unitType;
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