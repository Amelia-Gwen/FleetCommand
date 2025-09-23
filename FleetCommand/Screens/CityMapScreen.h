#pragma once

#include "IScreen.h"

#include "CityMap.h"
#include "DisplayPanel.h"
#include "GUIButton.h"

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
		GUIButton dashboardButton{ sf::Vector2f(game_button_width, game_button_height), "Dashboard", font };
		GUIButton cityDashboardButton{ sf::Vector2f(game_button_width, game_button_height), "", font };
		GUIButton cityUpgradeButton{ sf::Vector2f(game_button_width, game_button_height), "City Upgrades", font };
		GUIButton worldMapButton{ sf::Vector2f(game_button_width, game_button_height), "World Map", font };
	};
}