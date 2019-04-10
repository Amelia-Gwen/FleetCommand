#pragma once

#include "DisplayPanel.h"
#include "IScreen.h"
#include "Model.h"

namespace fleet {
	class CityUpgradeScreen : public IScreen {
	public:
		explicit CityUpgradeScreen(sf::RenderWindow& window, sf::Font& font, const Model& model, DisplayPanel& displayPanel);

		void setCity(unsigned index);

		GameEvent input() override;
		void update() override;
		void draw() override;
	private:
		const Model& model;
		DisplayPanel& displayPanel;
		std::string cityName;
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