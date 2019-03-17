#pragma once

#include "IMap.h"

namespace fleet {
	class CityMap : public IMap {
	public:
		CityMap();

		GameEvent input(const sf::Vector2f& mousePos) override;
		void update(const sf::Vector2f& mousePos) override;
	private:

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}