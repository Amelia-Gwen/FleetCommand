#include "CityMapScreen.h"

namespace fleet {
	CityMapScreen::CityMapScreen(sf::RenderWindow& window, const sf::Font& font, const Model& model, DisplayPanel& displayPanel) :
		IScreen{ window, font },
		model{ model },
		displayPanel{ displayPanel }
	{
	}
	GameEvent CityMapScreen::input()
	{
		return GameEvent();
	}
	void CityMapScreen::update()
	{
	}
	void CityMapScreen::draw()
	{
	}
}