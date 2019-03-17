#pragma once

#include "IScreen.h"

#include "LoadFile.h"

namespace fleet {
	/*
	Class that implements the IScreen interface. The user can return to the main menu or chose a file from which to load
	save data. (Begins gameplay)
	*/

	class LoadGameScreen : public IScreen {
	public:
		explicit LoadGameScreen(sf::RenderWindow& window, const sf::Font& font);

		LoadFile fileToLoad() { return loadFile; }

		GameEvent input() override;
		void update() override;
		void draw() override;
	private:
		sf::RectangleShape backButton{ sf::Vector2f(menu_back_button_width, menu_back_button_height) };
		sf::RectangleShape slot1{ sf::Vector2f(slot_width, slot_height) };
		sf::RectangleShape slot2{ sf::Vector2f(slot_width, slot_height) };
		sf::RectangleShape slot3{ sf::Vector2f(slot_width, slot_height) };
		LoadFile loadFile{ LoadFile::None };
	};
}