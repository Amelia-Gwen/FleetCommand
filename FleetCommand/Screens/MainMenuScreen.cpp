#include "MainMenuScreen.h"

namespace fleet {
	/*
	param: reference to RenderWindow
	param: constant reference to Font
	The constructor takes these references and forwards them to the base class.
	*/
	MainMenuScreen::MainMenuScreen(sf::RenderWindow& window, const sf::Font& font) :
		IScreen{ window, font }
	{
		logo.setPosition(logo_x, logo_y);
		logo.setFillColor(sf::Color::Cyan);
		logoText.setPosition(logo_text_x, logo_text_y);
		logoText.setCharacterSize(logo_text_character_size);
		logoText.setFillColor(sf::Color::Black);
		playButton.setLabelOffset(sf::Vector2f(play_button_x_offset, menu_text_y_offset));
		playButton.setPosition(main_menu_button_x, play_button_y);
		playButton.setCharacterSize(text_character_size);
		newGameButton.setLabelOffset(sf::Vector2f(new_or_load_x_offset, menu_text_y_offset));
		newGameButton.setPosition(main_menu_button_x, new_game_button_y);
		newGameButton.setCharacterSize(text_character_size);
		loadGameButton.setLabelOffset(sf::Vector2f(new_or_load_x_offset, menu_text_y_offset));
		loadGameButton.setPosition(main_menu_button_x, load_button_y);
		loadGameButton.setCharacterSize(text_character_size);
	}

	/*
	Specific choices for user include: expand the play button, navigate to the new game screen, and navigate to the load game screen.
	return: GameEvent - custum enum to handle game level events.
	*/
	GameEvent MainMenuScreen::input()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		if (!expanded && playButton.input(mousePos))
		{
			expanded = true;
			return GameEvent::ActionComplete;
		}
		else if (expanded)
		{
			if (newGameButton.input(mousePos))
			{
				return GameEvent::OpenNewGame;
			}
			else if (loadGameButton.input(mousePos))
			{
				return GameEvent::OpenLoadGame;
			}
		}

		return GameEvent::None;
	}
	/*
	Method to update screen components
	*/
	void MainMenuScreen::update()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		playButton.update(mousePos);
		newGameButton.update(mousePos);
		loadGameButton.update(mousePos);
	}
	/*
	Render logic. This is the main need for the window reference.
	*/
	void MainMenuScreen::draw()
	{
		window.draw(logo);
		window.draw(logoText);
		if (!expanded)
		{
			window.draw(playButton);
		}
		else
		{
			window.draw(newGameButton);
			window.draw(loadGameButton);
		}
	}
}