#pragma once

#include "Expressions.h"

#include <SFML\Graphics.hpp>

#include <string>

namespace fleet {
	class UpgradeButton : public sf::Drawable {
	public:
		explicit UpgradeButton(const std::string& newLabel, const sf::Font& font, unsigned short numUpgrades);

		void setPosition(float x, float y);
		void setPosition(const sf::Vector2f& position);

		void setLabelString(const std::string& string);
		void setCharacterSize(unsigned newSize);
		void setTextFillColor(const sf::Color& color);
		void setTextOutlineColor(const sf::Color& color);
		void setTextOutlineThickness(float thickness);

		bool input(const sf::Vector2f& mousePos, bool canAfford);
		void update(const sf::Vector2f& mousePos, unsigned currentLevel, bool canAfford);
	private:
		sf::RectangleShape button{ sf::Vector2f(default_upgrade_width, default_upgrade_height) };
		sf::Text label;
		std::vector<sf::RectangleShape> indicators;

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}