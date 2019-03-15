#pragma once

#include <SFML\Graphics.hpp>

#include <string>

namespace fleet {
	/*
	Class to provide a Label and an editable text field for user input.
	*/
	class TextField {
	public:
		TextField(const std::string& newLabel = "", sf::Color background = sf::Color::White);

		void setPosition(const sf::Vector2f& position);
		void setPosition(float x, float y);
		void setSize(const sf::Vector2f& position);
		void setFillColor(const sf::Color& color);
		void setOutlineColor(const sf::Color& color);
		void setOutlineThickness(float thickness);

		void setFont(const sf::Font& font);
		void setString(const sf::String &string);
		void setCharacterSize(unsigned int size);
		void setTextFillColor(const sf::Color& color);
		void setTextOutlineColor(const sf::Color& color);
		void setTextOutlineThickness(float thickness);

		void changeLabel(const sf::String& newLabel);
	private:
		sf::Text label;
		sf::RectangleShape textField;
		sf::Text fieldText;
	};
}