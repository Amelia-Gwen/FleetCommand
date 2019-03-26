#pragma once

#include "IScreen.h"
#include "DisplayPanel.h"

namespace fleet {
	class CityDashboard : public IScreen {
	public:
		explicit CityDashboard(sf::RenderWindow& window, sf::Font& font, DisplayPanel& displayPanel);

		void setCity(unsigned index);

		GameEvent input() override;
		void update() override;
		void draw() override;
	private:
		DisplayPanel& displayPanel;
		unsigned cityIndex{ 0 };
		sf::RectangleShape dashboard;
		sf::RectangleShape CityMap;
		sf::RectangleShape CityUpgrade;
		sf::RectangleShape WorldMap;
	};
}