#pragma once

#include "IScreen.h"

namespace fleet {
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