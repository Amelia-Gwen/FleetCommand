#pragma once

#include "IScreen.h"

namespace fleet {

	constexpr float new_button_width = 400.F;
	constexpr float new_button_height = 400.F;
	constexpr float campaign_button_x = 150.F;
	constexpr float custom_button_x = 650.F;
	constexpr float new_button_y = 200.F;
	constexpr float new_text_x_offset = 80.F;
	constexpr float campaign_text_x = campaign_button_x + new_text_x_offset;
	constexpr float custom_text_x = custom_button_x + new_text_x_offset;
	constexpr float new_game_text_y = new_button_y + 100.F;
	constexpr unsigned new_text_size = 60U;

	/*
	Class that implements the IScreen interface. The user can return to the main menu, open the custom
	game management screen, or begin a new game (starts gameplay)
	*/

	class NewGameMenuScreen : public IScreen {
	public:
		explicit NewGameMenuScreen(sf::RenderWindow& window, const sf::Font& font);

		GameEvent input() override;
		void update() override;
		void draw() override;
	private:
		sf::RectangleShape backButton{ sf::Vector2f(menu_back_button_width, menu_back_button_height) };
		sf::RectangleShape campaignButton{ sf::Vector2f(new_button_width, new_button_height) };
		sf::Text campaign{ "Campaign", font };
		sf::RectangleShape customButton{ sf::Vector2f(new_button_width, new_button_height) };
		sf::Text custom{ "Custom\n   Scenario", font };
	};
}