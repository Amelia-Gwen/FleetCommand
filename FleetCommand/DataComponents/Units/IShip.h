#pragma once

#include "IUnit.h"

#include "IComponent.h"

#include <vector>

namespace fleet {
	class IShip : public IUnit {
	public:
		IShip(const std::string& unitType, unsigned short rank) : IUnit{ unitType, rank } {}
		virtual ~IShip() = default;
	protected:
		unsigned componentCapacity;
		std::vector<IComponent*> components;
	};
}