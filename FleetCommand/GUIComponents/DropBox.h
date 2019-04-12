#pragma once

#include "Expressions.h"

#include <SFML\Graphics.hpp>

#include <utility>
#include <vector>
#include <string>

namespace fleet {
	/*
	Class to provide label and drop down options.
	*/
	class DropBox : public sf::Drawable {
	public:
		DropBox(const std::string& newLabel);

		/*
		Position will define the x,y coordinate of the upper left corner of the label.
		The dropdown will then be positioned by the default distance from the label unless otherwise specified.
		There is no y_offset. It cannot be altered at this time.
		*/
		void setPosition(float x, float y);
		void setPosition(const sf::Vector2f& position);
		void setDefaultDistance(float x_offset);

		void setFillColor(const sf::Color& color);
		void setOutlineColor(const sf::Color& color);
		void setOutlineThickness(float thickness);

		void setFont(const sf::Font& font);
		void setLabelString(const std::string& string);
		void setCharacterSize(unsigned newSize);
		void setTextFillColor(const sf::Color& color);
		void setTextOutlineColor(const sf::Color& color);
		void setTextOutlineThickness(float thickness);

		void addElement(const std::string& string, const sf::Font& font);
		void setElement(const std::string& string, unsigned index);
		void setDefaultElement(unsigned index);

		std::string getValue() const;

		void input(const sf::Vector2f& mousePos);
		void update(const sf::Vector2f& mousePos);
	private:
		sf::Text label;
		std::vector<std::pair<sf::Text, sf::RectangleShape>> elements;
		float xOffset{ dropbox_default_x_offset };
		bool open{ false };
		int selectedIndex{ 0 };
		int size{ 0 };

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
 }