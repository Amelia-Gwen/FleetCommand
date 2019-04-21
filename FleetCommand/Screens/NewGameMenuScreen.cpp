#include "NewGameMenuScreen.h"

namespace fleet {
    /*
	param: reference to RenderWindow
	param: constant reference to Font
	The constructor takes these references and forwards them to the base class.
	*/
	NewGameMenuScreen::NewGameMenuScreen(sf::RenderWindow& window, const sf::Font& font) :
		IScreen{ window, font }
	{
		backButton.setLabelOffset(back_x_offset);
		backButton.setPosition(menu_back_x, menu_back_y);
		campaignButton.setLabelOffset(new_text_x_offset);
		campaignButton.setPosition(campaign_button_x, new_button_y);
		campaignButton.setCharacterSize(new_text_size);
		customButton.setLabelOffset(new_text_x_offset);
		customButton.setPosition(custom_button_x, new_button_y);
		customButton.setCharacterSize(new_text_size);
	}

	/*
	Specific choices for user include: return to the main menu, start a campaign (begins gameplay,) open custom game screen
	return: GameEvent - custum enum to handle game level events.
	*/
	GameEvent NewGameMenuScreen::input()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		if (backButton.input(mousePos))
		{
			return GameEvent::ReturnToMainMenu;
		}
		else if (campaignButton.input(mousePos))
		{
			return GameEvent::StartCampaign;
		}
		else if (customButton.input(mousePos))
		{
			return GameEvent::OpenCustomGame;
		}

		return GameEvent::None;
	}
	/*
    Method to update screen components
    */
	void NewGameMenuScreen::update()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		backButton.update(mousePos);
		campaignButton.update(mousePos);
		customButton.update(mousePos);
	}
	/*
    Render logic. This is the main need for the window reference.
    */
	void NewGameMenuScreen::draw()
	{
		window.draw(backButton);
		window.draw(campaignButton);
		window.draw(customButton);
	}
}