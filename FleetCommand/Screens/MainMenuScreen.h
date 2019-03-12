#pragma once

#include "IScreen.h"

namespace fleet {

	constexpr int logo_width = 500;
	constexpr int logo_height = 300;
	constexpr float logo_x = 350.F;
	constexpr float logo_y = 100.F;
	constexpr float logo_text_x = logo_x + 90.F;
	constexpr float logo_text_y = logo_y + 80.F;
	constexpr float main_menu_button_width = 300.F;
	constexpr float main_menu_button_height = 75.F;
	constexpr float main_menu_button_x = 450.F;
	constexpr float main_menu_text_y_offset = 10.F;
	constexpr float play_button_y = 600.F;
	constexpr float play_text_x = main_menu_button_x + 100.F;
	constexpr float play_text_y = play_button_y + main_menu_text_y_offset;
	constexpr float new_game_button_y = 500.F;
	constexpr float new_text_x = main_menu_button_x + 40.F;
	constexpr float new_text_y = new_game_button_y + main_menu_text_y_offset;
	constexpr float load_button_y = 650.F;
	constexpr float load_text_x = main_menu_button_x + 40.F;
	constexpr float load_text_y = load_button_y + main_menu_text_y_offset;
	constexpr unsigned logo_text_character_size = 60;

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
		sf::RectangleShape playButton{ sf::Vector2f(main_menu_button_width, main_menu_button_height) };
		sf::Text play{ "Play", font };
		sf::RectangleShape newGameButton{ sf::Vector2f(main_menu_button_width, main_menu_button_height) };
		sf::Text newGame{ "New Game", font };
		sf::RectangleShape loadGameButton{ sf::Vector2f(main_menu_button_width, main_menu_button_height) };
		sf::Text loadGame{ "Load Game", font };
	};
}