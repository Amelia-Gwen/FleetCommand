#pragma once

#include "IScreen.h"

#include "DisplayPanel.h"
#include "GUIButton.h"

namespace fleet {
	class FleetScreen : public IScreen {
	public:
		explicit FleetScreen(sf::RenderWindow& window, sf::Font& font, DisplayPanel& displayPanel);

		GameEvent input() override;
		void update() override;
		void draw() override;
	private:
		DisplayPanel& displayPanel;
		GUIButton dashboardButton{ sf::Vector2f(game_button_width, game_button_height), "Dashboard", font };
		GUIButton researchButton{ sf::Vector2f(game_button_width, game_button_height), "Research", font };
		GUIButton unitsButton{ sf::Vector2f(game_button_width, game_button_height), "Units", font };
		GUIButton worldMapButton{ sf::Vector2f(game_button_width, game_button_height), "World Map", font };
	};
}