#pragma once

#include "Expressions.h"

#include <Graphics.hpp>

#include <string>

namespace fleet {
	class UnitButton : sf::Drawable {
	public:
		explicit UnitButton(const std::string& newLabel, const sf::Font& font, unsigned baseCost);

		void setPosition(float x, float y);
		void setPosition(const sf::Vector2f& position);

		const sf::String& getLabelString() const { return label.getString(); }

		bool input(const sf::Vector2f& mousePos, bool canAfford);
		void update(const sf::Vector2f& mousePos, bool canAfford);
	private:
		sf::RectangleShape button{ sf::Vector2f(default_unit_button_width, default_unit_button_height) };
		sf::Text label;
		unsigned baseCost;
		sf::Text baseCostLabel;

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}