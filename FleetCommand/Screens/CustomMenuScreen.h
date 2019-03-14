#pragma once

#include "IScreen.h"

namespace fleet {
	class CustomMenuScreen : public IScreen {
	public:
		explicit CustomMenuScreen(sf::RenderWindow& window, const sf::Font& font);

		GameEvent input() override;
		void update() override;
		void draw() override;
	private:
		sf::RectangleShape backButton{ sf::Vector2f(menu_back_button_width, menu_back_button_height) };
		sf::Text name{ "Name:", font };
		sf::RectangleShape nameBox{ sf::Vector2f() };
		sf::Text userName{ "Test-Remove me", font };
		sf::Text players{ "Players:", font };
		sf::RectangleShape playersBox{ sf::Vector2f() };
		sf::Text computers{ "Computers:", font };
		sf::RectangleShape computersBox{ sf::Vector2f() };
		sf::Text difficulty{ "Difficulty:", font };
		sf::RectangleShape difficultyBox{ sf::Vector2f() };
		sf::Text startingOil{ "Starting Oil:", font };
		sf::Text startingCash{ "Starting Cash:", font };
		sf::Text startingResearch{ "Starting Research", font };
	};
}