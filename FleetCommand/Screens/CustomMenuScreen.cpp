#include "CustomMenuScreen.h"

namespace fleet {
	/*
	///param: reference to RenderWindow
	///param: constant reference to Font
	The constructor takes these references and forwards them to the base class.
	*/
	CustomMenuScreen::CustomMenuScreen(sf::RenderWindow& window, const sf::Font& font) :
		IScreen{ window, font }
	{
		backButton.setPosition(menu_back_x, menu_back_y);
	}

	/*
	Specific choices for user include: return to the new game screen,
	start a custom game set to the values provided (begins gameplay,)
	///return: GameEvent - custum enum to handle game level events.
	*/
	GameEvent CustomMenuScreen::input()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		if (backButton.getGlobalBounds().contains(mousePos))
		{
			return GameEvent::OpenNewGame;
		}
	}
	/*
	Method to update screen components
	*/
	void CustomMenuScreen::update()
	{
		checkMouseOver(backButton);
	}
	/*
	Render logic. This is the main need for the window reference.
	*/
	void CustomMenuScreen::draw()
	{
		window.draw(backButton);
	}
}