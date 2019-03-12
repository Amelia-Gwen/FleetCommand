#include "MainMenuScreen.h"

namespace fleet {
	MainMenuScreen::MainMenuScreen(sf::RenderWindow & window, const sf::Font & font) :
		IScreen{ window, font }
	{
		logo.setPosition(logo_x, logo_y);
		//logo.setFillColor(sf::Color::Yellow);
		logoText.setPosition(logo_text_x, logo_text_y);
		logoText.setCharacterSize(logo_text_character_size);
		logoText.setFillColor(sf::Color::Black);
		playButton.setPosition(main_menu_button_x, play_button_y);
		play.setPosition(play_text_x, play_text_y);
		play.setCharacterSize(text_character_size);
		play.setFillColor(sf::Color::Black);
		newGameButton.setPosition(main_menu_button_x, new_button_y);
		newGame.setPosition(new_text_x, new_text_y);
		newGame.setCharacterSize(text_character_size);
		newGame.setFillColor(sf::Color::Black);
		loadGameButton.setPosition(main_menu_button_x, load_button_y);
		loadGame.setPosition(load_text_x, load_text_y);
		loadGame.setCharacterSize(text_character_size);
		loadGame.setFillColor(sf::Color::Black);
	}

	GameEvent MainMenuScreen::input()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		if (!expanded && playButton.getGlobalBounds().contains(mousePos))
		{
			expanded = true;
			return GameEvent::ActionComplete;
		}
		else if (expanded)
		{
			if (newGameButton.getGlobalBounds().contains(mousePos))
			{
				return GameEvent::OpenNewGame;
			}
			else if (loadGameButton.getGlobalBounds().contains(mousePos))
			{
				return GameEvent::OpenLoadGame;
			}
		}

		return GameEvent::None;
	}

	void MainMenuScreen::update()
	{
		checkMouseOver(playButton);
		checkMouseOver(newGameButton);
		checkMouseOver(loadGameButton);
	}

	void MainMenuScreen::draw()
	{
		window.draw(logo);
		window.draw(logoText);
		if (!expanded)
		{
			window.draw(playButton);
			window.draw(play);
		}
		else
		{
			window.draw(newGameButton);
			window.draw(newGame);
			window.draw(loadGameButton);
			window.draw(loadGame);
		}
	}
}