#include "CityMapScreen.h"

namespace fleet {
	CityMapScreen::CityMapScreen(sf::RenderWindow& window, const sf::Font& font, const Model& model, DisplayPanel& displayPanel) :
		IScreen{ window, font },
		model{ model },
		displayPanel{ displayPanel }
	{
		cityMap.setPosition(0.F, panel_box_height);
	}

	GameEvent CityMapScreen::input()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		GameEvent gameEvent = cityMap.input(mousePos);

		return gameEvent;
	}
	void CityMapScreen::update()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		cityMap.update(mousePos);
	}
	void CityMapScreen::draw()
	{
		window.draw(cityMap);
	}
}