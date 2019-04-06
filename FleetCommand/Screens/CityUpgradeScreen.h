#pragma once

#include "IScreen.h"
#include "DisplayPanel.h"

namespace fleet {
	class CityUpgradeScreen : public IScreen {
	public:
		explicit CityUpgradeScreen(sf::RenderWindow& window, sf::Font& font, DisplayPanel& displayPanel);

		GameEvent input() override;
		void update() override;
		void draw() override;
	private:
		DisplayPanel& displayPanel;
		sf::RectangleShape dashboardButton{ sf::Vector2f(game_button_width, game_button_height) };
		sf::Text dashboard{ "Dashboard", font };
		sf::RectangleShape cityDashboardButton{ sf::Vector2f(game_button_width, game_button_height) };
		sf::Text cityDashboard{ "", font };
		sf::RectangleShape cityMapButton{ sf::Vector2f(game_button_width, game_button_height) };
		sf::Text cityMap{ "City Map", font };
		sf::RectangleShape worldMapButton{ sf::Vector2f(game_button_width, game_button_height) };
		sf::Text worldMap{ "World Map", font };
	};
}