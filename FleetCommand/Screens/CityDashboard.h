#pragma once

#include "IScreen.h"

#include "DisplayPanel.h"
#include "GUIButton.h"

namespace fleet {
	class CityDashboard : public IScreen {
	public:
		explicit CityDashboard(sf::RenderWindow& window, sf::Font& font, DisplayPanel& displayPanel);

		void setCity(unsigned index, bool owned);

		GameEvent input() override;
		void update() override;
		void draw() override;
	private:
		DisplayPanel& displayPanel;
		unsigned cityIndex{ 0 };
		GUIButton dashboardButton{ sf::Vector2f(game_button_width, game_button_height), "Dashboard", font };
		GUIButton cityMapButton{ sf::Vector2f(game_button_width, game_button_height), "City Map", font };
		GUIButton cityUpgradeButton{ sf::Vector2f(game_button_width, game_button_height), "City Upgrades", font };
		GUIButton worldMapButton{ sf::Vector2f(game_button_width, game_button_height), "World Map", font };
	};
}