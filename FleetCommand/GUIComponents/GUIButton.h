#pragma once

#include <SFML\Graphics.hpp>

#include <string>

namespace fleet {
	class GUIButton {
	public:
		explicit GUIButton(const sf::Vector2f& size, const std::string& label, const sf::Font& font);

		void setPosition(float x, float y);
		void setPosition(const sf::Vector2f& position);
		void setLabelOffset(float offset);
		void setCharacterSize(unsigned newSize);

		void setActive(bool isActive);

		bool input(const sf::Vector2f& mousePos);
		void update(const sf::Vector2f& mousePos);
	private:
		sf::RectangleShape button;
		sf::Text label;
		bool active{ true };
		float labelOffset{ 0.F };
	};
}