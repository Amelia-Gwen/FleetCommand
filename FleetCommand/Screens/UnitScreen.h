#pragma once

#include "IScreen.h"

#include "DisplayPanel.h"
#include "GUIButton.h"
#include "UnitButton.h"

namespace fleet {
	class UnitScreen : public IScreen {
	public:
		explicit UnitScreen(sf::RenderWindow& window, sf::Font& font, DisplayPanel& displayPanel);

		GameEvent input() override;
		void update() override;
		void draw() override;
	private:
		DisplayPanel& displayPanel;
		GUIButton dashboardButton{ sf::Vector2f(game_button_width, game_button_height), "Dashboard", font };
		GUIButton researchButton{ sf::Vector2f(game_button_width, game_button_height), "Research", font };
		GUIButton fleetButton{ sf::Vector2f(game_button_width, game_button_height), "Fleet", font };
		GUIButton worldMapButton{ sf::Vector2f(game_button_width, game_button_height), "World Map", font };
	};
}