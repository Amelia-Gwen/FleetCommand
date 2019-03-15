#pragma once

#include <SFML\Graphics.hpp>

#include <unordered_map>
#include <string>

namespace fleet {
	/*
	Class to provide label and drop down options.
	*/
	class DropBox {
	public:
		DropBox(const std::string& newLabel, const sf::Font& font);

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

		void setElement();
		void addElement();
	private:
		sf::Text label;
		std::unordered_map<sf::Text, sf::RectangleShape> elements;
	};
 }