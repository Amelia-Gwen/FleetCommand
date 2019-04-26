#pragma once

#include "Expressions.h"

#include <Graphics.hpp>

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

		const sf::Vector2f& getPosition() const { return button.getPosition(); }
		const sf::String& getLabelString() const { return label.getString(); }
		unsigned getCharacterSize() const { return label.getCharacterSize(); }
		const sf::Color& getTextFillColor() const { return label.getFillColor(); }
		const std::vector<sf::RectangleShape>& getIndicators() const { return indicators; }

		bool input(const sf::Vector2f& mousePos, bool canAfford);
		void update(const sf::Vector2f& mousePos, unsigned currentLevel, bool canAfford);
	private:
		sf::RectangleShape button{ sf::Vector2f(default_upgrade_width, default_upgrade_height) };
		sf::Text label;
		std::vector<sf::RectangleShape> indicators;

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}