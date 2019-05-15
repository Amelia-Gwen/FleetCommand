#pragma once

#include <string>

namespace fleet {
	class IComponent {
	public:
		IComponent(const std::string& compontentType, unsigned short rank) : componentType{ componentType }, rank{ rank } {}
		virtual ~IComponent() = default;
	protected:
		std::string componentType;
		unsigned short rank;
		unsigned cost;
		unsigned size;
	};
}