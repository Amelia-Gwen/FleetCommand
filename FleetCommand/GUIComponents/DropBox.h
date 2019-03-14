#pragma once

#include <SFML\Graphics.hpp>

#include <unordered_map>

namespace fleet {
	/*
	Class to provide label and drop down options.
	*/
	class DropBox {
	public:
		DropBox();

		void addElement();
		void setPosition(const sf::Vector2f& position);
		void setSize(const sf::Vector2f& position);
		void setFillColor(const sf::Color& color);
		void setCharacterSize(unsigned int size);
	private:
		std::unordered_map<sf::Text, sf::RectangleShape> elements;
	};
 }