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
	};
}