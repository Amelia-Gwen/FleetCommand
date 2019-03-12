#include "IScreen.h"

namespace fleet {
	IScreen::IScreen(sf::RenderWindow& window, const sf::Font& font) :
		window{ window },
		font{ font }
	{
	}

	/*
	Helper function to change buttons on mouseover. This helps localize the color scheme for buttons in one location.
	*/
	void IScreen::checkMouseOver(sf::RectangleShape& button)
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };
		if (button.getGlobalBounds().contains(mousePos))
		{
			button.setFillColor(sf::Color::Green);
		}
		else
		{
			button.setFillColor(sf::Color::Cyan);
		}
	}
}