#pragma once

#include "DisplayPanel.h"
#include "IScreen.h"
#include "UpgradeButton.h"

namespace fleet {
	class ResearchScreen : public IScreen {
	public:
		explicit ResearchScreen(sf::RenderWindow& window, sf::Font& font, DisplayPanel& displayPanel);

		GameEvent input() override;
		void update() override;
		void draw() override;
	private:
		DisplayPanel& displayPanel;
		sf::RectangleShape dashboardButton{ sf::Vector2f(game_button_width, game_button_height) };
		sf::Text dashboard{ "Dashboard", font };
		sf::RectangleShape unitsButton{ sf::Vector2f(game_button_width, game_button_height) };
		sf::Text units{ "Units", font };
		sf::RectangleShape fleetButton{ sf::Vector2f(game_button_width, game_button_height) };
		sf::Text fleet{ "Fleet", font };
		sf::RectangleShape worldMapButton{ sf::Vector2f(game_button_width, game_button_height) };
		sf::Text worldMap{ "World Map", font };
	};
}