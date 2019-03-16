#pragma once

#include "IScreen.h"
#include "DropBox.h"

namespace fleet {

	constexpr float collumn_one_x = 300.F;
	constexpr float collumn_two_x = 700.F;
	constexpr float row_one_y = 50.F;
	constexpr float row_two_y = 275.f;
	constexpr float row_three_y = 500.F;
	constexpr float start_button_width = 300.F;
	constexpr float start_button_height = 75.F;
	constexpr float start_button_x = 400.F;
	constexpr float start_button_y = 700.F;
	constexpr float start_x = start_button_x + 40.F;
	constexpr float start_y = start_button_y + 10.F;
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
		sf::RectangleShape startButton{ sf::Vector2f(start_button_width, start_button_height) };
		sf::Text start{ "Start Game", font };

		void initializeBoxes();
	};
}