#pragma once

#include "IScreen.h"

#include "GUIButton.h"

namespace fleet {
	/*
	Class that implements the IScreen interface and acts as the splash page for the program.
	The user choses between loading a save game or beginning a new game.
	*/

	class MainMenuScreen : public IScreen {
	public:
		explicit MainMenuScreen(sf::RenderWindow& window, const sf::Font& font);

		GameEvent input() override;
		void update() override;
		void draw() override;
	private:
		bool expanded{ false };
		sf::RectangleShape logo{ sf::Vector2f(logo_width, logo_height) };
		sf::Text logoText{ "Fleet\n\tCommand", font };
		GUIButton playButton{ sf::Vector2f(main_menu_button_width, main_menu_button_height), "Play", font };
		GUIButton newGameButton{ sf::Vector2f(main_menu_button_width, main_menu_button_height), "New Game", font };
		GUIButton loadGameButton{ sf::Vector2f(main_menu_button_width, main_menu_button_height), "Load Game", font };
	};
}