#pragma once

#include "IScreen.h"
#include "DropBox.h"

namespace fleet {

	constexpr float collumn_one_x = 300.F;
	constexpr float collumn_two_x = 700.F;
	constexpr float row_one_y = 50.F;
	constexpr float row_two_y = 275.f;
	constexpr float row_three_y = 500.F;
	constexpr unsigned max_players = 4U;

	class CustomMenuScreen : public IScreen {
	public:
		explicit CustomMenuScreen(sf::RenderWindow& window, const sf::Font& font);

		GameEvent input() override;
		void update() override;
		void draw() override;
	private:
		sf::RectangleShape backButton{ sf::Vector2f(menu_back_button_width, menu_back_button_height) };
		DropBox playersBox{ "Players:" };
		DropBox computersBox{ "Computers:" };
		DropBox difficultyBox{ "Difficulty:" };
		DropBox oilBox{ "Oil:" };
		DropBox cashBox{ "Cash:" };
		DropBox researchBox{ "Research:" };
		// name input

		void initializeBoxes();
	};
}