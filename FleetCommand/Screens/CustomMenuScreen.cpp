#include "CustomMenuScreen.h"

namespace fleet {
	/*
	///param: reference to RenderWindow
	///param: constant reference to Font
	The constructor takes these references and forwards them to the base class.
	*/
	CustomMenuScreen::CustomMenuScreen(sf::RenderWindow& window, const sf::Font& font) :
		IScreen{ window, font }
	{
		backButton.setPosition(menu_back_x, menu_back_y);
		initializeBoxes();
		startButton.setPosition(start_button_x, start_button_y);
		start.setPosition(start_x, start_y);
		start.setFillColor(sf::Color::Black);
		start.setCharacterSize(text_character_size);
	}

	/*
	Specific choices for user include: return to the new game screen,
	start a custom game set to the values provided (begins gameplay,)
	///return: GameEvent - custum enum to handle game level events.
	*/
	GameEvent CustomMenuScreen::input()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		if (backButton.getGlobalBounds().contains(mousePos)) {
			return GameEvent::OpenNewGame;
		}
		else if (startButton.getGlobalBounds().contains(mousePos)) {
			// save values to be used in game
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

		checkMouseOver(backButton);
		playersBox.update(mousePos);
		computersBox.update(mousePos);
		difficultyBox.update(mousePos);
		oilBox.update(mousePos);
		cashBox.update(mousePos);
		researchBox.update(mousePos);
		checkMouseOver(startButton);
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
		window.draw(start);
	}

	void CustomMenuScreen::initializeBoxes()
	{
		playersBox.setPosition(collumn_one_x, row_one_y);
		playersBox.setFont(font);
		computersBox.setPosition(collumn_two_x, row_one_y);
		computersBox.setFont(font);
		difficultyBox.setPosition(collumn_one_x, row_two_y);
		difficultyBox.setFont(font);
		oilBox.setPosition(collumn_two_x, row_two_y);
		oilBox.setFont(font);
		cashBox.setPosition(collumn_one_x, row_three_y);
		cashBox.setFont(font);
		researchBox.setPosition(collumn_two_x, row_three_y);
		researchBox.setFont(font);

		for (unsigned i = 1; i <= max_players; ++i) {
			playersBox.addElement(std::to_string(i), font);
			computersBox.addElement(std::to_string(i), font);
		}
		difficultyBox.addElement("Easy", font);
		difficultyBox.addElement("Medium", font);
		difficultyBox.addElement("Hard", font);
		oilBox.addElement("10000", font);
		oilBox.addElement("20000", font);
		oilBox.addElement("30000", font);
		oilBox.addElement("40000", font);
		oilBox.addElement("50000", font);
		oilBox.addElement("100000", font);
		cashBox.addElement("1000", font);
		cashBox.addElement("2000", font);
		cashBox.addElement("3000", font);
		cashBox.addElement("4000", font);
		cashBox.addElement("5000", font);
		cashBox.addElement("10000", font);
		researchBox.addElement("10", font);
		researchBox.addElement("20", font);
		researchBox.addElement("30", font);
		researchBox.addElement("40", font);
		researchBox.addElement("50", font);
		researchBox.addElement("100", font);
	}
}