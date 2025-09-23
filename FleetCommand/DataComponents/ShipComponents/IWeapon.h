#pragma once

#include "IComponent.h"

namespace fleet {
	class IWeapon : public IComponent {
		IWeapon(const std::string& weaponType, unsigned short rank) : IComponent{ weaponType, rank } {}
		virtual ~IWeapon();
	protected:
		unsigned short range;
		unsigned short damageRange;
		unsigned accuracy;
		unsigned attack;
	};
}