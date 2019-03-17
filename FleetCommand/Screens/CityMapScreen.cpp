#include "CityMapScreen.h"

namespace fleet {
	CityMapScreen::CityMapScreen(sf::RenderWindow& window, const sf::Font& font, const Model& model, DisplayPanel& displayPanel) :
		IScreen{ window, font },
		model{ model },
		displayPanel{ displayPanel }
	{
		cityMap.setPosition(0.F, panel_box_height);
	}

	void CityMapScreen::setCity(unsigned index)
	{
		cityName = model.cityList()[index].cityName();

		// set city layout
	}

	GameEvent CityMapScreen::input()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		GameEvent gameEvent = displayPanel.input(mousePos);
		if (gameEvent != GameEvent::None) { return gameEvent; }

        gameEvent = cityMap.input(mousePos);

		return gameEvent;
	}
	void CityMapScreen::update()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		cityMap.update(mousePos);
		displayPanel.update(mousePos);
	}
	void CityMapScreen::draw()
	{
		window.draw(cityMap);
		window.draw(displayPanel);
	}
}