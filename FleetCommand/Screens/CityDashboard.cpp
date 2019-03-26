#include "CityDashboard.h"

namespace fleet {
	CityDashboard::CityDashboard(sf::RenderWindow& window, sf::Font& font, DisplayPanel& displayPanel) :
		IScreen{ window, font },
		displayPanel{ displayPanel }
	{
	}

	void CityDashboard::setCity(unsigned index)
	{
		cityIndex = index;
	}

	GameEvent CityDashboard::input()
	{
		return GameEvent();
	}
	void CityDashboard::update()
	{
	}
	void CityDashboard::draw()
	{
	}
}