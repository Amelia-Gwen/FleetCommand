#pragma once

#include <string>
#include <vector>

namespace fleet {

	class IUnit {
	public:
		IUnit(const std::string& type, unsigned short rank) : unitType{ type }, rank { rank } {}
		virtual ~IUnit() = default;

		virtual void move() = 0;
	protected:
		std::string unitType;
		unsigned short rank;

		unsigned hitPoints;
		unsigned short movePoints;
		unsigned short attackPoints;

		unsigned defense;
		unsigned evade;
	};
}