#include "NewGameMenuScreen.h"

namespace fleet {
	NewGameMenuScreen::NewGameMenuScreen(sf::RenderWindow& window, const sf::Font& font) :
		IScreen{ window, font }
	{
		backButton.setPosition(menu_back_x, menu_back_y);
		campaignButton.setPosition(campaign_button_x, new_button_y);
		campaign.setPosition(campaign_text_x, new_game_text_y);
		campaign.setFillColor(sf::Color::Black);
		campaign.setCharacterSize(new_text_size);
		customButton.setPosition(custom_button_x, new_button_y);
		custom.setPosition(custom_text_x, new_game_text_y);
		custom.setFillColor(sf::Color::Black);
		custom.setCharacterSize(new_text_size);
	}

	GameEvent NewGameMenuScreen::input()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		if (backButton.getGlobalBounds().contains(mousePos))
		{
			return GameEvent::ReturnToMainMenu;
		}
		else if (campaignButton.getGlobalBounds().contains(mousePos))
		{
			return GameEvent::StartCampaign;
		}
		else if (customButton.getGlobalBounds().contains(mousePos))
		{
			return GameEvent::OpenCustomGame;
		}

		return GameEvent::None;
	}
	void NewGameMenuScreen::update()
	{
		checkMouseOver(backButton);
		checkMouseOver(campaignButton);
		checkMouseOver(customButton);
	}
	void NewGameMenuScreen::draw()
	{
		window.draw(backButton);
		window.draw(campaignButton);
		window.draw(campaign);
		window.draw(customButton);
		window.draw(custom);
	}
}