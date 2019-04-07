#pragma once

#include "DropBox.h"
#include "GameValues.h"
#include "IScreen.h"

namespace fleet {
	class CustomMenuScreen : public IScreen {
	public:
		explicit CustomMenuScreen(sf::RenderWindow& window, const sf::Font& font);

		const GameValues& startValues() const { return gameValues; }

		GameEvent input() override;
		void update() override;
		void draw() override;
	private:
		sf::RectangleShape backButton{ sf::Vector2f(menu_back_button_width, menu_back_button_height) };
		DropBox playersBox{ "Players:" };
		DropBox computersBox{ "Computer:" };
		DropBox difficultyBox{ "Difficulty:" };
		DropBox oilBox{ "Oil:" };
		DropBox cashBox{ "Cash:" };
		DropBox researchBox{ "Research:" };
		sf::RectangleShape startButton{ sf::Vector2f(start_button_width, start_button_height) };
		sf::Text start{ "Start Game", font };
		GameValues gameValues;

		void initializeBoxes();
		void setValues();
	};
}