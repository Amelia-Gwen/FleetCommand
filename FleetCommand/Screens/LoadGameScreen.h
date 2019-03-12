#pragma once

#include "IScreen.h"

#include "LoadFile.h"

namespace fleet {

	constexpr float slot_width = 300.F;
	constexpr float slot_height = 300.F;
	constexpr float slot1_x = 50.F;
	constexpr float slot2_x = 450.F;
	constexpr float slot3_x = 850.F;
	constexpr float slot_y = 300.F;

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