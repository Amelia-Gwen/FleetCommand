#include "LoadGameScreen.h"

namespace fleet {
	/*
	///param: reference to RenderWindow
	///param: constant reference to Font
	The constructor takes these references and forwards them to the base class.
	*/
	LoadGameScreen::LoadGameScreen(sf::RenderWindow& window, const sf::Font& font) :
		IScreen{ window, font }
	{
		backButton.setPosition(menu_back_x, menu_back_y);
		slot1.setPosition(slot1_x, slot_y);
		slot2.setPosition(slot2_x, slot_y);
		slot3.setPosition(slot3_x, slot_y);
	}

	/*
	Specific choices for user include: return to main menu, load from one of three data files (if they exist)
	///return: GameEvent - custum enum to handle game level events.
	*/
	GameEvent LoadGameScreen::input()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		if (backButton.getGlobalBounds().contains(mousePos))
		{
			return GameEvent::ReturnToMainMenu;
		}
		else if (slot1.getGlobalBounds().contains(mousePos))
		{
			loadFile = LoadFile::One;
			return GameEvent::LoadGame;
		}
		else if (slot2.getGlobalBounds().contains(mousePos))
		{
			loadFile = LoadFile::Two;
			return GameEvent::LoadGame;
		}
		else if (slot3.getGlobalBounds().contains(mousePos))
		{
			loadFile = LoadFile::Three;
			return GameEvent::LoadGame;
		}

		return GameEvent::None;
	}
	/*
    Method to update screen components
    */
	void LoadGameScreen::update()
	{
		checkMouseOver(backButton);
		checkMouseOver(slot1);
		checkMouseOver(slot2);
		checkMouseOver(slot3);
	}
	/*
    Render logic. This is the main need for the window reference.
    */
	void LoadGameScreen::draw()
	{
		window.draw(backButton);
		window.draw(slot1);
		window.draw(slot2);
		window.draw(slot3);
	}
}