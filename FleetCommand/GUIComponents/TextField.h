#pragma once

#include <SFML\Graphics.hpp>

#include <string>

namespace fleet {
	/*
	Class to provide a Label and an editable text field for user input.
	*/
	class TextField {
	public:
		TextField(std::string title = "", sf::Color background = sf::Color::White);

		void setPosition(const sf::Vector2f& position);
		void setSize(const sf::Vector2f& position);
		void setFillColor(const sf::Color& color);
		void setCharacterSize(unsigned int size);
	private:
		sf::Text label;
		sf::RectangleShape textField;
		sf::Text fieldText;
	};
}