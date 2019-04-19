#pragma once

#include "IScreen.h"

#include "DisplayPanel.h"
#include "GUIButton.h"

namespace fleet {
	class Dashboard : public IScreen {
	public:
		explicit Dashboard(sf::RenderWindow& window, sf::Font& font, DisplayPanel& displayPanel);

		GameEvent input() override;
		void update() override;
		void draw() override;
	private:
		DisplayPanel& displayPanel;
		GUIButton unitsButton{ sf::Vector2f(game_button_width, game_button_height), "Units", font };
		GUIButton researchButton{ sf::Vector2f(game_button_width, game_button_height), "Research", font };
		GUIButton fleetButton{ sf::Vector2f(game_button_width, game_button_height), "Fleet", font };
		GUIButton worldMapButton{ sf::Vector2f(game_button_width, game_button_height), "World Map", font };
	};
}