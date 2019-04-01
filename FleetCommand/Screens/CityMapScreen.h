#pragma once

#include "IScreen.h"
#include "DisplayPanel.h"
#include "CityMap.h"

namespace fleet {
	class CityMapScreen : public IScreen {
	public:
		explicit CityMapScreen(sf::RenderWindow& window, const sf::Font& font, const Model& model, DisplayPanel& displayPanel);

		void releaseGrip() { cityMap.releaseGrip(); }
		void setCity(unsigned index);

		GameEvent input() override;
		void update() override;
		void draw() override;
	private:
		const Model& model;
		DisplayPanel& displayPanel;
		CityMap cityMap;
		std::string cityName;
		sf::RectangleShape dashboardButton{ sf::Vector2f(game_button_width, game_button_height) };
		sf::Text dashboard{ "Dashboard", font };
		sf::RectangleShape cityDashboardButton{ sf::Vector2f(game_button_width, game_button_height) };
		sf::Text cityDashboard{ "", font };
		sf::RectangleShape cityUpgradeButton{ sf::Vector2f(game_button_width, game_button_height) };
		sf::Text cityUpgrade{ "City Upgrades", font };
		sf::RectangleShape worldMapButton{ sf::Vector2f(game_button_width, game_button_height) };
		sf::Text worldMap{ "World Map", font };
	};
}