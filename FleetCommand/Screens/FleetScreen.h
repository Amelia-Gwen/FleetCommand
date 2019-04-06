#pragma once

#include "IScreen.h"
#include "DisplayPanel.h"

namespace fleet {
	class FleetScreen : public IScreen {
	public:
		explicit FleetScreen(sf::RenderWindow& window, sf::Font& font, DisplayPanel& displayPanel);

		GameEvent input() override;
		void update() override;
		void draw() override;
	private:
		DisplayPanel& displayPanel;
		sf::RectangleShape dashboardButton{ sf::Vector2f(game_button_width, game_button_height) };
		sf::Text dashboard{ "Dashboard", font };
		sf::RectangleShape researchButton{ sf::Vector2f(game_button_width, game_button_height) };
		sf::Text research{ "Research", font };
		sf::RectangleShape unitsButton{ sf::Vector2f(game_button_width, game_button_height) };
		sf::Text units{ "Units", font };
		sf::RectangleShape worldMapButton{ sf::Vector2f(game_button_width, game_button_height) };
		sf::Text worldMap{ "World Map", font };
	};
}