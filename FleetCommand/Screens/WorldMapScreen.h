#pragma once

#include "IScreen.h"

namespace fleet {
	class WorldMapScreen : public IScreen {
	public:
		WorldMapScreen(sf::RenderWindow& window, sf::Font& font, DisplayPanel& displayPanel);

		GameEvent input() override;
		void update() override;
		void draw() override;
	private:

	};
}