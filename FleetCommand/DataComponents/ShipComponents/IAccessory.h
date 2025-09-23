#pragma once

#include "IComponent.h"

namespace fleet {
	class IAccessory : public IComponent {
		IAccessory(const std::string& accessoryType, unsigned short rank) : IComponent{ accessoryType, rank } {}
		virtual ~IAccessory();
	};
}