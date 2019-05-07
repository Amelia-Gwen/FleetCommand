#pragma once

#include "Expressions.h"

#include <Graphics.hpp>

#include <string>

namespace fleet {
	class UnitButton : public sf::Drawable {
	public:
		explicit UnitButton(const std::string& newLabel, const sf::Font& font, unsigned baseCost);

		void setPosition(float x, float y);
		void setPosition(const sf::Vector2f& position);
		void setActive(bool isActive) { active = isActive; }

		const sf::String& getLabelString() const { return label.getString(); }
		const sf::Color& getTextFillColor() const { return label.getFillColor(); }

		bool input(const sf::Vector2f& mousePos, bool canAfford);
		void update(const sf::Vector2f& mousePos, bool canAfford);
	private:
		sf::RectangleShape button{ sf::Vector2f(default_unit_button_width, default_unit_button_height) };
		sf::Text label;
		unsigned baseCost;
		sf::Text baseCostLabel;
		bool active{ false };

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}