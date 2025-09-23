#pragma once

#include "IScreen.h"

#include "GUIButton.h"

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
		GUIButton backButton{ sf::Vector2f(menu_back_button_width, menu_back_button_height), "Back", font };
		GUIButton campaignButton{ sf::Vector2f(new_button_width, new_button_height), "Campaign", font };
		GUIButton customButton{ sf::Vector2f(new_button_width, new_button_height), "Custom\n   Scenario", font };
	};
}