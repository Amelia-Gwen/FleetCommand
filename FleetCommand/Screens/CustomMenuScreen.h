#pragma once

#include "IScreen.h"

#include "DropBox.h"
#include "GameValues.h"
#include "GUIButton.h"

namespace fleet {
	class CustomMenuScreen : public IScreen {
	public:
		explicit CustomMenuScreen(sf::RenderWindow& window, const sf::Font& font);

		const GameValues& startValues() const { return gameValues; }

		GameEvent input() override;
		void update() override;
		void draw() override;
	private:
		GUIButton backButton{ sf::Vector2f(menu_back_button_width, menu_back_button_height), "Back", font };
		DropBox playersBox{ "Players:", font };
		DropBox computersBox{ "Computer:", font };
		DropBox difficultyBox{ "Difficulty:", font };
		DropBox oilBox{ "Oil:", font };
		DropBox cashBox{ "Cash:", font };
		DropBox researchBox{ "Research:", font };
		GUIButton startButton{ sf::Vector2f(start_button_width, start_button_height), "Start Game", font };
		GameValues gameValues;

		void initializeBoxes();
		void setValues();
	};
}