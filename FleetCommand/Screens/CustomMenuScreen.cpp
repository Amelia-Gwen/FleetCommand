#include "CustomMenuScreen.h"

#include <map>

namespace fleet {
	std::map<std::string, Difficulty> string_to_difficulty_enum{
		std::make_pair<std::string, Difficulty>("Easy", Difficulty::Easy),
		std::make_pair<std::string, Difficulty>("Medium", Difficulty::Medium),
		std::make_pair<std::string, Difficulty>("Hard", Difficulty::Hard)
	};

	/*
	param: reference to RenderWindow
	param: constant reference to Font
	The constructor takes these references and forwards them to the base class.
	*/
	CustomMenuScreen::CustomMenuScreen(sf::RenderWindow& window, const sf::Font& font) :
		IScreen{ window, font }
	{
		backButton.setLabelOffset(sf::Vector2f(back_x_offset, menu_text_y_offset));
		backButton.setPosition(menu_back_x, menu_back_y);
		initializeBoxes();
		startButton.setLabelOffset(sf::Vector2f(start_x_offset, menu_text_y_offset));
		startButton.setPosition(start_button_x, start_button_y);
		startButton.setCharacterSize(text_character_size);
	}

	/*
	Specific choices for user include: return to the new game screen,
	start a custom game set to the values provided (begins gameplay,)
	return: GameEvent - custum enum to handle game level events.
	*/
	GameEvent CustomMenuScreen::input()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		if (backButton.input(mousePos)) {
			return GameEvent::OpenNewGame;
		}
		else if (startButton.input(mousePos)) {
			setValues();
			return GameEvent::StartGame;
		}

		playersBox.input(mousePos);
		computersBox.input(mousePos);
		difficultyBox.input(mousePos);
		oilBox.input(mousePos);
		cashBox.input(mousePos);
		researchBox.input(mousePos);

		return GameEvent::None;
	}
	/*
	Method to update screen components
	*/
	void CustomMenuScreen::update()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		backButton.update(mousePos);
		playersBox.update(mousePos);
		computersBox.update(mousePos);
		difficultyBox.update(mousePos);
		oilBox.update(mousePos);
		cashBox.update(mousePos);
		researchBox.update(mousePos);
		startButton.update(mousePos);
	}
	/*
	Render logic. This is the main need for the window reference.
	*/
	void CustomMenuScreen::draw()
	{
		window.draw(backButton);
		window.draw(playersBox);
		window.draw(computersBox);
		window.draw(difficultyBox);
		window.draw(oilBox);
		window.draw(cashBox);
		window.draw(researchBox);
		window.draw(startButton);
	}

	void CustomMenuScreen::initializeBoxes()
	{
		playersBox.setPosition(column_one_x, row_one_y);
		computersBox.setPosition(column_two_x, row_one_y);
		difficultyBox.setPosition(column_one_x, row_two_y);
		oilBox.setPosition(column_two_x, row_two_y);
		cashBox.setPosition(column_one_x, row_three_y);
		researchBox.setPosition(column_two_x, row_three_y);

		computersBox.addElement("0");
		for (unsigned i = 1; i <= max_players; ++i) {
			playersBox.addElement(std::to_string(i));
			computersBox.addElement(std::to_string(i));
		}
		difficultyBox.addElement("Easy");
		difficultyBox.addElement("Medium");
		difficultyBox.addElement("Hard");
		oilBox.addElement("10000");
		oilBox.addElement("20000");
		oilBox.addElement("30000");
		oilBox.addElement("40000");
		oilBox.addElement("50000");
		oilBox.addElement("100000");
		cashBox.addElement("1000");
		cashBox.addElement("2000");
		cashBox.addElement("3000");
		cashBox.addElement("4000");
		cashBox.addElement("5000");
		cashBox.addElement("10000");
		researchBox.addElement("10");
		researchBox.addElement("20");
		researchBox.addElement("30");
		researchBox.addElement("40");
		researchBox.addElement("50");
		researchBox.addElement("100");
	}
	void CustomMenuScreen::setValues()
	{
		gameValues = {
			std::stoi(playersBox.getValue()),
			std::stoi(computersBox.getValue()),
			string_to_difficulty_enum[difficultyBox.getValue()],
			std::stoi(oilBox.getValue()),
			std::stoi(cashBox.getValue()),
			std::stoi(researchBox.getValue())
		};
	}
}