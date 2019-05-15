#pragma once

namespace fleet {
	class IComponent {
	public:
		virtual ~IComponent() = default;
	protected:
		unsigned short rank;
		unsigned cost;
		unsigned size;
	};
}