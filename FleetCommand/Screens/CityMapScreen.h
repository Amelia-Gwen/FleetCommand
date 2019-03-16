#pragma once

#include "IScreen.h"

namespace fleet {
	class CityMapScreen : public IScreen {
	public:
		CityMapScreen(sf::RenderWindow& window, const sf::Font& font);

		GameEvent input() override;
		void update() override;
		void draw() override;
	private:

	};
}